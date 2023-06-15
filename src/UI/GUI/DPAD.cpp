#include "DPAD.hpp"

#include "../../Core/Resources.hpp"

#include <cmath>

DPAD::DPAD()
{
    m_center.setRadius(24.f);
    m_center.setFillColor(sf::Color::Black);
    
    m_left.setSize({64.f, 48.f});
    m_right.setSize({64.f, 48.f});
    m_up.setSize({48.f, 64.f});
    m_down.setSize({48.f, 64.f});
    
    m_left.setTexture(&left_arrow_texture);
    m_right.setTexture(&right_arrow_texture);
    m_up.setTexture(&up_arrow_texture);
    m_down.setTexture(&down_arrow_texture);
    
    m_left.setTextureRect(sf::IntRect{0, 0, 64, 48});
    m_right.setTextureRect(sf::IntRect{0, 0, 64, 48});
    m_up.setTextureRect(sf::IntRect{0, 0, 48, 64});
    m_down.setTextureRect(sf::IntRect{0, 0, 48, 64});
    
    setPosition({0.f, 300.f});
}

void DPAD::setPosition(const sf::Vector2f& position)
{
    m_center.setPosition(position.x + 64.f, position.y + 64.f);
    m_left.setPosition(position.x, position.y + 64.f);
    m_right.setPosition(position.x + 112.f, position.y + 64.f);
    m_up.setPosition(position.x + 64.f, position.y);
    m_down.setPosition(position.x + 64.f, position.y + 112.f);
}

bool DPAD::mouseOverLeft(const sf::Vector2f& mouse_pos) const
{
    return m_left.getGlobalBounds().contains(mouse_pos);
}
bool DPAD::mouseOverRight(const sf::Vector2f& mouse_pos) const
{
    return m_right.getGlobalBounds().contains(mouse_pos);
}
bool DPAD::mouseOverUp(const sf::Vector2f& mouse_pos) const
{
    return m_up.getGlobalBounds().contains(mouse_pos);
}
bool DPAD::mouseOverDown(const sf::Vector2f& mouse_pos) const
{
    return m_down.getGlobalBounds().contains(mouse_pos);
}

void DPAD::setLeftArrowFilled(bool filled)
{
    if (filled)
    {
        m_left.setTextureRect(sf::IntRect{64, 0, 64, 48});
    }
    else
    {
        m_left.setTextureRect(sf::IntRect{0, 0, 64, 48});
    }
}
void DPAD::setRightArrowFilled(bool filled)
{
    if (filled)
    {
        m_right.setTextureRect(sf::IntRect{64, 0, 64, 48});
    }
    else
    {
        m_right.setTextureRect(sf::IntRect{0, 0, 64, 48});
    }
}
void DPAD::setUpArrowFilled(bool filled)
{
    if (filled)
    {
        m_up.setTextureRect(sf::IntRect{48, 0, 48, 64});
    }
    else
    {
        m_up.setTextureRect(sf::IntRect{0, 0, 48, 64});
    }
}
void DPAD::setDownArrowFilled(bool filled)
{
    if (filled)
    {
        m_down.setTextureRect(sf::IntRect{48, 0, 48, 64});
    }
    else
    {
        m_down.setTextureRect(sf::IntRect{0, 0, 48, 64});
    }
}
void DPAD::update(const sf::Vector2f& mouse_pos, bool bypass)
{
    if ( bypass )
        return;
        
    if ( mouseOverLeft(mouse_pos) )
    {
        setLeftArrowFilled(true);
    }
    else
    {
        setLeftArrowFilled(false);
    }
    
    if ( mouseOverRight(mouse_pos) )
    {
        setRightArrowFilled(true);
    }
    else
    {
        setRightArrowFilled(false);
    }
    
    if ( mouseOverUp(mouse_pos) )
    {
        setUpArrowFilled(true);
    }
    else
    {
        setUpArrowFilled(false);
    }
    
    if ( mouseOverDown(mouse_pos) )
    {
        setDownArrowFilled(true);
    }
    else
    {
        setDownArrowFilled(false);
    }
}
void DPAD::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
        target.draw(m_up);
        target.draw(m_left);
        target.draw(m_right);
        target.draw(m_down);
        target.draw(m_center);
}
