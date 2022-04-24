#include "Resources.h"

Resources::Resources()
{
	loadTextures();
	loadBuffers();
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
sf::Font* Resources::getFont()
{
	return &m_font;
}

//=======================================================================================
void Resources::loadBuffers()
{
	for (int i = 0; i < NUM_OF_SOUNDS; i++)
	{
		if (!m_buffers[i].loadFromFile(soundBuffers[i]))
			return;
		m_sounds[i].setBuffer(m_buffers[i]);
		m_sounds[i].setVolume(20);
	}
}

//=======================================================================================
void Resources::playSound(int index)
{
	m_sounds[index].play();
}

//=======================================================================================
void Resources::setVolume(int volume)
{
	static bool music_on = true;

	for (int i = 0; i < NUM_OF_SOUNDS; i++)
	{
		m_sounds[i].setVolume(volume);
	}
}
//======================================================================================

void Resources::loadTextures()
{
	for (int i = 0; i < NUM_OF_SCREENS ; i++)
		m_screenTextures[i].loadFromFile(screenTextures[i]);

	m_enemyTexture.loadFromFile(enemyTexture);

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
	text.setColor(sf::Color::White);
	text.setOutlineColor(sf::Color::Black);
	text.setOutlineThickness(3);

	auto textRect = text.getLocalBounds();
	text.setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);
	
}
//=======================================================================================

sf::Texture* Resources::getTexture(int i)
{
	return &m_enemyTexture;
}

/*
void Resources::setAnimation(int i ,sf::Time deltaTime, sf::Sprite& player , int dir)
{
	m_animation[i].update(dir, deltaTime);
	player.setTextureRect(m_animation[i].uvRect);
}


//=======================================================================================
void Resources::setPauseScreen()
{
	m_pauseWindow.setFillColor(sf::Color(179, 218, 255, 255));
	m_pauseWindow.setPosition(sf::Vector2f(600, 250));
	m_pauseWindow.setSize(sf::Vector2f(340, 230));
	m_pauseWindow.setOutlineThickness(3);
	m_pauseWindow.setOutlineColor(sf::Color::Black);
	auto buttonSize = sf::Vector2f(30, 30);
	auto buttonPos = sf::Vector2f(550, 450);

	m_pauseText.setFont(m_font);
	m_pauseText.setString("Pause");
	m_pauseText.Bold;
	m_pauseText.setOutlineColor(sf::Color(12, 36, 97, 255));
	m_pauseText.setOutlineThickness(3);
	m_pauseText.setCharacterSize(80);
	m_pauseText.setColor(sf::Color(29, 209, 161, 255));
	m_pauseText.setPosition(sf::Vector2f(660, 260));
}


//=======================================================================================

//=======================================================================================
sf::Texture* Resources::getTexture(char c)
{
	switch (c)
	{
	case 'K': return &m_textures[load_King][0];
	case 'M': return &m_textures[load_Mage][0];
	case 'W': return &m_textures[load_Warrior][0];
	case 'T': return &m_textures[load_Thief][0];
	case 'X': return &m_textures[load_Teleport][0];
	case 'F': return &m_textures[load_Key][0];
	case '=': return &m_textures[load_Wall][0];
	case '@': return &m_textures[load_Throne][0];
	case '#': return &m_textures[load_Gate][0];
	case '!': return &m_textures[load_Orge][0];
	case '*': return &m_textures[load_Fire][0];
	case '^': return &m_textures[load_Gnome][0];
	case '%': return &m_textures[load_Gift][0];
	}
}

//=======================================================================================
sf::Texture* Resources::getTexture(int index , int dir)
{
	return &m_textures[index][dir];
}

//=======================================================================================
sf::Texture* Resources::getTexture(int index) 
{
	return &m_textures[index][0];
}

//=======================================================================================
sf::Texture* Resources::getBackground(int index)
{
	return &m_bg[index];
}

//=======================================================================================
sf::RectangleShape* Resources::getPauseButtons(int index)
{
	return &m_pauseButtons[index];
}

//=======================================================================================
sf::Texture* Resources::getButtonTexture(int index , bool pressed)
{
	if(pressed)
		return &m_buttonTextures[index][1];
	return &m_buttonTextures[index][0];
}

//=======================================================================================
void Resources::loadBackground()
{
	auto loadPic = sf::Texture();
	loadPic.loadFromFile("gamebg.png");
	m_bg.push_back(loadPic);

	loadPic.loadFromFile("helpBar.png");
	m_bg.push_back(loadPic);

	loadPic.loadFromFile("bg.png");
	m_bg.push_back(loadPic);
}





//=======================================================================================
void Resources::drawPauseScreen(sf::RenderWindow& window)
{
	window.draw(m_pauseWindow);
	window.draw(m_pauseText);
}

//=======================================================================================
void Resources::playMusic()
{
	static bool musicOn = false; // check if the music is played.
	if (!musicOn)
	{
		m_music.play();
		musicOn = true;
		return;
	}
	m_music.pause();
	musicOn = false;
}
*/