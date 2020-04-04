#ifndef SPACE_WARS_IOBJECTMOVER_HPP
#define SPACE_WARS_IOBJECTMOVER_HPP


#include "IDrawable.hpp"
#include <memory>


// class for moving IDrawables
class IObjectMover {
public:
    virtual void move(IDrawable&) = 0;
};


#endif //SPACE_WARS_IOBJECTMOVER_HPP
