#ifndef SPACE_WARS_GAME_HPP
#define SPACE_WARS_GAME_HPP


#include "Spaceship.hpp"
#include "Bullet.hpp"
#include <SFML/Graphics.hpp>
#include <list>


class Game {
private:
    sf::RenderWindow window_;
    sf::Clock clock_;

public:
    Game();

    ~Game();

    void run();
};


#endif //SPACE_WARS_GAME_HPP
