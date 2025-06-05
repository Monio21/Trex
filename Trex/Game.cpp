#include "Game.h"

Game::Game(sf::Texture Trex_Idle_Texture, sf::Font font, sf::SoundBuffer jump_buffer, sf::SoundBuffer point_buffer, sf::SoundBuffer death_buffer, sf::Texture desertTexture) :
    window(sf::VideoMode({ 900, 413 }), "Trex", sf::Style::Close | sf::Style::Resize),
    trex(sf::Sprite(Trex_Idle_Texture), Trex_Idle_Texture),
    ziemia1(desertTexture), ziemia2(desertTexture),
	startText(font), scoreText(font), endText(font), highScoreText(font),
	jumpSound(jump_buffer), pointSound(point_buffer), deathSound(death_buffer),
    score(scoreText)
{
    window.setFramerateLimit(120);
    loadResources();
    setUp();
    reset();

};

void Game::loadResources() {
    // Ikona
    sf::Image icon;
    icon.loadFromFile("pictures/icon.png");
    window.setIcon(icon.getSize(), icon.getPixelsPtr());

    // Trex
    sf::Texture idle;
    idle.loadFromFile("olaf/base/idle.png");
    sf::Sprite sprite(idle);
    Trex trex(sprite, idle);
    trex.setTextureRect();
    trex.setOrigin();
    trex.setScale(6.0f, 6.0f);

    // T³a
    ziemia1.setPosition(0.0f, 0.0f);
    ziemia2.setPosition(1440.0f, 0.0f);

    // Cactusy
    sf::Texture cactusTexture;
    cactusTexture.loadFromFile("pictures/cactus.png");
    cacti = {
        Cactus(cactusTexture),
        Cactus(cactusTexture),
        Cactus(cactusTexture)
    };

    // Muzyka
    music.openFromFile("audio/Jurassic Park theme song..ogg");
    music.setVolume(100.0f);
    music.setLooping(true);
    music.setPlayingOffset(sf::seconds(30.f));
    music.play();

    // DŸwiêki
    pointSound.setVolume(25.0f);

}

void Game::setUp() {

    scoreText.setFont(font);
    scoreText.setCharacterSize(30);
    scoreText.setPosition({ 10.0f, 10.0f });
    scoreText.setFillColor(sf::Color::Black);

    highScoreText.setFont(font);
    highScoreText.setCharacterSize(30);
    highScoreText.setPosition({ 680.0f, 10.0f });
    highScoreText.setFillColor(sf::Color::Black);

    startText.setFont(font);
    startText.setCharacterSize(60);
    startText.setString("Press ENTER to start");
    startText.setPosition({ 200.0f, 206.0f });
    startText.setFillColor(sf::Color::Black);

    endText.setFont(font);
    endText.setCharacterSize(60);
    endText.setPosition({ 100.0f, 100.0f });
    endText.setFillColor(sf::Color::Black);
}

void Game::run() {
    while (window.isOpen()) {
        processEvents();
        sf::Time delta = clock.restart();
        update(delta);
        render();
    }
}

void Game::processEvents() {
    while (const std::optional event = window.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
            window.close();
    }
}

void Game::update(sf::Time deltaTime) {
    if (death) {
        timeToSwitch += deltaTime.asSeconds();
        if (timeToSwitch > 0.5f) {
            reset();
        }
    }

    if (!start) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) {
            start = true;
            score.reset();
        }
        return;
    }

    frames++;
    if ((frames % 500) == 0 && multiplier < 2.5f) {
        multiplier += 0.15f;
    }

    for (auto& cactus : cacti) {
        cactus.move(multiplier);
    }

    ziemia1.move(multiplier);
    ziemia2.move(multiplier);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
        trex.jump(jumpSound);
        trex.setTexture(3);
    }

    trex.update(deltaTime.asSeconds());
    trex.applyGravity();
    score.update(multiplier, pointSound);

    for (auto& cactus : cacti) {
        Collider::checkCollision(trex, cactus.getGlobalBounds(), death, start, deathSound);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
        saveHighscore();
        window.close();
    }
}

void Game::render() {
    window.clear();
    ziemia1.draw(window);
    ziemia2.draw(window);

    if (!start) {
        window.draw(startText);
        if (death) {
            endText.setString("Your Score: " + std::to_string(score.getScore()));
            window.draw(endText);
        }
    }
    else {
        trex.draw(window);
        for (auto& cactus : cacti) {
            cactus.draw(window);
        }
        score.draw(window);
        highScoreText.setString("Highscore: " + std::to_string(score.getHighScore()));
        window.draw(highScoreText);
    }

    window.display();
}

void Game::reset() {
    multiplier = 1.0f;
    frames = 0;
    start = false;
    death = false;
    timeToSwitch = 0.0f;

    ziemia1.setPosition(0.0f, 0.0f);
    ziemia2.setPosition(1440.0f, 0.0f);
    trex.setPosition(80.0f, 300.0f);

    cacti[0].setPosition(900.0f, 325.0f);
    cacti[1].setPosition(1400.0f, 325.0f);
    cacti[2].setPosition(1900.0f, 325.0f);

    trex.setTexture(1);
}

void Game::saveHighscore() {
    std::ofstream file("logs/highscores.txt", std::ios::app);
    if (file) {
        auto now = std::time(nullptr);
        std::tm local;
        localtime_s(&local, &now);
        file << std::put_time(&local, "%d/%m/%Y %H:%M:%S") << " | HighScore: " << score.getHighScore() << "\n";
        file.close();
    }
}