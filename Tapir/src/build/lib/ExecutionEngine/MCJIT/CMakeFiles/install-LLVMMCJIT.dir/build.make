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

# Utility rule file for install-LLVMMCJIT.

# Include the progress variables for this target.
include lib/ExecutionEngine/MCJIT/CMakeFiles/install-LLVMMCJIT.dir/progress.make

lib/ExecutionEngine/MCJIT/CMakeFiles/install-LLVMMCJIT: lib/libLLVMMCJIT.a
	cd /mnt/cilk-plus-futures/Tapir/src/build/lib/ExecutionEngine/MCJIT && /usr/bin/cmake -DCMAKE_INSTALL_COMPONENT=LLVMMCJIT -P /mnt/cilk-plus-futures/Tapir/src/build/cmake_install.cmake

install-LLVMMCJIT: lib/ExecutionEngine/MCJIT/CMakeFiles/install-LLVMMCJIT
install-LLVMMCJIT: lib/ExecutionEngine/MCJIT/CMakeFiles/install-LLVMMCJIT.dir/build.make

.PHONY : install-LLVMMCJIT

# Rule to build all files generated by this target.
lib/ExecutionEngine/MCJIT/CMakeFiles/install-LLVMMCJIT.dir/build: install-LLVMMCJIT

.PHONY : lib/ExecutionEngine/MCJIT/CMakeFiles/install-LLVMMCJIT.dir/build

lib/ExecutionEngine/MCJIT/CMakeFiles/install-LLVMMCJIT.dir/clean:
	cd /mnt/cilk-plus-futures/Tapir/src/build/lib/ExecutionEngine/MCJIT && $(CMAKE_COMMAND) -P CMakeFiles/install-LLVMMCJIT.dir/cmake_clean.cmake
.PHONY : lib/ExecutionEngine/MCJIT/CMakeFiles/install-LLVMMCJIT.dir/clean

lib/ExecutionEngine/MCJIT/CMakeFiles/install-LLVMMCJIT.dir/depend:
	cd /mnt/cilk-plus-futures/Tapir/src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/cilk-plus-futures/Tapir/src /mnt/cilk-plus-futures/Tapir/src/lib/ExecutionEngine/MCJIT /mnt/cilk-plus-futures/Tapir/src/build /mnt/cilk-plus-futures/Tapir/src/build/lib/ExecutionEngine/MCJIT /mnt/cilk-plus-futures/Tapir/src/build/lib/ExecutionEngine/MCJIT/CMakeFiles/install-LLVMMCJIT.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/ExecutionEngine/MCJIT/CMakeFiles/install-LLVMMCJIT.dir/depend

