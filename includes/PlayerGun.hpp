#ifndef SPACE_WARS_PLAYERGUN_HPP
#define SPACE_WARS_PLAYERGUN_HPP


#include "IGun.hpp"
#include "ICartridgeBuilder.hpp"
#include <memory>


class PlayerGun : public IGun {
private:
    sf::Clock clock_;
    float reload_time_;

    std::shared_ptr<ICartridgeBuilder> builder_;

    Cartridge create_bullet_();

public:
    PlayerGun();

    Cartridge shoot() override;
};



#endif //SPACE_WARS_PLAYERGUN_HPP
