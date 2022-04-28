
#include "Enemy.h"

const auto epsilon = 1.f;

Enemy::Enemy()
	:m_location(), m_lastTile(sf::Vector2f()), m_sprite(), m_currTile(sf::Vector2f())
{
}

//=======================================================================================

Enemy::Enemy(Tile currTile, const sf::Texture& texture)
	:m_location(currTile.getLocation()), m_lastTile(currTile) , m_currTile(currTile) , m_enemyTrapped(false)
{
	//m_speedPerSecond = m_sprite.getScale().x * 30;
	Resources::instance().setAnimation(0.1f, m_sprite, m_dir);
	m_sprite.setTexture(texture);
	m_sprite.setPosition(currTile.getLocation());
	auto origin = m_sprite.getOrigin();
	m_sprite.setOrigin(sf::Vector2f(origin.x, origin.y +5));
}

//=======================================================================================

void Enemy::SetNextTile(Tile* tile , sf::RenderWindow& window)
{

	if (!tile) // if there is no possible way to the edges
	{
		if (!moveRandom()) // if there are no valid moves - enemy is trapped
			m_enemyTrapped = true;
		return;
	}
	else // found at least one path to the edges
	{
		animateMovement(tile->getLocation(),window);
		//Resources::instance().setAnimation(0.1f, m_sprite, m_dir);
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
	m_currTile = m_lastTile;
	m_location = m_lastTile.getLocation();
	m_sprite.setPosition(m_location);
	m_enemyTrapped = false;
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
					m_currTile = **i;
					m_location = (*i)->getLocation();
					m_sprite.setPosition(m_location);
					m_lastTile = m_currTile;
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

void Enemy::animateMovement(sf::Vector2f dest , sf::RenderWindow& window)
{
	sf::Clock clock;

	auto speedPerSecond = 0.5f;
	sf::Vector2f direction = dest - m_location;
	m_dir =  getAnimationDirection(direction);
	while( std::abs(m_sprite.getPosition().x - dest.x) > epsilon || std::abs(m_sprite.getPosition().y - dest.y) > epsilon)
	{
		const auto delta = clock.restart().asSeconds();
		m_sprite.move(direction * speedPerSecond * delta);
		m_location = m_sprite.getPosition();
		Resources::instance().setAnimation(delta, m_sprite, m_dir);
		draw(window);
		window.display();
	}
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