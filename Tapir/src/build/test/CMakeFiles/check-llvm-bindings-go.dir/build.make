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

# Utility rule file for check-llvm-bindings-go.

# Include the progress variables for this target.
include test/CMakeFiles/check-llvm-bindings-go.dir/progress.make

test/CMakeFiles/check-llvm-bindings-go:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/mnt/cilk-plus-futures/Tapir/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Running lit suite /mnt/cilk-plus-futures/Tapir/src/test/Bindings/Go"
	cd /mnt/cilk-plus-futures/Tapir/src/build/test && /usr/bin/python2.7 /mnt/cilk-plus-futures/Tapir/src/utils/lit/lit.py -sv --param llvm_site_config=/mnt/cilk-plus-futures/Tapir/src/build/test/lit.site.cfg --param llvm_unit_site_config=/mnt/cilk-plus-futures/Tapir/src/build/test/Unit/lit.site.cfg /mnt/cilk-plus-futures/Tapir/src/test/Bindings/Go

check-llvm-bindings-go: test/CMakeFiles/check-llvm-bindings-go
check-llvm-bindings-go: test/CMakeFiles/check-llvm-bindings-go.dir/build.make

.PHONY : check-llvm-bindings-go

# Rule to build all files generated by this target.
test/CMakeFiles/check-llvm-bindings-go.dir/build: check-llvm-bindings-go

.PHONY : test/CMakeFiles/check-llvm-bindings-go.dir/build

test/CMakeFiles/check-llvm-bindings-go.dir/clean:
	cd /mnt/cilk-plus-futures/Tapir/src/build/test && $(CMAKE_COMMAND) -P CMakeFiles/check-llvm-bindings-go.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/check-llvm-bindings-go.dir/clean

test/CMakeFiles/check-llvm-bindings-go.dir/depend:
	cd /mnt/cilk-plus-futures/Tapir/src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/cilk-plus-futures/Tapir/src /mnt/cilk-plus-futures/Tapir/src/test /mnt/cilk-plus-futures/Tapir/src/build /mnt/cilk-plus-futures/Tapir/src/build/test /mnt/cilk-plus-futures/Tapir/src/build/test/CMakeFiles/check-llvm-bindings-go.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/check-llvm-bindings-go.dir/depend

