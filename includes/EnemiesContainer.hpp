#ifndef SPACE_WARS_ENEMIESCONTAINER_HPP
#define SPACE_WARS_ENEMIESCONTAINER_HPP


#include "EnemyCreator.hpp"
#include "Spaceship.hpp"
#include <SFML/Graphics.hpp>
#include <list>
#include <random>


class EnemiesContainer {
private:

    sf::Clock clock_;

    std::list<Spaceship> spaceships_;

    EnemyCreator enemy_creator_;

    void spawnEnemies_();

    void destroyFarEnemies_();

public:

    void init();

    void draw(sf::RenderWindow&);

    void action();

    size_t collision(Spaceship&);

    [[nodiscard]] std::list<Spaceship>::const_iterator begin() const;

    [[nodiscard]] std::list<Spaceship>::const_iterator end() const;

    void reset();

};


#endif //SPACE_WARS_ENEMIESCONTAINER_HPP
