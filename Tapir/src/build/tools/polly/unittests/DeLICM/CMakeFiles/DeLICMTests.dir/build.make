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
include tools/polly/unittests/DeLICM/CMakeFiles/DeLICMTests.dir/depend.make

# Include the progress variables for this target.
include tools/polly/unittests/DeLICM/CMakeFiles/DeLICMTests.dir/progress.make

# Include the compile flags for this target's objects.
include tools/polly/unittests/DeLICM/CMakeFiles/DeLICMTests.dir/flags.make

tools/polly/unittests/DeLICM/CMakeFiles/DeLICMTests.dir/DeLICMTest.cpp.o: tools/polly/unittests/DeLICM/CMakeFiles/DeLICMTests.dir/flags.make
tools/polly/unittests/DeLICM/CMakeFiles/DeLICMTests.dir/DeLICMTest.cpp.o: ../tools/polly/unittests/DeLICM/DeLICMTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/cilk-plus-futures/Tapir/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tools/polly/unittests/DeLICM/CMakeFiles/DeLICMTests.dir/DeLICMTest.cpp.o"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/polly/unittests/DeLICM && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DeLICMTests.dir/DeLICMTest.cpp.o -c /mnt/cilk-plus-futures/Tapir/src/tools/polly/unittests/DeLICM/DeLICMTest.cpp

tools/polly/unittests/DeLICM/CMakeFiles/DeLICMTests.dir/DeLICMTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DeLICMTests.dir/DeLICMTest.cpp.i"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/polly/unittests/DeLICM && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/cilk-plus-futures/Tapir/src/tools/polly/unittests/DeLICM/DeLICMTest.cpp > CMakeFiles/DeLICMTests.dir/DeLICMTest.cpp.i

tools/polly/unittests/DeLICM/CMakeFiles/DeLICMTests.dir/DeLICMTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DeLICMTests.dir/DeLICMTest.cpp.s"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/polly/unittests/DeLICM && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/cilk-plus-futures/Tapir/src/tools/polly/unittests/DeLICM/DeLICMTest.cpp -o CMakeFiles/DeLICMTests.dir/DeLICMTest.cpp.s

tools/polly/unittests/DeLICM/CMakeFiles/DeLICMTests.dir/DeLICMTest.cpp.o.requires:

.PHONY : tools/polly/unittests/DeLICM/CMakeFiles/DeLICMTests.dir/DeLICMTest.cpp.o.requires

tools/polly/unittests/DeLICM/CMakeFiles/DeLICMTests.dir/DeLICMTest.cpp.o.provides: tools/polly/unittests/DeLICM/CMakeFiles/DeLICMTests.dir/DeLICMTest.cpp.o.requires
	$(MAKE) -f tools/polly/unittests/DeLICM/CMakeFiles/DeLICMTests.dir/build.make tools/polly/unittests/DeLICM/CMakeFiles/DeLICMTests.dir/DeLICMTest.cpp.o.provides.build
.PHONY : tools/polly/unittests/DeLICM/CMakeFiles/DeLICMTests.dir/DeLICMTest.cpp.o.provides

tools/polly/unittests/DeLICM/CMakeFiles/DeLICMTests.dir/DeLICMTest.cpp.o.provides.build: tools/polly/unittests/DeLICM/CMakeFiles/DeLICMTests.dir/DeLICMTest.cpp.o


# Object files for target DeLICMTests
DeLICMTests_OBJECTS = \
"CMakeFiles/DeLICMTests.dir/DeLICMTest.cpp.o"

# External object files for target DeLICMTests
DeLICMTests_EXTERNAL_OBJECTS =

