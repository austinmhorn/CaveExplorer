#include "Icon.hpp"

#include "../../Core/Resources.hpp"

Icon::Icon(const Icon::Type type)
    : m_type{type}
    , m_button{ sf::CircleShape{32.f}, sf::Text{"", Resources::Zorque, 30} }
{
    m_button.setTexture(&icons_texture_sheet);
    m_button.setTextureRect(sf::IntRect(0.f, static_cast<unsigned>(m_type)*64.f, 64.f, 64.f));
}

void Icon::setPosition(const sf::Vector2f& position)
{
    m_button.setPosition(position);
}
void Icon::setClicked(bool clicked)
{
    m_button.setClicked(clicked);
}

void Icon::handleEvent(sf::RenderWindow& window, sf::Event event)
{
    m_button.handleEvent(window, event);
}
const bool Icon::getClicked() const
{
    return m_button.getClicked();
}
sf::FloatRect Icon::getGlobalBounds() const
{
    return m_button.getGlobalBounds();
}

void Icon::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_button);
}
