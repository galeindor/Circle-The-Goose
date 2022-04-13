#pragma once

#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>

class Tile
{
public:
	Tile(sf::Vector2f loc);
	void addAdj(Tile* other);
	void setMode(bool newMode);
	bool getMode() const ;
	void draw(sf::RenderWindow& window);

private:
	bool m_mode; // each tile contains if the tile is coloured.
	std::vector < Tile* > m_adj; // list of all adjacent tiles.
	sf::CircleShape m_shape;

};
