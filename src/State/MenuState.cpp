#include "MenuState.hpp"

#include <cmath>

#include "PlayState.hpp"

#include "../Core/Resources.hpp"

MenuState::MenuState(sf::RenderWindow& window, Resources& resources)
    : State{ window, resources }
    , m_mouse_button_released{ false }
    , m_alpha{ 0, 0, 0, 255 } // Start off opaque
    , m_start{ sf::StadiumShape{15}, sf::Text{"Start", resources.Zorque, 30} }
    , m_options{ sf::StadiumShape{15}, sf::Text{"Options", resources.Zorque, 30} }
    , m_quit{ sf::StadiumShape{15}, sf::Text{"Quit", resources.Zorque, 30} }
{
    const auto window_size = sf::Vector2f{ window.getSize() };
    
    m_background.setSize(window_size);
    m_background.setPosition(0.f, 0.f);
    m_background.setTexture(&menu_state_bg_texture);
    
    // Fill the fader surface with black
    m_fader.setFillColor(m_alpha);
    m_fader.setSize(window_size);
    
    m_title.setString("Cave Explorer");
    m_title.setFont(resources.Zorque);
    m_title.setOrigin(m_title.getGlobalBounds().width/2, m_title.getGlobalBounds().height/2);
    m_title.setPosition(window_size.x/2.f, window_size.y/4.f);
    
    m_start.setCharacterSize(15.f);
    m_start.setSize({150.f, 30.f});
    m_start.setPosition({(window_size.x/2.f)-(m_start.getGlobalBounds().width/2.f)}, window_size.y/2.5f);
    
    m_options.setCharacterSize(15.f);
    m_options.setSize({150.f, 30.f});
    m_options.setPosition(m_start.getPosition().x, m_start.getPosition().y+50.f);
    
    m_quit.setCharacterSize(15.f);
    m_quit.setSize({150.f, 30.f});
    m_quit.setPosition(m_options.getPosition().x, m_options.getPosition().y+50.f);
}

void MenuState::processEvents()
{
    for (auto event = sf::Event{}; m_window.pollEvent(event);)
    {
        m_start.handleEvent(m_window, event);
        m_quit.handleEvent(m_window, event);
        
        if (event.type == sf::Event::Closed)
        {
            m_window.close();
        }
        else if (event.type == sf::Event::MouseMoved)
        {
            m_current_mouse_position = m_window.mapPixelToCoords({ event.mouseMove.x, event.mouseMove.y });
        }
        else if (event.type == sf::Event::MouseButtonPressed)
        {
            m_mouse_button_released = false;
        }
        else if (event.type == sf::Event::MouseButtonReleased)
        {
            m_current_mouse_position = m_window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
            m_mouse_button_released = true;
        }
    }
}

void MenuState::update(const sf::Time delta_time)
{
    processEvents();
    
    if (m_start.getClicked())
        m_next = std::make_unique<PlayState>(m_window, m_resources);
    else if (m_quit.getClicked())
        m_window.close();
    
    if (m_alpha.a != 0)
        m_alpha.a--;

    m_fader.setFillColor(m_alpha);
}

void MenuState::render()
{
    m_window.clear();

    m_window.draw(m_background);
    m_window.draw(m_title);
    m_window.draw(m_start);
    m_window.draw(m_options);
    m_window.draw(m_quit);
    
    ///< No need to draw if it's transparent
    if (m_alpha.a != 0)
        m_window.draw(m_fader);
    
    m_window.display();
}
