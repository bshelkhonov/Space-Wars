#ifndef SPACE_WARS_ISTATE_HPP
#define SPACE_WARS_ISTATE_HPP

#include "StateResponse.hpp"

#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>

class IState {
public:

    virtual void enable() = 0;

    virtual void disable() = 0;

    virtual void handleEvent(const sf::Event&) = 0;

    virtual StateResponse runIteration(sf::RenderWindow&) = 0;
};


#endif //SPACE_WARS_ISTATE_HPP
