#include "PlayState.hpp"
#include "PlayerSpaceship.hpp"
#include "Settings.hpp"
#include "RunningSubstate.hpp"
#include "PauseSubstate.hpp"

#include <SFML/Graphics.hpp>


PlayState::PlayState(tgui::Gui& gui)
        : score_label_(tgui::Label::create()),
          score_renderer_(),
          running_substate_(std::dynamic_pointer_cast<IState>(std::make_shared<RunningSubstate>(*this))),
          pause_substate_(std::dynamic_pointer_cast<IState>(std::make_shared<PauseSubstate>(*this, gui))),
          current_substate_(running_substate_), font_(FONT_PATH),
          response_(StateResponse::None), score_(0),
          score_prefix_("Your score: ") {
    score_renderer_.setTextColor(tgui::Color::White);
    score_label_->setPosition(SCORE_LABEL_POS);
    score_label_->setTextSize(SCORE_LABEL_FONT_SIZE);
    score_label_->setRenderer(score_renderer_.getData());
    score_label_->setInheritedFont(font_);
    gui.add(score_label_);

    pause_substate_->disable();
    running_substate_->enable();
}


void PlayState::changeState_() {
    current_substate_->disable();
    current_substate_ = current_substate_ == running_substate_ ? pause_substate_ : running_substate_;
    current_substate_->enable();
}


void PlayState::enable() {
    response_ = StateResponse::None;
    score_label_->showWithEffect(tgui::ShowAnimationType::Fade, sf::seconds(0.1));
    score_label_->setVisible(true);
    score_ = 0;

    running_substate_->enable();
    pause_substate_->disable();

    current_substate_ = running_substate_;
}


void PlayState::disable() {
    score_label_->hideWithEffect(tgui::ShowAnimationType::Fade, sf::seconds(0.1));
    PlayerSpaceship::destroy();
    enemies_.reset();
    response_ = StateResponse::None;

    running_substate_->disable();
    pause_substate_->enable();
}


void PlayState::handleEvent(const sf::Event& event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Escape)
            changeState_();
    }
    current_substate_->handleEvent(event);
}


StateResponse PlayState::runIteration(sf::RenderWindow& window) {
    auto response = current_substate_->runIteration(window);
    if (response == StateResponse::Pause || response == StateResponse::Unpause) {
        changeState_();
        response = StateResponse::None;
    }
    return response;
}


size_t PlayState::getScore() const {
    return score_;
}



