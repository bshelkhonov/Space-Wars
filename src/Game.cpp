#include "Game.hpp"
#include "Settings.hpp"
#include "IState.hpp"
#include "PlayState.hpp"
#include "MenuState.hpp"

#include <SFML/Graphics.hpp>

#include <memory>
#include <iostream>


Game::Game() :
        window_(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Space Wars", sf::Style::Close),
        gui_(window_), play_state_(std::make_shared<PlayState>(gui_)),
        menu_state_(std::make_shared<MenuState>(gui_)) {
    current_state_ = std::dynamic_pointer_cast<IState>(menu_state_);
    current_state_->enable();
    play_state_->disable();
}


Game::~Game() = default;


void Game::startGame_() {
    current_state_->disable();
    current_state_ = std::dynamic_pointer_cast<IState>(play_state_);
    current_state_->enable();
    std::cout << "START" << std::endl;
}


void Game::finishGame_() {
    current_state_->disable();
    current_state_ = std::dynamic_pointer_cast<IState>(menu_state_);;
    current_state_->enable();
    menu_state_->showScore(play_state_->getScore());
    std::cout << "FIINISH" << std::endl;
}


void Game::run() {
    while (window_.isOpen()) {
        if (current_state_ == std::dynamic_pointer_cast<IState>(play_state_)) {
            std::cout << 1 << std::endl;
        }

        sf::Event event{};

        while (window_.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window_.close();
            current_state_->handleEvent(event);
            gui_.handleEvent(event);
        }

        auto response = current_state_->runIteration(window_);

        if (response != StateResponse::None) {
            switch (response) {
                case StateResponse::Start:
                    startGame_();
                    break;
                case StateResponse::Finish:
                    finishGame_();
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




