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
	Graph();
	void resetGraph();
	void draw(sf::RenderWindow& window);
	bool handleClick(const sf::Vector2f& location);
	
private:
	void initGraph();
	void LevelCreate();
	void createTileAdjacent(int i, int j);
	std::vector < std::vector <Tile> > m_tiles;
	std::vector < std::vector <bool> > m_currLevel;
};