#ifndef SPACE_WARS_BULLETMOVER_HPP
#define SPACE_WARS_BULLETMOVER_HPP


#include "IObjectMover.hpp"


class BulletMover : public IObjectMover {
private:

    sf::Clock clock_;

    sf::Vector2f velocity_;

public:
    explicit BulletMover(const sf::Vector2f&);

    void move(IDrawable&) override;
};


#endif //SPACE_WARS_BULLETMOVER_HPP
