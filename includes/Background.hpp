#ifndef SPACE_WARS_BACKGROUND_HPP
#define SPACE_WARS_BACKGROUND_HPP


#include <SFML/Graphics.hpp>


class Background {
private:

    float left_corner_x_;

    sf::Clock clock_;

    sf::Sprite sprite_;

public:

    Background();

    void move();

    void draw(sf::RenderWindow&);

};


#endif //SPACE_WARS_BACKGROUND_HPP
