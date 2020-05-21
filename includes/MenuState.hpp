#ifndef SPACE_WARS_MENUSTATE_HPP
#define SPACE_WARS_MENUSTATE_HPP

#include "IState.hpp"
#include "Background.hpp"
#include "StateResponse.hpp"

#include <TGUI/TGUI.hpp>
#include <SFML/Graphics.hpp>


class MenuState : public IState {
private:

    tgui::Label::Ptr last_game_score_label_;

    tgui::Label::Ptr high_score_label_;

    tgui::LabelRenderer label_renderer_;

    tgui::Button::Ptr start_button_;

    tgui::Button::Ptr exit_button_;

    tgui::Font font_;

    Background background_;

    StateResponse response_;

    size_t last_game_score_;

    size_t high_score_;

    const std::string score_text_;

    const std::string high_score_text_;

public:

    explicit MenuState(tgui::Gui&);

    void enable() override;

    void disable() override;

    void handleEvent(const sf::Event&) override;

    StateResponse runIteration(sf::RenderWindow&) override;

    void showScore(size_t);
};


#endif //SPACE_WARS_MENUSTATE_HPP
