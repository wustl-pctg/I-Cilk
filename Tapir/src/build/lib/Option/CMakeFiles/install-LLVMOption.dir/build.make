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

# Utility rule file for install-LLVMOption.

# Include the progress variables for this target.
include lib/Option/CMakeFiles/install-LLVMOption.dir/progress.make

lib/Option/CMakeFiles/install-LLVMOption: lib/libLLVMOption.a
	cd /mnt/cilk-plus-futures/Tapir/src/build/lib/Option && /usr/bin/cmake -DCMAKE_INSTALL_COMPONENT=LLVMOption -P /mnt/cilk-plus-futures/Tapir/src/build/cmake_install.cmake

install-LLVMOption: lib/Option/CMakeFiles/install-LLVMOption
install-LLVMOption: lib/Option/CMakeFiles/install-LLVMOption.dir/build.make

.PHONY : install-LLVMOption

# Rule to build all files generated by this target.
lib/Option/CMakeFiles/install-LLVMOption.dir/build: install-LLVMOption

.PHONY : lib/Option/CMakeFiles/install-LLVMOption.dir/build

lib/Option/CMakeFiles/install-LLVMOption.dir/clean:
	cd /mnt/cilk-plus-futures/Tapir/src/build/lib/Option && $(CMAKE_COMMAND) -P CMakeFiles/install-LLVMOption.dir/cmake_clean.cmake
.PHONY : lib/Option/CMakeFiles/install-LLVMOption.dir/clean

lib/Option/CMakeFiles/install-LLVMOption.dir/depend:
	cd /mnt/cilk-plus-futures/Tapir/src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/cilk-plus-futures/Tapir/src /mnt/cilk-plus-futures/Tapir/src/lib/Option /mnt/cilk-plus-futures/Tapir/src/build /mnt/cilk-plus-futures/Tapir/src/build/lib/Option /mnt/cilk-plus-futures/Tapir/src/build/lib/Option/CMakeFiles/install-LLVMOption.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/Option/CMakeFiles/install-LLVMOption.dir/depend

