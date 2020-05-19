#ifndef SPACE_WARS_IGUN_HPP
#define SPACE_WARS_IGUN_HPP


#include "ICartridgeBuilder.hpp"


class IGun {
public:
    virtual Cartridge shoot() = 0;

    virtual ~IGun() = default;
};


#endif //SPACE_WARS_IGUN_HPP
