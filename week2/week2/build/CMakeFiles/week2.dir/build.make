# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lerfme/Documents/cpp/week2/week2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lerfme/Documents/cpp/week2/week2/build

# Include any dependencies generated for this target.
include CMakeFiles/week2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/week2.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/week2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/week2.dir/flags.make

CMakeFiles/week2.dir/main.cpp.o: CMakeFiles/week2.dir/flags.make
CMakeFiles/week2.dir/main.cpp.o: ../main.cpp
CMakeFiles/week2.dir/main.cpp.o: CMakeFiles/week2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lerfme/Documents/cpp/week2/week2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/week2.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/week2.dir/main.cpp.o -MF CMakeFiles/week2.dir/main.cpp.o.d -o CMakeFiles/week2.dir/main.cpp.o -c /home/lerfme/Documents/cpp/week2/week2/main.cpp

CMakeFiles/week2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/week2.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lerfme/Documents/cpp/week2/week2/main.cpp > CMakeFiles/week2.dir/main.cpp.i

CMakeFiles/week2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/week2.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lerfme/Documents/cpp/week2/week2/main.cpp -o CMakeFiles/week2.dir/main.cpp.s

CMakeFiles/week2.dir/src/billionaire.cpp.o: CMakeFiles/week2.dir/flags.make
CMakeFiles/week2.dir/src/billionaire.cpp.o: ../src/billionaire.cpp
CMakeFiles/week2.dir/src/billionaire.cpp.o: CMakeFiles/week2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lerfme/Documents/cpp/week2/week2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/week2.dir/src/billionaire.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/week2.dir/src/billionaire.cpp.o -MF CMakeFiles/week2.dir/src/billionaire.cpp.o.d -o CMakeFiles/week2.dir/src/billionaire.cpp.o -c /home/lerfme/Documents/cpp/week2/week2/src/billionaire.cpp

CMakeFiles/week2.dir/src/billionaire.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/week2.dir/src/billionaire.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lerfme/Documents/cpp/week2/week2/src/billionaire.cpp > CMakeFiles/week2.dir/src/billionaire.cpp.i

CMakeFiles/week2.dir/src/billionaire.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/week2.dir/src/billionaire.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lerfme/Documents/cpp/week2/week2/src/billionaire.cpp -o CMakeFiles/week2.dir/src/billionaire.cpp.s

# Object files for target week2
week2_OBJECTS = \
"CMakeFiles/week2.dir/main.cpp.o" \
"CMakeFiles/week2.dir/src/billionaire.cpp.o"

# External object files for target week2
week2_EXTERNAL_OBJECTS =

week2: CMakeFiles/week2.dir/main.cpp.o
week2: CMakeFiles/week2.dir/src/billionaire.cpp.o
week2: CMakeFiles/week2.dir/build.make
week2: CMakeFiles/week2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lerfme/Documents/cpp/week2/week2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable week2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/week2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/week2.dir/build: week2
.PHONY : CMakeFiles/week2.dir/build

CMakeFiles/week2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/week2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/week2.dir/clean

CMakeFiles/week2.dir/depend:
	cd /home/lerfme/Documents/cpp/week2/week2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lerfme/Documents/cpp/week2/week2 /home/lerfme/Documents/cpp/week2/week2 /home/lerfme/Documents/cpp/week2/week2/build /home/lerfme/Documents/cpp/week2/week2/build /home/lerfme/Documents/cpp/week2/week2/build/CMakeFiles/week2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/week2.dir/depend

