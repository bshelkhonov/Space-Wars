#ifndef SPACE_WARS_IDRAWABLE_HPP
#define SPACE_WARS_IDRAWABLE_HPP


#include <SFML/Graphics.hpp>


class IDrawable {
public:
    virtual void draw(sf::RenderWindow&) = 0;
};


#endif //SPACE_WARS_IDRAWABLE_HPP
