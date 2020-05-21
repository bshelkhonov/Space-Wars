#include "MenuState.hpp"
#include "Settings.hpp"


#include <cassert>

MenuState::MenuState(tgui::Gui& gui)
        : last_game_score_label_(tgui::Label::create()), high_score_label_(tgui::Label::create()), label_renderer_(),
          start_button_(tgui::Button::create("Start")),
          exit_button_(tgui::Button::create("Exit")),
          font_(FONT_PATH), response_(StateResponse::None),
          last_game_score_(0), high_score_(0), score_text_(LOSE_TEXT), high_score_text_(HIGH_SCORE_TEXT) {

    label_renderer_.setTextColor(tgui::Color::White);

    last_game_score_label_->setRenderer(label_renderer_.getData());
    last_game_score_label_->setPosition(MENU_SCORE_LABEL_POS);
    last_game_score_label_->setTextSize(SCORE_FONT_SIZE);

    high_score_label_->setRenderer(label_renderer_.getData());
    high_score_label_->setText(high_score_text_ + "0");
    high_score_label_->setPosition(HIGH_SCORE_LABEL_POS);
    high_score_label_->setTextSize(40);

    start_button_->setSize(BUTTON_SIZE.x, BUTTON_SIZE.y);
    start_button_->setPosition(START_BUTTON_POS.x, START_BUTTON_POS.y);
    start_button_->setInheritedFont(font_);
    start_button_->setTextSize(BUTTON_FONT_SIZE);
    start_button_->connect("pressed", [this]() { response_ = StateResponse::Start; });

    exit_button_->setSize(BUTTON_SIZE.x, BUTTON_SIZE.y);
    exit_button_->setPosition(EXIT_BUTTON_POS.x, EXIT_BUTTON_POS.y);
    exit_button_->setInheritedFont(font_);
    exit_button_->setTextSize(BUTTON_FONT_SIZE);
    exit_button_->connect("pressed", [this]() { response_ = StateResponse::CloseWindow; });

    gui.add(start_button_);
    gui.add(exit_button_);
    gui.add(last_game_score_label_);
    gui.add(high_score_label_);
}


void MenuState::enable() {
    start_button_->showWithEffect(tgui::ShowAnimationType::Fade, sf::seconds(0.1));
    exit_button_->showWithEffect(tgui::ShowAnimationType::Fade, sf::seconds(0.1));
    start_button_->setVisible(true);
    exit_button_->setVisible(true);
    last_game_score_label_->setVisible(true);

    high_score_label_->setPosition(HIGH_SCORE_LABEL_POS);
    high_score_label_->setTextSize(SCORE_FONT_SIZE);

    response_ = StateResponse::None;
}


void MenuState::disable() {
    start_button_->hideWithEffect(tgui::ShowAnimationType::Fade, sf::seconds(0.1));
    exit_button_->hideWithEffect(tgui::ShowAnimationType::Fade, sf::seconds(0.1));
    last_game_score_label_->hideWithEffect(tgui::ShowAnimationType::Fade, sf::seconds(0.1));
    response_ = StateResponse::None;

    high_score_label_->setPosition(HIGH_SCORE_INGAME_POS);
    high_score_label_->setTextSize(HIGH_SCORE_INGAME_FONT_SIZE);
}


void MenuState::handleEvent(const sf::Event&) {

}


StateResponse MenuState::runIteration(sf::RenderWindow& window) {
    background_.draw(window);
    return response_;
}


void MenuState::showScore(size_t score) {
    last_game_score_ = score;

    if (score > high_score_) {
        high_score_ = score;
        last_game_score_label_->setText(score_text_ + std::to_string(score) + " (new high score)");
        high_score_label_->setText(high_score_text_ + std::to_string(score));
    } else {
        last_game_score_label_->setText(score_text_ + std::to_string(score));
    }
    last_game_score_label_->showWithEffect(tgui::ShowAnimationType::Fade, sf::seconds(0.1));
    last_game_score_label_->setVisible(true);
}



