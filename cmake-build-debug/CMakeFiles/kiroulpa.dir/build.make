# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.21

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\cleme\OneDrive\Documents\GitHub\Kiroulpa

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\cleme\OneDrive\Documents\GitHub\Kiroulpa\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/kiroulpa.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/kiroulpa.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/kiroulpa.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/kiroulpa.dir/flags.make

CMakeFiles/kiroulpa.dir/src/AX12.cpp.obj: CMakeFiles/kiroulpa.dir/flags.make
CMakeFiles/kiroulpa.dir/src/AX12.cpp.obj: ../src/AX12.cpp
CMakeFiles/kiroulpa.dir/src/AX12.cpp.obj: CMakeFiles/kiroulpa.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\cleme\OneDrive\Documents\GitHub\Kiroulpa\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/kiroulpa.dir/src/AX12.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/kiroulpa.dir/src/AX12.cpp.obj -MF CMakeFiles\kiroulpa.dir\src\AX12.cpp.obj.d -o CMakeFiles\kiroulpa.dir\src\AX12.cpp.obj -c C:\Users\cleme\OneDrive\Documents\GitHub\Kiroulpa\src\AX12.cpp

CMakeFiles/kiroulpa.dir/src/AX12.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/kiroulpa.dir/src/AX12.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\cleme\OneDrive\Documents\GitHub\Kiroulpa\src\AX12.cpp > CMakeFiles\kiroulpa.dir\src\AX12.cpp.i

CMakeFiles/kiroulpa.dir/src/AX12.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/kiroulpa.dir/src/AX12.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\cleme\OneDrive\Documents\GitHub\Kiroulpa\src\AX12.cpp -o CMakeFiles\kiroulpa.dir\src\AX12.cpp.s

CMakeFiles/kiroulpa.dir/src/main.cpp.obj: CMakeFiles/kiroulpa.dir/flags.make
CMakeFiles/kiroulpa.dir/src/main.cpp.obj: ../src/main.cpp
CMakeFiles/kiroulpa.dir/src/main.cpp.obj: CMakeFiles/kiroulpa.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\cleme\OneDrive\Documents\GitHub\Kiroulpa\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/kiroulpa.dir/src/main.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/kiroulpa.dir/src/main.cpp.obj -MF CMakeFiles\kiroulpa.dir\src\main.cpp.obj.d -o CMakeFiles\kiroulpa.dir\src\main.cpp.obj -c C:\Users\cleme\OneDrive\Documents\GitHub\Kiroulpa\src\main.cpp

CMakeFiles/kiroulpa.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/kiroulpa.dir/src/main.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\cleme\OneDrive\Documents\GitHub\Kiroulpa\src\main.cpp > CMakeFiles\kiroulpa.dir\src\main.cpp.i

CMakeFiles/kiroulpa.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/kiroulpa.dir/src/main.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\cleme\OneDrive\Documents\GitHub\Kiroulpa\src\main.cpp -o CMakeFiles\kiroulpa.dir\src\main.cpp.s

# Object files for target kiroulpa
kiroulpa_OBJECTS = \
"CMakeFiles/kiroulpa.dir/src/AX12.cpp.obj" \
"CMakeFiles/kiroulpa.dir/src/main.cpp.obj"

# External object files for target kiroulpa
kiroulpa_EXTERNAL_OBJECTS =

kiroulpa.exe: CMakeFiles/kiroulpa.dir/src/AX12.cpp.obj
kiroulpa.exe: CMakeFiles/kiroulpa.dir/src/main.cpp.obj
kiroulpa.exe: CMakeFiles/kiroulpa.dir/build.make
kiroulpa.exe: CMakeFiles/kiroulpa.dir/linklibs.rsp
kiroulpa.exe: CMakeFiles/kiroulpa.dir/objects1.rsp
kiroulpa.exe: CMakeFiles/kiroulpa.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\cleme\OneDrive\Documents\GitHub\Kiroulpa\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable kiroulpa.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\kiroulpa.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/kiroulpa.dir/build: kiroulpa.exe
.PHONY : CMakeFiles/kiroulpa.dir/build

CMakeFiles/kiroulpa.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\kiroulpa.dir\cmake_clean.cmake
.PHONY : CMakeFiles/kiroulpa.dir/clean

CMakeFiles/kiroulpa.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\cleme\OneDrive\Documents\GitHub\Kiroulpa C:\Users\cleme\OneDrive\Documents\GitHub\Kiroulpa C:\Users\cleme\OneDrive\Documents\GitHub\Kiroulpa\cmake-build-debug C:\Users\cleme\OneDrive\Documents\GitHub\Kiroulpa\cmake-build-debug C:\Users\cleme\OneDrive\Documents\GitHub\Kiroulpa\cmake-build-debug\CMakeFiles\kiroulpa.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/kiroulpa.dir/depend
