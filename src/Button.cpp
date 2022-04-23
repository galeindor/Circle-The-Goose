#include "Button.h"


//=======================================================================================
Button::Button(const sf::Vector2f& size, const sf::Text& text , const sf::Vector2f& pos)
    : m_button(size), m_buttonText(text)
{
    // initiate button by parameters
    auto location = sf::Vector2f(pos.x, pos.y + 10);
    m_button.setPosition(location);
    m_button.setOrigin(sf::Vector2f(size.x / 2, size.y / 2));

    initButton();
}

//=======================================================================================
void Button::draw(sf::RenderWindow& window)
{
    window.draw(m_button);
    window.draw(m_buttonText);
}

//=======================================================================================
bool Button::handleClick(const sf::Vector2f& location)
{
    if (m_button.getGlobalBounds().contains(location))
        return true;

    return false;
}

//=======================================================================================
void Button::initButton()
{
    m_button.setOutlineColor(sf::Color(96, 163, 188));
    m_button.setOutlineThickness(3);

    m_buttonText.setColor(sf::Color::Blue);
    auto textRect = m_buttonText.getLocalBounds();
    m_buttonText.setOrigin(textRect.left + textRect.width / 2.0f,
        textRect.top + textRect.height / 2.0f);
}

