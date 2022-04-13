
#include "Graph.h"

Graph::Graph() { initGraph(); }

void Graph::initGraph()
{
	for (int i = 0; i < TILES_NUM; i++)
	{
		auto row = std::vector < std::shared_ptr <Tile> >();
		for (int j = 0; j < TILES_NUM ; j++)
		{
			row.push_back(std::make_shared<Tile>());
			createTileAdjacent(i, j);
		}
		m_tiles.push_back(row);
	}
}

void Graph::createTileAdjacent(int i, int j)
{
	if(j > 0)
		m_tiles[i][j].addAdj(m_tiles[i][j-1]);

	if (i > 0)
		m_tiles[i][j].addAdj(m_tiles[i - 1][j]);

	if (i < (TILES_NUM - 1) )
		m_tiles[i][j].addAdj(m_tiles[i][j+1]);

	if (j < (TILES_NUM - 1) )
		m_tiles[i][j].addAdj(m_tiles[i][j]);

	if (j > 0 && i < (TILES_NUM - 1) )
		m_tiles[i][j].addAdj(m_tiles[i+1][j-1]);

	if (i > 0 && j < (TILES_NUM - 1) )
		m_tiles[i][j].addAdj(m_tiles[i-1][j+1]);

}