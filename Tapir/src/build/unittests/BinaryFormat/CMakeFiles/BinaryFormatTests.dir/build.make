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
include unittests/BinaryFormat/CMakeFiles/BinaryFormatTests.dir/depend.make

# Include the progress variables for this target.
include unittests/BinaryFormat/CMakeFiles/BinaryFormatTests.dir/progress.make

# Include the compile flags for this target's objects.
include unittests/BinaryFormat/CMakeFiles/BinaryFormatTests.dir/flags.make

unittests/BinaryFormat/CMakeFiles/BinaryFormatTests.dir/DwarfTest.cpp.o: unittests/BinaryFormat/CMakeFiles/BinaryFormatTests.dir/flags.make
unittests/BinaryFormat/CMakeFiles/BinaryFormatTests.dir/DwarfTest.cpp.o: ../unittests/BinaryFormat/DwarfTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/cilk-plus-futures/Tapir/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object unittests/BinaryFormat/CMakeFiles/BinaryFormatTests.dir/DwarfTest.cpp.o"
	cd /mnt/cilk-plus-futures/Tapir/src/build/unittests/BinaryFormat && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BinaryFormatTests.dir/DwarfTest.cpp.o -c /mnt/cilk-plus-futures/Tapir/src/unittests/BinaryFormat/DwarfTest.cpp

unittests/BinaryFormat/CMakeFiles/BinaryFormatTests.dir/DwarfTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BinaryFormatTests.dir/DwarfTest.cpp.i"
	cd /mnt/cilk-plus-futures/Tapir/src/build/unittests/BinaryFormat && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/cilk-plus-futures/Tapir/src/unittests/BinaryFormat/DwarfTest.cpp > CMakeFiles/BinaryFormatTests.dir/DwarfTest.cpp.i

unittests/BinaryFormat/CMakeFiles/BinaryFormatTests.dir/DwarfTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BinaryFormatTests.dir/DwarfTest.cpp.s"
	cd /mnt/cilk-plus-futures/Tapir/src/build/unittests/BinaryFormat && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/cilk-plus-futures/Tapir/src/unittests/BinaryFormat/DwarfTest.cpp -o CMakeFiles/BinaryFormatTests.dir/DwarfTest.cpp.s

unittests/BinaryFormat/CMakeFiles/BinaryFormatTests.dir/DwarfTest.cpp.o.requires:

.PHONY : unittests/BinaryFormat/CMakeFiles/BinaryFormatTests.dir/DwarfTest.cpp.o.requires

unittests/BinaryFormat/CMakeFiles/BinaryFormatTests.dir/DwarfTest.cpp.o.provides: unittests/BinaryFormat/CMakeFiles/BinaryFormatTests.dir/DwarfTest.cpp.o.requires
	$(MAKE) -f unittests/BinaryFormat/CMakeFiles/BinaryFormatTests.dir/build.make unittests/BinaryFormat/CMakeFiles/BinaryFormatTests.dir/DwarfTest.cpp.o.provides.build
.PHONY : unittests/BinaryFormat/CMakeFiles/BinaryFormatTests.dir/DwarfTest.cpp.o.provides

unittests/BinaryFormat/CMakeFiles/BinaryFormatTests.dir/DwarfTest.cpp.o.provides.build: unittests/BinaryFormat/CMakeFiles/BinaryFormatTests.dir/DwarfTest.cpp.o


unittests/BinaryFormat/CMakeFiles/BinaryFormatTests.dir/TestFileMagic.cpp.o: unittests/BinaryFormat/CMakeFiles/BinaryFormatTests.dir/flags.make
unittests/BinaryFormat/CMakeFiles/BinaryFormatTests.dir/TestFileMagic.cpp.o: ../unittests/BinaryFormat/TestFileMagic.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/cilk-plus-futures/Tapir/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object unittests/BinaryFormat/CMakeFiles/BinaryFormatTests.dir/TestFileMagic.cpp.o"
	cd /mnt/cilk-plus-futures/Tapir/src/build/unittests/BinaryFormat && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BinaryFormatTests.dir/TestFileMagic.cpp.o -c /mnt/cilk-plus-futures/Tapir/src/unittests/BinaryFormat/TestFileMagic.cpp

unittests/BinaryFormat/CMakeFiles/BinaryFormatTests.dir/TestFileMagic.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BinaryFormatTests.dir/TestFileMagic.cpp.i"
	cd /mnt/cilk-plus-futures/Tapir/src/build/unittests/BinaryFormat && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/cilk-plus-futures/Tapir/src/unittests/BinaryFormat/TestFileMagic.cpp > CMakeFiles/BinaryFormatTests.dir/TestFileMagic.cpp.i

unittests/BinaryFormat/CMakeFiles/BinaryFormatTests.dir/TestFileMagic.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BinaryFormatTests.dir/TestFileMagic.cpp.s"
	cd /mnt/cilk-plus-futures/Tapir/src/build/unittests/BinaryFormat && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/cilk-plus-futures/Tapir/src/unittests/BinaryFormat/TestFileMagic.cpp -o CMakeFiles/BinaryFormatTests.dir/TestFileMagic.cpp.s

