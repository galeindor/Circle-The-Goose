#pragma once

#include <list>
#include <memory>
#include <queue>
#include <SFML/Graphics.hpp>

using std::vector;
using std::list;

class Tile
{
public:
	Tile(sf::Vector2f loc);
	void setMode(bool newMode);
	bool getMode() const ;
	bool isClicked(const sf::Vector2f& location);
	void draw(sf::RenderWindow& window);

	bool visited;
	int distance;
	int index;

private:
	bool m_mode; // each tile contains if the tile is coloured.
	sf::CircleShape m_shape;

};
