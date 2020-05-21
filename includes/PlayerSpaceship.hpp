#ifndef SPACE_WARS_PLAYERSPACESHIP_HPP
#define SPACE_WARS_PLAYERSPACESHIP_HPP


#include "Spaceship.hpp"
#include "EnemiesContainer.hpp"


class PlayerSpaceship {
private:

    static sf::Sprite sprite_;

    static std::shared_ptr<Spaceship> player_spaceship_;

    static void loadSprite_();

    static void create_();

public:
    static Spaceship& get();

    static bool collisionWithEnemy(const EnemiesContainer&);

    static void destroy();
};


#endif //SPACE_WARS_PLAYERSPACESHIP_HPP
