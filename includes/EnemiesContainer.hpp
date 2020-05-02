#ifndef SPACE_WARS_ENEMIESCONTAINER_HPP
#define SPACE_WARS_ENEMIESCONTAINER_HPP


#include "Spaceship.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <random>


class EnemiesContainer {
private:

    std::mt19937 random_;

    sf::Clock clock_;

    std::vector<Spaceship> spaceships_;

    void spawn_enemies_();

public:

    void action();

    void collision(Spaceship&);

};


#endif //SPACE_WARS_ENEMIESCONTAINER_HPP
