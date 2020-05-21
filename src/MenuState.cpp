#include "MenuState.hpp"
#include "Settings.hpp"


#include <cassert>

MenuState::MenuState(sf::RenderWindow& window) : start_button_(tgui::Button::create("Start")),
                                                 exit_button_(tgui::Button::create("Exit")),
                                                 gui_(window), response_(StateResponse::None) {
    start_button_->setSize(BUTTON_SIZE.x, BUTTON_SIZE.y);
    start_button_->setPosition(START_BUTTON_POS.x, START_BUTTON_POS.y);
    start_button_->setInheritedFont(font_);
    start_button_->setTextSize(FONT_SIZE);
    start_button_->connect("pressed", [this]() { response_ = StateResponse::ChangeState; });

    exit_button_->setSize(BUTTON_SIZE.x, BUTTON_SIZE.y);
    exit_button_->setPosition(EXIT_BUTTON_POS.x, EXIT_BUTTON_POS.y);
    exit_button_->setInheritedFont(font_);
    exit_button_->setTextSize(FONT_SIZE);
    exit_button_->connect("pressed", [this]() { response_ = StateResponse::CloseWindow; });

    gui_.add(start_button_);
    gui_.add(exit_button_);
}


void MenuState::enable() {
    start_button_->showWithEffect(tgui::ShowAnimationType::Fade, sf::seconds(0.1));
    exit_button_->showWithEffect(tgui::ShowAnimationType::Fade, sf::seconds(0.1));
    start_button_->setVisible(true);
    exit_button_->setVisible(true);
}


void MenuState::disable() {
    start_button_->hideWithEffect(tgui::ShowAnimationType::Fade, sf::seconds(0.1));
    exit_button_->hideWithEffect(tgui::ShowAnimationType::Fade, sf::seconds(0.1));
}


StateResponse MenuState::handleEvent(sf::Event& event) {
    response_ = StateResponse::None;
    gui_.handleEvent(event);
    return response_;
}


void MenuState::runIteration(sf::RenderWindow& window) {
    background_.draw(window);
    gui_.draw();
}




