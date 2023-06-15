#include "Application.hpp"

#include "../State/MenuState.hpp"

#include <memory>

Application::Application()
    : m_window{ { 640, 480 }, "Cave Explorer", sf::Style::Default, sf::ContextSettings{ 0, 0, 8 } }
{
    m_window.setVerticalSyncEnabled(true);
}

void Application::run()
{
    loadResources();

    // Simple state machine
    std::unique_ptr<State> state = std::make_unique<MenuState>(m_window, m_resources);

    while (state != nullptr)
    {
        state = state->run();
    }
}

void Application::loadResources()
{
    //__init_Bubble();
    //__init_Retro();
    //__init_Farenheight();
    //__init_TNR();
    //__init_Zorque();
    
    ///< Create SmartCursor
    m_resources.cursor.create(&m_window);
    
    // Set active cursor
    m_window.setMouseCursor(m_resources.cursor.Hand);
}
