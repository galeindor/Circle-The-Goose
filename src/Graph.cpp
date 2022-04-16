
#include "Graph.h"

Graph::Graph(int v)
	:m_V(v)
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

	for (int i = 0; i < TILES_NUM; i++)
		for (int j = 0; j < TILES_NUM; j++)
			createTileAdjacent(i, j);

	LevelCreate();
	
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

bool Graph::handleClick(const sf::Vector2f& location)
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

	for (int i=0 ; i< TILES_NUM ; i++)
	{
		for (int j = 0; j < TILES_NUM; j++)
		{
			if (m_tiles[i][j].isClicked(location) && !m_tiles[i][j].isPressed())
			{
				m_tiles[i][j].setMode(true);
				return true;
			}
		}
	}
	return false;
}

//=======================================================================================

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

//=======================================================================================

void Graph::LevelCreate()
{
	int limitOfLitTiles = 7; // change by level 
	int currentLitTiles = 0;

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
		m_tiles[rowIndex][colIndex].setMode(true);
		m_currLevel[rowIndex][colIndex] = true;
		currentLitTiles++;
	}
}

//=======================================================================================

void Graph::BFS(int row, int col)
{
	for (auto row : m_tiles)
	{
		for (auto& tile : row)
		{
			tile.resetTile();
		}
	}

	auto sourceTile = m_tiles[row][col];
	sourceTile.visit(0, nullptr);

	// queue to hold BFS
	std::queue <Tile*> q;

	// Mark the current node as visited and enqueue it
	q.push(&sourceTile);

	while (!q.empty())
	{
		auto a = q.front();
		q.pop(); //delete the first element form queue

		auto adjList = a->getAdjList();
		for (auto i = adjList.begin(); i != adjList.end(); i++)
		{
			if (!(*i)->isPressed() && (*i)->isVisited())
			{
				(*i)->visit(a->getDistance() + 1, a);
				q.push(*i);
			}
		}

	}
}



void Graph::BFS(int index)
{
	bool* visited = new bool[m_V];

	//initially none of the vertices is visited
	for (int i = 0; i < m_V; i++)
		visited[i] = false;

	// queue to hold BFS traversal sequence 
	std::queue <int> q;

	// Mark the current node as visited and enqueue it
	visited[index] = true;
	q.push(index);
}