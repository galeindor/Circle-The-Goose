
#include "Enemy.h"

Enemy::Enemy()
	:m_location(), m_lastTile(sf::Vector2f()), m_sprite(), m_currTile(sf::Vector2f())
{
}

//=======================================================================================

Enemy::Enemy(Tile currTile)
	:m_location(currTile.getLocation()), m_lastTile(currTile) , m_currTile(currTile) , m_enemyTrapped(false)
{
	Resources::instance().setAnimation(0.1f, m_sprite, m_dir);
	m_sprite.setTexture(*Resources::instance().getTexture(_enemy));
	m_sprite.setPosition(currTile.getLocation());
	auto origin = m_sprite.getOrigin();
	m_sprite.setOrigin(sf::Vector2f(origin.x + 5, origin.y + 5)); // set origin to centerize the enemy on tile
}

//=======================================================================================

Tile* Enemy::findNextTile(Tile* tile)
{

	if (!tile) // if there is no possible way to the edges
	{
		auto nextTile = moveRandom();
		if (!nextTile) // if moveRandom returned nullptr - no valid moves , enemy is trapped
		{
			m_enemyTrapped = true;
			return nullptr;
		}
		return nextTile; // return the tile returned by random movement
		
	}

	return tile; // if tile is not nullptr - tile is the next destination
}

//=======================================================================================
void Enemy::returnToLastTile()
{
	m_currTile = m_lastTile;
	m_location = m_lastTile.getLocation();
	m_sprite.setPosition(m_location);
	m_enemyTrapped = false;
}
//=======================================================================================

Tile* Enemy::moveRandom()
{
	srand(time(NULL));

	auto adjList = m_currTile.getAdjList();

	int randAdj = rand() % 5; 

	int foundNotPresssed=0;

	while (1)
	{
		for (auto i = adjList.begin(); i != adjList.end(); ++i)
		{
			if (!(*i)->isPressed())
			{
				foundNotPresssed++;
				if (foundNotPresssed >= randAdj)
				{
					return *i; // there was a valid move
				}
			}
		}
		if (foundNotPresssed == 0)
			return nullptr;
	}
	return nullptr; // no valid moves , enemy is trapped
}

//=======================================================================================

void Enemy::draw(sf::RenderWindow& window) const
{
	window.draw(m_sprite);
}

//=======================================================================================

void Enemy::animateMovement(sf::Vector2f direction , float delta)
{
	auto speedPerSecond = 1.5f;

	m_dir =  getAnimationDirection(direction);
	m_sprite.move(direction * speedPerSecond * delta);
	m_location = m_sprite.getPosition();
	Resources::instance().setAnimation(delta, m_sprite, m_dir);
}

//========================================================================

int Enemy::getAnimationDirection(sf::Vector2f direction)
{
	if (direction.y == 0) // movement is to one of the sides
		return (direction.x > 0) ? Right : Left;

	if (direction.y > 0)
		return Down ;

	else
		return Up;
}
//==========================================================================

bool Enemy::moveValidator(sf::Vector2f dest) const
{
	const auto epsilon = 2.f;

	return (std::abs(m_sprite.getPosition().x - dest.x) > epsilon || std::abs(m_sprite.getPosition().y - dest.y) > epsilon);
}

//==========================================================================
void Enemy::setTile(Tile tile)
{
	m_location = tile.getLocation();
	m_sprite.setPosition(m_location);
	m_lastTile = m_currTile;
	m_currTile = tile;
	m_enemyTrapped = false;
}