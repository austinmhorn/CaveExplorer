cmake_minimum_required(VERSION 3.15...3.25.2)

project(CaveExplorer
    LANGUAGES CXX)

# CaveExplorer uses C++17 features
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY
    ${PROJECT_SOURCE_DIR})


# CMake options
option(CAVEEXPLORER_STATIC_STD_LIBS "Use statically linked standard/runtime libraries? This option must match the one used for SFML." OFF)

# Append CMake Module path
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

if(NOT BUILD_SHARED_LIBS)
    set(SFML_STATIC_LIBRARIES FALSE)
endif()

# Find SFML
find_package(SFML 2.5.1 COMPONENTS audio graphics system window network REQUIRED)

if(NOT SFML_FOUND)
    message(FATAL_ERROR "SFML couldn't be located!")
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

# Compile target
set(SOURCE_FILES
    "src/main.hpp"
    "src/main.cpp"
    "src/Core/Resources.hpp"
    "src/Core/Resources.cpp"
    "src/Core/Application.hpp"
    "src/Core/Application.cpp"
    "src/Core/Map.hpp"
    "src/Core/Map.cpp"
    "src/Core/rng.hpp"
    "src/Entity/Base/Entity.hpp"
    "src/Entity/Player.hpp"
    "src/Entity/Player.cpp"
    "src/State/Base/State.hpp"
    "src/State/Base/State.cpp"
    "src/State/PlayState.hpp"
    "src/State/PlayState.cpp"
    "src/State/MenuState.hpp"
    "src/State/MenuState.cpp"
    "src/State/Cave.hpp"
    "src/State/Cave.cpp"
    "src/UI/GUI/Backpack.hpp"
    "src/UI/GUI/Backpack.cpp"
    "src/UI/GUI/DPAD.hpp"
    "src/UI/GUI/DPAD.cpp"
    "src/UI/GUI/Icon.hpp"
    "src/UI/GUI/Icon.cpp"
    "src/UI/GUI/ParticleEmitter.hpp"
    "src/UI/GUI/SmartCursor.hpp"
    "src/UI/GUI/SmartCursor.cpp"
    "src/UI/GUI/Shapes/StadiumShape.hpp"
    "src/UI/GUI/Shapes/StadiumShape.cpp"
    "src/UI/GUI/Elements/Button/Base/Button.hpp"
    "src/UI/GUI/Elements/Button/Base/Clickable.hpp"
    "src/UI/GUI/Elements/Button/CircleButton.hpp"
    "src/UI/GUI/Elements/Button/CircleButton.cpp"
    "src/UI/GUI/Elements/Button/RectButton.hpp"
    "src/UI/GUI/Elements/Button/RectButton.cpp"
    "src/UI/GUI/Elements/Button/StadiumButton.hpp"
    "src/UI/GUI/Elements/Button/StadiumButton.cpp"
    "src/UI/GUI/Elements/Toggle.hpp"
    "src/UI/GUI/Elements/Toggle.cpp")
add_executable(CaveExplorer ${SOURCE_FILES})

# Static Runtime
if(CAVEEXPLORER_STATIC_STD_LIBS)
    if(NOT SFML_STATIC_LIBRARIES)
        message("\n-> If you check CAVEEXPLORER_STATIC_STD_LIBS, you also need to check SFML_STATIC_LIBRARIES.")
        message("-> It would lead to multiple runtime environments which results in undefined behavior.\n")
    elseif(WIN32 AND MSVC)
        set_property(TARGET CaveExplorer PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
    elseif(CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        target_link_options(CaveExplorer PRIVATE -static)
    endif()
endif()

# Link libraries
target_link_libraries(CaveExplorer
    "-framework Cocoa"
    "-framework AppKit"
    "-framework CoreData"
    "-framework Foundation"
    sfml-audio
    sfml-graphics
    sfml-system
    sfml-window
    sfml-network)

# Install executable
install(TARGETS CaveExplorer
        RUNTIME DESTINATION .)

# Install game data
install(DIRECTORY bin/
        DESTINATION .)
