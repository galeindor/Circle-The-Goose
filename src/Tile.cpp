
#include "Tile.h"

Tile::Tile()
	: m_mode = false;
{}
void Tile::addAdj(std::shared_ptr <bool> other)
{
	if(!std::find(m_adjacent , other))
		m_adjacent.push_back(other);
}

void Tile::setMode(bool newMode)
{
	m_mode = newMode;
}

bool Tile::getMode() const
{
	return m_mode;
}