
#include "GameController.h"


GameController::GameController()
	:m_window(sf::VideoMode(1600, 1000), "Circle The Cat") , m_graph()
{
	m_texture.loadFromFile("enemy.png");
	auto tile = m_graph.getMiddleTile();
	m_enemy = Enemy(&tile, m_texture);
}

void GameController::run()
{
	while (m_window.isOpen())
	{
		m_window.clear();
		m_graph.draw(m_window);
		m_enemy.draw(m_window);
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
					int row, col;
					if (m_graph.handleClick(location, row , col)) // calculate enemy movement
					{
						m_enemy.SetNextTile(m_graph.CalculateShortestPath(m_enemy.getCurrTile()));
					}
					break;
				}
				break;
			}
		}
	}
}