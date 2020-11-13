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

# Include any dependencies generated for this target.
include lib/Linker/CMakeFiles/LLVMLinker.dir/depend.make

# Include the progress variables for this target.
include lib/Linker/CMakeFiles/LLVMLinker.dir/progress.make

# Include the compile flags for this target's objects.
include lib/Linker/CMakeFiles/LLVMLinker.dir/flags.make

lib/Linker/CMakeFiles/LLVMLinker.dir/IRMover.cpp.o: lib/Linker/CMakeFiles/LLVMLinker.dir/flags.make
lib/Linker/CMakeFiles/LLVMLinker.dir/IRMover.cpp.o: ../lib/Linker/IRMover.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/cilk-plus-futures/Tapir/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/Linker/CMakeFiles/LLVMLinker.dir/IRMover.cpp.o"
	cd /mnt/cilk-plus-futures/Tapir/src/build/lib/Linker && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LLVMLinker.dir/IRMover.cpp.o -c /mnt/cilk-plus-futures/Tapir/src/lib/Linker/IRMover.cpp

lib/Linker/CMakeFiles/LLVMLinker.dir/IRMover.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LLVMLinker.dir/IRMover.cpp.i"
	cd /mnt/cilk-plus-futures/Tapir/src/build/lib/Linker && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/cilk-plus-futures/Tapir/src/lib/Linker/IRMover.cpp > CMakeFiles/LLVMLinker.dir/IRMover.cpp.i

lib/Linker/CMakeFiles/LLVMLinker.dir/IRMover.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LLVMLinker.dir/IRMover.cpp.s"
	cd /mnt/cilk-plus-futures/Tapir/src/build/lib/Linker && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/cilk-plus-futures/Tapir/src/lib/Linker/IRMover.cpp -o CMakeFiles/LLVMLinker.dir/IRMover.cpp.s

lib/Linker/CMakeFiles/LLVMLinker.dir/IRMover.cpp.o.requires:

.PHONY : lib/Linker/CMakeFiles/LLVMLinker.dir/IRMover.cpp.o.requires

lib/Linker/CMakeFiles/LLVMLinker.dir/IRMover.cpp.o.provides: lib/Linker/CMakeFiles/LLVMLinker.dir/IRMover.cpp.o.requires
	$(MAKE) -f lib/Linker/CMakeFiles/LLVMLinker.dir/build.make lib/Linker/CMakeFiles/LLVMLinker.dir/IRMover.cpp.o.provides.build
.PHONY : lib/Linker/CMakeFiles/LLVMLinker.dir/IRMover.cpp.o.provides

lib/Linker/CMakeFiles/LLVMLinker.dir/IRMover.cpp.o.provides.build: lib/Linker/CMakeFiles/LLVMLinker.dir/IRMover.cpp.o


lib/Linker/CMakeFiles/LLVMLinker.dir/LinkModules.cpp.o: lib/Linker/CMakeFiles/LLVMLinker.dir/flags.make
lib/Linker/CMakeFiles/LLVMLinker.dir/LinkModules.cpp.o: ../lib/Linker/LinkModules.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/cilk-plus-futures/Tapir/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object lib/Linker/CMakeFiles/LLVMLinker.dir/LinkModules.cpp.o"
	cd /mnt/cilk-plus-futures/Tapir/src/build/lib/Linker && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LLVMLinker.dir/LinkModules.cpp.o -c /mnt/cilk-plus-futures/Tapir/src/lib/Linker/LinkModules.cpp

lib/Linker/CMakeFiles/LLVMLinker.dir/LinkModules.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LLVMLinker.dir/LinkModules.cpp.i"
	cd /mnt/cilk-plus-futures/Tapir/src/build/lib/Linker && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/cilk-plus-futures/Tapir/src/lib/Linker/LinkModules.cpp > CMakeFiles/LLVMLinker.dir/LinkModules.cpp.i

