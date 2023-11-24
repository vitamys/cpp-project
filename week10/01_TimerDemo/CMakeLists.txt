# Set Name of project and language
project(Timer LANGUAGES CXX)

# Set cmake version
cmake_minimum_required(VERSION 3.10)

# set build type to Debug/Release
set(CMAKE_BUILD_TYPE "Debug")

find_package(Threads REQUIRED)

# Create executable using the specified src
add_executable(${PROJECT_NAME} main.cpp
    timer.cpp
    timer.h
    eventloop.cpp
    eventloop.h
    timerCallback.h
    )

target_link_libraries(${PROJECT_NAME} PRIVATE Threads::Threads)

# Define required c++ standard to C++11
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_11)

# Set compile options, enable warnings
target_compile_options(${PROJECT_NAME} PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:GNU>>: -Wall>
    $<$<CXX_COMPILER_ID:MSVC>: /W3>
)

