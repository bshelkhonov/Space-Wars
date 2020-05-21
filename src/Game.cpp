#include "Game.hpp"
#include "Settings.hpp"
#include "IState.hpp"
#include "PlayState.hpp"
#include "MenuState.hpp"

#include <SFML/Graphics.hpp>

#include <memory>


Game::Game() : window_(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Space Wars", sf::Style::Close) {}


Game::~Game() = default;


void Game::run() {
    std::shared_ptr<IState> play_state = std::dynamic_pointer_cast<IState>(std::make_shared<PlayState>());
    std::shared_ptr<IState> menu_state = std::dynamic_pointer_cast<IState>(std::make_shared<MenuState>(window_));

    std::shared_ptr<IState> current_state = menu_state;

    while (window_.isOpen()) {
        sf::Event event{};

        while (window_.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window_.close();
            StateResponse response = current_state->handleEvent(event);
            if (response == StateResponse::ChangeState) {
                current_state->disable();
                if (current_state == play_state) {
                    current_state = menu_state;
                } else {
                    current_state = play_state;
                }
                current_state->enable();
            } else if (response == StateResponse::CloseWindow) {
                window_.close();
            }
        }

        current_state->runIteration(window_);

        window_.display();
    }
}

