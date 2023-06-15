//
//  SmartCursor.hpp
//  War
//
//  Created by Austin Horn on 12/2/22.
//  Copyright © 2022 Austin Horn. All rights reserved.
//

#ifndef SmartCursor_hpp
#define SmartCursor_hpp

#include <iostream>

#include <SFML/Window/Cursor.hpp>
#pragma once
#include <SFML/Window/Export.hpp>
#pragma once
#include <SFML/System/NonCopyable.hpp>
#pragma once
#include <SFML/System/Vector2.hpp>
#pragma once
#include <SFML/System/Clock.hpp>
#pragma once
#include <SFML/Graphics/Sprite.hpp>
#pragma once
#include <SFML/Window/Event.hpp>
#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#pragma once

namespace priv
{
    class CursorImpl;
}

class SmartCursor : public sf::Cursor {
public:
    
    SmartCursor();
    
    void create(sf::RenderWindow* window, sf::Cursor::Type type = sf::Cursor::Type::Arrow);
    
    void setCursor(sf::Cursor::Type type);
    void setWindow(sf::RenderWindow* window);
    void setCrosshairCursor();
    
    const bool& getLmbReleased() const;
    const bool& getRmbReleased() const;
    
    void handleEvent(sf::Event event);
    void grabSprite(sf::Sprite& sprite);
    void dropSprite();
    
    template <typename T>
    void attach(const T&);
    template <typename T>
    void detach(const T&);
    
public:
    
    sf::Cursor Hand;
    sf::Cursor Arrow;
    sf::Cursor Text;
    sf::Cursor Cross;
    sf::Cursor Help;
    sf::Cursor NotAllowed;
    
    ///< Custom Cursors
    sf::Cursor Crosshair;
    
    const void __init_HandCursor();
    const void __init_ArrowCursor();
    const void __init_TextCursor();
    const void __init_CrossCursor();
    const void __init_HelpCursor();
    const void __init_AllCursorTypes();
    
private:
    
    friend class Window;
        
    void assignCursorToWindow();
    
private:
    
    sf::RenderWindow* m_window;
    sf::Sprite*       m_held;
    
    sf::Cursor::Type  m_type;
    sf::Vector2f      m_position;
    bool              m_lmb_released;
    bool              m_rmb_released;
    
};




#endif /* SmartCursor_hpp */
