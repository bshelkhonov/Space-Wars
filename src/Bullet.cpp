#include <Bullet.hpp>
#include "Settings.hpp"


Bullet::Bullet() {
    auto texture = new sf::Texture();
    texture->loadFromFile(BULLET_FILE_1);
    sprite_.setTexture(*texture);
    sprite_.setTextureRect(sf::IntRect(376, 316, 37, 11));
    sprite_.setColor(sf::Color::Green);
}


void Bullet::setTexture(const sf::Texture& texture) {
    sprite_.setTexture(texture);
}


void Bullet::setColor(const sf::Color& color) {
    sprite_.setColor(color);
}



void Bullet::draw(sf::RenderWindow& window) {
    window.draw(sprite_);
}

