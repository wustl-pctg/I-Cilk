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
include tools/clang/unittests/Driver/CMakeFiles/ClangDriverTests.dir/depend.make

# Include the progress variables for this target.
include tools/clang/unittests/Driver/CMakeFiles/ClangDriverTests.dir/progress.make

# Include the compile flags for this target's objects.
include tools/clang/unittests/Driver/CMakeFiles/ClangDriverTests.dir/flags.make

tools/clang/unittests/Driver/CMakeFiles/ClangDriverTests.dir/DistroTest.cpp.o: tools/clang/unittests/Driver/CMakeFiles/ClangDriverTests.dir/flags.make
tools/clang/unittests/Driver/CMakeFiles/ClangDriverTests.dir/DistroTest.cpp.o: ../tools/clang/unittests/Driver/DistroTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/cilk-plus-futures/Tapir/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tools/clang/unittests/Driver/CMakeFiles/ClangDriverTests.dir/DistroTest.cpp.o"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/clang/unittests/Driver && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ClangDriverTests.dir/DistroTest.cpp.o -c /mnt/cilk-plus-futures/Tapir/src/tools/clang/unittests/Driver/DistroTest.cpp

tools/clang/unittests/Driver/CMakeFiles/ClangDriverTests.dir/DistroTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ClangDriverTests.dir/DistroTest.cpp.i"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/clang/unittests/Driver && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/cilk-plus-futures/Tapir/src/tools/clang/unittests/Driver/DistroTest.cpp > CMakeFiles/ClangDriverTests.dir/DistroTest.cpp.i

tools/clang/unittests/Driver/CMakeFiles/ClangDriverTests.dir/DistroTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ClangDriverTests.dir/DistroTest.cpp.s"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/clang/unittests/Driver && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/cilk-plus-futures/Tapir/src/tools/clang/unittests/Driver/DistroTest.cpp -o CMakeFiles/ClangDriverTests.dir/DistroTest.cpp.s

tools/clang/unittests/Driver/CMakeFiles/ClangDriverTests.dir/DistroTest.cpp.o.requires:

.PHONY : tools/clang/unittests/Driver/CMakeFiles/ClangDriverTests.dir/DistroTest.cpp.o.requires

tools/clang/unittests/Driver/CMakeFiles/ClangDriverTests.dir/DistroTest.cpp.o.provides: tools/clang/unittests/Driver/CMakeFiles/ClangDriverTests.dir/DistroTest.cpp.o.requires
	$(MAKE) -f tools/clang/unittests/Driver/CMakeFiles/ClangDriverTests.dir/build.make tools/clang/unittests/Driver/CMakeFiles/ClangDriverTests.dir/DistroTest.cpp.o.provides.build
.PHONY : tools/clang/unittests/Driver/CMakeFiles/ClangDriverTests.dir/DistroTest.cpp.o.provides

tools/clang/unittests/Driver/CMakeFiles/ClangDriverTests.dir/DistroTest.cpp.o.provides.build: tools/clang/unittests/Driver/CMakeFiles/ClangDriverTests.dir/DistroTest.cpp.o


tools/clang/unittests/Driver/CMakeFiles/ClangDriverTests.dir/ToolChainTest.cpp.o: tools/clang/unittests/Driver/CMakeFiles/ClangDriverTests.dir/flags.make
tools/clang/unittests/Driver/CMakeFiles/ClangDriverTests.dir/ToolChainTest.cpp.o: ../tools/clang/unittests/Driver/ToolChainTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/cilk-plus-futures/Tapir/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object tools/clang/unittests/Driver/CMakeFiles/ClangDriverTests.dir/ToolChainTest.cpp.o"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/clang/unittests/Driver && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ClangDriverTests.dir/ToolChainTest.cpp.o -c /mnt/cilk-plus-futures/Tapir/src/tools/clang/unittests/Driver/ToolChainTest.cpp

tools/clang/unittests/Driver/CMakeFiles/ClangDriverTests.dir/ToolChainTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ClangDriverTests.dir/ToolChainTest.cpp.i"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/clang/unittests/Driver && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/cilk-plus-futures/Tapir/src/tools/clang/unittests/Driver/ToolChainTest.cpp > CMakeFiles/ClangDriverTests.dir/ToolChainTest.cpp.i

