#include "PlayState.hpp"
#include "PlayerSpaceship.hpp"
#include "Settings.hpp"
#include <SFML/Graphics.hpp>


PlayState::PlayState(tgui::Gui& gui) : score_label_(tgui::Label::create()),
                                       score_renderer_(std::make_shared<tgui::LabelRenderer>()),
                                       response_(StateResponse::None), score_(0),
                                       score_prefix_("Your score: ") {
    score_renderer_->setTextColor(tgui::Color::White);
    score_label_->setPosition(SCORE_LABEL_POS);
    score_label_->setTextSize(SCORE_LABEL_FONT_SIZE);
    score_label_->setRenderer(score_renderer_->getData());
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


StateResponse PlayState::runIteration(sf::RenderWindow& window) {
    PlayerSpaceship::get().action();
    enemies_.action();

    if (PlayerSpaceship::collisionWithEnemy(enemies_))
        response_ = StateResponse::ChangeState;

    score_ += enemies_.collision(PlayerSpaceship::get());
    score_label_->setText(score_prefix_ + std::to_string(score_));

    background_.move();

    window.clear();
    background_.draw(window);
    PlayerSpaceship::get().draw(window);
    enemies_.draw(window);
    return response_;
}

