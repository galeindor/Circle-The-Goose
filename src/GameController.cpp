
#include "GameController.h"

GameController::GameController()
	:m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Circle The GOOSE") , m_graph() , m_level(1) , m_numOfClicks(0)
{
	Resources::instance().initText(m_clickCounterText);
	Resources::instance().initText(m_levelText);

	m_bg.setTexture(*Resources::instance().getBackground());
	m_bg.setColor(sf::Color(255, 255, 255, 150));

	m_clickCounterText.setPosition(sf::Vector2f(30, 150));
	m_levelText.setPosition(sf::Vector2f(30, 200));

	m_undoButton	= Button	( sf::Vector2f(400, 910) , "undo" );
	m_resetButton	= Button	( sf::Vector2f(WINDOW_WIDTH-400, 910) , "reset");

	auto tile = m_graph.getMiddleTile();
	m_enemy = Enemy(tile);
}

//=======================================================================================

void GameController::run()
{
	auto moveInProgress = false; // check if there is move in progress and block multiple presses

	while (m_window.isOpen())
	{

		m_clickCounterText.setString("Number of Clicks: " + std::to_string(m_numOfClicks));
		m_levelText.setString("Current level: " + std::to_string(m_level));

		drawGame();


		for (auto event = sf::Event{}; m_window.pollEvent(event); )
		{
 			switch (event.type)
			{

			case sf::Event::Closed:
				m_window.close();
				break;
			case sf::Event::MouseButtonReleased:
				auto location = m_window.mapPixelToCoords(
					{ event.mouseButton.x, event.mouseButton.y });

				switch (event.mouseButton.button)
				{
				case sf::Mouse::Button::Left:
					if (!moveInProgress)
					{
						moveInProgress = true;
						MouseClick(location);
					}
					break;
				}
				break;
			}
		}

		moveInProgress = false;
		
		if (m_enemy.isTrapped())
			nextLevel();
	}
}

//=======================================================================================

void GameController::MouseClick(sf::Vector2f location)
{
	auto enemyTile = m_enemy.getCurrTile();

	// check if there was a click on a valid tile ( enemy isnt on that tile and tile wasnt pressed)
	if (m_graph.handleClick(location, enemyTile))
	{
		m_numOfClicks++;
		if (m_graph.enemyOnEdge(enemyTile)) //check if enemy tile is an edge tile
		{
			resetBoard();
			popOutScreen(EnemyEscaped);
			return;
		}
		else
		{
			auto nextTile = m_enemy.findNextTile(m_graph.CalculateShortestPath(enemyTile));
			moveEnemy(nextTile);
			Resources::instance().playSound();
		}
	}
	else if (m_undoButton.handleClick(location)) // if presssed undo button
	{
		m_enemy.returnToLastTile();
		if(m_graph.undoClick())
			m_numOfClicks--;
	}
	else if (m_resetButton.handleClick(location)) // if pressed reset button
	{
		resetBoard();
	}
}

//=======================================================================================

void GameController::resetBoard()
{
	m_numOfClicks = 0;
	m_graph.resetGraph();
	auto tile = m_graph.getMiddleTile();
	m_enemy.setTile(tile);
	m_enemy.setTile(tile); // second time is in order to set lastloc to the current tile
}

//=======================================================================================

void GameController::nextLevel()
{
	m_numOfClicks = 0;
	m_graph.newLevel(++m_level);
	auto tile = m_graph.getMiddleTile();
	m_enemy.setTile(tile);
	m_enemy.setTile(tile); // second time is in order to set lastTile to the current tile
	popOutScreen(EnemyTrapped);
}

//=======================================================================================

void GameController::popOutScreen(bool isVictory)
{
	m_popOutScreen.setTexture(Resources::instance().getScreenTexture(isVictory));
	auto screenText = sf::Text();
	screenText.setString("Press any key to Continue");

	Resources::instance().setPopOutScreen(m_popOutScreen, screenText);

	while (m_window.isOpen())
	{
		m_window.clear(sf::Color::White);
		m_window.draw(m_bg);
		m_window.draw(m_popOutScreen); 
		m_window.draw(screenText);
		m_window.display();

		if (auto event = sf::Event{}; m_window.waitEvent(event))
		{
			if (event.type == sf::Event::Closed)
				m_window.close();

			if (event.type == sf::Event::KeyPressed)
				return;
		}
	}
}

//=======================================================================================

void GameController::drawGame() 
{
	m_window.clear(sf::Color::White);
	m_window.draw(m_bg);
	m_graph.draw(m_window);
	m_enemy.draw(m_window);
	m_undoButton.draw(m_window);
	m_resetButton.draw(m_window);
	m_window.draw(m_clickCounterText);
	m_window.draw(m_levelText);
	m_window.display();
}

//=======================================================================================

void GameController::moveEnemy(Tile* tile)
{
	if (!tile)
		return;

	auto dest = tile->getLocation();
	sf::Clock clock;
	
	auto direction = dest - m_enemy.getCurrTile().getLocation();
	
	while (m_enemy.moveValidator(dest))
	{
		auto delta = clock.restart().asSeconds();
		m_enemy.animateMovement(direction, delta);
		drawGame();
	}
	
	m_enemy.setTile(*tile);

}