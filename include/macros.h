#pragma once

#include <SFML/Graphics.hpp>

constexpr auto WINDOW_WIDTH = 1600;
constexpr auto WINDOW_HEIGHT = 1000;
constexpr auto STAGE_TIME = 150;
constexpr auto BAR_SIZE = 100;
constexpr auto BOARD_SIZE = 700;
constexpr auto NUM_OF_SCREENS = 3;
constexpr auto NUM_OF_SOUNDS = 1;

enum MenuButtons
{
	StartGame=3 , Help=5 , Exit=4
};

enum PauseButtons
{
	Home , Restart , Music
};

enum Directions
{
	Down , Left , Right , Up
};

enum LoadScreens
{
	load_escaped , load_trapped
};

enum State
{
	EnemyTrapped = true , EnemyEscaped = false
};

enum LoadSoundBuffers
{
	honk_sound
};

const std::string enemyTexture= { "goose.png"};

const std::string screenTextures[NUM_OF_SCREENS] = { "loseScreen.png" , "winScreen.png"};

const std::string soundBuffers[NUM_OF_SOUNDS] = { "honk.wav" };
