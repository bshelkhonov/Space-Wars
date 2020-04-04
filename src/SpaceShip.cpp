#include "SpaceShip.hpp"
#include "Settings.hpp"
#include "PlayerMover.hpp"
#include "PlayerGun.hpp"
#include <iostream>


SpaceShip::SpaceShip() : last_time_move_(0), gun_(new PlayerGun()), offset_(80, 40), mover_(new PlayerMover()) {
    auto texture = new sf::Texture();
    texture->loadFromFile(PLAYER_FILE);
    sprite_.setTexture(*texture);
    sprite_.setScale(PLAYER_SPRITE_SCALE);
    sprite_.setPosition(PLAYER_DEFAULT_POS);
}


SpaceShip::~SpaceShip() {
    delete sprite_.getTexture();
}


void SpaceShip::shoot_() {
    for (auto& bullet : gun_->shoot()) {
        bullet.setPosition(sprite_.getPosition() + offset_);
        bullets_.push_front(bullet);
    }
}


void SpaceShip::update_time_() {
    last_time_move_ = clock_.getElapsedTime().asSeconds();
}


void SpaceShip::reset_clock() {
    update_time_();
}


void SpaceShip::action() {
    mover_->move(*this);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        shoot_();
    for (auto& bullet : bullets_)
        bullet.move();

    update_time_();
}


void SpaceShip::move(const sf::Vector2f& movement) {
    sprite_.move(movement);
}


void SpaceShip::draw(sf::RenderWindow& window) {
    window.draw(sprite_);
    for (auto& bullet : bullets_)
        bullet.draw(window);
}


sf::Vector2f SpaceShip::getPosition() const {
    return sprite_.getPosition();
}


void SpaceShip::setPosition(const sf::Vector2f& pos) {
    sprite_.setPosition(pos);
}






