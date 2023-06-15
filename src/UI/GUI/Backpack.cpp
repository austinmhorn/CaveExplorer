#include "Backpack.hpp"

#include "../../Core/Resources.hpp"

Backpack::Backpack()
{
    m_rect.setSize({192.f, 192.f});
    m_rect.setPosition({448.f - 20.f, 288.f - 10.f});
    m_rect.setTexture(&backpack_bg_texture);
}

void Backpack::setPosition(const sf::Vector2f& position)
{
    m_rect.setPosition(position);
}

void Backpack::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_rect);
}
