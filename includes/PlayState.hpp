#ifndef SPACE_WARS_PLAYSTATE_HPP
#define SPACE_WARS_PLAYSTATE_HPP

#include "IState.hpp"
#include "EnemiesContainer.hpp"
#include "Background.hpp"
#include "StateResponse.hpp"

#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>


class PlayState : public IState {
public:

    EnemiesContainer enemies_;

    Background background_;

    StateResponse response_;

private:

    void enable() override;

    void disable() override;

    StateResponse runIteration(sf::RenderWindow&, tgui::Gui&) override;

};

#endif //SPACE_WARS_PLAYSTATE_HPP
