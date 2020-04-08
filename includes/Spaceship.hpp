#ifndef SPACE_WARS_SPACESHIP_HPP
#define SPACE_WARS_SPACESHIP_HPP


#include "IGun.hpp"
#include "IDrawable.hpp"
#include "Bullet.hpp"
#include "IObjectMover.hpp"
#include "SFML/Graphics.hpp"
#include <cstdint>
#include <memory>
#include <list>


class Spaceship : public IDrawable {
private:
    sf::Sprite sprite_;

    sf::Clock clock_;

    std::shared_ptr<IGun> gun_;

    std::shared_ptr<IObjectMover> mover_;

    std::list<Bullet> bullets_;

    sf::Vector2f bullet_offset_;

    void shoot_();

public:
    Spaceship();

    ~Spaceship();

    void setSprite(const sf::Sprite&);

    void setGun(IGun*);

    void setMover(IObjectMover*);

    void setBulletOffset(const sf::Vector2f&);

    void action();

    void draw(sf::RenderWindow&) override;

    void move(const sf::Vector2f&) override;

    sf::Vector2f getPosition() const override;

    void setPosition(const sf::Vector2f&) override;

    bool isOutside() const override;
};


#endif //SPACE_WARS_SPACESHIP_HPP
