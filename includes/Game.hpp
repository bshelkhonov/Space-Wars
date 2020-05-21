#ifndef SPACE_WARS_GAME_HPP
#define SPACE_WARS_GAME_HPP


#include "Background.hpp"
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <list>


class Game {
private:

    sf::RenderWindow window_;

    tgui::Gui gui_;

public:
    Game();

    ~Game();

    void run();
};


#endif //SPACE_WARS_GAME_HPP
