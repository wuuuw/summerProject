# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\ilins\CLionProjects\Project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\ilins\CLionProjects\Project\cmake-build-debug

# Include any dependencies generated for this target.
include doctest/CMakeFiles/doctest.dir/depend.make

# Include the progress variables for this target.
include doctest/CMakeFiles/doctest.dir/progress.make

# Include the compile flags for this target's objects.
include doctest/CMakeFiles/doctest.dir/flags.make

doctest/CMakeFiles/doctest.dir/doctest.cpp.obj: doctest/CMakeFiles/doctest.dir/flags.make
doctest/CMakeFiles/doctest.dir/doctest.cpp.obj: doctest/CMakeFiles/doctest.dir/includes_CXX.rsp
doctest/CMakeFiles/doctest.dir/doctest.cpp.obj: ../doctest/doctest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\ilins\CLionProjects\Project\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object doctest/CMakeFiles/doctest.dir/doctest.cpp.obj"
	cd /d C:\Users\ilins\CLionProjects\Project\cmake-build-debug\doctest && C:\mingw\mingw-w64-v8.0.0\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\doctest.dir\doctest.cpp.obj -c C:\Users\ilins\CLionProjects\Project\doctest\doctest.cpp

doctest/CMakeFiles/doctest.dir/doctest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/doctest.dir/doctest.cpp.i"
	cd /d C:\Users\ilins\CLionProjects\Project\cmake-build-debug\doctest && C:\mingw\mingw-w64-v8.0.0\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\ilins\CLionProjects\Project\doctest\doctest.cpp > CMakeFiles\doctest.dir\doctest.cpp.i

doctest/CMakeFiles/doctest.dir/doctest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/doctest.dir/doctest.cpp.s"
	cd /d C:\Users\ilins\CLionProjects\Project\cmake-build-debug\doctest && C:\mingw\mingw-w64-v8.0.0\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\ilins\CLionProjects\Project\doctest\doctest.cpp -o CMakeFiles\doctest.dir\doctest.cpp.s

# Object files for target doctest
doctest_OBJECTS = \
"CMakeFiles/doctest.dir/doctest.cpp.obj"

# External object files for target doctest
doctest_EXTERNAL_OBJECTS =

doctest/libdoctest.a: doctest/CMakeFiles/doctest.dir/doctest.cpp.obj
doctest/libdoctest.a: doctest/CMakeFiles/doctest.dir/build.make
doctest/libdoctest.a: doctest/CMakeFiles/doctest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\ilins\CLionProjects\Project\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libdoctest.a"
	cd /d C:\Users\ilins\CLionProjects\Project\cmake-build-debug\doctest && $(CMAKE_COMMAND) -P CMakeFiles\doctest.dir\cmake_clean_target.cmake
	cd /d C:\Users\ilins\CLionProjects\Project\cmake-build-debug\doctest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\doctest.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
doctest/CMakeFiles/doctest.dir/build: doctest/libdoctest.a

.PHONY : doctest/CMakeFiles/doctest.dir/build

doctest/CMakeFiles/doctest.dir/clean:
	cd /d C:\Users\ilins\CLionProjects\Project\cmake-build-debug\doctest && $(CMAKE_COMMAND) -P CMakeFiles\doctest.dir\cmake_clean.cmake
.PHONY : doctest/CMakeFiles/doctest.dir/clean

doctest/CMakeFiles/doctest.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\ilins\CLionProjects\Project C:\Users\ilins\CLionProjects\Project\doctest C:\Users\ilins\CLionProjects\Project\cmake-build-debug C:\Users\ilins\CLionProjects\Project\cmake-build-debug\doctest C:\Users\ilins\CLionProjects\Project\cmake-build-debug\doctest\CMakeFiles\doctest.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : doctest/CMakeFiles/doctest.dir/depend

