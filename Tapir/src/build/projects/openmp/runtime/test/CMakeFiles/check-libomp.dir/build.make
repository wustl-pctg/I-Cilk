# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /mnt/cilk-plus-futures/Tapir/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/cilk-plus-futures/Tapir/src/build

# Utility rule file for check-libomp.

# Include the progress variables for this target.
include projects/openmp/runtime/test/CMakeFiles/check-libomp.dir/progress.make

projects/openmp/runtime/test/CMakeFiles/check-libomp:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/mnt/cilk-plus-futures/Tapir/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Running libomp tests"
	cd /mnt/cilk-plus-futures/Tapir/src/build/projects/openmp/runtime/test && /usr/bin/python2.7 /mnt/cilk-plus-futures/Tapir/src/utils/lit/lit.py -sv /mnt/cilk-plus-futures/Tapir/src/build/projects/openmp/runtime/test

check-libomp: projects/openmp/runtime/test/CMakeFiles/check-libomp
check-libomp: projects/openmp/runtime/test/CMakeFiles/check-libomp.dir/build.make

.PHONY : check-libomp

# Rule to build all files generated by this target.
projects/openmp/runtime/test/CMakeFiles/check-libomp.dir/build: check-libomp

.PHONY : projects/openmp/runtime/test/CMakeFiles/check-libomp.dir/build

projects/openmp/runtime/test/CMakeFiles/check-libomp.dir/clean:
	cd /mnt/cilk-plus-futures/Tapir/src/build/projects/openmp/runtime/test && $(CMAKE_COMMAND) -P CMakeFiles/check-libomp.dir/cmake_clean.cmake
.PHONY : projects/openmp/runtime/test/CMakeFiles/check-libomp.dir/clean

projects/openmp/runtime/test/CMakeFiles/check-libomp.dir/depend:
	cd /mnt/cilk-plus-futures/Tapir/src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/cilk-plus-futures/Tapir/src /mnt/cilk-plus-futures/Tapir/src/projects/openmp/runtime/test /mnt/cilk-plus-futures/Tapir/src/build /mnt/cilk-plus-futures/Tapir/src/build/projects/openmp/runtime/test /mnt/cilk-plus-futures/Tapir/src/build/projects/openmp/runtime/test/CMakeFiles/check-libomp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : projects/openmp/runtime/test/CMakeFiles/check-libomp.dir/depend

