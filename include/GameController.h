#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include "Graph.h"

//#include "Resources.h"
//#include "Consts.h"
//#include "LevelManager.h"


class GameController
{
public:
	GameController();
	void run();

	bool updateLevel();
	void resetBoard();

private:

	sf::RenderWindow m_window;
	sf::Texture m_texture;
	Graph m_graph;
	Enemy m_enemy;

	bool m_timerIsOver;
	bool m_isLvlRunning;

	std::vector<std::unique_ptr<int>> m_movingObj;
	std::vector<std::unique_ptr<int>> m_staticObj;


	sf::Text m_timeText;
	sf::Text m_levelText;
	sf::Text m_timeLeftText;
};


