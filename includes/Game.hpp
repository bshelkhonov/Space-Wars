#ifndef SPACE_WARS_GAME_HPP
#define SPACE_WARS_GAME_HPP


#include "Background.hpp"
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <list>


class Game {
private:
    enum class GAME_STATE {
        IN_MENU, PLAY
    };

    sf::RenderWindow window_;

    tgui::Gui gui_;

    tgui::Font font_;

    GAME_STATE game_state_;

    Background background_;

    sf::Clock clock_;

    void play_();

    void menu_();

public:
    Game();

    ~Game();

    void run();
};


#endif //SPACE_WARS_GAME_HPP
