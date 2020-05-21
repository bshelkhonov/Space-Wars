#include "PauseSubstate.hpp"
#include "PlayerSpaceship.hpp"
#include "Settings.hpp"

#include <TGUI/TGUI.hpp>

PlayState::PauseSubstate::PauseSubstate(PlayState& play_state, tgui::Gui& gui)
        : play_state_(play_state),
          resume_button_(tgui::Button::create("Resume")), exit_button_(tgui::Button::create("Exit")),
          font_(FONT_PATH), response_(StateResponse::None) {
    resume_button_->setSize(BUTTON_SIZE.x, BUTTON_SIZE.y);
    resume_button_->setPosition(START_BUTTON_POS.x, START_BUTTON_POS.y);
    resume_button_->setInheritedFont(font_);
    resume_button_->setTextSize(BUTTON_FONT_SIZE);
    resume_button_->connect("pressed", [this]() { response_ = StateResponse::Unpause; });

    exit_button_->setSize(BUTTON_SIZE.x, BUTTON_SIZE.y);
    exit_button_->setPosition(EXIT_BUTTON_POS.x, EXIT_BUTTON_POS.y);
    exit_button_->setInheritedFont(font_);
    exit_button_->setTextSize(BUTTON_FONT_SIZE);
    exit_button_->connect("pressed", [this]() { response_ = StateResponse::CloseWindow; });

    gui.add(resume_button_);
    gui.add(exit_button_);
}


void PlayState::PauseSubstate::enable() {
    resume_button_->showWithEffect(tgui::ShowAnimationType::Fade, sf::seconds(0.1));
    exit_button_->showWithEffect(tgui::ShowAnimationType::Fade, sf::seconds(0.1));
    resume_button_->setVisible(true);
    exit_button_->setVisible(true);
    response_ = StateResponse::None;
}


void PlayState::PauseSubstate::disable() {
    resume_button_->hideWithEffect(tgui::ShowAnimationType::Fade, sf::seconds(0.1));
    exit_button_->hideWithEffect(tgui::ShowAnimationType::Fade, sf::seconds(0.1));
    PlayerSpaceship::unpause();
    play_state_.enemies_.unpause();
}


StateResponse PlayState::PauseSubstate::runIteration(sf::RenderWindow& window) {
    window.clear();
    play_state_.background_.draw(window);
    PlayerSpaceship::get().draw(window);
    play_state_.enemies_.draw(window);
    return response_;
}
