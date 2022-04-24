#pragma once

#include "Tile.h"

class Enemy
{
public:
	Enemy();
	Enemy(Tile currTile, const sf::Texture& texture);

	void returnToLastTile();
	void SetNextTile(Tile* tile);
	void draw(sf::RenderWindow& window);
	Tile			getLastTile()	const		{ return m_lastTile; }
	Tile			getCurrTile()	const		{ return m_currTile; }
	bool			isTrapped()		const		{ return m_enemyTrapped; }

private:

	bool moveRandom();
	Tile m_currTile; // current tile enemy is standing on
	Tile m_lastTile; // last tile enemy stood on
	sf::Vector2f m_location; // location of the object
	sf::Sprite m_sprite; // image of the object

	bool m_enemyTrapped = false; // if enemy is trapped
};

