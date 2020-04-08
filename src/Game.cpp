#include "Game.hpp"
#include "Background.hpp"
#include "Settings.hpp"
#include "PlayerSpaceship.hpp"
#include <SFML/Graphics.hpp>


Game::Game() : window_(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Space Wars", sf::Style::Close) {}


Game::~Game() = default;


void Game::run() {
    Background background;
    while (window_.isOpen()) {
        clock_.restart();
        sf::Event event{};

        for (auto& enemy : EnemyCreator::get())
            enemies_.push_front(enemy);

        while (window_.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window_.close();
        }

        PlayerSpaceship::get().action();

        for (auto& enemy : enemies_)
            enemy.action();

        background.move();

        window_.clear();
        background.draw(window_);
        PlayerSpaceship::get().draw(window_);
        window_.display();
    }
    PlayerSpaceship::destroy();
}

