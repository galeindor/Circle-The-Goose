#pragma once

#include <vector>
#include <memory>

class Tile
{
public:
	Tile();
	void addAdj(std::shared_ptr <bool> other);
	void setMode(bool newMode);
	bool getMode() const ;

private:
	bool m_mode; // each tile contains if the tile is coloured.
	std::vector < std::shared_ptr <Tile> > m_adjacent; // list of all adjacent tiles.

};
