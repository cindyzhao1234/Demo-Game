cmake_minimum_required(VERSION 3.16)
project(GameDemo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(2D-Game-Engine)

add_executable(GameDemo
    src/main.cpp
    # src/game/Player.cpp
    # src/game/Villager.cpp
    # src/game/Mailbox.cpp
    # src/game/DeliveryQuest.cpp
    # src/world/DemoWorld.cpp
    # src/ui/Hud.cpp
)

target_include_directories(GameDemo PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(GameDemo PRIVATE
    GameEngine
)