#include <Bullet.hpp>
#include "Settings.hpp"


Bullet::Bullet() {
//    auto texture = new sf::Texture();
//    texture->loadFromFile(BULLET_FILE_1);
//    sprite_.setTexture(*texture);
//    sprite_.setTextureRect(sf::IntRect(376, 316, 37, 11));
//    sprite_.setColor(sf::Color::Green);
}


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