lib/Linker/CMakeFiles/LLVMLinker.dir/LinkModules.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LLVMLinker.dir/LinkModules.cpp.s"
	cd /mnt/cilk-plus-futures/Tapir/src/build/lib/Linker && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/cilk-plus-futures/Tapir/src/lib/Linker/LinkModules.cpp -o CMakeFiles/LLVMLinker.dir/LinkModules.cpp.s

lib/Linker/CMakeFiles/LLVMLinker.dir/LinkModules.cpp.o.requires:

.PHONY : lib/Linker/CMakeFiles/LLVMLinker.dir/LinkModules.cpp.o.requires

lib/Linker/CMakeFiles/LLVMLinker.dir/LinkModules.cpp.o.provides: lib/Linker/CMakeFiles/LLVMLinker.dir/LinkModules.cpp.o.requires
	$(MAKE) -f lib/Linker/CMakeFiles/LLVMLinker.dir/build.make lib/Linker/CMakeFiles/LLVMLinker.dir/LinkModules.cpp.o.provides.build
.PHONY : lib/Linker/CMakeFiles/LLVMLinker.dir/LinkModules.cpp.o.provides

lib/Linker/CMakeFiles/LLVMLinker.dir/LinkModules.cpp.o.provides.build: lib/Linker/CMakeFiles/LLVMLinker.dir/LinkModules.cpp.o


# Object files for target LLVMLinker
LLVMLinker_OBJECTS = \
"CMakeFiles/LLVMLinker.dir/IRMover.cpp.o" \
"CMakeFiles/LLVMLinker.dir/LinkModules.cpp.o"

# External object files for target LLVMLinker
LLVMLinker_EXTERNAL_OBJECTS =

lib/libLLVMLinker.a: lib/Linker/CMakeFiles/LLVMLinker.dir/IRMover.cpp.o
lib/libLLVMLinker.a: lib/Linker/CMakeFiles/LLVMLinker.dir/LinkModules.cpp.o
lib/libLLVMLinker.a: lib/Linker/CMakeFiles/LLVMLinker.dir/build.make
lib/libLLVMLinker.a: lib/Linker/CMakeFiles/LLVMLinker.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/cilk-plus-futures/Tapir/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library ../libLLVMLinker.a"
	cd /mnt/cilk-plus-futures/Tapir/src/build/lib/Linker && $(CMAKE_COMMAND) -P CMakeFiles/LLVMLinker.dir/cmake_clean_target.cmake
	cd /mnt/cilk-plus-futures/Tapir/src/build/lib/Linker && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LLVMLinker.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/Linker/CMakeFiles/LLVMLinker.dir/build: lib/libLLVMLinker.a

.PHONY : lib/Linker/CMakeFiles/LLVMLinker.dir/build

lib/Linker/CMakeFiles/LLVMLinker.dir/requires: lib/Linker/CMakeFiles/LLVMLinker.dir/IRMover.cpp.o.requires
lib/Linker/CMakeFiles/LLVMLinker.dir/requires: lib/Linker/CMakeFiles/LLVMLinker.dir/LinkModules.cpp.o.requires

.PHONY : lib/Linker/CMakeFiles/LLVMLinker.dir/requires

lib/Linker/CMakeFiles/LLVMLinker.dir/clean:
	cd /mnt/cilk-plus-futures/Tapir/src/build/lib/Linker && $(CMAKE_COMMAND) -P CMakeFiles/LLVMLinker.dir/cmake_clean.cmake
.PHONY : lib/Linker/CMakeFiles/LLVMLinker.dir/clean

lib/Linker/CMakeFiles/LLVMLinker.dir/depend:
	cd /mnt/cilk-plus-futures/Tapir/src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/cilk-plus-futures/Tapir/src /mnt/cilk-plus-futures/Tapir/src/lib/Linker /mnt/cilk-plus-futures/Tapir/src/build /mnt/cilk-plus-futures/Tapir/src/build/lib/Linker /mnt/cilk-plus-futures/Tapir/src/build/lib/Linker/CMakeFiles/LLVMLinker.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/Linker/CMakeFiles/LLVMLinker.dir/depend

