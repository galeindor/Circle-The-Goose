#pragma once

#include "Tile.h"

class Graph
{
public:
	Graph();

	void			resetGraph();
	void			newLevel(int level);
	void			draw(sf::RenderWindow& window);

	bool			undoClick();
	bool			enemyOnEdge(Tile enemyLoc) const; // check if the enemy is on edge piece
	bool			handleClick(const sf::Vector2f& location, Tile invalidTile);

	Tile			getMiddleTile() const; // get the middle of graph tile
	Tile*			CalculateShortestPath(Tile sourceTile); 

private:
	
	Tile* m_lastPressed; // index of last pressed tile
	
	void BFS(Tile sourceTile);
	void initGraph(); // initiate graph with randomized level.
	void LevelCreate(int levelNum); // create randomized level
	void createTileAdjacent(int i, int j); // create adjacent lists

	bool edgeOfRange(int i) const; // return if index 'i' in on the edge of the range of tiles vector.

	std::vector <Tile*> m_edges; // graph edges
	vector < vector <Tile> > m_tiles; // all the graph tiles
	vector < vector <bool> > m_currLevel; // member to store current level setup
};