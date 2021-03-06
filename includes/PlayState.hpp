#ifndef SPACE_WARS_PLAYSTATE_HPP
#define SPACE_WARS_PLAYSTATE_HPP

#include "IState.hpp"
#include "EnemiesContainer.hpp"
#include "Background.hpp"
#include "StateResponse.hpp"

#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>

#include <memory>


class PlayState : public IState {
private:

    class PauseSubstate;

    class RunningSubstate;


    tgui::Label::Ptr score_label_;

    tgui::LabelRenderer score_renderer_;

    std::shared_ptr<IState> running_substate_;

    std::shared_ptr<IState> pause_substate_;

    std::shared_ptr<IState> current_substate_;

    tgui::Font font_;

    EnemiesContainer enemies_;

    Background background_;

    StateResponse response_;

    size_t score_;

    const std::string score_prefix_;

    void changeState_();

public:

    explicit PlayState(tgui::Gui&);

    void enable() override;

    void disable() override;

    void handleEvent(const sf::Event&) override;

    StateResponse runIteration(sf::RenderWindow&) override;

    size_t getScore() const;

};

#endif //SPACE_WARS_PLAYSTATE_HPP
