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
CMAKE_SOURCE_DIR = /home/lerfme/Documents/cpp/test3/week3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lerfme/Documents/cpp/test3/build-week3-Desktop-Debug

# Include any dependencies generated for this target.
include CMakeFiles/week3.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/week3.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/week3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/week3.dir/flags.make

CMakeFiles/week3.dir/week3_autogen/mocs_compilation.cpp.o: CMakeFiles/week3.dir/flags.make
CMakeFiles/week3.dir/week3_autogen/mocs_compilation.cpp.o: week3_autogen/mocs_compilation.cpp
CMakeFiles/week3.dir/week3_autogen/mocs_compilation.cpp.o: CMakeFiles/week3.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lerfme/Documents/cpp/test3/build-week3-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/week3.dir/week3_autogen/mocs_compilation.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/week3.dir/week3_autogen/mocs_compilation.cpp.o -MF CMakeFiles/week3.dir/week3_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/week3.dir/week3_autogen/mocs_compilation.cpp.o -c /home/lerfme/Documents/cpp/test3/build-week3-Desktop-Debug/week3_autogen/mocs_compilation.cpp

CMakeFiles/week3.dir/week3_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/week3.dir/week3_autogen/mocs_compilation.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lerfme/Documents/cpp/test3/build-week3-Desktop-Debug/week3_autogen/mocs_compilation.cpp > CMakeFiles/week3.dir/week3_autogen/mocs_compilation.cpp.i

CMakeFiles/week3.dir/week3_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/week3.dir/week3_autogen/mocs_compilation.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lerfme/Documents/cpp/test3/build-week3-Desktop-Debug/week3_autogen/mocs_compilation.cpp -o CMakeFiles/week3.dir/week3_autogen/mocs_compilation.cpp.s

CMakeFiles/week3.dir/main.cpp.o: CMakeFiles/week3.dir/flags.make
CMakeFiles/week3.dir/main.cpp.o: /home/lerfme/Documents/cpp/test3/week3/main.cpp
CMakeFiles/week3.dir/main.cpp.o: CMakeFiles/week3.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lerfme/Documents/cpp/test3/build-week3-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/week3.dir/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/week3.dir/main.cpp.o -MF CMakeFiles/week3.dir/main.cpp.o.d -o CMakeFiles/week3.dir/main.cpp.o -c /home/lerfme/Documents/cpp/test3/week3/main.cpp

CMakeFiles/week3.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/week3.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lerfme/Documents/cpp/test3/week3/main.cpp > CMakeFiles/week3.dir/main.cpp.i

CMakeFiles/week3.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/week3.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lerfme/Documents/cpp/test3/week3/main.cpp -o CMakeFiles/week3.dir/main.cpp.s

CMakeFiles/week3.dir/src/ui/widget.cpp.o: CMakeFiles/week3.dir/flags.make
CMakeFiles/week3.dir/src/ui/widget.cpp.o: /home/lerfme/Documents/cpp/test3/week3/src/ui/widget.cpp
CMakeFiles/week3.dir/src/ui/widget.cpp.o: CMakeFiles/week3.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lerfme/Documents/cpp/test3/build-week3-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/week3.dir/src/ui/widget.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/week3.dir/src/ui/widget.cpp.o -MF CMakeFiles/week3.dir/src/ui/widget.cpp.o.d -o CMakeFiles/week3.dir/src/ui/widget.cpp.o -c /home/lerfme/Documents/cpp/test3/week3/src/ui/widget.cpp

CMakeFiles/week3.dir/src/ui/widget.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/week3.dir/src/ui/widget.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lerfme/Documents/cpp/test3/week3/src/ui/widget.cpp > CMakeFiles/week3.dir/src/ui/widget.cpp.i

CMakeFiles/week3.dir/src/ui/widget.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/week3.dir/src/ui/widget.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lerfme/Documents/cpp/test3/week3/src/ui/widget.cpp -o CMakeFiles/week3.dir/src/ui/widget.cpp.s

CMakeFiles/week3.dir/src/ui/qcustomplot-source/qcustomplot.cpp.o: CMakeFiles/week3.dir/flags.make
CMakeFiles/week3.dir/src/ui/qcustomplot-source/qcustomplot.cpp.o: /home/lerfme/Documents/cpp/test3/week3/src/ui/qcustomplot-source/qcustomplot.cpp
CMakeFiles/week3.dir/src/ui/qcustomplot-source/qcustomplot.cpp.o: CMakeFiles/week3.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lerfme/Documents/cpp/test3/build-week3-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/week3.dir/src/ui/qcustomplot-source/qcustomplot.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/week3.dir/src/ui/qcustomplot-source/qcustomplot.cpp.o -MF CMakeFiles/week3.dir/src/ui/qcustomplot-source/qcustomplot.cpp.o.d -o CMakeFiles/week3.dir/src/ui/qcustomplot-source/qcustomplot.cpp.o -c /home/lerfme/Documents/cpp/test3/week3/src/ui/qcustomplot-source/qcustomplot.cpp

CMakeFiles/week3.dir/src/ui/qcustomplot-source/qcustomplot.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/week3.dir/src/ui/qcustomplot-source/qcustomplot.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lerfme/Documents/cpp/test3/week3/src/ui/qcustomplot-source/qcustomplot.cpp > CMakeFiles/week3.dir/src/ui/qcustomplot-source/qcustomplot.cpp.i

CMakeFiles/week3.dir/src/ui/qcustomplot-source/qcustomplot.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/week3.dir/src/ui/qcustomplot-source/qcustomplot.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lerfme/Documents/cpp/test3/week3/src/ui/qcustomplot-source/qcustomplot.cpp -o CMakeFiles/week3.dir/src/ui/qcustomplot-source/qcustomplot.cpp.s

# Object files for target week3
week3_OBJECTS = \
"CMakeFiles/week3.dir/week3_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/week3.dir/main.cpp.o" \
"CMakeFiles/week3.dir/src/ui/widget.cpp.o" \
"CMakeFiles/week3.dir/src/ui/qcustomplot-source/qcustomplot.cpp.o"

# External object files for target week3
week3_EXTERNAL_OBJECTS =

week3: CMakeFiles/week3.dir/week3_autogen/mocs_compilation.cpp.o
week3: CMakeFiles/week3.dir/main.cpp.o
week3: CMakeFiles/week3.dir/src/ui/widget.cpp.o
week3: CMakeFiles/week3.dir/src/ui/qcustomplot-source/qcustomplot.cpp.o
week3: CMakeFiles/week3.dir/build.make
week3: /usr/lib/x86_64-linux-gnu/libQt5PrintSupport.so.5.15.3
week3: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.15.3
week3: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.15.3
week3: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.15.3
week3: CMakeFiles/week3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lerfme/Documents/cpp/test3/build-week3-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable week3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/week3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/week3.dir/build: week3
.PHONY : CMakeFiles/week3.dir/build

CMakeFiles/week3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/week3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/week3.dir/clean

CMakeFiles/week3.dir/depend:
	cd /home/lerfme/Documents/cpp/test3/build-week3-Desktop-Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lerfme/Documents/cpp/test3/week3 /home/lerfme/Documents/cpp/test3/week3 /home/lerfme/Documents/cpp/test3/build-week3-Desktop-Debug /home/lerfme/Documents/cpp/test3/build-week3-Desktop-Debug /home/lerfme/Documents/cpp/test3/build-week3-Desktop-Debug/CMakeFiles/week3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/week3.dir/depend
