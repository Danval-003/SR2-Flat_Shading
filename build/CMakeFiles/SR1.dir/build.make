# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_SOURCE_DIR = "/home/danval/Lab 4"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/danval/Lab 4/build"

# Include any dependencies generated for this target.
include CMakeFiles/SR1.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/SR1.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/SR1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SR1.dir/flags.make

CMakeFiles/SR1.dir/main.cpp.o: CMakeFiles/SR1.dir/flags.make
CMakeFiles/SR1.dir/main.cpp.o: /home/danval/Lab\ 4/main.cpp
CMakeFiles/SR1.dir/main.cpp.o: CMakeFiles/SR1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/home/danval/Lab 4/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SR1.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SR1.dir/main.cpp.o -MF CMakeFiles/SR1.dir/main.cpp.o.d -o CMakeFiles/SR1.dir/main.cpp.o -c "/home/danval/Lab 4/main.cpp"

CMakeFiles/SR1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SR1.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/danval/Lab 4/main.cpp" > CMakeFiles/SR1.dir/main.cpp.i

CMakeFiles/SR1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SR1.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/danval/Lab 4/main.cpp" -o CMakeFiles/SR1.dir/main.cpp.s

CMakeFiles/SR1.dir/render.cpp.o: CMakeFiles/SR1.dir/flags.make
CMakeFiles/SR1.dir/render.cpp.o: /home/danval/Lab\ 4/render.cpp
CMakeFiles/SR1.dir/render.cpp.o: CMakeFiles/SR1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/home/danval/Lab 4/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SR1.dir/render.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SR1.dir/render.cpp.o -MF CMakeFiles/SR1.dir/render.cpp.o.d -o CMakeFiles/SR1.dir/render.cpp.o -c "/home/danval/Lab 4/render.cpp"

CMakeFiles/SR1.dir/render.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SR1.dir/render.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/danval/Lab 4/render.cpp" > CMakeFiles/SR1.dir/render.cpp.i

CMakeFiles/SR1.dir/render.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SR1.dir/render.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/danval/Lab 4/render.cpp" -o CMakeFiles/SR1.dir/render.cpp.s

CMakeFiles/SR1.dir/color.cpp.o: CMakeFiles/SR1.dir/flags.make
CMakeFiles/SR1.dir/color.cpp.o: /home/danval/Lab\ 4/color.cpp
CMakeFiles/SR1.dir/color.cpp.o: CMakeFiles/SR1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/home/danval/Lab 4/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/SR1.dir/color.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SR1.dir/color.cpp.o -MF CMakeFiles/SR1.dir/color.cpp.o.d -o CMakeFiles/SR1.dir/color.cpp.o -c "/home/danval/Lab 4/color.cpp"

CMakeFiles/SR1.dir/color.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SR1.dir/color.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/danval/Lab 4/color.cpp" > CMakeFiles/SR1.dir/color.cpp.i

CMakeFiles/SR1.dir/color.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SR1.dir/color.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/danval/Lab 4/color.cpp" -o CMakeFiles/SR1.dir/color.cpp.s

CMakeFiles/SR1.dir/framebuffer.cpp.o: CMakeFiles/SR1.dir/flags.make
CMakeFiles/SR1.dir/framebuffer.cpp.o: /home/danval/Lab\ 4/framebuffer.cpp
CMakeFiles/SR1.dir/framebuffer.cpp.o: CMakeFiles/SR1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/home/danval/Lab 4/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/SR1.dir/framebuffer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SR1.dir/framebuffer.cpp.o -MF CMakeFiles/SR1.dir/framebuffer.cpp.o.d -o CMakeFiles/SR1.dir/framebuffer.cpp.o -c "/home/danval/Lab 4/framebuffer.cpp"

CMakeFiles/SR1.dir/framebuffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SR1.dir/framebuffer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/danval/Lab 4/framebuffer.cpp" > CMakeFiles/SR1.dir/framebuffer.cpp.i

CMakeFiles/SR1.dir/framebuffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SR1.dir/framebuffer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/danval/Lab 4/framebuffer.cpp" -o CMakeFiles/SR1.dir/framebuffer.cpp.s

CMakeFiles/SR1.dir/vertexGML.cpp.o: CMakeFiles/SR1.dir/flags.make
CMakeFiles/SR1.dir/vertexGML.cpp.o: /home/danval/Lab\ 4/vertexGML.cpp
CMakeFiles/SR1.dir/vertexGML.cpp.o: CMakeFiles/SR1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/home/danval/Lab 4/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/SR1.dir/vertexGML.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SR1.dir/vertexGML.cpp.o -MF CMakeFiles/SR1.dir/vertexGML.cpp.o.d -o CMakeFiles/SR1.dir/vertexGML.cpp.o -c "/home/danval/Lab 4/vertexGML.cpp"

