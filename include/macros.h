#pragma once

#include <SFML/Graphics.hpp>

constexpr auto TILES_NUM = 11;
constexpr auto SPACING = 75;
constexpr auto WINDOW_WIDTH = 1600;
constexpr auto WINDOW_HEIGHT = 1000;
constexpr auto BAR_SIZE = 100;
constexpr auto DIRECTIONS = 4;
constexpr auto NUM_OF_SCREENS = 3;
constexpr auto NUM_OF_PICS = 2;



enum LoadScreens
{
	load_escaped , load_trapped , load_bg
};

enum State
{
	EnemyTrapped = true , EnemyEscaped = false
};

enum Directions
{
	Down=0, Left, Right, Up=3
};

enum Pictures
{
	_enemy , _tile
};

const std::string textures[NUM_OF_PICS] = { "goose.png" , "circle1.png" };

const std::string screenTextures[NUM_OF_SCREENS] = { "loseScreen.png" , "winScreen.png" , "bg1.jpg"};

const std::string soundBuffer = { "honk.wav" };
