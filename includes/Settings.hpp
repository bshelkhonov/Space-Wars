#ifndef SPACE_WARS_SETTINGS_HPP
#define SPACE_WARS_SETTINGS_HPP


#include <cstdlib>
#include <string>
#include <SFML/System/Vector2.hpp>


// SCREEN

const size_t SCREEN_WIDTH = 1366;
const size_t SCREEN_HEIGHT = 768;

// PLAYER

const sf::Vector2f PLAYER_SPRITE_SCALE = {0.13, 0.13};
const sf::Vector2f PLAYER_DEFAULT_POS = {50, 360};
const sf::Vector2f PLAYER_MIN_POS = {50, 30};
const sf::Vector2f PLAYER_MAX_POS = {50, 678};
const sf::Vector2f PLAYER_MOVE_UP = {0, -760};
const sf::Vector2f PLAYER_MOVE_DOWN = {0, 760};
const float PLAYER_DEFAULT_GUN_RELOAD = 0.1f;
const sf::Vector2f PLAYER_DEFAULT_BULLET_VELOCITY = {500, 0};

// RESOURCES

const std::string BACKGROUND_FILE = "../resources/images/sky1.png";
const std::string PLAYER_FILE =  "../resources/images/airship.png";
const std::string BULLET_FILE_1 = "../resources/images/M484BulletCollection1.png";


#endif //SPACE_WARS_SETTINGS_HPP
