# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2024.3\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2024.3\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Jose

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Jose\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ProgramaLectorMemoria.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ProgramaLectorMemoria.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ProgramaLectorMemoria.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ProgramaLectorMemoria.dir/flags.make

CMakeFiles/ProgramaLectorMemoria.dir/main.cpp.obj: CMakeFiles/ProgramaLectorMemoria.dir/flags.make
CMakeFiles/ProgramaLectorMemoria.dir/main.cpp.obj: D:/Jose/main.cpp
CMakeFiles/ProgramaLectorMemoria.dir/main.cpp.obj: CMakeFiles/ProgramaLectorMemoria.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\Jose\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ProgramaLectorMemoria.dir/main.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ProgramaLectorMemoria.dir/main.cpp.obj -MF CMakeFiles\ProgramaLectorMemoria.dir\main.cpp.obj.d -o CMakeFiles\ProgramaLectorMemoria.dir\main.cpp.obj -c D:\Jose\main.cpp

CMakeFiles/ProgramaLectorMemoria.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ProgramaLectorMemoria.dir/main.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Jose\main.cpp > CMakeFiles\ProgramaLectorMemoria.dir\main.cpp.i

CMakeFiles/ProgramaLectorMemoria.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ProgramaLectorMemoria.dir/main.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Jose\main.cpp -o CMakeFiles\ProgramaLectorMemoria.dir\main.cpp.s

# Object files for target ProgramaLectorMemoria
ProgramaLectorMemoria_OBJECTS = \
"CMakeFiles/ProgramaLectorMemoria.dir/main.cpp.obj"

# External object files for target ProgramaLectorMemoria
ProgramaLectorMemoria_EXTERNAL_OBJECTS =

ProgramaLectorMemoria.exe: CMakeFiles/ProgramaLectorMemoria.dir/main.cpp.obj
ProgramaLectorMemoria.exe: CMakeFiles/ProgramaLectorMemoria.dir/build.make
ProgramaLectorMemoria.exe: CMakeFiles/ProgramaLectorMemoria.dir/linkLibs.rsp
ProgramaLectorMemoria.exe: CMakeFiles/ProgramaLectorMemoria.dir/objects1.rsp
ProgramaLectorMemoria.exe: CMakeFiles/ProgramaLectorMemoria.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=D:\Jose\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ProgramaLectorMemoria.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ProgramaLectorMemoria.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ProgramaLectorMemoria.dir/build: ProgramaLectorMemoria.exe
.PHONY : CMakeFiles/ProgramaLectorMemoria.dir/build

CMakeFiles/ProgramaLectorMemoria.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ProgramaLectorMemoria.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ProgramaLectorMemoria.dir/clean

CMakeFiles/ProgramaLectorMemoria.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Jose D:\Jose D:\Jose\cmake-build-debug D:\Jose\cmake-build-debug D:\Jose\cmake-build-debug\CMakeFiles\ProgramaLectorMemoria.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/ProgramaLectorMemoria.dir/depend

