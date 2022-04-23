
#include "Enemy.h"

Enemy::Enemy()
	:m_location(), m_lastLoc(), m_sprite(), m_currTile(sf::Vector2f())
{
}

//=======================================================================================

Enemy::Enemy(Tile currTile, const sf::Texture& texture)
	:m_location(currTile.getLocation()), m_lastLoc(currTile.getLocation()) , m_currTile(currTile) , m_enemyTrapped(false)
{
	m_sprite.setTexture(texture);
	m_sprite.setPosition(currTile.getLocation());
}

//=======================================================================================

void Enemy::SetNextTile(Tile* tile)
{
	if (tile == nullptr)
	{
		if (!moveRandom()) // if there are no valid moves - enemy is trapped
			m_enemyTrapped = true;
		return;
	}
	else
	{
		m_lastLoc = m_location;
		m_currTile = *tile;
		m_location = tile->getLocation();
		m_sprite.setPosition(m_location);
		m_enemyTrapped = false;
	}
}

//=======================================================================================

void Enemy::setLastLoc()
{
	m_lastLoc = m_location;
}

//=======================================================================================

bool Enemy::moveRandom()
{
	auto adjList = m_currTile.getAdjList();
	for (auto tile = adjList.begin(); tile != adjList.end(); tile++)
	{
		if (!(*tile)->isPressed())
		{
			m_lastLoc = m_location;
			m_currTile = **tile;
			m_location = (*tile)->getLocation();
			m_sprite.setPosition(m_location);
			return true; // there was a valid move
		}
	}
	return false; // no valid moves , enemy is trapped
}

//=======================================================================================

void Enemy::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}

//=======================================================================================