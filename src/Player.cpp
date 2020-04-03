#include "Player.hpp"
#include "Settings.hpp"
#include <iostream>


Player::Player() : last_time_move_(0), gun_(new Gun()) {
    auto texture = new sf::Texture();
    texture->loadFromFile(PLAYER_FILE);
    sprite_.setTexture(*texture);
    sprite_.setScale(PLAYER_SPRITE_SCALE);
    sprite_.setPosition(PLAYER_DEFAULT_POS);
}


Player::~Player() {
    delete sprite_.getTexture();
}


float Player::get_delta_time_() const {
    return clock_.getElapsedTime().asSeconds() - last_time_move_;
}


void Player::move_up_() {
    sprite_.move(PLAYER_MOVE_UP * get_delta_time_());
    if (sprite_.getPosition().y < PLAYER_MIN_POS.y)
        sprite_.setPosition(PLAYER_MIN_POS);
    update_time_();
}

void Player::move_down_() {
    sprite_.move(PLAYER_MOVE_DOWN * get_delta_time_());
    if (sprite_.getPosition().y > PLAYER_MAX_POS.y)
        sprite_.setPosition(PLAYER_MAX_POS);
    update_time_();
}


void Player::shoot_() {
    for (auto& bullet : gun_->shoot()) {
        bullet.setPosition(sprite_.getPosition());
        bullets_.push_front(bullet);
    }
}


void Player::update_time_() {
    last_time_move_ = clock_.getElapsedTime().asSeconds();
}


void Player::reset_clock() {
    update_time_();
}


void Player::action() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        move_up_();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        move_down_();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        shoot_();
    for (auto& bullet : bullets_)
        bullet.move();
    update_time_();
}


void Player::draw(sf::RenderWindow& window) {
    window.draw(sprite_);
    for (auto& bullet : bullets_)
        bullet.draw(window);
}





