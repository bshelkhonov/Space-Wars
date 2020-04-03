#include "PlayerMover.hpp"
#include "Settings.hpp"
#include <iostream>



void PlayerMover::move_up_(IDrawable& player_spaceship) const {
    player_spaceship.move(PLAYER_MOVE_UP_SPEED * get_current_time_());
    if (player_spaceship.getPosition().y < PLAYER_MIN_POS.y)
        player_spaceship.move({0, PLAYER_MIN_POS.y - player_spaceship.getPosition().y});
}


void PlayerMover::move_down_(IDrawable& player_spaceship) const {
    player_spaceship.move(PLAYER_MOVE_DOWN_SPEED * get_current_time_());
    if (player_spaceship.getPosition().y > PLAYER_MAX_POS.y)
        player_spaceship.move({0, PLAYER_MAX_POS.y - player_spaceship.getPosition().y});
}


void PlayerMover::move_left_(IDrawable& player_spaceship) const {
    player_spaceship.move(PLAYER_MOVE_LEFT_SPEED * get_current_time_());
    if (player_spaceship.getPosition().x < PLAYER_MIN_POS.x)
        player_spaceship.move({PLAYER_MIN_POS.x - player_spaceship.getPosition().x, 0});
}


void PlayerMover::move_right_(IDrawable& player_spaceship) const {
    player_spaceship.move(PLAYER_MOVE_RIGHT_SPEED * get_current_time_());
    if (player_spaceship.getPosition().x > PLAYER_MAX_POS.x)
        player_spaceship.move({PLAYER_MAX_POS.x - player_spaceship.getPosition().x, 0});
}


float PlayerMover::get_current_time_() const {
    return clock_.getElapsedTime().asSeconds();
}


void PlayerMover::update_clock_() {
    clock_.restart();
}


void PlayerMover::move(IDrawable& player_spaceship) {

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        move_down_(player_spaceship);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        move_up_(player_spaceship);


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        move_left_(player_spaceship);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        move_right_(player_spaceship);

    update_clock_();
}

