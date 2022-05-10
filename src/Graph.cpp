
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
			auto currTile = Tile(loc);
			currTile.setMode(false);
			row.push_back(currTile);
		}
		m_tiles.push_back(row);
	}

	// create adjacent lists 
	for (int i = 0; i < TILES_NUM; i++)
	{
		for (int j = 0; j < TILES_NUM; j++)
		{
			createTileAdjacent(i, j);
			if (edgeOfRange(i) || edgeOfRange(j))
			{
				m_edges.push_back(&m_tiles[i][j]);
				m_tiles[i][j].setEdge();
			}
		}
	}

	m_lastPressed = nullptr;
	LevelCreate(1); // create a randomized level
	
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

	if (invalidTile.isClicked(location))
		return false;

	for (auto& row : m_tiles)
	{
		for (auto tile = row.begin() ; tile != row.end() ; tile++)
		{
			if (tile->isClicked(location) && !tile->isPressed())
			{
				tile->setMode(true);
				m_lastPressed = &*tile;
				return true;
			}
		}
	}

	return false;
}

//=======================================================================================

void Graph::createTileAdjacent(int row, int col)
{
	auto nCol = col;
	if (row % 2 != 0)
		nCol++;

	if ( col-1 >= 0)											// col-1 is in range , m_tiles[row-1][col] exists
		m_tiles[row][col].addAdj(&m_tiles[row][col-1]);

	if ( col+1 < TILES_NUM )									// col+1 is in range , m_tiles[row][col+1] exists
		m_tiles[row][col].addAdj(&m_tiles[row][col+1]);

	if ( row-1 >= 0 && nCol-1 >= 0)								// if m_tiles[row][col-1] exists
		m_tiles[row][col].addAdj(&m_tiles[row - 1][nCol-1]);

	if ( row+1 < TILES_NUM && nCol-1 >= 0 )						// row+1 is in range , m_tiles[row+1][col] exists
		m_tiles[row][col].addAdj(&m_tiles[row + 1][nCol-1]);

	if (row - 1 >= 0 && nCol < TILES_NUM )			// if m_tiles[row+1][col+1] exists
		m_tiles[row][col].addAdj(&m_tiles[row - 1][nCol]);

	if (row + 1 < TILES_NUM && nCol < TILES_NUM )
		m_tiles[row][col].addAdj(&m_tiles[row + 1][nCol]);		// if m_tiles[row-1][col+1] exists

}

//=======================================================================================

void Graph::LevelCreate(int levelNum)
{
	int limitOfLitTiles = 15 - 2* (levelNum % 3) ; // change 
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
			continue;

		m_tiles[rowIndex][colIndex].setMode(true);
		m_currLevel[rowIndex][colIndex] = true;
		currentLitTiles++;
	}
}

//=======================================================================================

void Graph::BFS(Tile sourceTile)
{
	for (auto& row : m_tiles)
	{
		for (auto tile = row.begin(); tile != row.end(); tile++)
		{
			tile->resetTile();
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
	return (tile->getDistance() < other->getDistance());
}

//=======================================================================================

Tile* Graph::CalculateShortestPath(Tile sourceTile)
{
	// create the distances between each tile to the sourceTile using BFS algorithm

	BFS(sourceTile);

	std::sort(m_edges.begin(), m_edges.end(), isCloser);
	
	auto closestEdge = m_edges.front();

	while (closestEdge && closestEdge->getDistance() > 1)
	{
		closestEdge = closestEdge->getParent();
	}

	return closestEdge;
}

//=======================================================================================

bool Graph::enemyOnEdge(Tile enemy) const
{
	return enemy.isOnEdge();
}

//=======================================================================================

void Graph::resetGraph()
{
	m_lastPressed = nullptr; 

	// set graph to be the current level saved
	for (int i = 0; i < TILES_NUM; i++ ) 
	{
		for (int j = 0; j < TILES_NUM; j++ )
		{
			m_tiles[i][j].setMode(m_currLevel[i][j]);
		}
	}
}

//=======================================================================================

void Graph::newLevel(int level)
{
	LevelCreate(level);
	resetGraph();

}

//=======================================================================================

bool Graph::undoClick()
{
	if (!m_lastPressed) // if there is no last pressed
		return false;
	m_lastPressed->setMode(false);
	m_lastPressed = nullptr;
	return true;
}

//=======================================================================================

bool Graph::edgeOfRange(int i) const
{
	return (i == TILES_NUM - 1 || i == 0);
}

//========================================================================================

Tile Graph::getMiddleTile() const
{
	return m_tiles[TILES_NUM / 2][TILES_NUM / 2]; 
}