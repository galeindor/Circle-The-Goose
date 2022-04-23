#pragma once


#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "macros.h"
#include <vector>

class Resources
{
public:
	~Resources();
	static Resources& instance();

	sf::Font* getFont();
	void playSound(int index);
	void setVolume(int volume);

/*
	sf::Texture* getTexture(char c);
	sf::Texture* getTexture(int i , int j);
	sf::Texture* getTexture(int i);
	sf::Texture* getButtonTexture(int i , bool pressed);
	sf::Texture* getBackground(int index);
	sf::RectangleShape* getPauseButtons(int index);
	
	void drawPauseScreen(sf::RenderWindow& window);
	void playMusic();
	void setAnimation(int i ,sf::Time deltaTime, sf::Sprite& player , int dir);
*/

private:

	Resources();
	Resources(const Resources&) = default;

	sf::Font m_font;
	sf::SoundBuffer m_buffers[NUM_OF_SOUNDS];
	sf::Sound m_sounds[NUM_OF_SOUNDS];
	void loadBuffers();

/*
	Resources& operator=(const Resources&) = default;

	sf::Music m_music;

	void loadTextures();
	void loadBackground();
	void setPauseScreen();

	sf::RectangleShape m_pauseWindow;
	sf::RectangleShape m_pauseButtons[MENU_BUTTONS];
	sf::Text m_pauseText;

	sf::Texture m_buttonTextures[NUM_OF_BUTTONS][2];

	sf::Texture m_textures[NUM_OF_PICS][DIRECTIONS];
	std::vector < sf::Texture > m_bg;
	

	Animation m_animation[5];
*/

};
