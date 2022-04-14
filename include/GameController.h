#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

#include "Graph.h"

//#include "Resources.h"
//#include "Consts.h"
//#include "LevelManager.h"


class GameController
{
public:
	GameController();
	void run();
	//~GameController();
	//void drawBoard(sf::RenderWindow& window) const;
	bool updateLevel();
	void resetBoard();

private:

	bool m_timerIsOver;
	bool m_isLvlRunning;

	std::vector<std::unique_ptr<int>> m_movingObj;
	std::vector<std::unique_ptr<int>> m_staticObj;


	sf::Text m_timeText;
	sf::Text m_levelText;
	sf::Text m_timeLeftText;
};


