#ifndef Resources_hpp
#define Resources_hpp

#include <SFML/Graphics.hpp>

#include "../UI/GUI/SmartCursor.hpp"

#include <utility>

#include <vector>

#include <iostream>

///< Texture and Image Filepaths
static const std::basic_string<char> __filepath_icon = "resources/img/icon.png";

///< Backgrounds
static const std::string __filepath_backpack_bg_texture   = "resources/img/backgrounds/backpack.png";
static const std::string __filepath_game_over_bg_texture  = "resources/img/backgrounds/game_over.png";
static const std::string __filepath_ground_bg_texture     = "resources/img/backgrounds/ground.png";
static const std::string __filepath_menu_state_bg_texture = "resources/img/backgrounds/menu.png";

///< Caves
static const std::string __filepath_cave_1_texture = "resources/img/caves/1.png";
static const std::string __filepath_cave_2_texture = "resources/img/caves/2.png";
static const std::string __filepath_cave_3_texture = "resources/img/caves/3.png";
static const std::string __filepath_cave_4_texture = "resources/img/caves/4.png";

///< Maps
static const std::string __filepath_map_texture = "resources/img/maps/map.png";

///< Sprites
static const std::string __filepath_center_texture           = "resources/img/sprites/arrow_center.png";
static const std::string __filepath_left_arrow_texture       = "resources/img/sprites/arrow_left.png";
static const std::string __filepath_right_arrow_texture      = "resources/img/sprites/arrow_right.png";
static const std::string __filepath_up_arrow_texture         = "resources/img/sprites/arrow_up.png";
static const std::string __filepath_cave_signs_texture_sheet = "resources/img/sprites/cave_signs_sheet.png";
static const std::string __filepath_down_arrow_texture       = "resources/img/sprites/arrow_down.png";
static const std::string __filepath_icons_texture_sheet      = "resources/img/sprites/icons_sheet.png";

///< Font Filepaths
static const std::basic_string<char> __filepath_Bubble      = "resources/fonts/Bubble.ttf";
static const std::basic_string<char> __filepath_Retro       = "resources/fonts/Retro.ttf";
static const std::basic_string<char> __filepath_Farenheight = "resources/fonts/Farenheight.ttf";
static const std::basic_string<char> __filepath_TNR         = "resources/fonts/TNR.otf";
static const std::basic_string<char> __filepath_Zorque      = "resources/fonts/Zorque.otf";

///< Icon Load Function
static const sf::Image __load_icon() {
    static sf::Image icon;
    assert((void("Loading : "+__filepath_icon), icon.loadFromFile(__filepath_icon)));
    return icon;
}
///< Font Load Functions
static const sf::Font __init_Bubble() {
    static sf::Font font;
    assert((void("Init : "+__filepath_Bubble), font.loadFromFile(__filepath_Bubble)));
    return font;
}
static const sf::Font __init_Retro() {
    static sf::Font font;
    assert((void("Init : "+__filepath_Retro), font.loadFromFile(__filepath_Retro)));
    return font;
}
static const sf::Font __init_Farenheight() {
    static sf::Font font;
    assert((void("Init : "+__filepath_Farenheight), font.loadFromFile(__filepath_Farenheight)));
    return font;
}
static const sf::Font __init_TNR() {
    static sf::Font font;
    assert((void("Init : "+__filepath_TNR), font.loadFromFile(__filepath_TNR)));
    return font;
}
static const sf::Font __init_Zorque() {
    static sf::Font font;
    assert((void("Init : "+__filepath_Zorque), font.loadFromFile(__filepath_Zorque)));
    return font;
}

///< Backgrounds
static sf::Texture __load_backpack_bg_texture() {
    static sf::Texture texture;
    assert((void("Init : "+__filepath_backpack_bg_texture),
            texture.loadFromFile(__filepath_backpack_bg_texture)));
    return texture;
}
static sf::Texture __load_game_over_bg_texture() {
    static sf::Texture texture;
    assert((void("Init : "+__filepath_game_over_bg_texture),
            texture.loadFromFile(__filepath_game_over_bg_texture)));
    return texture;
}
static sf::Texture __load_ground_bg_texture() {
    static sf::Texture texture;
    assert((void("Init : "+__filepath_ground_bg_texture),
            texture.loadFromFile(__filepath_ground_bg_texture)));
    return texture;
}
static sf::Texture __load_menu_state_bg_texture() {
    static sf::Texture texture;
    assert((void("Init : "+__filepath_menu_state_bg_texture),
            texture.loadFromFile(__filepath_menu_state_bg_texture)));
    return texture;
}

///< Caves
static sf::Texture __load_cave_1_texture() {
    static sf::Texture texture;
    assert((void("Init : "+__filepath_cave_1_texture),
            texture.loadFromFile(__filepath_cave_1_texture)));
    return texture;
}
static sf::Texture __load_cave_2_texture() {
    static sf::Texture texture;
    assert((void("Init : "+__filepath_cave_2_texture),
            texture.loadFromFile(__filepath_cave_2_texture)));
    return texture;
}
static sf::Texture __load_cave_3_texture() {
    static sf::Texture texture;
    assert((void("Init : "+__filepath_cave_3_texture),
            texture.loadFromFile(__filepath_cave_3_texture)));
    return texture;
}
static sf::Texture __load_cave_4_texture() {
    static sf::Texture texture;
    assert((void("Init : "+__filepath_cave_4_texture),
            texture.loadFromFile(__filepath_cave_4_texture)));
    return texture;
}

