#include "PlayerSpaceship.hpp"
#include "PlayerMover.hpp"
#include "PlayerGun.hpp"
#include "Settings.hpp"
#include <iostream>


std::shared_ptr<Spaceship> PlayerSpaceship::player_spaceship_ = nullptr;
sf::Sprite PlayerSpaceship::sprite_ = sf::Sprite();


void PlayerSpaceship::load_sprite_() {
    auto texture = new sf::Texture();
    texture->loadFromFile(PLAYER_FILE);
    PlayerSpaceship::sprite_.setTexture(*texture);
    PlayerSpaceship::sprite_.setScale(PLAYER_SPRITE_SCALE);
}



void PlayerSpaceship::create_() {
    player_spaceship_ = std::make_shared<Spaceship>();
    load_sprite_();
    player_spaceship_->setSprite(PlayerSpaceship::sprite_);
    player_spaceship_->setMover(new PlayerMover());
    player_spaceship_->setGun(new PlayerGun());
    player_spaceship_->setBulletOffset(PLAYER_DEFAULT_BULLET_OFFSET);
    player_spaceship_->setPosition(PLAYER_DEFAULT_POS);
}


Spaceship& PlayerSpaceship::get() {
    if (player_spaceship_ == nullptr)
        create_();

    return *player_spaceship_;
}


bool PlayerSpaceship::collisionWithEnemy(const EnemiesContainer& enemies) {
    for (const auto& enemy : enemies) {
        if (get().isSpriteColliding(enemy))
            return true;
    }
    return false;
}


void PlayerSpaceship::destroy() {
    player_spaceship_.reset();
    delete sprite_.getTexture();
}


