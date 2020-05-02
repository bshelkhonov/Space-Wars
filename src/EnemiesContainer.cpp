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


void EnemiesContainer::draw(sf::RenderWindow& window) {
    for (auto& spaceship : spaceships_)
        spaceship.draw(window);
}


void EnemiesContainer::action() {
    for (auto& spaceship : spaceships_)
        spaceship.action();

    spawn_enemies_();
}


void EnemiesContainer::collision(Spaceship&) {

}



