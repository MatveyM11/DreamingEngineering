# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_SOURCE_DIR = "/mnt/sdb1/Linux/Minecraft CPP"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/sdb1/Linux/Minecraft CPP/build"

# Include any dependencies generated for this target.
include CMakeFiles/Events.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Events.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Events.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Events.dir/flags.make

CMakeFiles/Events.dir/DreamEngine/Window/Events.cpp.o: CMakeFiles/Events.dir/flags.make
CMakeFiles/Events.dir/DreamEngine/Window/Events.cpp.o: /mnt/sdb1/Linux/Minecraft\ CPP/DreamEngine/Window/Events.cpp
CMakeFiles/Events.dir/DreamEngine/Window/Events.cpp.o: CMakeFiles/Events.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/sdb1/Linux/Minecraft CPP/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Events.dir/DreamEngine/Window/Events.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Events.dir/DreamEngine/Window/Events.cpp.o -MF CMakeFiles/Events.dir/DreamEngine/Window/Events.cpp.o.d -o CMakeFiles/Events.dir/DreamEngine/Window/Events.cpp.o -c "/mnt/sdb1/Linux/Minecraft CPP/DreamEngine/Window/Events.cpp"

CMakeFiles/Events.dir/DreamEngine/Window/Events.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Events.dir/DreamEngine/Window/Events.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/sdb1/Linux/Minecraft CPP/DreamEngine/Window/Events.cpp" > CMakeFiles/Events.dir/DreamEngine/Window/Events.cpp.i

CMakeFiles/Events.dir/DreamEngine/Window/Events.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Events.dir/DreamEngine/Window/Events.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/sdb1/Linux/Minecraft CPP/DreamEngine/Window/Events.cpp" -o CMakeFiles/Events.dir/DreamEngine/Window/Events.cpp.s

# Object files for target Events
Events_OBJECTS = \
"CMakeFiles/Events.dir/DreamEngine/Window/Events.cpp.o"

# External object files for target Events
Events_EXTERNAL_OBJECTS =

libEvents.a: CMakeFiles/Events.dir/DreamEngine/Window/Events.cpp.o
libEvents.a: CMakeFiles/Events.dir/build.make
libEvents.a: CMakeFiles/Events.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/mnt/sdb1/Linux/Minecraft CPP/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libEvents.a"
	$(CMAKE_COMMAND) -P CMakeFiles/Events.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Events.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Events.dir/build: libEvents.a
.PHONY : CMakeFiles/Events.dir/build

CMakeFiles/Events.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Events.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Events.dir/clean

CMakeFiles/Events.dir/depend:
	cd "/mnt/sdb1/Linux/Minecraft CPP/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/sdb1/Linux/Minecraft CPP" "/mnt/sdb1/Linux/Minecraft CPP" "/mnt/sdb1/Linux/Minecraft CPP/build" "/mnt/sdb1/Linux/Minecraft CPP/build" "/mnt/sdb1/Linux/Minecraft CPP/build/CMakeFiles/Events.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Events.dir/depend

