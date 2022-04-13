
#include "Tile.h"

Tile::Tile(sf::Vector2f location)
	: m_mode(false) 
{
	m_shape = sf::CircleShape(20.f);
	m_shape.setPosition(location);
	m_shape.setFillColor(sf::Color::Blue);
}

void Tile::addAdj(Tile* other)
{
	auto i = std::find(m_adj.begin(), m_adj.end(), other);
	if( i != m_adj.end())
		m_adj.push_back(other);
}

void Tile::setMode(bool newMode)
{
	m_mode = newMode;
}

bool Tile::getMode() const
{
	return m_mode;
}

void Tile::draw(sf::RenderWindow& window)
{
	window.draw(m_shape);
}