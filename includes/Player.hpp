#ifndef SPACE_WARS_PLAYER_HPP
#define SPACE_WARS_PLAYER_HPP


#include "IGun.hpp"
#include "IDrawable.hpp"
#include "SFML/Graphics.hpp"
#include <cstdint>
#include <memory>


class Player : public IDrawable {
private:
    sf::Sprite sprite_;

    sf::Clock clock_;

    std::shared_ptr<IGun> gun_;

    float last_time_move_;

    float get_delta_time_() const;

    void move_up_();

    void move_down_();

    void shoot_();

    void update_time_();

public:
    Player();

    ~Player();

    void reset_clock();

    void action();

    void draw(sf::RenderWindow&) override;
};


#endif //SPACE_WARS_PLAYER_HPP
