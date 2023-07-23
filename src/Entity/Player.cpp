#include "Player.hpp"

Player::Player()
    : m_arrows(3)
    , m_lookingDown(false)
{
    
}

void Player::addArrow()
{
    
}
void Player::remArrow()
{

}

void Player::setLookingDown(bool isLookingDown)
{
    m_lookingDown = isLookingDown;
}

bool Player::getLookingDown() const
{
    return m_lookingDown;
}

unsigned Player::getArrowCount() const noexcept
{
    return m_arrows;
}
