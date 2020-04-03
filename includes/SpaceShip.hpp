#ifndef SPACE_WARS_SPACESHIP_HPP
#define SPACE_WARS_SPACESHIP_HPP


#include "Gun.hpp"
#include "IDrawable.hpp"
#include "Bullet.hpp"
#include "SFML/Graphics.hpp"
#include <cstdint>
#include <memory>
#include <list>


class SpaceShip : public IDrawable {
private:
    sf::Sprite sprite_;

    sf::Clock clock_;

    std::shared_ptr<Gun> gun_;

    std::list<Bullet> bullets_;

    float last_time_move_;

    sf::Vector2f offset_;

    float get_delta_time_() const;

    void move_up_();

    void move_down_();

    void shoot_();

    void update_time_();

public:
    SpaceShip();

    ~SpaceShip();

    void reset_clock();

    void action();

    void draw(sf::RenderWindow&) override;
};


#endif //SPACE_WARS_SPACESHIP_HPP
