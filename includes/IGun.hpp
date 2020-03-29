#ifndef SPACE_WARS_IGUN_HPP
#define SPACE_WARS_IGUN_HPP

#include <IDrawable.hpp>


class IGun : public IDrawable {
public:
    virtual void shoot() = 0;
};


#endif //SPACE_WARS_IGUN_HPP
