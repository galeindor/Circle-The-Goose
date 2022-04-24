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

	sf::Texture* getScreenTexture(bool victoryFlag);
	sf::Font* getFont();
	sf::Texture* getTexture(int i);

	void playSound(int index);
	void setVolume(int volume);
	void setPopOutScreen(sf::RectangleShape& rect , sf::Text& text);
	void initText(sf::Text& text);
/*
	sf::Texture* getTexture(char c);
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
	sf::Texture m_screenTextures[NUM_OF_SCREENS];
	sf::Texture m_enemyTexture;
	sf::Sound m_sounds[NUM_OF_SOUNDS];

	void loadBuffers();
	void loadTextures();

/*
	Resources& operator=(const Resources&) = default;

	sf::Music m_music;

	void loadBackground();
	void setPauseScreen();

	sf::RectangleShape m_pauseWindow;
	sf::RectangleShape m_pauseButtons[MENU_BUTTONS];
	sf::Text m_pauseText;

	sf::Texture m_buttonTextures[NUM_OF_BUTTONS][2];

	std::vector < sf::Texture > m_bg;
	

	Animation m_animation[5];
*/

};
