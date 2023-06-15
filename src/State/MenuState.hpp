#pragma once

#include "Base/State.hpp"

#include "../UI/GUI/Elements/Button/Base/Button.hpp"

struct Resources;

class MenuState final : public State
{
public:
    explicit MenuState(sf::RenderWindow& window, Resources& resources);

private:
    void processEvents() override;
    void update(sf::Time delta_time) override;
    void render() override;
    
    sf::Vector2f m_current_mouse_position;
    bool m_mouse_button_released;
    
    sf::RectangleShape m_fader;
    sf::Color m_alpha;
    sf::RectangleShape m_background;
    sf::Text m_title;
    
    StadiumButton m_start;
    StadiumButton m_options;
    StadiumButton m_quit;
};
