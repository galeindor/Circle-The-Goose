#include "Animation.h"

#include "Resources.h"

const auto AnimationTime = 0.3f;

Animation::Animation(){}

Animation::Animation(sf::Texture texture, sf::Vector2u imageCount, int dir)
    : m_imageCount(imageCount), m_dir(dir)
{
    m_elapsed = 0.0f;
    m_currentImage.x = 0;

    uvRect.width = 139 / float(imageCount.x);
    uvRect.height = 185 / float(imageCount.y);
}

void Animation::update(int row , float deltaTime)
{
    m_currentImage.y = row;
    m_elapsed += deltaTime;

    if (m_elapsed >= AnimationTime)
    {
        m_elapsed -= AnimationTime;
        m_currentImage.x++;
        if (m_currentImage.x >= m_imageCount.x)
            m_currentImage.x = 0;

    }
    uvRect.top = m_currentImage.y * uvRect.height;
    uvRect.left = m_currentImage.x * uvRect.width;

}

