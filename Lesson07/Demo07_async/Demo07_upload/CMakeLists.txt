# Set Name of project and language
project(01_ThreadDemo LANGUAGES CXX)

# Set cmake version
cmake_minimum_required(VERSION 3.0)

find_package(Threads)

# Create executable using the specified source files
add_executable(${PROJECT_NAME} main6.cpp
    main1.cpp
    main2.cpp
    main3.cpp
    main4.cpp
    main5.cpp)

# Define required c++ standard to C++11
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

target_link_libraries(${PROJECT_NAME} PRIVATE Threads::Threads)

# set build type to Debug/Release
set(CMAKE_BUILD_TYPE "Debug")

# Set compile options, enable warnings
target_compile_options(${PROJECT_NAME} PRIVATE
$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:GNU>>: -Wall>
$<$<CXX_COMPILER_ID:MSVC>: /W3>
)


