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

# Utility rule file for install-LLVMTapirOpts.

# Include the progress variables for this target.
include lib/Transforms/Tapir/CMakeFiles/install-LLVMTapirOpts.dir/progress.make

lib/Transforms/Tapir/CMakeFiles/install-LLVMTapirOpts: lib/libLLVMTapirOpts.a
	cd /mnt/cilk-plus-futures/Tapir/src/build/lib/Transforms/Tapir && /usr/bin/cmake -DCMAKE_INSTALL_COMPONENT=LLVMTapirOpts -P /mnt/cilk-plus-futures/Tapir/src/build/cmake_install.cmake

install-LLVMTapirOpts: lib/Transforms/Tapir/CMakeFiles/install-LLVMTapirOpts
install-LLVMTapirOpts: lib/Transforms/Tapir/CMakeFiles/install-LLVMTapirOpts.dir/build.make

.PHONY : install-LLVMTapirOpts

# Rule to build all files generated by this target.
lib/Transforms/Tapir/CMakeFiles/install-LLVMTapirOpts.dir/build: install-LLVMTapirOpts

.PHONY : lib/Transforms/Tapir/CMakeFiles/install-LLVMTapirOpts.dir/build

lib/Transforms/Tapir/CMakeFiles/install-LLVMTapirOpts.dir/clean:
	cd /mnt/cilk-plus-futures/Tapir/src/build/lib/Transforms/Tapir && $(CMAKE_COMMAND) -P CMakeFiles/install-LLVMTapirOpts.dir/cmake_clean.cmake
.PHONY : lib/Transforms/Tapir/CMakeFiles/install-LLVMTapirOpts.dir/clean

lib/Transforms/Tapir/CMakeFiles/install-LLVMTapirOpts.dir/depend:
	cd /mnt/cilk-plus-futures/Tapir/src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/cilk-plus-futures/Tapir/src /mnt/cilk-plus-futures/Tapir/src/lib/Transforms/Tapir /mnt/cilk-plus-futures/Tapir/src/build /mnt/cilk-plus-futures/Tapir/src/build/lib/Transforms/Tapir /mnt/cilk-plus-futures/Tapir/src/build/lib/Transforms/Tapir/CMakeFiles/install-LLVMTapirOpts.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/Transforms/Tapir/CMakeFiles/install-LLVMTapirOpts.dir/depend

