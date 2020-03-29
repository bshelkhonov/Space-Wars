#ifndef SPACE_WARS_BULLET_HPP
#define SPACE_WARS_BULLET_HPP


#include "IDrawable.hpp"
#include <SFML/Graphics.hpp>


class Bullet : public IDrawable {
private:
    sf::Sprite sprite_;

    shared_ptr<BulletBuilder> bullet_builder_;
public:
    Bullet();

    void setTexture(const sf::Texture&);

    void setColor(const sf::Color&);

    void move();

    void draw(sf::RenderWindow&) override;
};

#endif //SPACE_WARS_BULLET_HPP
