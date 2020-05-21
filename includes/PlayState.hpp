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

    tgui::Label::Ptr score_label_;

    std::shared_ptr<tgui::LabelRenderer> score_renderer_;

    EnemiesContainer enemies_;

    Background background_;

    StateResponse response_;

    size_t score_;

    const std::string score_prefix_;

public:

    explicit PlayState(tgui::Gui&);

    void enable() override;

    void disable() override;

    StateResponse runIteration(sf::RenderWindow&) override;

};

#endif //SPACE_WARS_PLAYSTATE_HPP
