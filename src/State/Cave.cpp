#include "Cave.hpp"

#include "../Core/Resources.hpp"

#include "../Core/rng.hpp"

#include <iostream>

Cave::Cave()
    : m_show_ground{ false }
    , m_num_arrows{ 0 }
{
    unsigned rand = random_ranged_uint(1, 4);
    
    switch (rand)
    {
        default:
        case 1: m_cave.setTexture(cave_1_texture); break;
        case 2: m_cave.setTexture(cave_2_texture); break;
        case 3: m_cave.setTexture(cave_3_texture); break;
        case 4: m_cave.setTexture(cave_4_texture); break;
            
    }
    
    m_ground.setTexture(ground_bg_texture);
}
void Cave::insertArrow()
{
    ++m_num_arrows;
}
void Cave::removeArrow()
{
    if (m_num_arrows)
        --m_num_arrows;
}
bool Cave::hasArrow() const
{
    return m_num_arrows;
}
void Cave::setShowingGround(bool show)
{
    m_show_ground = show;
}
bool Cave::getShowingGround() const
{
    return m_show_ground;
}
void Cave::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    if (m_show_ground)
        window.draw(m_ground);
    else
        window.draw(m_cave);
        
}
