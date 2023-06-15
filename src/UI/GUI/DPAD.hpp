#pragma once

#include <SFML/Graphics.hpp>

class DPAD : public sf::Drawable, public sf::Transformable {
public:
    DPAD();
    
    void setPosition(const sf::Vector2f& position);
    
    void update(const sf::Vector2f& mouse_pos, bool bypass = false);
    
    bool mouseOverLeft(const sf::Vector2f& mouse_pos) const;
    bool mouseOverRight(const sf::Vector2f& mouse_pos) const;
    bool mouseOverUp(const sf::Vector2f& mouse_pos) const;
    bool mouseOverDown(const sf::Vector2f& mouse_pos) const;
    
    void setLeftArrowFilled(bool filled);
    void setRightArrowFilled(bool filled);
    void setUpArrowFilled(bool filled);
    void setDownArrowFilled(bool filled);
    
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
    sf::CircleShape    m_center;
    sf::RectangleShape m_left;
    sf::RectangleShape m_right;
    sf::RectangleShape m_up;
    sf::RectangleShape m_down;
};
