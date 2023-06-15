//
//  SmartCursor.cpp
//  War
//
//  Created by Austin Horn on 12/2/22.
//  Copyright © 2022 Austin Horn. All rights reserved.
//

#include "SmartCursor.hpp"

///< Individual Cursor Init Functions
const void SmartCursor::__init_ArrowCursor() {
    assert((void("Loading : sf::Cursor::Type::Arrow"), SmartCursor::Arrow.loadFromSystem(sf::Cursor::Arrow)));
}
const void SmartCursor::__init_TextCursor() {
    assert((void("Loading : sf::Cursor::Type::Text"), SmartCursor::Text.loadFromSystem(sf::Cursor::Text)));
}
const void SmartCursor::__init_HandCursor() {
    assert((void("Loading : sf::Cursor::Type::Hand"), SmartCursor::Hand.loadFromSystem(sf::Cursor::Hand)));
}
const void SmartCursor::__init_CrossCursor() {
    assert((void("Loading : sf::Cursor::Type::Cross"), SmartCursor::Cross.loadFromSystem(sf::Cursor::Cross)));
}
const void SmartCursor::__init_HelpCursor() {
    assert((void("Loading : sf::Cursor::Type::Help"), SmartCursor::Help.loadFromSystem(sf::Cursor::Help)));
}

///< All Cursors Init Function
const void SmartCursor::__init_AllCursorTypes()
{
    SmartCursor::__init_ArrowCursor();
    SmartCursor::__init_TextCursor();
    SmartCursor::__init_HandCursor();
    SmartCursor::__init_CrossCursor();
    SmartCursor::__init_HelpCursor();
}

SmartCursor::SmartCursor()
    : m_window(nullptr)
    , m_held(nullptr)
    , m_position()
    , m_lmb_released(false)
    , m_rmb_released(false)
{
    sf::Image crosshair_img;
    assert( (void("Loading : resources/img/sprites/crosshair.png"), crosshair_img.loadFromFile("resources/img/sprites/crosshair.png")) );
    assert( (void("Loading : Crosshair Cursor"), Crosshair.loadFromPixels(crosshair_img.getPixelsPtr(), crosshair_img.getSize(), sf::Vector2u(16,16))) );
}

void SmartCursor::create(sf::RenderWindow* window, sf::Cursor::Type type)
{
    setWindow(window);
    setCursor(type);
    assignCursorToWindow();
}

void SmartCursor::setCursor(sf::Cursor::Type type)
{
    m_type = type;
}
void SmartCursor::setWindow(sf::RenderWindow* window)
{
    m_window = window;
}
void SmartCursor::setCrosshairCursor()
{
    m_window->setMouseCursor(Crosshair);
}
void SmartCursor::assignCursorToWindow()
{
    switch (m_type)
    {
        case sf::Cursor::Arrow:      m_window->setMouseCursor(Arrow);      break;
        case sf::Cursor::Text:       m_window->setMouseCursor(Text);       break;
        case sf::Cursor::Hand:       m_window->setMouseCursor(Hand);       break;
        case sf::Cursor::Cross:      m_window->setMouseCursor(Cross);      break;
        case sf::Cursor::Help:       m_window->setMouseCursor(Help);       break;
        case sf::Cursor::NotAllowed: m_window->setMouseCursor(NotAllowed); break;
        default: break;
    }
}
const bool& SmartCursor::getLmbReleased() const
{
    return m_lmb_released;
}
const bool& SmartCursor::getRmbReleased() const
{
    return m_rmb_released;
}


void SmartCursor::handleEvent(sf::Event event)
{
    switch (event.type)
    {
        case sf::Event::MouseButtonPressed:
            if (event.mouseButton.button == sf::Mouse::Button::Left)
                m_lmb_released = false;
            if (event.mouseButton.button == sf::Mouse::Button::Right)
                m_rmb_released = false;
            break;
            
        case sf::Event::MouseButtonReleased:
            if (event.mouseButton.button == sf::Mouse::Button::Left)
                m_lmb_released = true;
            if (event.mouseButton.button == sf::Mouse::Button::Right)
                m_rmb_released = true;
            break;
            
        case sf::Event::MouseMoved:
            if (m_held)
                m_held->setPosition(m_position);
            break;
            
        default: break;
    }
}


template <typename T>
void SmartCursor::attach(const T&)
{
    
}

template <typename T>
void SmartCursor::detach(const T&)
{
    
}

