#include "PlayState.hpp"

#include "MenuState.hpp"

#include "../Core/Resources.hpp"

#include "../Core/rng.hpp"

#include <iostream>

PlayState::PlayState(sf::RenderWindow& window, Resources& resources)
    : State{ window, resources }
    , m_mouse_button_released{ false }
    , m_alpha{ 0, 0, 0, 255 } // Start off opaque
    , m_fade_in{ true }
    , m_fade_out{ false }
    , m_map{ s_planar_dodecahedron_edges, s_planar_dodecahedron_vertex_count }
    , m_backpack{ }
    , m_show_map{ false }
    , m_show_backpack{ false }
    , m_show_crosshair{ false }
    , m_turn_left{ false }
    , m_turn_right{ false }
    , m_move_forward{ false }
    , m_look_down{ false }
    , m_game_over{ false }
    , m_backpack_icon{ Icon::Type::Backpack }
    , m_map_icon{ Icon::Type::Map }
    , m_crosshair_icon{ Icon::Type::Crosshair }
{
    const auto window_size = sf::Vector2f{ m_window.getSize() };
            
    m_background.setSize(window_size);
    m_background.setPosition(0.f, 0.f);
    
    m_game_over_screen.setSize(window_size);
    m_game_over_screen.setPosition(0.f, 0.f);
    m_game_over_screen.setTexture(&game_over_bg_texture);
    
    // Fill the fader surface with black
    m_fader.setFillColor(m_alpha);
    m_fader.setSize(window_size);
    
    assert(m_cave_sound_buffer.loadFromFile("resources/sounds/cave.wav"));
    m_cave_sound.setBuffer(m_cave_sound_buffer);
    m_cave_sound.setLoop(true);
    m_cave_sound.play();
    
    m_caves.resize( m_map.size() + 1);
    
    m_num_cave_positioned = random_ranged_uint(1, m_map.size());
    
    unsigned int count = 0;
    for (auto &edge : m_map.edges())
    {
        if (edge.src == m_num_cave_positioned)
        {
            //std::cout << edge.src << " leads to " << edge.dest << std::endl;
            switch (count)
            {
                case 0:
                    m_num_cave_viewing = edge.dest;
                    count++;
                    break;
                case 1:
                    m_num_cave_left = edge.dest;
                    count++;
                    break;
                case 2:
                    m_num_cave_right = edge.dest;
                    count++;
                    break;
                default:
                    break;
            }
        }
    }
    
    m_num_cave_pit = random_ranged_uint(1, m_map.size());
    
    while (m_num_cave_pit == m_num_cave_positioned)
        m_num_cave_pit = random_ranged_uint(1, m_map.size());
    
    m_num_cave_basilisk = random_ranged_uint(1, m_map.size());
    
    while (m_num_cave_basilisk == m_num_cave_positioned || m_num_cave_basilisk == m_num_cave_pit)
        m_num_cave_basilisk = random_ranged_uint(1, m_map.size());
    
    std::cout << "Pit: " << m_num_cave_pit << std::endl;
    std::cout << "Basilisk: " << m_num_cave_basilisk << std::endl;
    
    //std::cout << "In:      " << m_num_cave_positioned << std::endl;
    //std::cout << "Viewing: " << m_num_cave_viewing    << std::endl;
    //std::cout << "Left:    " << m_num_cave_left       << std::endl;
    //std::cout << "Right:   " << m_num_cave_right      << std::endl;
    
    m_cave_sign.setSize({128.f, 64.f});
    m_cave_sign.setPosition((window_size.x/2.f)-(m_cave_sign.getGlobalBounds().width/2.f), 0.f);
    m_cave_sign.setTexture(&cave_signs_texture_sheet);
    
    m_backpack_icon.setPosition({20.f, 10.f});
    m_crosshair_icon.setPosition({20.f, 94.f});
    m_map_icon.setPosition({20.f, 178.f});
    
    updateCaveSignTextureRect();
    scanNeighborCaves();
}

