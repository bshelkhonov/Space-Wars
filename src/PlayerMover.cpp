#include "PlayerMover.hpp"
#include "Settings.hpp"


void PlayerMover::moveUp_(IDrawable& player_spaceship) const {
    player_spaceship.move(PLAYER_MOVE_UP_SPEED * getCurrentTime_());
    if (player_spaceship.getPosition().y < PLAYER_MIN_POS.y)
        player_spaceship.move({0, PLAYER_MIN_POS.y - player_spaceship.getPosition().y});
}


void PlayerMover::moveDown_(IDrawable& player_spaceship) const {
    player_spaceship.move(PLAYER_MOVE_DOWN_SPEED * getCurrentTime_());
    if (player_spaceship.getPosition().y > PLAYER_MAX_POS.y)
        player_spaceship.move({0, PLAYER_MAX_POS.y - player_spaceship.getPosition().y});
}


void PlayerMover::moveLeft_(IDrawable& player_spaceship) const {
    player_spaceship.move(PLAYER_MOVE_LEFT_SPEED * getCurrentTime_());
    if (player_spaceship.getPosition().x < PLAYER_MIN_POS.x)
        player_spaceship.move({PLAYER_MIN_POS.x - player_spaceship.getPosition().x, 0});
}


void PlayerMover::moveRight_(IDrawable& player_spaceship) const {
    player_spaceship.move(PLAYER_MOVE_RIGHT_SPEED * getCurrentTime_());
    if (player_spaceship.getPosition().x > PLAYER_MAX_POS.x)
        player_spaceship.move({PLAYER_MAX_POS.x - player_spaceship.getPosition().x, 0});
}


float PlayerMover::getCurrentTime_() const {
    return clock_.getElapsedTime().asSeconds();
}


void PlayerMover::updateClock_() {
    clock_.restart();
}


void PlayerMover::move(IDrawable& player_spaceship) {

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        moveDown_(player_spaceship);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        moveUp_(player_spaceship);


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        moveLeft_(player_spaceship);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        moveRight_(player_spaceship);

    updateClock_();
}


void PlayerMover::unpause() {
    clock_.restart();
}

