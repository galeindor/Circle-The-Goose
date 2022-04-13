
#include "Graph.h"

Graph::Graph() { resetGraph(); }

void Graph::resetGraph()
{
	for (int i = 0; i < TILES_NUM; i++)
	{
		for (int j = 0; j < TILES_NUM ; j++)
		{
			auto newTile = Tile();
			m_tiles.push_back(Tile);
		}
	}
}