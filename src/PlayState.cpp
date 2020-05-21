#include "PlayState.hpp"
#include "PlayerSpaceship.hpp"
#include "Settings.hpp"
#include <SFML/Graphics.hpp>


PlayState::PlayState(tgui::Gui& gui) : score_label_(tgui::Label::create()),
                                       score_renderer_(),
                                       current_substate_(
                                               std::dynamic_pointer_cast<IState>(
                                                       std::make_shared<RunningSubstate>(*this))),
                                       next_substate_(std::dynamic_pointer_cast<IState>(
                                               std::make_shared<PauseSubstate>(*this))),
                                       response_(StateResponse::None), score_(0),
                                       score_prefix_("Your score: ") {
    score_renderer_.setTextColor(tgui::Color::White);
    score_label_->setPosition(SCORE_LABEL_POS);
    score_label_->setTextSize(SCORE_LABEL_FONT_SIZE);
    score_label_->setRenderer(score_renderer_.getData());
    gui.add(score_label_);
}


void PlayState::enable() {
    response_ = StateResponse::None;
    score_label_->showWithEffect(tgui::ShowAnimationType::Fade, sf::seconds(0.1));
    score_label_->setVisible(true);
}


void PlayState::disable() {
    score_label_->hideWithEffect(tgui::ShowAnimationType::Fade, sf::seconds(0.1));
    PlayerSpaceship::destroy();
    enemies_.reset();
    response_ = StateResponse::None;
}


void PlayState::handleEvent(const sf::Event& event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Escape) {
            current_substate_->disable();
            std::swap(current_substate_, next_substate_);
            next_substate_->enable();
        }
    }
}


StateResponse PlayState::runIteration(sf::RenderWindow& window) {
    return current_substate_->runIteration(window);
}


PlayState::PauseSubstate::PauseSubstate(PlayState& play_state) : play_state_(play_state) {}


void PlayState::PauseSubstate::enable() {
    PlayerSpaceship::get().pause();
    play_state_.enemies_.pause();
}


void PlayState::PauseSubstate::disable() {
    PlayerSpaceship::unpause();
    play_state_.enemies_.unpause();
}


StateResponse PlayState::PauseSubstate::runIteration(sf::RenderWindow& window) {
    window.clear();
    play_state_.background_.draw(window);
    PlayerSpaceship::get().draw(window);
    play_state_.enemies_.draw(window);
    return play_state_.response_;
}


PlayState::RunningSubstate::RunningSubstate(PlayState& play_state) : play_state_(play_state) {}


StateResponse PlayState::RunningSubstate::runIteration(sf::RenderWindow& window) {
    PlayerSpaceship::get().action();
    play_state_.enemies_.action();

    if (PlayerSpaceship::collisionWithEnemy(play_state_.enemies_))
        play_state_.response_ = StateResponse::ChangeState;

    play_state_.score_ += play_state_.enemies_.collision(PlayerSpaceship::get());
    play_state_.score_label_->setText(play_state_.score_prefix_ + std::to_string(play_state_.score_));

    play_state_.background_.move();

    window.clear();
    play_state_.background_.draw(window);
    PlayerSpaceship::get().draw(window);
    play_state_.enemies_.draw(window);
    return play_state_.response_;
}

