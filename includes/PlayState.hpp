#ifndef SPACE_WARS_PLAYSTATE_HPP
#define SPACE_WARS_PLAYSTATE_HPP

#include "IState.hpp"
#include "EnemiesContainer.hpp"
#include "Background.hpp"
#include "StateResponse.hpp"

#include <SFML/Graphics.hpp>


class PlayState : public IState {
public:

    EnemiesContainer enemies_;

    Background background_;

    StateResponse response_;

private:

    void enable() override;

    void disable() override;

    StateResponse handleEvent(sf::Event&) override;

    void runIteration(sf::RenderWindow&) override;

};

#endif //SPACE_WARS_PLAYSTATE_HPP
