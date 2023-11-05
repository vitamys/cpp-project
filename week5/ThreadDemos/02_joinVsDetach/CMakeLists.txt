# Set Name of project and language
project(02_JoinVsDetach LANGUAGES CXX)

# Set cmake version
cmake_minimum_required(VERSION 3.0)

find_package(Threads REQUIRED)

# Create executable using the specified source files
add_executable(${PROJECT_NAME} main.cpp)

# link libraries
target_link_libraries(${PROJECT_NAME} PRIVATE Threads::Threads)

# Define required c++ standard to C++11
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_14)

# set build type to Debug/Release
set(CMAKE_BUILD_TYPE "Debug")

# Set compile options, enable warnings
target_compile_options(${PROJECT_NAME} PRIVATE
$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:GNU>>: -Wall>
$<$<CXX_COMPILER_ID:MSVC>: /W3>
)


