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


class SpaceShip : public IDrawable {
private:
    sf::Sprite sprite_;

    sf::Clock clock_;

    std::shared_ptr<IGun> gun_;

    std::shared_ptr<IObjectMover> mover_;

    std::list<Bullet> bullets_;

    float last_time_move_;

    sf::Vector2f offset_;

    void shoot_();

    void update_time_();

public:
    SpaceShip();

    ~SpaceShip();

    void reset_clock();

    void action();

    void draw(sf::RenderWindow&) override;

    void move(const sf::Vector2f&) override;

    sf::Vector2f getPosition() const override;

    void setPosition(const sf::Vector2f&) override;
};


#endif //SPACE_WARS_SPACESHIP_HPP