void PlayState::processEvents()
{
    for (auto event = sf::Event{}; m_window.pollEvent(event);)
    {
        m_backpack_icon.handleEvent(m_window, event);
        m_crosshair_icon.handleEvent(m_window, event);
        m_map_icon.handleEvent(m_window, event);
        
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
            
            ///< DPAD Movement
            if (m_dpad.mouseOverLeft(m_current_mouse_position))
            {
                m_fade_out = true;
                m_fade_in = false;
                
                m_turn_left = true;
            }
            if (m_dpad.mouseOverRight(m_current_mouse_position))
            {
                m_fade_out = true;
                m_fade_in = false;
                
                m_turn_right = true;
            }
            if (m_dpad.mouseOverUp(m_current_mouse_position))
            {
                m_fade_out = true;
                m_fade_in = false;
                
                m_move_forward = true;
            }
            if (m_dpad.mouseOverDown(m_current_mouse_position))
            {
                m_fade_out = true;
                m_fade_in = false;
                
                m_look_down = true;
            }
            
            if ( m_crosshair_icon.getClicked() )
            {
                setCrosshairCursor(true);
                m_show_crosshair = true;
            }
            else
            {
                setCrosshairCursor(false);
                m_show_crosshair = false;
            }
        }
        else if (event.type == sf::Event::KeyPressed && !m_fade_out)
        {
            if ( m_game_over )
                m_next = std::make_unique<MenuState>(m_window, m_resources);
            
            ///< Arrow Key Movement
            if (event.key.code == sf::Keyboard::Key::Left)
            {
                m_fade_out = true;
                m_fade_in = false;
                
                m_turn_left = true;
            }
            else if (event.key.code == sf::Keyboard::Key::Right)
            {
                m_fade_out = true;
                m_fade_in = false;
                
                m_turn_right = true;
            }
            else if (event.key.code == sf::Keyboard::Key::Up)
            {
                m_fade_out = true;
                m_fade_in = false;
                
                m_move_forward = true;
            }
            else if (event.key.code == sf::Keyboard::Key::Down)
            {
                m_fade_out = true;
                m_fade_in = false;
                
                m_look_down = true;
            }
            else if (event.key.code == sf::Keyboard::Key::M)
            {
                m_map_icon.setClicked( !m_map_icon.getClicked() );
            }
            else if (event.key.code == sf::Keyboard::Key::B)
            {
                m_backpack_icon.setClicked( !m_backpack_icon.getClicked() );
            }
        }
    }
    
    ///< Check status of icons
    if ( m_backpack_icon.getClicked() )
    {
        m_show_backpack = true;
        
        m_map_icon.setClicked(false);
    }
    else
    {
        m_show_backpack = false;
    }
    
    if ( m_map_icon.getClicked() )
    {
        m_show_map = true;
        
        m_backpack_icon.setClicked(false);
    }
    else
    {
        m_show_map = false;
    }
}

void PlayState::update(const sf::Time delta_time)
{
    processEvents();
    
    
    m_dpad.update(m_current_mouse_position);
    
    if (m_fade_in)
    {
        if (m_alpha.a != 150)
            m_alpha.a--;
    }
    if (m_fade_out)
    {
        if (m_alpha.a != 255)
            m_alpha.a++;
    }
    if (m_alpha.a == 255)
    {
        m_fade_out = false;
        m_fade_in = true;
        
        if (m_turn_left)
        {
            unsigned temp = m_num_cave_viewing;
            m_num_cave_viewing = m_num_cave_left;
            m_num_cave_left    = m_num_cave_right;
            m_num_cave_right   = temp;
        }
        else if (m_turn_right)
        {
            unsigned temp = m_num_cave_viewing;
            m_num_cave_viewing = m_num_cave_right;
            m_num_cave_right   = m_num_cave_left;
            m_num_cave_left    = temp;
        }
        else if (m_move_forward)
        {
            if ( m_player.getLookingDown() )
            {
                m_caves[m_num_cave_viewing].setShowingGround( !m_caves[ m_num_cave_viewing ].getShowingGround() );
                m_player.setLookingDown(false);
            }
            else
            {
                m_num_cave_positioned = m_num_cave_viewing;
                
                ///< Moved into Pit (GAME OVER)
                if ( m_num_cave_positioned == m_num_cave_pit )
                {
                    m_fade_in = false;
                    m_game_over = true;
                    
                    playFallWithImpactSound();
                }
                ///< Moved into Basilisk (GAME OVER)
                if ( m_num_cave_positioned == m_num_cave_basilisk )
                {
                    m_fade_in = false;
                    m_game_over = true;
                    
                    playBasiliskAttackSound();
                }
                
                unsigned int count = 0;
                for (auto &edge : m_map.edges())
                {
                    if (edge.src == m_num_cave_positioned)
                    {
                        //std::cout << edge.src << " leads to " << edge.dest << std::endl;
                        switch (count)
                        {
                            case 0:
                                m_num_cave_viewing = edge.dest;
                                count++;
                                break;
                            case 1:
                                m_num_cave_left = edge.dest;
                                count++;
                                break;
                            case 2:
                                m_num_cave_right = edge.dest;
                                count++;
                                break;
                            default:
                                break;
                        }
                    }
                }
                
                ///< Only scan neighbor caves if a move has been made
                scanNeighborCaves();
            }
        }
        else if (m_look_down)
        {
            m_caves[m_num_cave_viewing].setShowingGround( !m_caves[ m_num_cave_viewing ].getShowingGround() );
            m_player.setLookingDown(true);
        }
        
        //std::cout << "In:      " << m_num_cave_positioned << std::endl;
        //std::cout << "Viewing: " << m_num_cave_viewing    << std::endl;
        //std::cout << "Left:    " << m_num_cave_left       << std::endl;
        //std::cout << "Right:   " << m_num_cave_right      << std::endl;

        m_turn_left = false;
        m_turn_right = false;
        m_move_forward = false;
        m_look_down = false;
        
        updateCaveSignTextureRect();
    }
    
    m_fader.setFillColor(m_alpha);
}

