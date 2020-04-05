#include "PlayerGun.hpp"
#include "StockPlayerCartridgeBuilder.hpp"
#include "Settings.hpp"


PlayerGun::PlayerGun() : IGun(), reload_time_(PLAYER_DEFAULT_GUN_RELOAD),
                         builder_(dynamic_cast<ICartridgeBuilder*>(new StockPlayerCartridgeBuilder())) {}


Cartridge PlayerGun::create_bullet_() {
    builder_->create_cartridge();
    builder_->setSprite();
    builder_->setVelocity();
    builder_->setColor();
    builder_->setRotation();
    return *builder_->get_cartridge();
}

Cartridge PlayerGun::shoot() {
    if (clock_.getElapsedTime().asSeconds() >= reload_time_) {
        clock_.restart();
        return create_bullet_();
    }
    return {};
}






