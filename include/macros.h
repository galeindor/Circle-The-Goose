#pragma once

#include <SFML/Graphics.hpp>

constexpr auto TILES_NUM = 11;
constexpr auto SPACING = 75;
constexpr auto WINDOW_WIDTH = 1600;
constexpr auto WINDOW_HEIGHT = 1000;
constexpr auto BAR_SIZE = 100;
constexpr auto DIRECTIONS = 4;
constexpr auto NUM_OF_SCREENS = 3;
constexpr auto NUM_OF_SOUNDS = 1;


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
	Down, Left, Right, Up
};

enum Sounds
{
	honk_sound
};

const std::string enemyTexture = { "goose.png"};

const std::string screenTextures[NUM_OF_SCREENS] = { "loseScreen.png" , "winScreen.png" , "bg1.jpg"};

const std::string soundBuffers[NUM_OF_SOUNDS] = { "honk.wav" };
