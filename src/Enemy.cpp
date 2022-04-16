
#include "Enemy.h"

Enemy::Enemy()
	:m_location(), m_lastLoc(), m_sprite()
{
}

//=======================================================================================

Enemy::Enemy(sf::Vector2f loc, const sf::Texture& texture)
	:m_location(loc), m_lastLoc(loc)
{
	m_sprite.setTexture(texture);
	m_sprite.setPosition(loc);
	//m_sprite.scale(1.2f, 1.2f);
}

//=======================================================================================

void Enemy::SetNextTile(const sf::Vector2f& loc)
{
	m_lastLoc = m_location;
	m_location = sf::Vector2f( loc.x + m_location.x , loc.y + m_location.y);
	m_sprite.setPosition(m_location);
}

//=======================================================================================

void Enemy::setLastLoc()
{
	m_lastLoc = m_location;
}

//=======================================================================================

sf::Vector2f Enemy::getLastLoc() const
{
	return m_lastLoc;
}

//=======================================================================================

void Enemy::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}

//=======================================================================================