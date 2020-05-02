#ifndef SPACE_WARS_ENEMYCREATOR_HPP
#define SPACE_WARS_ENEMYCREATOR_HPP


#include "Spaceship.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <random>


class EnemyCreator {
private:

    std::vector<sf::Sprite> sprites_;

    std::mt19937 random_;

    Spaceship get_random_enemy_();

public:
    EnemyCreator();

    std::vector<Spaceship> get();
};


#endif //SPACE_WARS_ENEMYCREATOR_HPP
