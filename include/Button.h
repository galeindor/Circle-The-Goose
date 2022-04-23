#pragma once

#include <SFML/Graphics.hpp>
//#include "Resources.h"

class Button
{
public:
	Button() {}
	Button(const sf::Vector2f& size , const sf::Text& text , const sf::Vector2f& pos);

	// check click on the button
	bool handleClick(const sf::Vector2f& location);

	void draw(sf::RenderWindow& window);


private:

	sf::RectangleShape m_button;
	sf::Text m_buttonText;
	int m_type;

	void initButton(); // set the buttons default values
};