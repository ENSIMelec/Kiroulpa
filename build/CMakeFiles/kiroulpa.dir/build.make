# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_SOURCE_DIR = /home/pi/Documents/tmp/tmp.bCKtbqF7Mt

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/Documents/tmp/tmp.bCKtbqF7Mt/build

# Include any dependencies generated for this target.
include CMakeFiles/kiroulpa.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/kiroulpa.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/kiroulpa.dir/flags.make

CMakeFiles/kiroulpa.dir/src/main.cpp.o: CMakeFiles/kiroulpa.dir/flags.make
CMakeFiles/kiroulpa.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Documents/tmp/tmp.bCKtbqF7Mt/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/kiroulpa.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/kiroulpa.dir/src/main.cpp.o -c /home/pi/Documents/tmp/tmp.bCKtbqF7Mt/src/main.cpp

CMakeFiles/kiroulpa.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/kiroulpa.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/Documents/tmp/tmp.bCKtbqF7Mt/src/main.cpp > CMakeFiles/kiroulpa.dir/src/main.cpp.i

CMakeFiles/kiroulpa.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/kiroulpa.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/Documents/tmp/tmp.bCKtbqF7Mt/src/main.cpp -o CMakeFiles/kiroulpa.dir/src/main.cpp.s

# Object files for target kiroulpa
kiroulpa_OBJECTS = \
"CMakeFiles/kiroulpa.dir/src/main.cpp.o"

# External object files for target kiroulpa
kiroulpa_EXTERNAL_OBJECTS =

kiroulpa: CMakeFiles/kiroulpa.dir/src/main.cpp.o
kiroulpa: CMakeFiles/kiroulpa.dir/build.make
kiroulpa: CMakeFiles/kiroulpa.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pi/Documents/tmp/tmp.bCKtbqF7Mt/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable kiroulpa"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/kiroulpa.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/kiroulpa.dir/build: kiroulpa

.PHONY : CMakeFiles/kiroulpa.dir/build

CMakeFiles/kiroulpa.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/kiroulpa.dir/cmake_clean.cmake
.PHONY : CMakeFiles/kiroulpa.dir/clean

CMakeFiles/kiroulpa.dir/depend:
	cd /home/pi/Documents/tmp/tmp.bCKtbqF7Mt/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/Documents/tmp/tmp.bCKtbqF7Mt /home/pi/Documents/tmp/tmp.bCKtbqF7Mt /home/pi/Documents/tmp/tmp.bCKtbqF7Mt/build /home/pi/Documents/tmp/tmp.bCKtbqF7Mt/build /home/pi/Documents/tmp/tmp.bCKtbqF7Mt/build/CMakeFiles/kiroulpa.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/kiroulpa.dir/depend

