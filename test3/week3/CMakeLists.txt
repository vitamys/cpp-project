# Set cmake version
cmake_minimum_required(VERSION 3.0)

# Set Name of project and language
project(week3 LANGUAGES CXX)

# Declare and find qt library
find_package(Qt5 COMPONENTS Widgets PrintSupport REQUIRED)


# Qt specific flags
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


# set build type to Debug/Release
set(CMAKE_BUILD_TYPE "Debug")


# Create executable using the specified src
add_executable(${PROJECT_NAME} main.cpp src/ui/widget.h src/ui/widget.cpp src/ui/widget.ui
    src/ui/qcustomplot-source/qcustomplot.cpp
    src/ui/qcustomplot-source/qcustomplot.h

    )

target_include_directories(${PROJECT_NAME} PRIVATE src src/ui src/ui/qcustomplot-source)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Widgets Qt5::PrintSupport)

# Define required c++ standard to C++11
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

# Set compile options, enable warnings
target_compile_options(${PROJECT_NAME} PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:GNU>>: -Wall>
    $<$<CXX_COMPILER_ID:MSVC>: /W3>
)


file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/ekg.txt
    DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/ekg.txt)


