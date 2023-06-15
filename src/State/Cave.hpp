#pragma once

#include <SFML/Graphics.hpp>

class Cave : public sf::Drawable, public sf::Transformable {
public:
    Cave();
    
    void insertArrow();
    void removeArrow();
    
    bool hasArrow() const;
    
    void setShowingGround(bool showGround);
    bool getShowingGround() const;
    
private:
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const override;
private:
    sf::Sprite m_cave;
    sf::Sprite m_ground;
    bool       m_show_ground;
    unsigned   m_num_arrows;
};
