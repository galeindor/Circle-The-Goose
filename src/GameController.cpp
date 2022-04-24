
#include "GameController.h"


GameController::GameController()
	:m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Circle The GOOSE") , m_graph() , m_level(1)
{
	m_undoButton = Button( sf::Vector2f(400, 910) , "undo" );
	m_texture.loadFromFile("goose.png");
	auto tile = m_graph.getMiddleTile();
	m_enemy = Enemy(tile, m_texture);
}

void GameController::run()
{
	while (m_window.isOpen())
	{
		m_window.clear(sf::Color(169, 169, 169));
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
		if (m_enemy.isTrapped())
		{
			nextLevel();
		}
	}
}

void GameController::MouseClick(sf::Vector2f location)
{
	auto enemyTile = m_enemy.getCurrTile();
	if (m_graph.handleClick(location, enemyTile)) // calculate enemy movement
	{
		
		if (m_graph.enemyOnEdge(enemyTile.getLocation()))
		{
			resetBoard();
			return;
		}
		else
		{
			m_enemy.SetNextTile(m_graph.CalculateShortestPath(enemyTile));
			Resources::instance().playSound(honk_sound);
		}
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
	popOutScreen(EnemyEscaped);
}

void GameController::nextLevel()
{
	m_graph.newLevel(++m_level);
	auto tile = m_graph.getMiddleTile();
	m_enemy.SetNextTile(&tile);
	popOutScreen(EnemyTrapped);
}

void GameController::popOutScreen(bool isVictory)
{
	m_popOutScreen.setTexture(Resources::instance().getScreenTexture(isVictory));
	auto screenText = sf::Text();
	screenText.setString("Press 'Space' or 'Esc' to Continue");

	Resources::instance().setPopOutScreen(m_popOutScreen, screenText);

	while (m_window.isOpen())
	{
		m_window.clear(sf::Color(169, 169, 169));
		m_window.draw(m_popOutScreen); 
		m_window.draw(screenText);
		m_window.display();

		if (auto event = sf::Event{}; m_window.waitEvent(event))
		{
			if ((event.type == sf::Event::Closed) ||
				((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)) ||
				((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Space)))
			{
				return;
			}
		}
	}
}
