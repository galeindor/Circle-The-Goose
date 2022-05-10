
#include "Tile.h"

Tile::Tile(sf::Vector2f location)
	: m_mode(false), m_onEdge(false)
{
	resetTile();
	m_shape.setTexture(*Resources::instance().getTexture(_tile));
	m_shape.setPosition(location);
}

//=======================================================================================

void Tile::addAdj(Tile* other)
{
	auto i = std::find(m_adj.begin(), m_adj.end(), other);
	if (i != m_adj.end())
		m_adj.push_back(other);

	m_adj.push_back(other);
}
//=======================================================================================

void Tile::setMode(bool newMode)
{
	m_mode = newMode;

	if (newMode)
		m_shape.setColor(sf::Color::White);
	else
		m_shape.setColor(sf::Color(0, 0, 0, 100 )); // faded version for un-pressed tile
}

//=======================================================================================

void Tile::draw(sf::RenderWindow& window)
{
	window.draw(m_shape);
}

//=======================================================================================

bool Tile::isClicked(const sf::Vector2f& location) const
{
	return m_shape.getGlobalBounds().contains(location);
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
	m_distance = INT_MAX;
	m_parent = nullptr;
}

//=======================================================================================

Tile* Tile::getParent() const
{
	if (m_parent)
		return m_parent;
	return nullptr;
}

//=======================================================================================

void Tile::setEdge()
{
	m_onEdge = true;
}