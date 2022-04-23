
#include "GameController.h"


GameController::GameController()
	:m_window(sf::VideoMode(1600, 1000), "Circle The Cat") , m_graph() , m_level(1)
{
	auto text = sf::Text();
	text.setString("undo");
	m_undoButton = Button(sf::Vector2f(100, 100), text , sf::Vector2f(50, 100));
	m_texture.loadFromFile("duck.png");
	auto tile = m_graph.getMiddleTile();
	m_enemy = Enemy(tile, m_texture);
}

void GameController::run()
{
	while (m_window.isOpen())
	{
		m_window.clear();
		m_graph.draw(m_window);
		m_enemy.draw(m_window);
		m_undoButton.draw(m_window);
		m_window.display();
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
					MouseClick(location);
					break;
				}
				break;
			}
		}
	}
}

void GameController::MouseClick(sf::Vector2f location)
{
	auto enemyTile = m_enemy.getCurrTile();
	if (m_graph.handleClick(location, enemyTile)) // calculate enemy movement
	{
		if (m_enemy.isTrapped())
		{
			nextLevel();
			return;
		}

		if (m_graph.enemyOnEdge(enemyTile.getLocation()))
		{
			resetBoard();
			return;
		}
		else
			m_enemy.SetNextTile(m_graph.CalculateShortestPath(enemyTile));
	}
	else if (m_undoButton.handleClick(location))
	{
		m_graph.undoClick();
		m_enemy.returnToLastTile();
	}
}

void GameController::resetBoard()
{
	m_graph.resetGraph();
	auto tile = m_graph.getMiddleTile();
	m_enemy.SetNextTile(&tile);
}

void GameController::nextLevel()
{
	m_graph.newLevel(++m_level);
	auto tile = m_graph.getMiddleTile();
	m_enemy.SetNextTile(&tile);
}