tools/polly/unittests/DeLICM/DeLICMTests: tools/polly/unittests/DeLICM/CMakeFiles/DeLICMTests.dir/DeLICMTest.cpp.o
tools/polly/unittests/DeLICM/DeLICMTests: tools/polly/unittests/DeLICM/CMakeFiles/DeLICMTests.dir/build.make
tools/polly/unittests/DeLICM/DeLICMTests: lib/libLLVMSupport.a
tools/polly/unittests/DeLICM/DeLICMTests: lib/libgtest_main.a
tools/polly/unittests/DeLICM/DeLICMTests: lib/libgtest.a
tools/polly/unittests/DeLICM/DeLICMTests: lib/libPolly.a
tools/polly/unittests/DeLICM/DeLICMTests: lib/libPollyISL.a
tools/polly/unittests/DeLICM/DeLICMTests: lib/libLLVMPasses.a
tools/polly/unittests/DeLICM/DeLICMTests: lib/libLLVMipo.a
tools/polly/unittests/DeLICM/DeLICMTests: lib/libLLVMIRReader.a
tools/polly/unittests/DeLICM/DeLICMTests: lib/libLLVMAsmParser.a
tools/polly/unittests/DeLICM/DeLICMTests: lib/libLLVMLinker.a
tools/polly/unittests/DeLICM/DeLICMTests: lib/libLLVMTapirOpts.a
tools/polly/unittests/DeLICM/DeLICMTests: lib/libLLVMInstrumentation.a
tools/polly/unittests/DeLICM/DeLICMTests: lib/libLLVMCodeGen.a
tools/polly/unittests/DeLICM/DeLICMTests: lib/libLLVMScalarOpts.a
tools/polly/unittests/DeLICM/DeLICMTests: lib/libLLVMInstCombine.a
tools/polly/unittests/DeLICM/DeLICMTests: lib/libLLVMBitWriter.a
tools/polly/unittests/DeLICM/DeLICMTests: lib/libLLVMTarget.a
tools/polly/unittests/DeLICM/DeLICMTests: lib/libLLVMVectorize.a
tools/polly/unittests/DeLICM/DeLICMTests: lib/libLLVMTransformUtils.a
tools/polly/unittests/DeLICM/DeLICMTests: lib/libLLVMAnalysis.a
tools/polly/unittests/DeLICM/DeLICMTests: lib/libLLVMObject.a
tools/polly/unittests/DeLICM/DeLICMTests: lib/libLLVMBitReader.a
tools/polly/unittests/DeLICM/DeLICMTests: lib/libLLVMMCParser.a
tools/polly/unittests/DeLICM/DeLICMTests: lib/libLLVMMC.a
tools/polly/unittests/DeLICM/DeLICMTests: lib/libLLVMProfileData.a
tools/polly/unittests/DeLICM/DeLICMTests: lib/libLLVMCore.a
tools/polly/unittests/DeLICM/DeLICMTests: lib/libLLVMBinaryFormat.a
tools/polly/unittests/DeLICM/DeLICMTests: lib/libLLVMSupport.a
tools/polly/unittests/DeLICM/DeLICMTests: lib/libLLVMDemangle.a
tools/polly/unittests/DeLICM/DeLICMTests: tools/polly/unittests/DeLICM/CMakeFiles/DeLICMTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/cilk-plus-futures/Tapir/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable DeLICMTests"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/polly/unittests/DeLICM && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DeLICMTests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tools/polly/unittests/DeLICM/CMakeFiles/DeLICMTests.dir/build: tools/polly/unittests/DeLICM/DeLICMTests

.PHONY : tools/polly/unittests/DeLICM/CMakeFiles/DeLICMTests.dir/build

tools/polly/unittests/DeLICM/CMakeFiles/DeLICMTests.dir/requires: tools/polly/unittests/DeLICM/CMakeFiles/DeLICMTests.dir/DeLICMTest.cpp.o.requires

.PHONY : tools/polly/unittests/DeLICM/CMakeFiles/DeLICMTests.dir/requires

tools/polly/unittests/DeLICM/CMakeFiles/DeLICMTests.dir/clean:
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/polly/unittests/DeLICM && $(CMAKE_COMMAND) -P CMakeFiles/DeLICMTests.dir/cmake_clean.cmake
.PHONY : tools/polly/unittests/DeLICM/CMakeFiles/DeLICMTests.dir/clean

tools/polly/unittests/DeLICM/CMakeFiles/DeLICMTests.dir/depend:
	cd /mnt/cilk-plus-futures/Tapir/src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/cilk-plus-futures/Tapir/src /mnt/cilk-plus-futures/Tapir/src/tools/polly/unittests/DeLICM /mnt/cilk-plus-futures/Tapir/src/build /mnt/cilk-plus-futures/Tapir/src/build/tools/polly/unittests/DeLICM /mnt/cilk-plus-futures/Tapir/src/build/tools/polly/unittests/DeLICM/CMakeFiles/DeLICMTests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tools/polly/unittests/DeLICM/CMakeFiles/DeLICMTests.dir/depend
