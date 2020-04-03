#include "Gun.hpp"
#include "PlayerCartridgeBuilder.hpp"
#include "Settings.hpp"


Gun::Gun() : reload_time_(PLAYER_DEFAULT_GUN_RELOAD),
             builder_(dynamic_cast<ICartridgeBuilder*>(new PlayerCartridgeBuilder())) {}


Cartridge Gun::create_bullet_() {
    builder_->create_cartridge();
    builder_->setSprite();
    builder_->setVelocity();
    builder_->setColor();
    builder_->setRotation();
    return *builder_->get_cartridge();
}


Cartridge Gun::shoot() {
    if (clock_.getElapsedTime().asSeconds() >= reload_time_) {
        clock_.restart();
        return create_bullet_();
    }
    return {};
}




