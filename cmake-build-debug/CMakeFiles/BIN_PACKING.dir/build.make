# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/alex/Desktop/CLION_WORKSPACE/BIN_PACKING

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/alex/Desktop/CLION_WORKSPACE/BIN_PACKING/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/BIN_PACKING.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/BIN_PACKING.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BIN_PACKING.dir/flags.make

CMakeFiles/BIN_PACKING.dir/GenerateBins.cpp.o: CMakeFiles/BIN_PACKING.dir/flags.make
CMakeFiles/BIN_PACKING.dir/GenerateBins.cpp.o: ../GenerateBins.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/alex/Desktop/CLION_WORKSPACE/BIN_PACKING/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/BIN_PACKING.dir/GenerateBins.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BIN_PACKING.dir/GenerateBins.cpp.o -c /Users/alex/Desktop/CLION_WORKSPACE/BIN_PACKING/GenerateBins.cpp

CMakeFiles/BIN_PACKING.dir/GenerateBins.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BIN_PACKING.dir/GenerateBins.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/alex/Desktop/CLION_WORKSPACE/BIN_PACKING/GenerateBins.cpp > CMakeFiles/BIN_PACKING.dir/GenerateBins.cpp.i

CMakeFiles/BIN_PACKING.dir/GenerateBins.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BIN_PACKING.dir/GenerateBins.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/alex/Desktop/CLION_WORKSPACE/BIN_PACKING/GenerateBins.cpp -o CMakeFiles/BIN_PACKING.dir/GenerateBins.cpp.s

CMakeFiles/BIN_PACKING.dir/Pack.cpp.o: CMakeFiles/BIN_PACKING.dir/flags.make
CMakeFiles/BIN_PACKING.dir/Pack.cpp.o: ../Pack.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/alex/Desktop/CLION_WORKSPACE/BIN_PACKING/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/BIN_PACKING.dir/Pack.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BIN_PACKING.dir/Pack.cpp.o -c /Users/alex/Desktop/CLION_WORKSPACE/BIN_PACKING/Pack.cpp

CMakeFiles/BIN_PACKING.dir/Pack.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BIN_PACKING.dir/Pack.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/alex/Desktop/CLION_WORKSPACE/BIN_PACKING/Pack.cpp > CMakeFiles/BIN_PACKING.dir/Pack.cpp.i

CMakeFiles/BIN_PACKING.dir/Pack.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BIN_PACKING.dir/Pack.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/alex/Desktop/CLION_WORKSPACE/BIN_PACKING/Pack.cpp -o CMakeFiles/BIN_PACKING.dir/Pack.cpp.s

# Object files for target BIN_PACKING
BIN_PACKING_OBJECTS = \
"CMakeFiles/BIN_PACKING.dir/GenerateBins.cpp.o" \
"CMakeFiles/BIN_PACKING.dir/Pack.cpp.o"

# External object files for target BIN_PACKING
BIN_PACKING_EXTERNAL_OBJECTS =

BIN_PACKING: CMakeFiles/BIN_PACKING.dir/GenerateBins.cpp.o
BIN_PACKING: CMakeFiles/BIN_PACKING.dir/Pack.cpp.o
BIN_PACKING: CMakeFiles/BIN_PACKING.dir/build.make
BIN_PACKING: CMakeFiles/BIN_PACKING.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/alex/Desktop/CLION_WORKSPACE/BIN_PACKING/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable BIN_PACKING"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BIN_PACKING.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BIN_PACKING.dir/build: BIN_PACKING

.PHONY : CMakeFiles/BIN_PACKING.dir/build

CMakeFiles/BIN_PACKING.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/BIN_PACKING.dir/cmake_clean.cmake
.PHONY : CMakeFiles/BIN_PACKING.dir/clean

CMakeFiles/BIN_PACKING.dir/depend:
	cd /Users/alex/Desktop/CLION_WORKSPACE/BIN_PACKING/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/alex/Desktop/CLION_WORKSPACE/BIN_PACKING /Users/alex/Desktop/CLION_WORKSPACE/BIN_PACKING /Users/alex/Desktop/CLION_WORKSPACE/BIN_PACKING/cmake-build-debug /Users/alex/Desktop/CLION_WORKSPACE/BIN_PACKING/cmake-build-debug /Users/alex/Desktop/CLION_WORKSPACE/BIN_PACKING/cmake-build-debug/CMakeFiles/BIN_PACKING.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BIN_PACKING.dir/depend
