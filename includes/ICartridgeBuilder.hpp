#ifndef SPACE_WARS_BULLETBUILDER_HPP
#define SPACE_WARS_BULLETBUILDER_HPP


#include "Bullet.hpp"
#include <SFML/Graphics.hpp>
#include <memory>


class ICartridgeBuilder {
protected:
    std::shared_ptr<Cartridge> cartridge_;
public:
    ICartridgeBuilder();

    virtual void create_cartridge();

    std::shared_ptr<Cartridge> get_cartridge();

    virtual void setSprite() = 0;
    virtual void setRotation() {};
    virtual void setVelocity() = 0;
    virtual void setColor() {};
};




#endif //SPACE_WARS_BULLETBUILDER_HPP
