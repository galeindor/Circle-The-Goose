#pragma once

#include "Tile.h"

class Controller;

class Enemy
{
public:
	Enemy();
	Enemy(Tile currTile, const sf::Texture& texture);

	void returnToLastTile();
	void animateMovement(sf::Vector2f direction, float delta);
	void draw(sf::RenderWindow& window);
	void setTile(Tile tile);
	
	Tile*			findNextTile(Tile* tile);
	Tile			getLastTile()	const		{ return m_lastTile; }
	Tile			getCurrTile()	const		{ return m_currTile; }
	bool			isTrapped()		const		{ return m_enemyTrapped; }
	bool			moveValidator(sf::Vector2f dest);

private:

	Tile* moveRandom();
	int getAnimationDirection(sf::Vector2f direction);

	Tile m_currTile; // current tile enemy is standing on
	Tile m_lastTile; // last tile enemy stood on
	sf::Vector2f m_location; // location of the object
	sf::Sprite m_sprite; // image of the object
	int m_dir = 1; // direction of the sprite
	bool m_enemyTrapped = false; // if enemy is trapped

	//float m_speedPerSecond;
};

