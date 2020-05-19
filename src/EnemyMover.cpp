#include "EnemyMover.hpp"
#include <cmath>


EnemyMover::EnemyMover(const sf::Vector2f& velocity) : velocity_(velocity), max_ver_velocity_(std::abs(velocity.y)),
                                                       timestamp_(0) {}


void EnemyMover::move(IDrawable& enemy) {
    auto delta_time = clock_.getElapsedTime().asSeconds();
    clock_.restart();
    timestamp_ += delta_time;

    velocity_.y = std::sin(timestamp_) * max_ver_velocity_;
    enemy.move(velocity_ * delta_time);
}

