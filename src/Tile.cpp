
#include "Tile.h"

Tile::Tile()
	: m_mode(false)
{
}


void Tile::addAdj(std::shared_ptr <Tile> other)
{
	auto i = std::find_if(m_adj.begin(), m_adj.end(), other);
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
	auto shape = sf::CircleShape(100.f);
	shape.setFillColor(sf::Color::Blue);
	window.draw(shape);
}