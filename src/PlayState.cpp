#include "PlayState.hpp"
#include "PlayerSpaceship.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>


void PlayState::enable() {

}


void PlayState::disable() {
    PlayerSpaceship::destroy();
    enemies_.reset();
}


StateResponse PlayState::handleEvent(sf::Event&) {
    return response_;
}


void PlayState::runIteration(sf::RenderWindow& window) {
    PlayerSpaceship::get().action();
    enemies_.action();


    if (PlayerSpaceship::collisionWithEnemy(enemies_)) {
        response_ = StateResponse::ChangeState;
        return;
    }

    enemies_.collision(PlayerSpaceship::get());


    background_.move();

    window.clear();
    background_.draw(window);
    PlayerSpaceship::get().draw(window);
    enemies_.draw(window);
}
