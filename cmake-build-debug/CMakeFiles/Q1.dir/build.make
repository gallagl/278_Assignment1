# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2022.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2022.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\galla\Desktop\278_Assignment1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\galla\Desktop\278_Assignment1\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Q1.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Q1.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Q1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Q1.dir/flags.make

CMakeFiles/Q1.dir/Q1.c.obj: CMakeFiles/Q1.dir/flags.make
CMakeFiles/Q1.dir/Q1.c.obj: ../Q1.c
CMakeFiles/Q1.dir/Q1.c.obj: CMakeFiles/Q1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\galla\Desktop\278_Assignment1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Q1.dir/Q1.c.obj"
	"C:\PROGRA~1\JetBrains\CLion 2022.2.1\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Q1.dir/Q1.c.obj -MF CMakeFiles\Q1.dir\Q1.c.obj.d -o CMakeFiles\Q1.dir\Q1.c.obj -c C:\Users\galla\Desktop\278_Assignment1\Q1.c

CMakeFiles/Q1.dir/Q1.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Q1.dir/Q1.c.i"
	"C:\PROGRA~1\JetBrains\CLion 2022.2.1\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\galla\Desktop\278_Assignment1\Q1.c > CMakeFiles\Q1.dir\Q1.c.i

CMakeFiles/Q1.dir/Q1.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Q1.dir/Q1.c.s"
	"C:\PROGRA~1\JetBrains\CLion 2022.2.1\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\galla\Desktop\278_Assignment1\Q1.c -o CMakeFiles\Q1.dir\Q1.c.s

# Object files for target Q1
Q1_OBJECTS = \
"CMakeFiles/Q1.dir/Q1.c.obj"

# External object files for target Q1
Q1_EXTERNAL_OBJECTS =

Q1.exe: CMakeFiles/Q1.dir/Q1.c.obj
Q1.exe: CMakeFiles/Q1.dir/build.make
Q1.exe: CMakeFiles/Q1.dir/linklibs.rsp
Q1.exe: CMakeFiles/Q1.dir/objects1.rsp
Q1.exe: CMakeFiles/Q1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\galla\Desktop\278_Assignment1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Q1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Q1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Q1.dir/build: Q1.exe
.PHONY : CMakeFiles/Q1.dir/build

CMakeFiles/Q1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Q1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Q1.dir/clean

CMakeFiles/Q1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\galla\Desktop\278_Assignment1 C:\Users\galla\Desktop\278_Assignment1 C:\Users\galla\Desktop\278_Assignment1\cmake-build-debug C:\Users\galla\Desktop\278_Assignment1\cmake-build-debug C:\Users\galla\Desktop\278_Assignment1\cmake-build-debug\CMakeFiles\Q1.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Q1.dir/depend

