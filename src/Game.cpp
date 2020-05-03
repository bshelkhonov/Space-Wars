#include "Game.hpp"
#include "Background.hpp"
#include "Settings.hpp"
#include "PlayerSpaceship.hpp"
#include "EnemiesContainer.hpp"
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>



Game::Game() : window_(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Space Wars", sf::Style::Close) {}


Game::~Game() = default;


void Game::run() {
    Background background;

    EnemiesContainer enemies;

    tgui::Gui gui(window_);

    while (window_.isOpen()) {
        clock_.restart();
        sf::Event event{};


        while (window_.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window_.close();
            gui.handleEvent(event);
        }

        PlayerSpaceship::get().action();
        enemies.action();

        enemies.collision(PlayerSpaceship::get());

        background.move();

        window_.clear();
        background.draw(window_);
        PlayerSpaceship::get().draw(window_);
        enemies.draw(window_);

        gui.draw();
        window_.display();
    }
    PlayerSpaceship::destroy();
}

