#ifndef SPACE_WARS_ENEMIESCONTAINER_HPP
#define SPACE_WARS_ENEMIESCONTAINER_HPP


#include "EnemyCreator.hpp"
#include "Spaceship.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <random>


class EnemiesContainer {
private:

    sf::Clock clock_;

    std::vector<Spaceship> spaceships_;

    EnemyCreator enemy_creator_;

    void spawn_enemies_();

public:

    void draw(sf::RenderWindow&);

    void action();

    void collision(Spaceship&);

};


#endif //SPACE_WARS_ENEMIESCONTAINER_HPP