unittests/BinaryFormat/CMakeFiles/BinaryFormatTests.dir/TestFileMagic.cpp.o.requires:

.PHONY : unittests/BinaryFormat/CMakeFiles/BinaryFormatTests.dir/TestFileMagic.cpp.o.requires

unittests/BinaryFormat/CMakeFiles/BinaryFormatTests.dir/TestFileMagic.cpp.o.provides: unittests/BinaryFormat/CMakeFiles/BinaryFormatTests.dir/TestFileMagic.cpp.o.requires
	$(MAKE) -f unittests/BinaryFormat/CMakeFiles/BinaryFormatTests.dir/build.make unittests/BinaryFormat/CMakeFiles/BinaryFormatTests.dir/TestFileMagic.cpp.o.provides.build
.PHONY : unittests/BinaryFormat/CMakeFiles/BinaryFormatTests.dir/TestFileMagic.cpp.o.provides

unittests/BinaryFormat/CMakeFiles/BinaryFormatTests.dir/TestFileMagic.cpp.o.provides.build: unittests/BinaryFormat/CMakeFiles/BinaryFormatTests.dir/TestFileMagic.cpp.o


# Object files for target BinaryFormatTests
BinaryFormatTests_OBJECTS = \
"CMakeFiles/BinaryFormatTests.dir/DwarfTest.cpp.o" \
"CMakeFiles/BinaryFormatTests.dir/TestFileMagic.cpp.o"

# External object files for target BinaryFormatTests
BinaryFormatTests_EXTERNAL_OBJECTS =

unittests/BinaryFormat/BinaryFormatTests: unittests/BinaryFormat/CMakeFiles/BinaryFormatTests.dir/DwarfTest.cpp.o
unittests/BinaryFormat/BinaryFormatTests: unittests/BinaryFormat/CMakeFiles/BinaryFormatTests.dir/TestFileMagic.cpp.o
unittests/BinaryFormat/BinaryFormatTests: unittests/BinaryFormat/CMakeFiles/BinaryFormatTests.dir/build.make
unittests/BinaryFormat/BinaryFormatTests: lib/libLLVMBinaryFormat.a
unittests/BinaryFormat/BinaryFormatTests: lib/libLLVMSupport.a
unittests/BinaryFormat/BinaryFormatTests: lib/libgtest_main.a
unittests/BinaryFormat/BinaryFormatTests: lib/libgtest.a
unittests/BinaryFormat/BinaryFormatTests: lib/libLLVMSupport.a
unittests/BinaryFormat/BinaryFormatTests: lib/libLLVMDemangle.a
unittests/BinaryFormat/BinaryFormatTests: unittests/BinaryFormat/CMakeFiles/BinaryFormatTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/cilk-plus-futures/Tapir/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable BinaryFormatTests"
	cd /mnt/cilk-plus-futures/Tapir/src/build/unittests/BinaryFormat && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BinaryFormatTests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
unittests/BinaryFormat/CMakeFiles/BinaryFormatTests.dir/build: unittests/BinaryFormat/BinaryFormatTests

.PHONY : unittests/BinaryFormat/CMakeFiles/BinaryFormatTests.dir/build

unittests/BinaryFormat/CMakeFiles/BinaryFormatTests.dir/requires: unittests/BinaryFormat/CMakeFiles/BinaryFormatTests.dir/DwarfTest.cpp.o.requires
unittests/BinaryFormat/CMakeFiles/BinaryFormatTests.dir/requires: unittests/BinaryFormat/CMakeFiles/BinaryFormatTests.dir/TestFileMagic.cpp.o.requires

.PHONY : unittests/BinaryFormat/CMakeFiles/BinaryFormatTests.dir/requires

unittests/BinaryFormat/CMakeFiles/BinaryFormatTests.dir/clean:
	cd /mnt/cilk-plus-futures/Tapir/src/build/unittests/BinaryFormat && $(CMAKE_COMMAND) -P CMakeFiles/BinaryFormatTests.dir/cmake_clean.cmake
.PHONY : unittests/BinaryFormat/CMakeFiles/BinaryFormatTests.dir/clean

unittests/BinaryFormat/CMakeFiles/BinaryFormatTests.dir/depend:
	cd /mnt/cilk-plus-futures/Tapir/src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/cilk-plus-futures/Tapir/src /mnt/cilk-plus-futures/Tapir/src/unittests/BinaryFormat /mnt/cilk-plus-futures/Tapir/src/build /mnt/cilk-plus-futures/Tapir/src/build/unittests/BinaryFormat /mnt/cilk-plus-futures/Tapir/src/build/unittests/BinaryFormat/CMakeFiles/BinaryFormatTests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : unittests/BinaryFormat/CMakeFiles/BinaryFormatTests.dir/depend

