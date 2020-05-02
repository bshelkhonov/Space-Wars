#include "EnemiesContainer.hpp"
#include "EnemyCreator.hpp"
#include "Settings.hpp"
#include <algorithm>


void EnemiesContainer::spawn_enemies_() {
    if (clock_.getElapsedTime().asSeconds() >= MIN_DELAY_BETWEEN_SPAWN && random_() % 2 == 1) {
        auto new_enemies = EnemyCreator::get();

        std::copy(new_enemies.begin(), new_enemies.end(), std::back_inserter(spaceships_));
    }
}



void EnemiesContainer::action() {
    for (auto& spaceship : spaceships_)
        spaceship.action();

    spawn_enemies_();
}


void EnemiesContainer::collision(Spaceship&) {

}
