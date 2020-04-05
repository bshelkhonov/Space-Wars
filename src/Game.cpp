#include "Game.hpp"
#include "Background.hpp"
#include "Settings.hpp"
#include <SFML/Graphics.hpp>


Game::Game() : window_(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Space Wars", sf::Style::Close) {}


Game::~Game() {}


void Game::run() {
    SpaceShip player;
    Background background;
    while (window_.isOpen()) {
        clock_.restart();
        sf::Event event;


        while (window_.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window_.close();
        }

        player.action();
        background.move();

        window_.clear();
        background.draw(window_);
        player.draw(window_);
        window_.display();
    }
}

