cmake_minimum_required(VERSION 3.17)
project(Space_Wars)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -Wextra")

set(SFML_DIR ${PROJECT_SOURCE_DIR}/SFML-2.5.1)

find_package(SFML 2.5 COMPONENTS graphics audio PATHS ${SFML_DIR} REQUIRED)

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
        ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
        EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include")
endif()


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
target_link_libraries(RunTest sfml-graphics sfml-audio gtest_main)