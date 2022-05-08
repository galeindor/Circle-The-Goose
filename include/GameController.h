#pragma once

#include "Enemy.h"
#include "Graph.h"
#include "Button.h"


using std::vector;

class GameController
{
public:

	GameController();
	void run(); // run the game 

private:

	void nextLevel(); // move to next level - create new graph , reset enemy location , increase level counter
	void resetBoard(); // reset current level - reset the graph and enemy location

	void drawGame(); // draw the game
	void MouseClick(sf::Vector2f location); // when mouse is clicked
	void popOutScreen(bool isVictory); // when victory or lose accures , open pop out screen
	void moveEnemy(Tile* tile); // move the enemy to the tile parameter - used for animation

	int m_level; // current level
	int m_numOfClicks; // number of clicks made

	sf::RenderWindow m_window;

	sf::Text m_levelText;
	sf::Text m_clickCounterText;

	sf::Sprite m_bg;

	Graph m_graph;
	Enemy m_enemy;

	// buttons used to undo last move and reset the board to the current level
	Button m_undoButton; 
	Button m_resetButton;

	sf::RectangleShape m_popOutScreen; // screen used when victory or loss accures

};


