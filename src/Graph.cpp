
#include "Graph.h"

Graph::Graph() { initGraph(); }

void Graph::initGraph()
{
	auto rowShift = 1.f;
	for (int i = 0; i < TILES_NUM; i++)
	{
		auto row = std::vector < Tile > ();
		rowShift = 1 - rowShift;
		for (int j = 0; j < TILES_NUM ; j++)
		{
			auto loc = sf::Vector2f(100 + SPACING * (j + (rowShift / 2) ) , 100 + SPACING * i);
			row.push_back(Tile(loc));
		}
		m_tiles.push_back(row);
	}

	for (int i = 0; i < TILES_NUM; i++)
		for (int j = 0; j < TILES_NUM; j++)
			createTileAdjacent(i, j);
	
}

void Graph::draw(sf::RenderWindow& window)
{

	for (auto row : m_tiles)
	{
		for (auto tile : row)
		{
			tile.draw(window);
			
		}
	}
}


void Graph::createTileAdjacent(int i, int j)
{
	if(j > 0)
		m_tiles[i][j].addAdj(&(m_tiles[i][j-1]));

	if (i > 0)
		m_tiles[i][j].addAdj(&m_tiles[i - 1][j]);

	if (i < (TILES_NUM - 1))
		m_tiles[i][j].addAdj(&m_tiles[i + 1][j]);

	if (j < (TILES_NUM - 1) )
		m_tiles[i][j].addAdj(&m_tiles[i][j+1]);

	if (j > 0 && i < (TILES_NUM - 1) )
		m_tiles[i][j].addAdj(&m_tiles[i+1][j-1]);

	if (i > 0 && j < (TILES_NUM - 1) )
		m_tiles[i][j].addAdj(&m_tiles[i-1][j+1]);

}