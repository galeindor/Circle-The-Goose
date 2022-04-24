#pragma once

#include "Enemy.h"
#include "Graph.h"
#include "Button.h"


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

	sf::RenderWindow m_window;
	sf::Text m_levelText;
	sf::Text m_clickCounterText;


	Graph m_graph;
	Enemy m_enemy;

	// buttons used to undo last move and reset the board to the current level
	Button m_undoButton; 
	Button m_resetButton;

	sf::RectangleShape m_popOutScreen; // screen used when victory or loss accures

};


