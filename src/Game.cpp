#include "Game.hpp"
#include "Settings.hpp"
#include "IState.hpp"
#include "PlayState.hpp"
#include "MenuState.hpp"

#include <SFML/Graphics.hpp>

#include <memory>


Game::Game() : window_(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Space Wars", sf::Style::Close),
               gui_(window_) {}


Game::~Game() = default;



void Game::run() {
    std::shared_ptr<IState> play_state = std::dynamic_pointer_cast<IState>(std::make_shared<PlayState>(gui_));
    std::shared_ptr<IState> menu_state = std::dynamic_pointer_cast<IState>(std::make_shared<MenuState>(gui_));

    std::shared_ptr<IState> current_state = menu_state;
    std::shared_ptr<IState> next_state = play_state;

    current_state->enable();
    next_state->disable();

    while (window_.isOpen()) {
        sf::Event event{};

        while (window_.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window_.close();
            current_state->handleEvent(event);
            gui_.handleEvent(event);
        }

        auto response = current_state->runIteration(window_);
        if (response != StateResponse::None) {
            switch (response) {
                case StateResponse::Start:
                case StateResponse::Finish:
                    current_state->disable();
                    swap(current_state, next_state);
                    current_state->enable();
                    break;
                case StateResponse::CloseWindow:
                    window_.close();
                default:
                    break;
            }
        }

        gui_.draw();
        window_.display();
    }
}


