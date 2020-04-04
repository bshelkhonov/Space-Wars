#include "Game.hpp"
#include "Settings.hpp"
#include <SFML/Graphics.hpp>


Game::Game() : window_(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Space Wars", sf::Style::Close) {
    auto bg_texture = new sf::Texture();
    bg_texture->loadFromFile(BACKGROUND_FILE);
    background_.setTexture(*bg_texture);
    background_.setPosition(0, 0);
}


Game::~Game() {
    delete background_.getTexture();
}


void Game::run() {
    player_.reset_clock();
    while (window_.isOpen()) {
        clock_.restart();
        sf::Event event;


        while (window_.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window_.close();
        }

        player_.action();

        window_.clear();
        window_.draw(background_);
        player_.draw(window_);
        window_.display();
    }
}

