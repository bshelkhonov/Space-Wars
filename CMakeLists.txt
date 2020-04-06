cmake_minimum_required(VERSION 3.17)
project(Space_Wars)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -Wextra")

set(SFML_DIR ${PROJECT_SOURCE_DIR}/SFML-2.5.1)

find_package(SFML 2.5 COMPONENTS graphics audio PATHS ${SFML_DIR} REQUIRED)
add_subdirectory(gtest)

include_directories(includes)


set(SOURCES
        includes/Game.hpp src/Game.cpp includes/Settings.hpp includes/Spaceship.hpp src/Spaceship.cpp
        includes/IDrawable.hpp includes/Bullet.hpp src/Bullet.cpp
        includes/ICartridgeBuilder.hpp includes/StockPlayerCartridgeBuilder.hpp src/ICartridgeBuilder.cpp
        src/StockPlayerCartridgeBuilder.cpp includes/IObjectMover.hpp includes/PlayerMover.hpp src/PlayerMover.cpp
        includes/PlayerGun.hpp includes/IGun.hpp src/PlayerGun.cpp includes/PlayerSpaceship.hpp src/PlayerSpaceship.cpp
        includes/Background.hpp src/Background.cpp includes/BulletMover.hpp src/BulletMover.cpp
        includes/EnemyCreator.hpp src/EnemyCreator.cpp)

add_executable(${PROJECT_NAME} main.cpp ${SOURCES})
add_executable(RunTest ${SOURCES} tests/RunTest.cpp tests/TestIDrawables.hpp)

target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-audio)
target_link_libraries(RunTest sfml-graphics sfml-audio gtest)