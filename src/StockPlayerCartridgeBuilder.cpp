#include "StockPlayerCartridgeBuilder.hpp"
#include "BulletMover.hpp"
#include "Settings.hpp"


StockPlayerCartridgeBuilder::StockPlayerCartridgeBuilder() : ICartridgeBuilder() {
    auto texture = new sf::Texture();
    texture->loadFromFile(BULLET_FILE_1);
    sprite_.setTexture(*texture);
    sprite_.setTextureRect(sf::IntRect(376, 316, 37, 11));
    sprite_.setScale(0.3, 0.3);
    sprite_.setColor(sf::Color::Green);
}


StockPlayerCartridgeBuilder::~StockPlayerCartridgeBuilder() {
    delete sprite_.getTexture();
}


void StockPlayerCartridgeBuilder::createCartridge() {
    cartridge_.reset(new Cartridge(1));
}


void StockPlayerCartridgeBuilder::setSprite() {
    cartridge_->front().setSprite(sprite_);
}


void StockPlayerCartridgeBuilder::setMover() {
    cartridge_->front().setMover(new BulletMover(PLAYER_DEFAULT_BULLET_VELOCITY));
}



