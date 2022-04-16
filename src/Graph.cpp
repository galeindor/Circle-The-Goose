
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
			auto line = list < Tile* >();
			//line.push_back(&(m_tiles[i][j]));
			m_adj.push_back(line);

			auto loc = sf::Vector2f(100 + SPACING * (j + (rowShift / 2) ) , 100 + SPACING * i);
			auto tile = Tile(loc);
			row.push_back(tile);
			tile.index = i * TILES_NUM + j;
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
			if (m_tiles[i][j].isClicked(location) && !m_tiles[i][j].getMode())
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
	auto index = TILES_NUM * i + j;

	if(j > 0)
		m_adj[index].push_back(&(m_tiles[i][j-1]));

	if (i > 0)
		m_adj[index].push_back(&m_tiles[i - 1][j]);

	if (i < (TILES_NUM - 1))
		m_adj[index].push_back(&m_tiles[i + 1][j]);

	if (j < (TILES_NUM - 1) )
		m_adj[index].push_back(&m_tiles[i][j+1]);

	if (j > 0 && i < (TILES_NUM - 1) )
		m_adj[index].push_back(&m_tiles[i+1][j-1]);

	if (i > 0 && j < (TILES_NUM - 1) )
		m_adj[index].push_back(&m_tiles[i-1][j+1]);

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
	auto s = TILES_NUM * row + col;
	
	//m_adj = new list <Tile*>[m_V];

	bool* visited = new bool[m_V];

	//initially none of the vertices is visited
	for (int i = 0; i < m_V; i++)
		visited[i] = false;

	// queue to hold BFS traversal sequence 
	std::queue <int> q;

	// Mark the current node as visited and enqueue it
	visited[s] = true;
	(*m_adj[s].begin())->distance = 0;
	q.push(s);

	while (!q.empty())
	{
		int a = q.front();
		q.pop(); //delete the first element form queue

		auto start = m_adj[a].begin();
		for (auto j = ++start ; j != m_adj[a].end(); j++)
		{
			auto currIndex = (*j)->index;
			if (!visited[currIndex])
			{
				visited[currIndex] = true;
				(*j)->distance = (*start)->distance + 1; // increase distance from source
				q.push(currIndex);
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