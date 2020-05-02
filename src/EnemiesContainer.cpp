#include "EnemiesContainer.hpp"
#include "Settings.hpp"
#include "Randomizer.hpp"
#include <algorithm>


void EnemiesContainer::spawn_enemies_() {
    if (clock_.getElapsedTime().asSeconds() >= MIN_DELAY_BETWEEN_SPAWN && Randomizer::randint(0, 1) == 0) {
        auto new_enemies = enemy_creator_.get();

        std::copy(new_enemies.begin(), new_enemies.end(), std::back_inserter(spaceships_));
        clock_.restart();
    }
}


void EnemiesContainer::destroy_far_enemies_() {
    for (auto it = spaceships_.begin(); it != spaceships_.end(); ) {
        if (it->getPosition().x <= -X_BORDER) {
            spaceships_.erase(it++);
        } else {
            ++it;
        }
    }
}



void EnemiesContainer::draw(sf::RenderWindow& window) {
    for (auto& spaceship : spaceships_)
        spaceship.draw(window);
}


void EnemiesContainer::action() {
    for (auto& spaceship : spaceships_)
        spaceship.action();

    spawn_enemies_();
    destroy_far_enemies_();
}


void EnemiesContainer::collision(Spaceship& other) {
    for (auto it = spaceships_.begin(); it != spaceships_.end();) {
        if (other.isColliding(*it)) {
            spaceships_.erase(it++);
        } else {
            ++it;
        }
    }
}




