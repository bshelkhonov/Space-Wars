#include <Background.hpp>
#include "Settings.hpp"


Background::Background() : left_corner_x_(0) {
    auto bg_texture = new sf::Texture();
    bg_texture->loadFromFile(BACKGROUND_FILE);
    sprite_.setTexture(*bg_texture);
    sprite_.setTextureRect({0, 0, SCREEN_WIDTH, SCREEN_HEIGHT});
}


void Background::move() {
    sprite_.setTextureRect({left_corner_x_ += 0.1, 0, SCREEN_WIDTH, SCREEN_HEIGHT});
    if (left_corner_x_ > SCREEN_WIDTH)
        left_corner_x_ = 0.1;
}



void Background::draw(sf::RenderWindow& window) {
    window.draw(sprite_);
}

