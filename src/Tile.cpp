
#include "Tile.h"

Tile::Tile(sf::Vector2f location)
	: m_mode(false) 
{
	m_shape = sf::CircleShape(30.f);
	m_shape.setPosition(location);
	m_shape.setFillColor(sf::Color::Blue);
}

//=======================================================================================

void Tile::addAdj(Tile* other)
{
	auto i = std::find(m_adj.begin(), m_adj.end(), other);
	if (i != m_adj.end())
		m_adj.push_back(other);
	//auto i = std::find(m_adj.begin(), m_adj.end(), other);
	//if( i != m_adj.end())
	m_adj.push_back(other);
}
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

bool Tile::isPressed() const
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

//=======================================================================================

void Tile::visit(int distance, Tile* parent)
{
	m_visited = true;
	m_distance = distance;
	m_parent = parent;
}

//=======================================================================================

void Tile::resetTile()
{
	m_visited = false;
	m_distance = INFINITY;
	m_parent = nullptr;
}

//=======================================================================================

list <Tile*> Tile::getAdjList()
{
	return m_adj;
}
//=======================================================================================

bool Tile::isVisited() const
{
	
	return m_visited;
}

int Tile::getDistance() const
{
	return m_distance;
}