#pragma once

#include <SFML/Graphics.hpp>

#include "Tile.h"

class Enemy
{
public:
	Enemy();
	Enemy(Tile* currTile, const sf::Texture& texture);

	void setLastLoc();
	void SetNextTile(Tile* tile);
	void draw(sf::RenderWindow& window);
	sf::Vector2f getLastLoc() const { return m_lastLoc; }
	Tile* getCurrTile() const { return m_currTile; }

private:

	Tile* m_currTile;
	sf::Vector2f m_lastLoc; // last location before the last movement
	sf::Vector2f m_location; // location of the object
	sf::Sprite m_sprite; // image of the object
};

