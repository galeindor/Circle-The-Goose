#pragma once

#include <list>
#include <memory>
#include <queue>
#include <SFML/Graphics.hpp>

using std::vector;
using std::list;

class Tile
{
public:
	Tile(sf::Vector2f loc);
	void setMode(bool newMode);
	bool isPressed() const ;
	bool isClicked(const sf::Vector2f& location);
	bool isVisited() const;
	void draw(sf::RenderWindow& window);
	void addAdj(Tile* other);

	void visit(int distance , Tile* parent);
	
	void resetTile();
	list <Tile*> getAdjList();
	int getDistance() const;

private:
	bool m_mode; // each tile contains if the tile is coloured.
	list < Tile* > m_adj; // list of adjacent tiles
	sf::CircleShape m_shape;

	// for bfs
	bool m_visited; // if allready visited
	int m_distance; //
	Tile* m_parent;

};
