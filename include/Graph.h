#pragma once

#include "Tile.h"

class Graph
{
public:
	Graph();

	void			resetGraph();
	void			newLevel(int level);
	bool			undoClick();
	void			draw(sf::RenderWindow& window);
	bool			handleClick(const sf::Vector2f& location, Tile invalidTile);
	bool			enemyOnEdge(sf::Vector2f enemyLoc);
	Tile*			CalculateShortestPath(Tile sourceTile);
	Tile			getMiddleTile() const { return m_tiles[TILES_NUM / 2][TILES_NUM / 2];}

private:
	
	Tile* m_lastPressed; // index of last pressed tile
	
	void BFS(Tile sourceTile);
	void initGraph(); // initiate graph with randomized level.
	void LevelCreate(int levelNum); // create randomized level
	void createTileAdjacent(int i, int j); // create adjacent lists

	vector < vector <Tile> > m_tiles; // all the graph tiles
	std::vector <Tile*> m_edges; // graph edges
	vector < vector <bool> > m_currLevel; // member to store current level setup
};