tools/clang/unittests/Driver/CMakeFiles/ClangDriverTests.dir/ToolChainTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ClangDriverTests.dir/ToolChainTest.cpp.s"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/clang/unittests/Driver && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/cilk-plus-futures/Tapir/src/tools/clang/unittests/Driver/ToolChainTest.cpp -o CMakeFiles/ClangDriverTests.dir/ToolChainTest.cpp.s

tools/clang/unittests/Driver/CMakeFiles/ClangDriverTests.dir/ToolChainTest.cpp.o.requires:

.PHONY : tools/clang/unittests/Driver/CMakeFiles/ClangDriverTests.dir/ToolChainTest.cpp.o.requires

tools/clang/unittests/Driver/CMakeFiles/ClangDriverTests.dir/ToolChainTest.cpp.o.provides: tools/clang/unittests/Driver/CMakeFiles/ClangDriverTests.dir/ToolChainTest.cpp.o.requires
	$(MAKE) -f tools/clang/unittests/Driver/CMakeFiles/ClangDriverTests.dir/build.make tools/clang/unittests/Driver/CMakeFiles/ClangDriverTests.dir/ToolChainTest.cpp.o.provides.build
.PHONY : tools/clang/unittests/Driver/CMakeFiles/ClangDriverTests.dir/ToolChainTest.cpp.o.provides

tools/clang/unittests/Driver/CMakeFiles/ClangDriverTests.dir/ToolChainTest.cpp.o.provides.build: tools/clang/unittests/Driver/CMakeFiles/ClangDriverTests.dir/ToolChainTest.cpp.o


tools/clang/unittests/Driver/CMakeFiles/ClangDriverTests.dir/MultilibTest.cpp.o: tools/clang/unittests/Driver/CMakeFiles/ClangDriverTests.dir/flags.make
tools/clang/unittests/Driver/CMakeFiles/ClangDriverTests.dir/MultilibTest.cpp.o: ../tools/clang/unittests/Driver/MultilibTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/cilk-plus-futures/Tapir/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object tools/clang/unittests/Driver/CMakeFiles/ClangDriverTests.dir/MultilibTest.cpp.o"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/clang/unittests/Driver && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ClangDriverTests.dir/MultilibTest.cpp.o -c /mnt/cilk-plus-futures/Tapir/src/tools/clang/unittests/Driver/MultilibTest.cpp

tools/clang/unittests/Driver/CMakeFiles/ClangDriverTests.dir/MultilibTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ClangDriverTests.dir/MultilibTest.cpp.i"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/clang/unittests/Driver && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/cilk-plus-futures/Tapir/src/tools/clang/unittests/Driver/MultilibTest.cpp > CMakeFiles/ClangDriverTests.dir/MultilibTest.cpp.i

tools/clang/unittests/Driver/CMakeFiles/ClangDriverTests.dir/MultilibTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ClangDriverTests.dir/MultilibTest.cpp.s"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/clang/unittests/Driver && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/cilk-plus-futures/Tapir/src/tools/clang/unittests/Driver/MultilibTest.cpp -o CMakeFiles/ClangDriverTests.dir/MultilibTest.cpp.s

tools/clang/unittests/Driver/CMakeFiles/ClangDriverTests.dir/MultilibTest.cpp.o.requires:

.PHONY : tools/clang/unittests/Driver/CMakeFiles/ClangDriverTests.dir/MultilibTest.cpp.o.requires

tools/clang/unittests/Driver/CMakeFiles/ClangDriverTests.dir/MultilibTest.cpp.o.provides: tools/clang/unittests/Driver/CMakeFiles/ClangDriverTests.dir/MultilibTest.cpp.o.requires
	$(MAKE) -f tools/clang/unittests/Driver/CMakeFiles/ClangDriverTests.dir/build.make tools/clang/unittests/Driver/CMakeFiles/ClangDriverTests.dir/MultilibTest.cpp.o.provides.build
.PHONY : tools/clang/unittests/Driver/CMakeFiles/ClangDriverTests.dir/MultilibTest.cpp.o.provides

tools/clang/unittests/Driver/CMakeFiles/ClangDriverTests.dir/MultilibTest.cpp.o.provides.build: tools/clang/unittests/Driver/CMakeFiles/ClangDriverTests.dir/MultilibTest.cpp.o


# Object files for target ClangDriverTests
ClangDriverTests_OBJECTS = \
"CMakeFiles/ClangDriverTests.dir/DistroTest.cpp.o" \
"CMakeFiles/ClangDriverTests.dir/ToolChainTest.cpp.o" \
"CMakeFiles/ClangDriverTests.dir/MultilibTest.cpp.o"

