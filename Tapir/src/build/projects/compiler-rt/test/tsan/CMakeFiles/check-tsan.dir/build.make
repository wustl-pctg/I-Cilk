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

# Utility rule file for check-tsan.

# Include the progress variables for this target.
include projects/compiler-rt/test/tsan/CMakeFiles/check-tsan.dir/progress.make

projects/compiler-rt/test/tsan/CMakeFiles/check-tsan:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/mnt/cilk-plus-futures/Tapir/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Running ThreadSanitizer tests"
	cd /mnt/cilk-plus-futures/Tapir/src/build/projects/compiler-rt/test/tsan && /usr/bin/python2.7 /mnt/cilk-plus-futures/Tapir/src/utils/lit/lit.py -sv /mnt/cilk-plus-futures/Tapir/src/build/projects/compiler-rt/test/tsan/X86_64Config /mnt/cilk-plus-futures/Tapir/src/build/projects/compiler-rt/test/tsan/Unit

check-tsan: projects/compiler-rt/test/tsan/CMakeFiles/check-tsan
check-tsan: projects/compiler-rt/test/tsan/CMakeFiles/check-tsan.dir/build.make

.PHONY : check-tsan

# Rule to build all files generated by this target.
projects/compiler-rt/test/tsan/CMakeFiles/check-tsan.dir/build: check-tsan

.PHONY : projects/compiler-rt/test/tsan/CMakeFiles/check-tsan.dir/build

projects/compiler-rt/test/tsan/CMakeFiles/check-tsan.dir/clean:
	cd /mnt/cilk-plus-futures/Tapir/src/build/projects/compiler-rt/test/tsan && $(CMAKE_COMMAND) -P CMakeFiles/check-tsan.dir/cmake_clean.cmake
.PHONY : projects/compiler-rt/test/tsan/CMakeFiles/check-tsan.dir/clean

projects/compiler-rt/test/tsan/CMakeFiles/check-tsan.dir/depend:
	cd /mnt/cilk-plus-futures/Tapir/src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/cilk-plus-futures/Tapir/src /mnt/cilk-plus-futures/Tapir/src/projects/compiler-rt/test/tsan /mnt/cilk-plus-futures/Tapir/src/build /mnt/cilk-plus-futures/Tapir/src/build/projects/compiler-rt/test/tsan /mnt/cilk-plus-futures/Tapir/src/build/projects/compiler-rt/test/tsan/CMakeFiles/check-tsan.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : projects/compiler-rt/test/tsan/CMakeFiles/check-tsan.dir/depend

