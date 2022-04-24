#include "Button.h"


//=======================================================================================
Button::Button(const sf::Vector2f& pos , const sf::String& text)
{
    // initiate button by parameters
    m_buttonText.setString(text);
    auto location = sf::Vector2f(pos.x, pos.y + 10);
    m_buttonText.setPosition(location);

    initButton();
}

//=======================================================================================
void Button::draw(sf::RenderWindow& window)
{
    window.draw(m_buttonText);
}

//=======================================================================================
bool Button::handleClick(const sf::Vector2f& location)
{
    if (m_buttonText.getGlobalBounds().contains(location))
        return true;

    return false;
}

//=======================================================================================
void Button::initButton()
{
    m_buttonText.setFont(*Resources::instance().getFont());
    m_buttonText.setCharacterSize(40);
    m_buttonText.setOutlineColor(sf::Color::Black);
    m_buttonText.setOutlineThickness(3);
    m_buttonText.setColor(sf::Color::White);

    auto textRect = m_buttonText.getLocalBounds();
    m_buttonText.setOrigin(textRect.left + textRect.width / 2.0f,
        textRect.top + textRect.height / 2.0f);
}