CMakeFiles/SR1.dir/vertexGML.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SR1.dir/vertexGML.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/danval/Lab 4/vertexGML.cpp" > CMakeFiles/SR1.dir/vertexGML.cpp.i

CMakeFiles/SR1.dir/vertexGML.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SR1.dir/vertexGML.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/danval/Lab 4/vertexGML.cpp" -o CMakeFiles/SR1.dir/vertexGML.cpp.s

CMakeFiles/SR1.dir/objSettings.cpp.o: CMakeFiles/SR1.dir/flags.make
CMakeFiles/SR1.dir/objSettings.cpp.o: /home/danval/Lab\ 4/objSettings.cpp
CMakeFiles/SR1.dir/objSettings.cpp.o: CMakeFiles/SR1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/home/danval/Lab 4/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/SR1.dir/objSettings.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SR1.dir/objSettings.cpp.o -MF CMakeFiles/SR1.dir/objSettings.cpp.o.d -o CMakeFiles/SR1.dir/objSettings.cpp.o -c "/home/danval/Lab 4/objSettings.cpp"

CMakeFiles/SR1.dir/objSettings.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SR1.dir/objSettings.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/danval/Lab 4/objSettings.cpp" > CMakeFiles/SR1.dir/objSettings.cpp.i

CMakeFiles/SR1.dir/objSettings.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SR1.dir/objSettings.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/danval/Lab 4/objSettings.cpp" -o CMakeFiles/SR1.dir/objSettings.cpp.s

CMakeFiles/SR1.dir/uniform.cpp.o: CMakeFiles/SR1.dir/flags.make
CMakeFiles/SR1.dir/uniform.cpp.o: /home/danval/Lab\ 4/uniform.cpp
CMakeFiles/SR1.dir/uniform.cpp.o: CMakeFiles/SR1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/home/danval/Lab 4/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/SR1.dir/uniform.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SR1.dir/uniform.cpp.o -MF CMakeFiles/SR1.dir/uniform.cpp.o.d -o CMakeFiles/SR1.dir/uniform.cpp.o -c "/home/danval/Lab 4/uniform.cpp"

CMakeFiles/SR1.dir/uniform.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SR1.dir/uniform.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/danval/Lab 4/uniform.cpp" > CMakeFiles/SR1.dir/uniform.cpp.i

CMakeFiles/SR1.dir/uniform.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SR1.dir/uniform.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/danval/Lab 4/uniform.cpp" -o CMakeFiles/SR1.dir/uniform.cpp.s

# Object files for target SR1
SR1_OBJECTS = \
"CMakeFiles/SR1.dir/main.cpp.o" \
"CMakeFiles/SR1.dir/render.cpp.o" \
"CMakeFiles/SR1.dir/color.cpp.o" \
"CMakeFiles/SR1.dir/framebuffer.cpp.o" \
"CMakeFiles/SR1.dir/vertexGML.cpp.o" \
"CMakeFiles/SR1.dir/objSettings.cpp.o" \
"CMakeFiles/SR1.dir/uniform.cpp.o"

# External object files for target SR1
SR1_EXTERNAL_OBJECTS =

SR1: CMakeFiles/SR1.dir/main.cpp.o
SR1: CMakeFiles/SR1.dir/render.cpp.o
SR1: CMakeFiles/SR1.dir/color.cpp.o
SR1: CMakeFiles/SR1.dir/framebuffer.cpp.o
SR1: CMakeFiles/SR1.dir/vertexGML.cpp.o
SR1: CMakeFiles/SR1.dir/objSettings.cpp.o
SR1: CMakeFiles/SR1.dir/uniform.cpp.o
SR1: CMakeFiles/SR1.dir/build.make
SR1: CMakeFiles/SR1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/home/danval/Lab 4/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable SR1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SR1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SR1.dir/build: SR1
.PHONY : CMakeFiles/SR1.dir/build

CMakeFiles/SR1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SR1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SR1.dir/clean

CMakeFiles/SR1.dir/depend:
	cd "/home/danval/Lab 4/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/danval/Lab 4" "/home/danval/Lab 4" "/home/danval/Lab 4/build" "/home/danval/Lab 4/build" "/home/danval/Lab 4/build/CMakeFiles/SR1.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/SR1.dir/depend