///< Maps
static sf::Texture __load_map_texture() {
    static sf::Texture texture;
    assert((void("Init : "+__filepath_map_texture),
            texture.loadFromFile(__filepath_map_texture)));
    return texture;
}

///< Sprites
static sf::Texture __load_center_texture() {
    static sf::Texture texture;
    assert((void("Init : "+__filepath_center_texture),
            texture.loadFromFile(__filepath_center_texture)));
    return texture;
}
static sf::Texture __load_left_arrow_texture() {
    static sf::Texture texture;
    assert((void("Init : "+__filepath_left_arrow_texture),
            texture.loadFromFile(__filepath_left_arrow_texture)));
    return texture;
}
static sf::Texture __load_right_arrow_texture() {
    static sf::Texture texture;
    assert((void("Init : "+__filepath_right_arrow_texture),
            texture.loadFromFile(__filepath_right_arrow_texture)));
    return texture;
}
static sf::Texture __load_up_arrow_texture() {
    static sf::Texture texture;
    assert((void("Init : "+__filepath_up_arrow_texture),
            texture.loadFromFile(__filepath_up_arrow_texture)));
    return texture;
}
static sf::Texture __load_cave_signs_texture_sheet() {
    static sf::Texture texture;
    assert((void("Init : "+__filepath_cave_signs_texture_sheet),
            texture.loadFromFile(__filepath_cave_signs_texture_sheet)));
    return texture;
}
static sf::Texture __load_down_arrow_texture() {
    static sf::Texture texture;
    assert((void("Init : "+__filepath_down_arrow_texture),
            texture.loadFromFile(__filepath_down_arrow_texture)));
    return texture;
}
static sf::Texture __load_icons_texture_sheet() {
    static sf::Texture texture;
    assert((void("Init : "+__filepath_icons_texture_sheet),
            texture.loadFromFile(__filepath_icons_texture_sheet)));
    return texture;
}

static const sf::Texture backpack_bg_texture      = __load_backpack_bg_texture();
static const sf::Texture game_over_bg_texture     = __load_game_over_bg_texture();
static const sf::Texture ground_bg_texture        = __load_ground_bg_texture();
static const sf::Texture menu_state_bg_texture    = __load_menu_state_bg_texture();
static const sf::Texture map_texture              = __load_map_texture();
static const sf::Texture cave_signs_texture_sheet = __load_cave_signs_texture_sheet();
static const sf::Texture cave_1_texture           = __load_cave_1_texture();
static const sf::Texture cave_2_texture           = __load_cave_2_texture();
static const sf::Texture cave_3_texture           = __load_cave_3_texture();
static const sf::Texture cave_4_texture           = __load_cave_4_texture();
static const sf::Texture center_texture           = __load_center_texture();
static const sf::Texture left_arrow_texture       = __load_left_arrow_texture();
static const sf::Texture right_arrow_texture      = __load_right_arrow_texture();
static const sf::Texture up_arrow_texture         = __load_up_arrow_texture();
static const sf::Texture down_arrow_texture       = __load_down_arrow_texture();
static const sf::Texture icons_texture_sheet      = __load_icons_texture_sheet();

namespace Font
{
//const auto SpaceGrotesk = std::string{ "SpaceGrotesk" };
}

namespace Texture
{
//const auto Explosion = std::string{ "Explosion" };
}

struct Resources
{
    ///< Fonts
    static const sf::Font Bubble;
    static const sf::Font Retro;
    static const sf::Font Farenheight;
    static const sf::Font TimesNewRoman;
    static const sf::Font Zorque;
    
    ///< Colors
    static const sf::Color Gray;
    static const sf::Color DarkGreen;
    static const sf::Color DarkRed;
    static const sf::Color DarkPurple;
    static const sf::Color LightBlue;
    static const sf::Color Seafoam;
    static const sf::Color LightGreen;
    static const sf::Color Peach;
    static const sf::Color Tan;
    static const sf::Color Pink;
    static const sf::Color LightPurple;
    static const sf::Color Orange;
    static const sf::Color DarkBlue;
    
    SmartCursor cursor;
};

struct Frame
{
   sf::IntRect rect;
   double duration; // in seconds
};

class Animator
{
private:
    std::vector<Frame> frames;
    std::vector<Frame>::iterator iter;
    double totalLength;
    double totalProgress;
    sf::Sprite *target;
public:
    Animator(sf::Sprite& target)
    {
        this->target = &target;
        totalProgress = 0.0;
    }

    void addFrame(Frame&& frame)
    {
        frames.push_back(std::move(frame));
        totalLength += frame.duration;
    }

    void update(double elapsed, bool makeStop = true)
    {
        totalProgress += elapsed;
        
        if ( makeStop )
        {
            totalProgress = ( totalProgress > totalLength ) ? 0.f : totalProgress;
        }

        double progress = totalProgress;
        for(auto frame : frames)
        {
            progress -= (frame).duration;
            
            
            std::cout << progress << std::endl;
             
            if (progress <= 0.0 || &(frame) == &frames.back())
            {
               target->setTextureRect((frame).rect);
               break; // we found our frame
            }
        }
    }
};



#endif /* Resources_hpp */
