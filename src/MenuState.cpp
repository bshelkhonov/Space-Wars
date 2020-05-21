#include "MenuState.hpp"
#include "Settings.hpp"


#include <cassert>

MenuState::MenuState(tgui::Gui& gui) : start_button_(tgui::Button::create("Start")),
                                       exit_button_(tgui::Button::create("Exit")),
                                       font_(FONT_PATH), response_(StateResponse::None) {
    start_button_->setSize(BUTTON_SIZE.x, BUTTON_SIZE.y);
    start_button_->setPosition(START_BUTTON_POS.x, START_BUTTON_POS.y);
    start_button_->setInheritedFont(font_);
    start_button_->setTextSize(BUTTON_FONT_SIZE);
    start_button_->connect("pressed", [this]() { response_ = StateResponse::ChangeState; });

    exit_button_->setSize(BUTTON_SIZE.x, BUTTON_SIZE.y);
    exit_button_->setPosition(EXIT_BUTTON_POS.x, EXIT_BUTTON_POS.y);
    exit_button_->setInheritedFont(font_);
    exit_button_->setTextSize(BUTTON_FONT_SIZE);
    exit_button_->connect("pressed", [this]() { response_ = StateResponse::CloseWindow; });

    gui.add(start_button_);
    gui.add(exit_button_);
}


void MenuState::enable() {
    start_button_->showWithEffect(tgui::ShowAnimationType::Fade, sf::seconds(0.1));
    exit_button_->showWithEffect(tgui::ShowAnimationType::Fade, sf::seconds(0.1));
    start_button_->setVisible(true);
    exit_button_->setVisible(true);
    response_ = StateResponse::None;
}


void MenuState::disable() {
    start_button_->hideWithEffect(tgui::ShowAnimationType::Fade, sf::seconds(0.1));
    exit_button_->hideWithEffect(tgui::ShowAnimationType::Fade, sf::seconds(0.1));
    response_ = StateResponse::None;
}


StateResponse MenuState::runIteration(sf::RenderWindow& window) {
    background_.draw(window);
    return response_;
}




