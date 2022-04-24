#pragma once

#include "Resources.h"

class Tile
{
public:

	Tile(sf::Vector2f loc);

	bool	isClicked	(const sf::Vector2f& location)  const;
	Tile*	getParent()	const;
	void	resetTile();
	void	setMode(bool newMode);
	void	draw(sf::RenderWindow& window);
	void	addAdj(Tile* other);
	void	visit(int distance , Tile* parent);

	bool			isPressed()			const		{ return m_mode;				}
	bool			isVisited()			const		{ return m_visited;				}
	list <Tile*>	getAdjList()		const		{ return m_adj;					}
	int				getDistance()		const		{ return m_distance;			}
	sf::Vector2f	getLocation()		const		{ return m_shape.getPosition(); }

private:
	bool m_mode; // each tile contains if the tile is coloured.
	list < Tile* > m_adj; // list of adjacent tiles
	sf::CircleShape m_shape;

	// for BFS algorithm
	bool m_visited; // if already visited in current BFS run
	int m_distance; // distance from source tile
	Tile* m_parent; // parent tile in current BFS run

};
