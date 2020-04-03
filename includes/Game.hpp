#ifndef SPACE_WARS_GAME_HPP
#define SPACE_WARS_GAME_HPP


#include "SpaceShip.hpp"
#include "Bullet.hpp"
#include <SFML/Graphics.hpp>
#include <list>


class Game {
private:
    sf::RenderWindow window_;
    sf::Clock clock_;

    sf::Sprite background_;
    SpaceShip player_;

public:
    Game();

    ~Game();

    void run();
};


#endif //SPACE_WARS_GAME_HPP
