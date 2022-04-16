
#include "Tile.h"

Tile::Tile(sf::Vector2f location)
	: m_mode(false) 
{
	m_shape = sf::CircleShape(20.f);
	m_shape.setPosition(location);
	m_shape.setFillColor(sf::Color::Blue);
}

//=======================================================================================

//=======================================================================================

void Tile::setMode(bool newMode)
{
	m_mode = newMode;

	if (newMode)
		m_shape.setFillColor(sf::Color::Cyan);
	else
		m_shape.setFillColor(sf::Color::Blue);

	
}

//=======================================================================================

bool Tile::getMode() const
{
	return m_mode;
}

//=======================================================================================

void Tile::draw(sf::RenderWindow& window)
{
	window.draw(m_shape);
}

//=======================================================================================

bool Tile::isClicked(const sf::Vector2f& location)
{
	if (m_shape.getGlobalBounds().contains(location))
		return true;

	return false;
}