#ifndef SPACE_WARS_SETTINGS_HPP
#define SPACE_WARS_SETTINGS_HPP


#include <cstdint>
#include <string>
#include <SFML/System/Vector2.hpp>


// SCREEN

const size_t SCREEN_WIDTH = 1366;
const size_t SCREEN_HEIGHT = 768;
const float X_BORDER = 200;
const float Y_BORDER = 200;

// PLAYER

const sf::Vector2f PLAYER_SPRITE_SCALE = {0.13, 0.13};
const sf::Vector2f PLAYER_DEFAULT_POS = {50, 360};
const sf::Vector2f PLAYER_MIN_POS = {50, 30};
const sf::Vector2f PLAYER_MAX_POS = {1000, 678};
const sf::Vector2f PLAYER_MOVE_UP_SPEED = {0, -760};
const sf::Vector2f PLAYER_MOVE_DOWN_SPEED = {0, 760};
const sf::Vector2f PLAYER_MOVE_LEFT_SPEED = {-500, 0};
const sf::Vector2f PLAYER_MOVE_RIGHT_SPEED = {500, 0};
const float PLAYER_DEFAULT_GUN_RELOAD = 0.2f;
const sf::Vector2f PLAYER_DEFAULT_BULLET_VELOCITY = {800, 0};
const sf::Vector2f PLAYER_DEFAULT_BULLET_OFFSET = {80, 40};


// ENEMIES

const float MIN_DELAY_BETWEEN_SPAWN = 1.5;
const uint32_t MIN_ENEMIES_SPAWNED = 1;
const uint32_t MAX_ENEMIES_SPAWNED = 5;
const sf::Vector2f DEFAULT_ENEMY_VELOCITY = {-200, 80};
const sf::Vector2f DEFAULT_ENEMY_POS = {1400, 300};
const sf::Vector2f ENEMY_SPRITE_SCALE = {0.3, 0.3};
const float DISTANCE_BETWEEN_ENEMIES = 100;


// RESOURCES

const std::string BACKGROUND_FILE = "../resources/images/space_bg2.png";
const std::string PLAYER_FILE =  "../resources/images/airship.png";
const std::string BULLET_FILE_1 = "../resources/images/M484BulletCollection1.png";
const std::vector<std::string> ENEMIES_FILES {
        "../resources/images/enemy1.png", "../resources/images/enemy2.png", "../resources/images/enemy3.png",
        "../resources/images/enemy4.png"
};

// GUI

const std::string FONT_PATH = "../resources/fonts/default.ttf";
const sf::Vector2f BUTTON_SIZE = {400, 200};
const sf::Vector2f START_BUTTON_POS = {
        (SCREEN_WIDTH - BUTTON_SIZE.x) / 2, SCREEN_HEIGHT / 2 - BUTTON_SIZE.y
};
const sf::Vector2f EXIT_BUTTON_POS = {
        (SCREEN_WIDTH - BUTTON_SIZE.x) / 2, SCREEN_HEIGHT/ 2
};
const uint32_t FONT_SIZE = 100;


#endif //SPACE_WARS_SETTINGS_HPP
