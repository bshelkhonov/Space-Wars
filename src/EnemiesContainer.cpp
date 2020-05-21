#include "EnemiesContainer.hpp"
#include "Settings.hpp"
#include "Randomizer.hpp"
#include <algorithm>


void EnemiesContainer::spawnEnemies_() {
    if (clock_.getElapsedTime().asSeconds() >= MIN_DELAY_BETWEEN_SPAWN && Randomizer::randint(0, 1) == 0) {
        auto new_enemies = enemy_creator_.get();

        std::copy(new_enemies.begin(), new_enemies.end(), std::back_inserter(spaceships_));
        clock_.restart();
    }
}


void EnemiesContainer::destroyFarEnemies_() {
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

    spawnEnemies_();
    destroyFarEnemies_();
}


void EnemiesContainer::collision(Spaceship& other) {
    for (auto it = spaceships_.begin(); it != spaceships_.end();) {
        if (other.isBulletColliding(*it)) {
            spaceships_.erase(it++);
        } else {
            ++it;
        }
    }
}


void EnemiesContainer::init() {
    clock_.restart();
}


void EnemiesContainer::reset() {
    spaceships_.clear();
}

std::list<Spaceship>::const_iterator EnemiesContainer::begin() const {
    return spaceships_.begin();
}


std::list<Spaceship>::const_iterator EnemiesContainer::end() const {
    return spaceships_.end();
}




