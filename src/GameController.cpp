
#include "GameController.h"


GameController::GameController()
	:m_window(sf::VideoMode(1600, 1000), "Circle The Cat") , m_graph(TILES_NUM * TILES_NUM)
{
	m_texture.loadFromFile("enemy.png");
	m_enemy = Enemy(sf::Vector2f(100, 100), m_texture);
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
					if (m_graph.handleClick(location)) // calculate enemy movement
					{
						m_enemy.SetNextTile(sf::Vector2f(50,0));
						//m_graph.BFS(1, 1);
					}
					break;
				}
				break;
			}
		}
	}
}