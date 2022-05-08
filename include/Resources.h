#pragma once

// ==================== include section ======================

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "macros.h"
#include "Animation.h"
#include <vector>
#include <list>
#include <memory>
#include <queue>
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <stdlib.h> 
#include <time.h> 

using std::vector;
using std::list;

// ==========================================================

// Resources is a singleton class for saving the textures and sounds of the game

class Resources
{
public:
	~Resources();
	static Resources& instance();

	sf::Texture* getScreenTexture(bool victoryFlag);
	sf::Font* getFont();
	sf::Texture* getTexture(int i);
	sf::Texture* getBackground();
	void playSound();
	void setVolume(int volume);
	void setPopOutScreen(sf::RectangleShape& rect , sf::Text& text);
	void initText(sf::Text& text);
	void setAnimation(float deltaTime, sf::Sprite& player, int dir);

private:

	Resources();
	Resources(const Resources&) = default;

	sf::Font m_font;
	sf::SoundBuffer m_buffer;
	sf::Texture m_screenTextures[NUM_OF_SCREENS];
	sf::Texture m_textures[NUM_OF_PICS];
	sf::Sound m_sounds;

	Animation m_animation;

	void loadBuffers();
	void loadTextures();

};
