#pragma once

#include <SFML/Graphics.hpp>

class Enemy
{
public:
	Enemy();
	Enemy(sf::Vector2f loc, const sf::Texture& texture);
	void moveEnemyTo(const sf::Vector2f& loc);
	void setLastLoc();
	sf::Vector2f getLastLoc() const;
	void draw(sf::RenderWindow& window);

private:

	sf::Vector2f m_lastLoc; // last location before the last movement
	sf::Vector2f m_location; // location of the object
	sf::Sprite m_sprite; // image of the object
};

