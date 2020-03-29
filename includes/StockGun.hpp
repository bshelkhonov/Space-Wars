#ifndef SPACE_WARS_STOCKGUN_HPP
#define SPACE_WARS_STOCKGUN_HPP


#include "IGun.hpp"
#include "Bullet.hpp"
#include <SFML/Graphics.hpp>
#include <list>


class StockGun : public IGun {
private:
    sf::Clock clock_;
    float reload_time_;

    std::list<Bullet> bullets_;

public:
    void shoot() override;

    void draw(sf::RenderWindow&) override;
};


#endif //SPACE_WARS_STOCKGUN_HPP
