
#include "GameController.h"

GameController::GameController() { }

void GameController::run()
{
	auto graph = Graph();
	auto window = sf::RenderWindow(sf::VideoMode(800, 800), "Circle The Cat");

	while (window.isOpen())
	{
		window.clear();
		graph.draw(window);
		window.display();
		for (auto event = sf::Event{}; window.pollEvent(event); )
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			}
		}
	}
}