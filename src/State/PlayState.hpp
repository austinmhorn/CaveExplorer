#pragma once

#include "Base/State.hpp"

#include "../State/Cave.hpp"

#include "../Core/Map.hpp"

#include "../UI/GUI/Backpack.hpp"

#include "../UI/GUI/DPAD.hpp"

#include "../UI/GUI/Icon.hpp"

#include "../UI/GUI/SmartCursor.hpp"

#include <SFML/Audio.hpp>

struct Resources;

class PlayState final : public State
{
public:
    explicit PlayState(sf::RenderWindow& window, Resources& resources);

private:
    void processEvents() override;
    void update(sf::Time delta_time) override;
    void render() override;
    
    void updateCaveSignTextureRect();
    void scanNeighborCaves();
    void setCrosshairCursor(bool enabled);
    
    void playPebbleFallingSound();
    void stopPebbleFallingSound();
    void playBasiliskBreathingSound();
    void stopBasiliskBreathingSound();
    
    void playFallWithImpactSound();
    void playBasiliskAttackSound();
        
    sf::Vector2f m_current_mouse_position;
    bool m_mouse_button_released;
    
    sf::RectangleShape m_fader;
    sf::Color m_alpha;
    bool m_fade_in;
    bool m_fade_out;
    
    sf::RectangleShape m_background;
    sf::RectangleShape m_game_over_screen;
    
    Map      m_map;
    Backpack m_backpack;
    
    bool m_show_map;
    bool m_show_backpack;
    bool m_show_crosshair;
    
    std::vector<Cave> m_caves;
    unsigned m_num_cave_positioned;
    unsigned m_num_cave_viewing;
    unsigned m_num_cave_left;
    unsigned m_num_cave_right;
    sf::RectangleShape m_cave_sign;
    
    bool m_turn_left;
    bool m_turn_right;
    bool m_move_forward;
    bool m_look_down;
    bool m_game_over;
        
    sf::SoundBuffer m_cave_sound_buffer;
    sf::Sound       m_cave_sound;
    sf::SoundBuffer m_pebble_falling_buffer;
    sf::Sound       m_pebble_falling_sound;
    sf::SoundBuffer m_fall_with_impact_buffer;
    sf::Sound       m_fall_with_impact_sound;
    sf::SoundBuffer m_basilisk_breathing_sound_buffer;
    sf::Sound       m_basilisk_breathing_sound;
    sf::SoundBuffer m_basilisk_attack_sound_buffer;
    sf::Sound       m_basilisk_attack_sound;
    
    unsigned m_num_cave_pit;
    unsigned m_num_cave_basilisk;
    
    DPAD m_dpad;
    
    Icon m_backpack_icon;
    Icon m_map_icon;
    Icon m_crosshair_icon;
};
