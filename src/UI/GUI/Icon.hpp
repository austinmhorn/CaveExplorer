#pragma once

#include "Elements/Button/Base/Button.hpp"

class Icon : public sf::Drawable, public sf::Transformable
{
public:
    enum class Type : unsigned
    {
        Backpack  = 0,
        Map       = 1,
        Crosshair = 2,
        
        ///< Keep last -- indicates # of enumerations
        Count    = 3
    };
    
    Icon(const Icon::Type type);
    
    void setPosition(const sf::Vector2f& position);
    void setClicked(bool clicked);
    
    void handleEvent(sf::RenderWindow& window, sf::Event event);
    const bool getClicked() const;
    sf::FloatRect getGlobalBounds() const;
    
private:
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    
protected:
    const Type m_type;
    Button<sf::CircleShape> m_button;
};