void PlayState::render()
{
    m_window.clear();
    
    m_window.draw(m_background);
    
    m_window.draw(m_caves[ m_num_cave_viewing ]);
    
    m_window.draw(m_cave_sign);
    
    m_window.draw(m_dpad);
    
    m_window.draw(m_backpack_icon);
    m_window.draw(m_crosshair_icon);
    m_window.draw(m_map_icon);
    
    if (m_show_backpack)
        m_window.draw(m_backpack);
    if (m_show_map)
        m_window.draw(m_map);
    
    if (m_game_over)
        m_window.draw(m_game_over_screen);
    
    ///< No need to draw if it's transparent
    if (m_alpha.a != 0)
        m_window.draw(m_fader);
    
    m_window.display();
}

void PlayState::updateCaveSignTextureRect()
{
    m_cave_sign.setTextureRect((sf::IntRect((m_num_cave_viewing-1)*128, 0, 128, 64)));
}

void PlayState::scanNeighborCaves()
{
    ///< Scan for Pit
    for (auto &edge : m_map.edges())
    {
        if (edge.src == m_num_cave_positioned)
        {
            if (edge.dest == m_num_cave_pit)
            {
                playPebbleFallingSound();
                break;
            }
        }
        else if (edge.src > m_num_cave_positioned)
        {
            stopPebbleFallingSound();
            break;
        }
    }
    
    ///< Scan for Basilisk
    for (auto &edge : m_map.edges())
    {
        if (edge.src == m_num_cave_positioned)
        {
            if (edge.dest == m_num_cave_basilisk)
            {
                playBasiliskBreathingSound();
                break;
            }
        }
        else if (edge.src > m_num_cave_positioned)
        {
            stopBasiliskBreathingSound();
            break;
        }
    }
}

void PlayState::setCrosshairCursor(bool enabled)
{
    if (enabled)
        m_resources.cursor.setCrosshairCursor();
    else
        m_window.setMouseCursor(m_resources.cursor.Hand);
}

void PlayState::playPebbleFallingSound()
{
    assert(m_pebble_falling_buffer.loadFromFile("resources/sounds/pebble_falling.wav"));
    m_pebble_falling_sound.setBuffer(m_pebble_falling_buffer);
    m_pebble_falling_sound.setLoop(true);
    m_pebble_falling_sound.setVolume(5.f);
    m_pebble_falling_sound.play();
}
void PlayState::stopPebbleFallingSound()
{
    m_pebble_falling_sound.stop();
}

void PlayState::playBasiliskBreathingSound()
{
    assert(m_basilisk_breathing_sound_buffer.loadFromFile("resources/sounds/basilisk_breathing.wav"));
    m_basilisk_breathing_sound.setBuffer(m_basilisk_breathing_sound_buffer);
    m_basilisk_breathing_sound.setLoop(true);
    m_basilisk_breathing_sound.setVolume(1.f);
    m_basilisk_breathing_sound.play();
}
void PlayState::stopBasiliskBreathingSound()
{
    m_basilisk_breathing_sound.stop();
}

void PlayState::playFallWithImpactSound()
{
    assert(m_fall_with_impact_buffer.loadFromFile("resources/sounds/fall_with_impact.ogg"));
    m_fall_with_impact_sound.setBuffer(m_fall_with_impact_buffer);
    m_fall_with_impact_sound.setLoop(false);
    m_fall_with_impact_sound.setVolume(20.f);
    m_fall_with_impact_sound.play();
}

void PlayState::playBasiliskAttackSound()
{
    assert(m_basilisk_attack_sound_buffer.loadFromFile("resources/sounds/basilisk_attack.wav"));
    m_basilisk_attack_sound.setBuffer(m_basilisk_attack_sound_buffer);
    m_basilisk_attack_sound.setLoop(false);
    m_basilisk_attack_sound.setVolume(20.f);
    m_basilisk_attack_sound.play();
}

