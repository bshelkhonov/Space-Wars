#ifndef SPACE_WARS_BULLETBUILDER_HPP
#define SPACE_WARS_BULLETBUILDER_HPP


#include "Bullet.hpp"
#include <memory>


class IBulletBuilder {
public:
    virtual void setTexture() = 0;
    virtual void setRotation() = 0;
    virtual void setTrajectory() = 0;
    virtual void setColor() = 0;
};




#endif //SPACE_WARS_BULLETBUILDER_HPP
