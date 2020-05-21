#ifndef SPACE_WARS_ENEMYCREATOR_HPP
#define SPACE_WARS_ENEMYCREATOR_HPP


#include "Spaceship.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <random>


class EnemyCreator {
private:

    std::vector<sf::Sprite> sprites_;

    Spaceship getRandomEnemy();

public:
    EnemyCreator();

    std::vector<Spaceship> get();
};


#endif //SPACE_WARS_ENEMYCREATOR_HPP
