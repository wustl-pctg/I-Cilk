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

# Utility rule file for stats.

# Include the progress variables for this target.
include projects/compiler-rt/lib/stats/CMakeFiles/stats.dir/progress.make

stats: projects/compiler-rt/lib/stats/CMakeFiles/stats.dir/build.make

.PHONY : stats

# Rule to build all files generated by this target.
projects/compiler-rt/lib/stats/CMakeFiles/stats.dir/build: stats

.PHONY : projects/compiler-rt/lib/stats/CMakeFiles/stats.dir/build

projects/compiler-rt/lib/stats/CMakeFiles/stats.dir/clean:
	cd /mnt/cilk-plus-futures/Tapir/src/build/projects/compiler-rt/lib/stats && $(CMAKE_COMMAND) -P CMakeFiles/stats.dir/cmake_clean.cmake
.PHONY : projects/compiler-rt/lib/stats/CMakeFiles/stats.dir/clean

projects/compiler-rt/lib/stats/CMakeFiles/stats.dir/depend:
	cd /mnt/cilk-plus-futures/Tapir/src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/cilk-plus-futures/Tapir/src /mnt/cilk-plus-futures/Tapir/src/projects/compiler-rt/lib/stats /mnt/cilk-plus-futures/Tapir/src/build /mnt/cilk-plus-futures/Tapir/src/build/projects/compiler-rt/lib/stats /mnt/cilk-plus-futures/Tapir/src/build/projects/compiler-rt/lib/stats/CMakeFiles/stats.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : projects/compiler-rt/lib/stats/CMakeFiles/stats.dir/depend

