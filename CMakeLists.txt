cmake_minimum_required(VERSION 3.11)
project(Space_Wars)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -Wextra")


# Download and unpack googletest at configure time
configure_file(gtest_install.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download)
if (result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif ()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download)
if (result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif ()


# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
        ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
        EXCLUDE_FROM_ALL)


configure_file(sfml_install.in sfml-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/sfml-download)

if (result)
    message(FATAL_ERROR "CMake step for sfml failed: ${result}")
endif ()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/sfml-download)
if (result)
    message(FATAL_ERROR "Build step for sfml failed: ${result}")
endif ()


set(sfml_force_shared_crt ON CACHE BOOL "" FORCE)

set(SFML_DIR ${CMAKE_CURRENT_BINARY_DIR}/sfml-build)
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/sfml-src
        ${CMAKE_CURRENT_BINARY_DIR}/sfml-build
        EXCLUDE_FROM_ALL)


include_directories(includes)

set(SOURCES
        includes/Game.hpp src/Game.cpp includes/Settings.hpp includes/Spaceship.hpp src/Spaceship.cpp
        includes/IDrawable.hpp includes/Bullet.hpp src/Bullet.cpp
        includes/ICartridgeBuilder.hpp includes/StockPlayerCartridgeBuilder.hpp src/ICartridgeBuilder.cpp
        src/StockPlayerCartridgeBuilder.cpp includes/IObjectMover.hpp includes/PlayerMover.hpp src/PlayerMover.cpp
        includes/PlayerGun.hpp includes/IGun.hpp src/PlayerGun.cpp includes/PlayerSpaceship.hpp src/PlayerSpaceship.cpp
        includes/Background.hpp src/Background.cpp includes/BulletMover.hpp src/BulletMover.cpp
        includes/EnemyCreator.hpp src/EnemyCreator includes/EnemiesContainer.hpp src/EnemiesContainer.cpp
        src/EnemyMover.cpp includes/EnemyMover.hpp includes/Randomizer.hpp src/Randomizer.cpp)

add_executable(${PROJECT_NAME} main.cpp ${SOURCES})
add_executable(RunTest ${SOURCES} tests/RunTest.cpp tests/TestIDrawables.hpp)

target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-audio)
target_link_libraries(RunTest sfml-graphics sfml-audio gtest_main)