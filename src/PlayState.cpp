#include "PlayState.hpp"
#include "PlayerSpaceship.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>


void PlayState::enable() {
    response_ = StateResponse::None;
}


void PlayState::disable() {
    PlayerSpaceship::destroy();
    enemies_.reset();
    response_ = StateResponse::None;
}


StateResponse PlayState::runIteration(sf::RenderWindow& window, tgui::Gui& gui) {
    PlayerSpaceship::get().action();
    enemies_.action();


    if (PlayerSpaceship::collisionWithEnemy(enemies_))
        response_ = StateResponse::ChangeState;


    enemies_.collision(PlayerSpaceship::get());

    background_.move();

    window.clear();
    background_.draw(window);
    PlayerSpaceship::get().draw(window);
    enemies_.draw(window);
    return response_;
}
