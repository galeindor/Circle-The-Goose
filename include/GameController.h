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

	sf::RenderWindow m_window;
	sf::Texture m_texture;
	Graph m_graph;
	Enemy m_enemy;

	bool m_timerIsOver;
	bool m_isLvlRunning;

	vector<std::unique_ptr<int>> m_movingObj;
	vector<std::unique_ptr<int>> m_staticObj;


	int m_level;
	sf::Text m_levelText;
	sf::Text m_timeLeftText;

	Button m_undoButton;
};


