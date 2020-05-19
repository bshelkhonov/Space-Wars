#ifndef SPACE_WARS_ENEMYMOVER_HPP
#define SPACE_WARS_ENEMYMOVER_HPP


#include "IObjectMover.hpp"
#include <SFML/Graphics.hpp>


class EnemyMover : public IObjectMover {
private:

    sf::Clock clock_;

    sf::Vector2f velocity_;

    float max_ver_velocity_;

    float timestamp_;

public:
    explicit EnemyMover(const sf::Vector2f&);

    void move(IDrawable&) override;
};


#endif //SPACE_WARS_ENEMYMOVER_HPP
