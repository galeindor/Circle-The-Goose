#pragma once

#include "Tile.h"

const int TILES_NUM = 11;
const int SPACING = 50;
const int ROW_SPACING = 10;

class Graph
{
public:
	Graph();
	void resetGraph();
	void draw(sf::RenderWindow& window);
	
private:
	void initGraph();
	void createTileAdjacent(int i, int j);
	std::vector < std::vector <Tile> > m_tiles;
};