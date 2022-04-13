#pragma once

#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>

class Tile
{
public:
	Tile();
	void addAdj(std::shared_ptr <Tile> other);
	void setMode(bool newMode);
	bool getMode() const ;
	void draw(sf::RenderWindow& window);

private:
	bool m_mode; // each tile contains if the tile is coloured.
	std::vector < std::shared_ptr <Tile> > m_adj; // list of all adjacent tiles.
	sf::Sprite m_sprite;

};
