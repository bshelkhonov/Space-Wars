#include "StockGun.hpp"


void StockGun::shoot() {
    if (clock_.getElapsedTime().asSeconds() >= reload_time_) {
        bullets_.push_front();
    }
}


void StockGun::draw(sf::RenderWindow& window) {
    for (auto& bullet : bullets_)
        bullet.draw(window);
}
