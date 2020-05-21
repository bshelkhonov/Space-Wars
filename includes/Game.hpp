#ifndef SPACE_WARS_GAME_HPP
#define SPACE_WARS_GAME_HPP


#include "Background.hpp"
#include "IState.hpp"
#include "PlayState.hpp"
#include "MenuState.hpp"

#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <memory>


class Game {
private:

    sf::RenderWindow window_;

    tgui::Gui gui_;

    void startGame_();

    void finishGame_();

    std::shared_ptr<PlayState> play_state_;

    std::shared_ptr<MenuState> menu_state_;

    std::shared_ptr<IState> current_state_;

public:
    Game();

    ~Game();

    void run();
};


#endif //SPACE_WARS_GAME_HPP
