# Set cmake version
cmake_minimum_required(VERSION 3.0)

# Set Name of project and language
project(project LANGUAGES CXX)

# Declare and find qt library
find_package(Qt5 COMPONENTS Widgets PrintSupport REQUIRED)


# Qt specific flags
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

#TODO: Set the path to your Cinder directory
set(CINDER_PATH ~/Cinder)
include("${CINDER_PATH}/proj/cmake/modules/cinderMakeApp.cmake")


# set build type to Debug/Release
set(CMAKE_BUILD_TYPE "Debug")


# Create executable using the specified src
add_executable(${PROJECT_NAME} src/main.cpp src/ui/widget.h src/ui/widget.cpp src/ui/widget.ui
src/game/gameOfLife.h src/game/gameOfLife.cpp
src/game/pattern.h
src/game/gamefactory.h src/game/gamefactory.cpp
src/game/Blinkergame.cpp src/game/BlinkerGame.h
src/ui/quadraticWidget.h
src/game/iGameOfLife.h
src/game/SpaceshipGame.cpp src/game/SpaceshipGame.h
src/game/RandomGame.h src/game/RandomGame.cpp
src/game/StaticGame.h src/game/StaticGame.cpp
src/game/MethuselahGame.h src/game/MethuselahGame.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE src src/ui src/game )

target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Widgets Qt5::PrintSupport)

# Define required c++ standard to C++11
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

# Set compile options, enable warnings
target_compile_options(${PROJECT_NAME} PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:GNU>>: -Wall>
    $<$<CXX_COMPILER_ID:MSVC>: /W3>
)




