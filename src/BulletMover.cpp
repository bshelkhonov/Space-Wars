#include "BulletMover.hpp"


BulletMover::BulletMover(const sf::Vector2f& velocity) : velocity_(velocity) {}


void BulletMover::move(IDrawable& bullet) {
    bullet.move(velocity_ * clock_.getElapsedTime().asSeconds());
    clock_.restart();
}

