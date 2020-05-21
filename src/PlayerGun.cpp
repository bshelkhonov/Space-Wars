#include "PlayerGun.hpp"
#include "StockPlayerCartridgeBuilder.hpp"
#include "Settings.hpp"


PlayerGun::PlayerGun() : IGun(), reload_time_(PLAYER_DEFAULT_GUN_RELOAD),
                         builder_(dynamic_cast<ICartridgeBuilder*>(new StockPlayerCartridgeBuilder())) {}


Cartridge PlayerGun::createBullet_() {
    builder_->createCartridge();
    builder_->setSprite();
    builder_->setMover();
    builder_->setColor();
    builder_->setRotation();
    return *builder_->getCartridge();
}


Cartridge PlayerGun::shoot() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && clock_.getElapsedTime().asSeconds() >= reload_time_) {
        clock_.restart();
        return createBullet_();
    }
    return {};
}







