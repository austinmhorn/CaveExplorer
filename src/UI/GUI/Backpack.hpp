#pragma once

#include <SFML/Graphics.hpp>

class Backpack : public sf::Drawable, public sf::Transformable {
public:
    Backpack();
    
    void setPosition(const sf::Vector2f& position);
    
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
    sf::RectangleShape m_rect;
};
