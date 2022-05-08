#include "Resources.h"

Resources::Resources()
{
	loadTextures();
	loadBuffers();

	m_animation = Animation(m_textures[_enemy], sf::Vector2u(3, 4), 1);
	m_font.loadFromFile("font.ttf");
}

//=======================================================================================

Resources::~Resources(){}

//=======================================================================================

Resources& Resources::instance()
{
	static Resources inst;
	return inst;
}

//=======================================================================================
void Resources::loadBuffers()
{
	if (!m_buffer.loadFromFile(soundBuffer))
			return;
		m_sounds.setBuffer(m_buffer);
		m_sounds.setVolume(20);
	}

//=======================================================================================
void Resources::playSound()
{
	m_sounds.play();
}

//=======================================================================================
void Resources::setVolume(int volume)
{
	static bool music_on = true;

	m_sounds.setVolume((float)volume);
}
//======================================================================================

void Resources::loadTextures()
{
	for (int i = 0; i < NUM_OF_SCREENS ; i++)
		m_screenTextures[i].loadFromFile(screenTextures[i]);

	for (int i = 0; i < NUM_OF_PICS; i++)
		m_textures[i].loadFromFile(textures[i]);

}

//======================================================================================

sf::Texture* Resources::getScreenTexture(bool victoryFlag) 
{
	switch (victoryFlag)
	{
	case State::EnemyEscaped:
		return &m_screenTextures[load_escaped];
	case State::EnemyTrapped:
		return &m_screenTextures[load_trapped];
	default:
		break;
	}
	return nullptr;
}

//=========================================================================
void Resources::setPopOutScreen(sf::RectangleShape& rect, sf::Text& text)
{

	auto size = sf::Vector2f(WINDOW_WIDTH / 1.5f, WINDOW_HEIGHT / 1.5f);
	rect.setSize(size);
	rect.setOrigin(size.x / 2, size.y / 2);

	auto loc = sf::Vector2f(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	rect.setPosition(loc);
	
	initText(text);
	text.setPosition(loc.x, loc.y + 400);
}
//=======================================================================================
void Resources::initText(sf::Text& text)
{
	text.setCharacterSize(40);
	text.setFont(m_font);
	text.setLetterSpacing(0.8f);
	//text.setColor(sf::Color::White);
	text.setOutlineColor(sf::Color::Black);
	text.setOutlineThickness(3);

	auto textRect = text.getLocalBounds();
	text.setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);
	
}

//=======================================================================================
void Resources::setAnimation(float deltaTime, sf::Sprite& player , int dir)
{
	m_animation.update(dir, deltaTime);
	player.setTextureRect(m_animation.uvRect);
	player.setScale(1.5f, 1.5f);
}

//=======================================================================================

sf::Texture* Resources::getTexture(int i)
{
	return &m_textures[i];
}

//=======================================================================================

sf::Texture* Resources::getBackground()
{ 
	return &m_screenTextures[load_bg]; 
}

//=======================================================================================

sf::Font* Resources::getFont()
{
	return &m_font;
}

//=======================================================================================