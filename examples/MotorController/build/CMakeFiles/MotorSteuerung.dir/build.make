# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/parallels/Downloads/MotorController

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/parallels/Downloads/MotorController/build

# Include any dependencies generated for this target.
include CMakeFiles/MotorSteuerung.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MotorSteuerung.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MotorSteuerung.dir/flags.make

CMakeFiles/MotorSteuerung.dir/main.c.o: CMakeFiles/MotorSteuerung.dir/flags.make
CMakeFiles/MotorSteuerung.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/parallels/Downloads/MotorController/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/MotorSteuerung.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/MotorSteuerung.dir/main.c.o   -c /home/parallels/Downloads/MotorController/main.c

CMakeFiles/MotorSteuerung.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MotorSteuerung.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/parallels/Downloads/MotorController/main.c > CMakeFiles/MotorSteuerung.dir/main.c.i

CMakeFiles/MotorSteuerung.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MotorSteuerung.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/parallels/Downloads/MotorController/main.c -o CMakeFiles/MotorSteuerung.dir/main.c.s

CMakeFiles/MotorSteuerung.dir/MotorSteuerung.c.o: CMakeFiles/MotorSteuerung.dir/flags.make
CMakeFiles/MotorSteuerung.dir/MotorSteuerung.c.o: ../MotorSteuerung.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/parallels/Downloads/MotorController/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/MotorSteuerung.dir/MotorSteuerung.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/MotorSteuerung.dir/MotorSteuerung.c.o   -c /home/parallels/Downloads/MotorController/MotorSteuerung.c

CMakeFiles/MotorSteuerung.dir/MotorSteuerung.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MotorSteuerung.dir/MotorSteuerung.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/parallels/Downloads/MotorController/MotorSteuerung.c > CMakeFiles/MotorSteuerung.dir/MotorSteuerung.c.i

CMakeFiles/MotorSteuerung.dir/MotorSteuerung.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MotorSteuerung.dir/MotorSteuerung.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/parallels/Downloads/MotorController/MotorSteuerung.c -o CMakeFiles/MotorSteuerung.dir/MotorSteuerung.c.s

# Object files for target MotorSteuerung
MotorSteuerung_OBJECTS = \
"CMakeFiles/MotorSteuerung.dir/main.c.o" \
"CMakeFiles/MotorSteuerung.dir/MotorSteuerung.c.o"

# External object files for target MotorSteuerung
MotorSteuerung_EXTERNAL_OBJECTS =

MotorSteuerung: CMakeFiles/MotorSteuerung.dir/main.c.o
MotorSteuerung: CMakeFiles/MotorSteuerung.dir/MotorSteuerung.c.o
MotorSteuerung: CMakeFiles/MotorSteuerung.dir/build.make
MotorSteuerung: CMakeFiles/MotorSteuerung.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/parallels/Downloads/MotorController/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable MotorSteuerung"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MotorSteuerung.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MotorSteuerung.dir/build: MotorSteuerung

.PHONY : CMakeFiles/MotorSteuerung.dir/build

CMakeFiles/MotorSteuerung.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MotorSteuerung.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MotorSteuerung.dir/clean

CMakeFiles/MotorSteuerung.dir/depend:
	cd /home/parallels/Downloads/MotorController/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/parallels/Downloads/MotorController /home/parallels/Downloads/MotorController /home/parallels/Downloads/MotorController/build /home/parallels/Downloads/MotorController/build /home/parallels/Downloads/MotorController/build/CMakeFiles/MotorSteuerung.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MotorSteuerung.dir/depend

