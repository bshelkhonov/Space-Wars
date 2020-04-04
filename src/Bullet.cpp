#include <Bullet.hpp>
#include "Settings.hpp"


Bullet::Bullet() = default;


void Bullet::setSprite(const sf::Sprite& sprite) {
    sprite_ = sprite;
}


void Bullet::setColor(const sf::Color& color) {
    sprite_.setColor(color);
}


void Bullet::setVelocity(const sf::Vector2f& velocity) {
    velocity_ = velocity;
}


void Bullet::setPosition(const sf::Vector2f& position) {
    sprite_.setPosition(position);
}


void Bullet::move() {
    sprite_.move(velocity_ * clock_.getElapsedTime().asSeconds());
    clock_.restart();
}


void Bullet::draw(sf::RenderWindow& window) {
    window.draw(sprite_);
}


