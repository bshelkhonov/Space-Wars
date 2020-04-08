#include "Spaceship.hpp"
#include "Settings.hpp"
#include "PlayerMover.hpp"
#include "PlayerGun.hpp"
#include <iostream>


Spaceship::Spaceship() = default;


Spaceship::~Spaceship() = default;


void Spaceship::setSprite(const sf::Sprite& sprite) {
    sprite_ = sprite;
}


void Spaceship::setGun(IGun* gun) {
    gun_.reset(gun);
}


void Spaceship::setMover(IObjectMover* mover) {
    mover_.reset(mover);
}


void Spaceship::setBulletOffset(const sf::Vector2f& bullet_offset) {
    bullet_offset_ = bullet_offset;
}


void Spaceship::shoot_() {
    for (auto& bullet : gun_->shoot()) {
        bullet.setPosition(sprite_.getPosition() + bullet_offset_);
        bullets_.push_front(bullet);
    }
}


void Spaceship::action() {
    mover_->move(*this);

    shoot_();
    for (auto& bullet : bullets_)
        bullet.move();

    for (auto it = bullets_.begin(); it != bullets_.end(); ) {
        if (it->isOutside()) {
            bullets_.erase(it++);
        } else {
            ++it;
        }
    }
}


void Spaceship::move(const sf::Vector2f& movement) {
    sprite_.move(movement);
}


void Spaceship::draw(sf::RenderWindow& window) {
    window.draw(sprite_);
    for (auto& bullet : bullets_)
        bullet.draw(window);
}


sf::Vector2f Spaceship::getPosition() const {
    return sprite_.getPosition();
}


void Spaceship::setPosition(const sf::Vector2f& pos) {
    sprite_.setPosition(pos);
}


bool Spaceship::isOutside() const {
    bool out_x_border = sprite_.getPosition().x <= -X_BORDER || sprite_.getPosition().x >= SCREEN_WIDTH + X_BORDER;
    bool out_y_border = sprite_.getPosition().y <= -Y_BORDER || sprite_.getPosition().y >= SCREEN_HEIGHT + Y_BORDER;
    return out_x_border || out_y_border;
}








