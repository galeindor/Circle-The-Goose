#pragma once

#include "Tile.h"
#include <stdlib.h> 
#include <time.h> 



const int TILES_NUM = 11;
const int SPACING = 50;
const int ROW_SPACING = 10;

class Graph
{
public:
	Graph(int v);
	void resetGraph();
	void draw(sf::RenderWindow& window);
	bool handleClick(const sf::Vector2f& location);
	void BFS(int row, int col);
	void BFS(int index);

private:
	
	int m_V; // number of tiles in the graph

	void initGraph(); // initiate graph with randomized level.
	void LevelCreate(); // create randomized level
	void createTileAdjacent(int i, int j); // create adjacent lists

	vector < vector <Tile> > m_tiles; // all the graph tiles
	vector < list < Tile* > > m_adj; // adjacent lists
	vector < vector <bool> > m_currLevel; // member to store current level setup
};