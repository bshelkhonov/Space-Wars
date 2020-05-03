#include "Game.hpp"
#include "Settings.hpp"
#include "PlayerSpaceship.hpp"
#include "EnemiesContainer.hpp"
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>



Game::Game() : window_(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Space Wars", sf::Style::Close),
    gui_(window_), font_(tgui::Font(FONT_PATH)), game_state_(GAME_STATE::IN_MENU) {}


Game::~Game() = default;



void Game::play_() {
    EnemiesContainer enemies;

    while (window_.isOpen()) {
        clock_.restart();
        sf::Event event{};


        while (window_.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window_.close();
            gui_.handleEvent(event);
        }

        PlayerSpaceship::get().action();
        enemies.action();

        enemies.collision(PlayerSpaceship::get());

        background_.move();

        window_.clear();
        background_.draw(window_);
        PlayerSpaceship::get().draw(window_);
        enemies.draw(window_);

        gui_.draw();
        window_.display();
    }
    PlayerSpaceship::destroy();
}


void Game::start_button_pressed_() {
    game_state_ = GAME_STATE::PLAY;
}


void Game::menu_() {

    auto start_button = tgui::Button::create("Start");
    auto exit_button = tgui::Button::create("Exit");

    start_button->setSize(BUTTON_SIZE.x, BUTTON_SIZE.y);
    start_button->setPosition(START_BUTTON_POS.x, START_BUTTON_POS.y);
    start_button->setInheritedFont(font_);
    start_button->setTextSize(FONT_SIZE);
    start_button->connect("pressed", [&]() { game_state_ = GAME_STATE::PLAY; });

    exit_button->setSize(BUTTON_SIZE.x, BUTTON_SIZE.y);
    exit_button->setPosition(EXIT_BUTTON_POS.x, EXIT_BUTTON_POS.y);
    exit_button->setInheritedFont(font_);
    exit_button->setTextSize(FONT_SIZE);
    exit_button->connect("pressed", [&]() { window_.close(); });

    gui_.add(start_button);
    gui_.add(exit_button);

    while (window_.isOpen()) {
        if (game_state_ != GAME_STATE::IN_MENU) {
            start_button->hideWithEffect(tgui::ShowAnimationType::Fade, sf::seconds(0.1));
            exit_button->hideWithEffect(tgui::ShowAnimationType::Fade, sf::seconds(0.1));
            play_();
            start_button->showWithEffect(tgui::ShowAnimationType::Fade, sf::seconds(0.1));
            exit_button->showWithEffect(tgui::ShowAnimationType::Fade, sf::seconds(0.1));
        }

        sf::Event event{};

        while (window_.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window_.close();
            gui_.handleEvent(event);
        }

        background_.draw(window_);
        gui_.draw();
        window_.display();
    }
}


void Game::run() {
    menu_();
}

