#ifndef SPACE_WARS_SETTINGS_HPP
#define SPACE_WARS_SETTINGS_HPP


#include <cstdlib>
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
const float PLAYER_DEFAULT_GUN_RELOAD = 0.4f;
const sf::Vector2f PLAYER_DEFAULT_BULLET_VELOCITY = {800, 0};
const sf::Vector2f PLAYER_DEFAULT_BULLET_OFFSET = {80, 40};


// ENEMIES

const float MIN_DELAY_BETWEEN_SPAWN = 1.0;

// RESOURCES

const std::string BACKGROUND_FILE = "../resources/images/space_bg2.png";
const std::string PLAYER_FILE =  "../resources/images/airship.png";
const std::string BULLET_FILE_1 = "../resources/images/M484BulletCollection1.png";


#endif //SPACE_WARS_SETTINGS_HPP
