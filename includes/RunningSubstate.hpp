#ifndef SPACE_WARS_RUNNINGSUBSTATE_HPP
#define SPACE_WARS_RUNNINGSUBSTATE_HPP

#include "PlayState.hpp"
#include "StateResponse.hpp"


class PlayState::RunningSubstate : public IState {
private:

    PlayState& play_state_;

    StateResponse response_;

public:

    explicit RunningSubstate(PlayState&);

    void enable() override;

    void disable() override {};

    void handleEvent(const sf::Event&) override {};

    StateResponse runIteration(sf::RenderWindow&) override;
};

#endif //SPACE_WARS_RUNNINGSUBSTATE_HPP
