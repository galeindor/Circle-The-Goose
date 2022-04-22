
#include "Enemy.h"

Enemy::Enemy()
	:m_location(), m_lastLoc(), m_sprite(), m_currTile(sf::Vector2f())
{
}

//=======================================================================================

Enemy::Enemy(Tile currTile, const sf::Texture& texture)
	:m_location(currTile.getLocation()), m_lastLoc(currTile.getLocation()) , m_currTile(currTile)
{
	m_sprite.setTexture(texture);
	m_sprite.setPosition(currTile.getLocation());
}

//=======================================================================================

void Enemy::SetNextTile(Tile* tile)
{
	m_lastLoc = m_location;
	m_currTile = *tile;
	m_location = tile->getLocation();
	m_sprite.setPosition(m_location);
}

//=======================================================================================

void Enemy::setLastLoc()
{
	m_lastLoc = m_location;
}

//=======================================================================================

//=======================================================================================

void Enemy::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}

//=======================================================================================