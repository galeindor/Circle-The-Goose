#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include "Graph.h"
#include "Button.h"

//#include "Resources.h"
//#include "Consts.h"
//#include "LevelManager.h"

using std::vector;

class GameController
{
public:
	GameController();
	void run();

	void nextLevel();
	void resetBoard();

private:

	void MouseClick(sf::Vector2f location);
	void popOutScreen(bool isVictory);

	int m_level;
	int m_numOfClicks;

	sf::Text m_levelText;
	sf::Text m_clickCounterText;

	sf::RenderWindow m_window;
	sf::Texture m_texture;
	Graph m_graph;
	Enemy m_enemy;
	Button m_undoButton;
	Button m_resetButton;



	sf::RectangleShape m_popOutScreen; // screen used when victory or loss accures

};


