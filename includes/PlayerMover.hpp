#ifndef SPACE_WARS_PLAYERMOVER_HPP
#define SPACE_WARS_PLAYERMOVER_HPP


#include "IObjectMover.hpp"
#include <SFML/Graphics.hpp>
#include <memory>


class PlayerMover : public IObjectMover {
private:

    sf::Clock clock_;

    void moveUp_(IDrawable&) const;

    void moveDown_(IDrawable&) const;

    void moveLeft_(IDrawable&) const;

    void moveRight_(IDrawable&) const;

    [[nodiscard]] float getCurrentTime_() const;

    void updateClock_();

public:

    void move(IDrawable&) override;

    void pause() {};

    void unpause();
};

#endif //SPACE_WARS_PLAYERMOVER_HPP
