cmake_minimum_required(VERSION 3.17)
project(Space_Wars)

set(CMAKE_CXX_STANDARD 17)
set(SFML_DIR ${PROJECT_SOURCE_DIR}/SFML-2.5.1)
find_package(SFML 2.5 COMPONENTS graphics audio PATHS ${SFML_DIR} REQUIRED)

include_directories(includes)

set(SOURCES
        main.cpp includes/Game.hpp src/Game.cpp includes/Settings.hpp includes/Player.hpp src/Player.cpp
        includes/IDrawable.hpp includes/Bullet.hpp src/Bullet.cpp includes/IGun.hpp includes/StockGun.hpp
        src/StockGun.cpp
        includes/IBulletBuilder.hpp)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-audio)