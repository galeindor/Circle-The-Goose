
#include "Graph.h"

Graph::Graph()
{ 
	srand(time(NULL));
	initGraph(); 
}

//=======================================================================================

void Graph::initGraph()
{
	auto rowShift = 1.f;
	for (int i = 0; i < TILES_NUM; i++)
	{
		auto row = std::vector < Tile > ();
		rowShift = 1 - rowShift;

		for (int j = 0; j < TILES_NUM ; j++)
		{
			auto loc = sf::Vector2f(375 + SPACING * (j + (rowShift / 2) ) , 75 + SPACING * i);
			row.push_back(Tile(loc));
		}
		m_tiles.push_back(row);
	}

	// create adjacent lists and m_edges
	for (int i = 0; i < TILES_NUM; i++)
	{
		m_edges.push_back(&m_tiles[i][0] );
		m_edges.push_back(&m_tiles[0][i] );

		m_edges.push_back(&m_tiles [i] [TILES_NUM - 1] );
		m_edges.push_back(&m_tiles [TILES_NUM - 1] [i] );

		for (int j = 0; j < TILES_NUM; j++)
			createTileAdjacent(i, j);
	}

	LevelCreate(); // create a randomized level
	
}

//=======================================================================================

void Graph::draw(sf::RenderWindow& window)
{
	for (auto row : m_tiles)
	{
		for (auto& tile : row)
		{
			tile.draw(window);
		}
	}
}

//=======================================================================================

bool Graph::handleClick(const sf::Vector2f& location , Tile invalidTile)
{

	/*
	for (auto row : m_tiles)
	{
		for (auto& tile : row)
		{
			if (tile.isClicked(location))
			{
				tile.setMode(true);
			}
		}
	}
	*/

	if (invalidTile.isClicked(location))
		return false;


	for (int row=0 ; row < TILES_NUM ; row++)
	{
		for (int col = 0; col < TILES_NUM; col++)
		{
			if (m_tiles[row][col].isClicked(location) && !m_tiles[row][col].isPressed())
			{
					m_tiles[row][col].setMode(true);
					return true;
			}
		}
	}
	return false;
}

//=======================================================================================

void Graph::createTileAdjacent(int row, int col)
{

	if( col-1 >= 0)											// if m_tiles[row-1][col] exists
		m_tiles[row][col].addAdj(&(m_tiles[row][col-1]));

	if (row-1 >= 0)											// if m_tiles[row][col-1] exists
		m_tiles[row][col].addAdj(&m_tiles[row - 1][col]);

	if ( row+1 < TILES_NUM )								// row+1 is in range , m_tiles[row+1][col] exists
		m_tiles[row][col].addAdj(&m_tiles[row + 1][col]);

	if ( col+1 < TILES_NUM )								// col+1 is in range , m_tiles[row][col+1] exists
		m_tiles[row][col].addAdj(&m_tiles[row][col+1]);

	if (col-1 >= 0 && row + 1 < TILES_NUM )					// if m_tiles[row+1][col-1] exists
		m_tiles[row][col].addAdj(&m_tiles[row+1][col-1]);

	if (row-1 >= 0 && col + 1 < TILES_NUM )
		m_tiles[row][col].addAdj(&m_tiles[row-1][col+1]);	// if m_tiles[row-1][col+1] exists

}

//=======================================================================================

void Graph::LevelCreate()
{
	int limitOfLitTiles = 7; // change by level 
	int currentLitTiles = 0;
	
	m_currLevel.clear();

	for (int i = 0; i < TILES_NUM; i++)
	{
		auto row = std::vector<bool>();
		for (int j = 0; j < TILES_NUM; j++)
		{
			row.push_back(false);
		}
		m_currLevel.push_back(row);
	}

	while (currentLitTiles <= limitOfLitTiles)
	{
		int rowIndex = rand() % 11;
		int colIndex = rand() % 11;

		// middle tile is preserved to the enemy , so it may not start pressed
		if (rowIndex == TILES_NUM / 2 && colIndex == TILES_NUM / 2 ) 
			break;

		m_tiles[rowIndex][colIndex].setMode(true);
		m_currLevel[rowIndex][colIndex] = true;
		currentLitTiles++;
	}
}

//=======================================================================================

void Graph::BFS(Tile sourceTile)
{
	for (int i = 0; i < TILES_NUM; i++)
	{
		for (int j = 0; j < TILES_NUM; j++)
		{
			m_tiles[i][j].resetTile();
		}
	}

	sourceTile.visit(0, nullptr);

	// queue to hold BFS
	std::queue <Tile*> q;

	// Mark the current node as visited and enqueue it
	q.push(&sourceTile);

	while (!q.empty())
	{
		auto currTile = q.front();
		q.pop(); // remove the first element from the queue

		auto adjList = currTile->getAdjList();

		for (auto i = adjList.begin(); i != adjList.end(); i++)
		{
			if (!(*i)->isPressed() && !(*i)->isVisited())
			{
				(*i)->visit(currTile->getDistance() + 1, currTile);
				q.push(*i);
			}
		}
	}
}

//=======================================================================================

bool isCloser(Tile* tile, Tile* other)
{
	return (tile->getDistance() <= other->getDistance());
}

//=======================================================================================

Tile* Graph::CalculateShortestPath(Tile sourceTile)
{
	// create the distances between each tile to the current tile ( m_tiles[row][col] ) 
	// using BFS algorithm

	BFS(sourceTile);

	//std::sort(m_edges.begin(), m_edges.end(), isCloser); 
	
	auto closestEdge = m_edges.front();

	while (closestEdge && closestEdge->getParent() != &sourceTile)
	{
		closestEdge = closestEdge->getParent();
	}

	if (closestEdge)
		return closestEdge;

	return nullptr;

}

//=======================================================================================

bool Graph::enemyOnEdge(sf::Vector2f enemyLoc)
{
	for (auto& tile : m_edges)
		if (tile->getLocation() == enemyLoc)
			return true;
	return false;
}

//=======================================================================================

void Graph::resetGraph()
{
	for (int i = 0; i < TILES_NUM; i++ )
	{
		for (int j = 0; j < TILES_NUM; j++ )
		{
			m_tiles[i][j].setMode(m_currLevel[i][j]);
		}
	}
}

//=======================================================================================

void Graph::newLevel()
{
	LevelCreate();
	resetGraph();

}