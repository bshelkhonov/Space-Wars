cmake_minimum_required(VERSION 3.17)
project(Space_Wars)

set(CMAKE_CXX_STANDARD 17)
set(SFML_DIR ${PROJECT_SOURCE_DIR}/SFML-2.5.1)
find_package(SFML 2.5 COMPONENTS graphics audio PATHS ${SFML_DIR} REQUIRED)

include_directories(includes)

set(SOURCES
        main.cpp includes/Game.hpp src/Game.cpp includes/Settings.hpp includes/SpaceShip.hpp src/SpaceShip.cpp
        includes/IDrawable.hpp includes/Bullet.hpp src/Bullet.cpp includes/Gun.hpp
        includes/ICartridgeBuilder.hpp includes/PlayerCartridgeBuilder.hpp src/ICartridgeBuilder.cpp src/PlayerCartridgeBuilder.cpp src/Gun.cpp includes/IObjectMover.hpp)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-audio)