#ifndef SPACE_WARS_IDRAWABLE_HPP
#define SPACE_WARS_IDRAWABLE_HPP


#include <SFML/Graphics.hpp>


class IDrawable {
public:
    virtual void move(const sf::Vector2f&) = 0;

    virtual void draw(sf::RenderWindow&) = 0;

    [[nodiscard]] virtual sf::Vector2f getPosition() const = 0;

    virtual const sf::Sprite& getSprite() const = 0;

    virtual void setPosition(const sf::Vector2f&) = 0;

    virtual bool isSpriteColliding(const IDrawable&) = 0;

    [[nodiscard]] virtual bool isOutside() const = 0;

    virtual ~IDrawable() = default;
};


#endif //SPACE_WARS_IDRAWABLE_HPP
