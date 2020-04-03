#include "StockPlayerCartridgeBuilder.hpp"
#include "Settings.hpp"


StockPlayerCartridgeBuilder::StockPlayerCartridgeBuilder() : ICartridgeBuilder() {
    auto texture = new sf::Texture();
    texture->loadFromFile(BULLET_FILE_1);
    sprite_.setTexture(*texture);
    sprite_.setTextureRect(sf::IntRect(376, 316, 37, 11));
    sprite_.setScale(0.8, 0.8);
    sprite_.setColor(sf::Color::Green);
}


void StockPlayerCartridgeBuilder::create_cartridge() {
    cartridge_.reset(new Cartridge(1));
}


void StockPlayerCartridgeBuilder::setSprite() {
    cartridge_->front().setSprite(sprite_);
}


void StockPlayerCartridgeBuilder::setVelocity() {
    cartridge_->front().setVelocity(PLAYER_DEFAULT_BULLET_VELOCITY);
}

