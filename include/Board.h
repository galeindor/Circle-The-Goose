#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

//#include "Resources.h"
//#include "Consts.h"
//#include "LevelManager.h"


class Board
{
public:
	Board();
	~Board();
	void drawBoard(sf::RenderWindow& window) const;
	//void updateBoard(sf::Time deltaTime);		//Update level's objects
	bool updateLevel();				//no const - Update level and return a bool value if update succeed 
	void resetBoard();

private:

	sf::Sprite m_gameBackground;
	sf::RectangleShape m_boardArea;

	bool m_timerIsOver;
	bool m_isLvlRunning;

	std::vector<std::unique_ptr<MovingObj>> m_movingObj;
	std::vector<std::unique_ptr<StaticObj>> m_staticObj;

	StaticObj* m_ptrThrone;
	LevelManager m_levelManager;

	sf::Text m_timeText;
	sf::Text m_levelText;
	sf::Text m_timeLeftText;
};


