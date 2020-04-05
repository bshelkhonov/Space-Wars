#ifndef SPACE_WARS_PLAYERSPACESHIP_HPP
#define SPACE_WARS_PLAYERSPACESHIP_HPP


#include "Spaceship.hpp"


class PlayerSpaceship {
private:

    static sf::Sprite sprite_;

    static std::shared_ptr<Spaceship> player_spaceship_;

    static void load_sprite_();

    static void create_();

public:
    static Spaceship& get();
};


#endif //SPACE_WARS_PLAYERSPACESHIP_HPP
