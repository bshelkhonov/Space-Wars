#ifndef SPACE_WARS_BULLET_HPP
#define SPACE_WARS_BULLET_HPP


#include "IDrawable.hpp"
#include <SFML/Graphics.hpp>
#include <vector>


class Bullet : public IDrawable {
private:
    sf::Sprite sprite_;

    sf::Vector2f velocity_;

    sf::Clock clock_;

public:
    Bullet();

    void setSprite(const sf::Sprite&);

    void setColor(const sf::Color&);

    void setVelocity(const sf::Vector2f&);

    void setPosition(const sf::Vector2f&);

    void move();

    void draw(sf::RenderWindow&) override;
};


using Cartridge = std::vector<Bullet>;


#endif //SPACE_WARS_BULLET_HPP
