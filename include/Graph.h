#pragma once

#include "Tile.h"

const int TILES_NUM = 11;

class Graph
{
public:
	Graph();
	void resetGraph();
	
private:
	std::vector < std::vector <Tile> > m_tiles;
};