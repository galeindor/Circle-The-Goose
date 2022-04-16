#pragma once

#include <SFML/Graphics.hpp>

#include "Tile.h"

class Enemy
{
public:
	Enemy();
	Enemy(sf::Vector2f loc, const sf::Texture& texture);
	void SetNextTile(const sf::Vector2f& loc);
	void setLastLoc();
	sf::Vector2f getLastLoc() const;
	void draw(sf::RenderWindow& window);

private:

	//Tile m_currTile();
	sf::Vector2f m_lastLoc; // last location before the last movement
	sf::Vector2f m_location; // location of the object
	sf::Sprite m_sprite; // image of the object
};

