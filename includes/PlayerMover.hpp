#ifndef SPACE_WARS_PLAYERMOVER_HPP
#define SPACE_WARS_PLAYERMOVER_HPP


#include "IObjectMover.hpp"
#include <SFML/Graphics.hpp>
#include <memory>


class PlayerMover : public IObjectMover {
private:

    sf::Clock clock_;

    void move_up_(IDrawable&) const;

    void move_down_(IDrawable&) const;

    void move_left_(IDrawable&) const;

    void move_right_(IDrawable&) const;

    [[nodiscard]] float get_current_time_() const;

    void update_clock_();

public:

    void move(IDrawable&) override;
};

#endif //SPACE_WARS_PLAYERMOVER_HPP
