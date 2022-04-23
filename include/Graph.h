#pragma once

#include "Tile.h"
#include <algorithm>
#include <stdlib.h> 
#include <time.h> 



const int TILES_NUM = 11;
const int SPACING = 75;
const int ROW_SPACING = 10;

class Graph
{
public:
	Graph();

	void			resetGraph();
	void			newLevel();
	void			draw(sf::RenderWindow& window);
	bool			handleClick(const sf::Vector2f& location, Tile invalidTile);
	bool			enemyOnEdge(sf::Vector2f enemyLoc);
	Tile*			CalculateShortestPath(Tile sourceTile);
	Tile			getMiddleTile() const { return m_tiles[TILES_NUM / 2][TILES_NUM / 2];}

private:
	
	//bool isCloser(Tile tile , Tile other);
	
	void BFS(Tile sourceTile);
	void initGraph(); // initiate graph with randomized level.
	void LevelCreate(); // create randomized level
	void createTileAdjacent(int i, int j); // create adjacent lists

	vector < vector <Tile> > m_tiles; // all the graph tiles
	std::vector <Tile*> m_edges; // graph edges
	vector < vector <bool> > m_currLevel; // member to store current level setup
};