#ifndef SPACE_WARS_MENUSTATE_HPP
#define SPACE_WARS_MENUSTATE_HPP

#include "IState.hpp"
#include "Background.hpp"
#include "StateResponse.hpp"

#include <TGUI/TGUI.hpp>
#include <SFML/Graphics.hpp>


class MenuState : public IState {
private:

    tgui::Button::Ptr start_button_;

    tgui::Button::Ptr exit_button_;

    tgui::Gui gui_;

    tgui::Font font_;

    Background background_;

    StateResponse response_;

public:

    explicit MenuState(sf::RenderWindow&);

    void enable() override;

    void disable() override;

    StateResponse handleEvent(sf::Event&) override;

    void runIteration(sf::RenderWindow&) override;

};


#endif //SPACE_WARS_MENUSTATE_HPP
