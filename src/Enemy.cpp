
#include "Enemy.h"

Enemy::Enemy()
	:m_location(), m_lastTile(sf::Vector2f()), m_sprite(), m_currTile(sf::Vector2f())
{
}

//=======================================================================================

Enemy::Enemy(Tile currTile, const sf::Texture& texture)
	:m_location(currTile.getLocation()), m_lastTile(currTile) , m_currTile(currTile) , m_enemyTrapped(false)
{
	m_sprite.setTexture(texture);
	m_sprite.setPosition(currTile.getLocation());
}

//=======================================================================================

void Enemy::SetNextTile(Tile* tile)
{
	if (!tile) // if there is no possible way to the edges
	{
		if (!moveRandom()) // if there are no valid moves - enemy is trapped
			m_enemyTrapped = true;
		return;
	}
	else // found at least one path to the edges
	{
		m_lastTile = m_currTile;
		m_currTile = *tile;
		m_location = tile->getLocation();
		m_sprite.setPosition(m_location);
		m_enemyTrapped = false;
	}
}

//=======================================================================================
void Enemy::returnToLastTile()
{
	SetNextTile(&m_lastTile);
}
//=======================================================================================

bool Enemy::moveRandom()
{
	srand(time(NULL));

	auto adjList = m_currTile.getAdjList();

	int randAdj = rand() % 5; 

/*
	auto first = adjList.begin();

	int counter = 0;
	for (auto adj : adjList)
	{
		if (adj->isPressed())
			counter++;
		else
			break;
	}
	if(counter == adjList.size())
		return false; // no valid moves , enemy is trapped

	int index = rand() % (adjList.size()-1);
	auto tile = (*first + index);

	while (tile->isPressed()) // do until an unpressed tile is found
	{
		index = rand() % (m_currTile.getAdjList().size());
		tile = (*first+ index);
	}
*/

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
					m_lastTile = m_currTile;
					m_currTile = **i;
					m_location = (*i)->getLocation();
					m_sprite.setPosition(m_location);
					return true; // there was a valid move
				}
			}
		}
		if (foundNotPresssed == 0)
			return false;
	}
	return false; // no valid moves , enemy is trapped
}

//=======================================================================================

void Enemy::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}

//=======================================================================================