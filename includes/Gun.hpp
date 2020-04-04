#ifndef SPACE_WARS_GUN_HPP
#define SPACE_WARS_GUN_HPP


#include "ICartridgeBuilder.hpp"


class Gun {
private:
    sf::Clock clock_;
    float reload_time_;

    std::shared_ptr<ICartridgeBuilder> builder_;

    Cartridge create_bullet_();

public:
    Gun();

    Cartridge shoot();
};




#endif //SPACE_WARS_GUN_HPP
