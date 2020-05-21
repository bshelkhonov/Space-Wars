#include "RunningSubstate.hpp"
#include "PlayerSpaceship.hpp"


PlayState::RunningSubstate::RunningSubstate(PlayState& play_state) : play_state_(play_state),
                                                                     response_(StateResponse::None) {}


void PlayState::RunningSubstate::enable() {
    response_ = StateResponse::None;
}


StateResponse PlayState::RunningSubstate::runIteration(sf::RenderWindow& window) {
    PlayerSpaceship::get().action();
    play_state_.enemies_.action();

    if (PlayerSpaceship::collisionWithEnemy(play_state_.enemies_))
        response_ = StateResponse::Finish;

    play_state_.score_ += play_state_.enemies_.collision(PlayerSpaceship::get());
    play_state_.score_label_->setText(play_state_.score_prefix_ + std::to_string(play_state_.score_));

    play_state_.background_.move();

    window.clear();
    play_state_.background_.draw(window);
    PlayerSpaceship::get().draw(window);
    play_state_.enemies_.draw(window);
    return response_;
}


