#include "Button.h"


//=======================================================================================
Button::Button(const sf::Vector2f& pos , const sf::String& text)
{
    // initiate button by parameters
    m_buttonText.setString(text);
    auto location = sf::Vector2f(pos.x, pos.y + 10);
    m_buttonText.setPosition(location);

    Resources::instance().initText(m_buttonText);
}

//=======================================================================================
void Button::draw(sf::RenderWindow& window) const
{
    window.draw(m_buttonText);
}

//=======================================================================================
bool Button::handleClick(const sf::Vector2f& location) const
{
    if (m_buttonText.getGlobalBounds().contains(location))
        return true;

    return false;
}

//=======================================================================================