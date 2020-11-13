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

# Utility rule file for check-lsan.

# Include the progress variables for this target.
include projects/compiler-rt/test/lsan/CMakeFiles/check-lsan.dir/progress.make

projects/compiler-rt/test/lsan/CMakeFiles/check-lsan:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/mnt/cilk-plus-futures/Tapir/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Running the LeakSanitizer tests"
	cd /mnt/cilk-plus-futures/Tapir/src/build/projects/compiler-rt/test/lsan && /usr/bin/python2.7 /mnt/cilk-plus-futures/Tapir/src/utils/lit/lit.py -sv /mnt/cilk-plus-futures/Tapir/src/build/projects/compiler-rt/test/lsan/X86_64LsanConfig /mnt/cilk-plus-futures/Tapir/src/build/projects/compiler-rt/test/lsan/X86_64AsanConfig

check-lsan: projects/compiler-rt/test/lsan/CMakeFiles/check-lsan
check-lsan: projects/compiler-rt/test/lsan/CMakeFiles/check-lsan.dir/build.make

.PHONY : check-lsan

# Rule to build all files generated by this target.
projects/compiler-rt/test/lsan/CMakeFiles/check-lsan.dir/build: check-lsan

.PHONY : projects/compiler-rt/test/lsan/CMakeFiles/check-lsan.dir/build

projects/compiler-rt/test/lsan/CMakeFiles/check-lsan.dir/clean:
	cd /mnt/cilk-plus-futures/Tapir/src/build/projects/compiler-rt/test/lsan && $(CMAKE_COMMAND) -P CMakeFiles/check-lsan.dir/cmake_clean.cmake
.PHONY : projects/compiler-rt/test/lsan/CMakeFiles/check-lsan.dir/clean

projects/compiler-rt/test/lsan/CMakeFiles/check-lsan.dir/depend:
	cd /mnt/cilk-plus-futures/Tapir/src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/cilk-plus-futures/Tapir/src /mnt/cilk-plus-futures/Tapir/src/projects/compiler-rt/test/lsan /mnt/cilk-plus-futures/Tapir/src/build /mnt/cilk-plus-futures/Tapir/src/build/projects/compiler-rt/test/lsan /mnt/cilk-plus-futures/Tapir/src/build/projects/compiler-rt/test/lsan/CMakeFiles/check-lsan.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : projects/compiler-rt/test/lsan/CMakeFiles/check-lsan.dir/depend

