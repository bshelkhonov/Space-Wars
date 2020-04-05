#include <Bullet.hpp>
#include <utility>
#include "Settings.hpp"


Bullet::Bullet() = default;


void Bullet::setSprite(const sf::Sprite& sprite) {
    sprite_ = sprite;
}


void Bullet::setColor(const sf::Color& color) {
    sprite_.setColor(color);
}


void Bullet::setMover(IObjectMover* mover) {
    mover_.reset(mover);
}


void Bullet::setPosition(const sf::Vector2f& position) {
    sprite_.setPosition(position);
}


void Bullet::move() {
    mover_->move(*this);
}


void Bullet::move(const sf::Vector2f& movement) {
    sprite_.move(movement);
}


sf::Vector2f Bullet::getPosition() const {
    return sprite_.getPosition();
}


void Bullet::draw(sf::RenderWindow& window) {
    window.draw(sprite_);
}


bool Bullet::isOutside() const {
    bool out_x_border = sprite_.getPosition().x <= -X_BORDER || sprite_.getPosition().x >= SCREEN_WIDTH + X_BORDER;
    bool out_y_border = sprite_.getPosition().y <= -Y_BORDER || sprite_.getPosition().y >= SCREEN_HEIGHT + Y_BORDER;
    return out_x_border || out_y_border;
}