# External object files for target ClangDriverTests
ClangDriverTests_EXTERNAL_OBJECTS =

tools/clang/unittests/Driver/ClangDriverTests: tools/clang/unittests/Driver/CMakeFiles/ClangDriverTests.dir/DistroTest.cpp.o
tools/clang/unittests/Driver/ClangDriverTests: tools/clang/unittests/Driver/CMakeFiles/ClangDriverTests.dir/ToolChainTest.cpp.o
tools/clang/unittests/Driver/ClangDriverTests: tools/clang/unittests/Driver/CMakeFiles/ClangDriverTests.dir/MultilibTest.cpp.o
tools/clang/unittests/Driver/ClangDriverTests: tools/clang/unittests/Driver/CMakeFiles/ClangDriverTests.dir/build.make
tools/clang/unittests/Driver/ClangDriverTests: lib/libLLVMSupport.a
tools/clang/unittests/Driver/ClangDriverTests: lib/libLLVMOption.a
tools/clang/unittests/Driver/ClangDriverTests: lib/libLLVMSupport.a
tools/clang/unittests/Driver/ClangDriverTests: lib/libgtest_main.a
tools/clang/unittests/Driver/ClangDriverTests: lib/libgtest.a
tools/clang/unittests/Driver/ClangDriverTests: lib/libclangDriver.a
tools/clang/unittests/Driver/ClangDriverTests: lib/libclangBasic.a
tools/clang/unittests/Driver/ClangDriverTests: lib/libLLVMOption.a
tools/clang/unittests/Driver/ClangDriverTests: lib/libLLVMCore.a
tools/clang/unittests/Driver/ClangDriverTests: lib/libLLVMMC.a
tools/clang/unittests/Driver/ClangDriverTests: lib/libLLVMBinaryFormat.a
tools/clang/unittests/Driver/ClangDriverTests: lib/libLLVMSupport.a
tools/clang/unittests/Driver/ClangDriverTests: lib/libLLVMDemangle.a
tools/clang/unittests/Driver/ClangDriverTests: tools/clang/unittests/Driver/CMakeFiles/ClangDriverTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/cilk-plus-futures/Tapir/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable ClangDriverTests"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/clang/unittests/Driver && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ClangDriverTests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tools/clang/unittests/Driver/CMakeFiles/ClangDriverTests.dir/build: tools/clang/unittests/Driver/ClangDriverTests

.PHONY : tools/clang/unittests/Driver/CMakeFiles/ClangDriverTests.dir/build

tools/clang/unittests/Driver/CMakeFiles/ClangDriverTests.dir/requires: tools/clang/unittests/Driver/CMakeFiles/ClangDriverTests.dir/DistroTest.cpp.o.requires
tools/clang/unittests/Driver/CMakeFiles/ClangDriverTests.dir/requires: tools/clang/unittests/Driver/CMakeFiles/ClangDriverTests.dir/ToolChainTest.cpp.o.requires
tools/clang/unittests/Driver/CMakeFiles/ClangDriverTests.dir/requires: tools/clang/unittests/Driver/CMakeFiles/ClangDriverTests.dir/MultilibTest.cpp.o.requires

.PHONY : tools/clang/unittests/Driver/CMakeFiles/ClangDriverTests.dir/requires

tools/clang/unittests/Driver/CMakeFiles/ClangDriverTests.dir/clean:
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/clang/unittests/Driver && $(CMAKE_COMMAND) -P CMakeFiles/ClangDriverTests.dir/cmake_clean.cmake
.PHONY : tools/clang/unittests/Driver/CMakeFiles/ClangDriverTests.dir/clean

tools/clang/unittests/Driver/CMakeFiles/ClangDriverTests.dir/depend:
	cd /mnt/cilk-plus-futures/Tapir/src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/cilk-plus-futures/Tapir/src /mnt/cilk-plus-futures/Tapir/src/tools/clang/unittests/Driver /mnt/cilk-plus-futures/Tapir/src/build /mnt/cilk-plus-futures/Tapir/src/build/tools/clang/unittests/Driver /mnt/cilk-plus-futures/Tapir/src/build/tools/clang/unittests/Driver/CMakeFiles/ClangDriverTests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tools/clang/unittests/Driver/CMakeFiles/ClangDriverTests.dir/depend

