#ifndef SPACE_WARS_PAUSESUBSTATE_HPP
#define SPACE_WARS_PAUSESUBSTATE_HPP


#include "PlayState.hpp"
#include "StateResponse.hpp"

#include <TGUI/TGUI.hpp>

class PlayState::PauseSubstate : public IState {
private:

    PlayState& play_state_;

    tgui::Button::Ptr resume_button_;
    tgui::Button::Ptr exit_button_;

    tgui::Font font_;

    StateResponse response_;

public:

    PauseSubstate(PlayState&, tgui::Gui&);

    void enable() override;

    void disable() override;

    void handleEvent(const sf::Event&) override {};

    StateResponse runIteration(sf::RenderWindow&) override;
};


#endif //SPACE_WARS_PAUSESUBSTATE_HPP
