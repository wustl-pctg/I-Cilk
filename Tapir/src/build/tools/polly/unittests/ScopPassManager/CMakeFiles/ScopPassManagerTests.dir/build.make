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
include tools/polly/unittests/ScopPassManager/CMakeFiles/ScopPassManagerTests.dir/depend.make

# Include the progress variables for this target.
include tools/polly/unittests/ScopPassManager/CMakeFiles/ScopPassManagerTests.dir/progress.make

# Include the compile flags for this target's objects.
include tools/polly/unittests/ScopPassManager/CMakeFiles/ScopPassManagerTests.dir/flags.make

tools/polly/unittests/ScopPassManager/CMakeFiles/ScopPassManagerTests.dir/PassManagerTest.cpp.o: tools/polly/unittests/ScopPassManager/CMakeFiles/ScopPassManagerTests.dir/flags.make
tools/polly/unittests/ScopPassManager/CMakeFiles/ScopPassManagerTests.dir/PassManagerTest.cpp.o: ../tools/polly/unittests/ScopPassManager/PassManagerTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/cilk-plus-futures/Tapir/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tools/polly/unittests/ScopPassManager/CMakeFiles/ScopPassManagerTests.dir/PassManagerTest.cpp.o"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/polly/unittests/ScopPassManager && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ScopPassManagerTests.dir/PassManagerTest.cpp.o -c /mnt/cilk-plus-futures/Tapir/src/tools/polly/unittests/ScopPassManager/PassManagerTest.cpp

tools/polly/unittests/ScopPassManager/CMakeFiles/ScopPassManagerTests.dir/PassManagerTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ScopPassManagerTests.dir/PassManagerTest.cpp.i"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/polly/unittests/ScopPassManager && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/cilk-plus-futures/Tapir/src/tools/polly/unittests/ScopPassManager/PassManagerTest.cpp > CMakeFiles/ScopPassManagerTests.dir/PassManagerTest.cpp.i

tools/polly/unittests/ScopPassManager/CMakeFiles/ScopPassManagerTests.dir/PassManagerTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ScopPassManagerTests.dir/PassManagerTest.cpp.s"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/polly/unittests/ScopPassManager && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/cilk-plus-futures/Tapir/src/tools/polly/unittests/ScopPassManager/PassManagerTest.cpp -o CMakeFiles/ScopPassManagerTests.dir/PassManagerTest.cpp.s

tools/polly/unittests/ScopPassManager/CMakeFiles/ScopPassManagerTests.dir/PassManagerTest.cpp.o.requires:

.PHONY : tools/polly/unittests/ScopPassManager/CMakeFiles/ScopPassManagerTests.dir/PassManagerTest.cpp.o.requires

tools/polly/unittests/ScopPassManager/CMakeFiles/ScopPassManagerTests.dir/PassManagerTest.cpp.o.provides: tools/polly/unittests/ScopPassManager/CMakeFiles/ScopPassManagerTests.dir/PassManagerTest.cpp.o.requires
	$(MAKE) -f tools/polly/unittests/ScopPassManager/CMakeFiles/ScopPassManagerTests.dir/build.make tools/polly/unittests/ScopPassManager/CMakeFiles/ScopPassManagerTests.dir/PassManagerTest.cpp.o.provides.build
.PHONY : tools/polly/unittests/ScopPassManager/CMakeFiles/ScopPassManagerTests.dir/PassManagerTest.cpp.o.provides

tools/polly/unittests/ScopPassManager/CMakeFiles/ScopPassManagerTests.dir/PassManagerTest.cpp.o.provides.build: tools/polly/unittests/ScopPassManager/CMakeFiles/ScopPassManagerTests.dir/PassManagerTest.cpp.o


# Object files for target ScopPassManagerTests
ScopPassManagerTests_OBJECTS = \
"CMakeFiles/ScopPassManagerTests.dir/PassManagerTest.cpp.o"

# External object files for target ScopPassManagerTests
ScopPassManagerTests_EXTERNAL_OBJECTS =

tools/polly/unittests/ScopPassManager/ScopPassManagerTests: tools/polly/unittests/ScopPassManager/CMakeFiles/ScopPassManagerTests.dir/PassManagerTest.cpp.o
tools/polly/unittests/ScopPassManager/ScopPassManagerTests: tools/polly/unittests/ScopPassManager/CMakeFiles/ScopPassManagerTests.dir/build.make
tools/polly/unittests/ScopPassManager/ScopPassManagerTests: lib/libLLVMSupport.a
tools/polly/unittests/ScopPassManager/ScopPassManagerTests: lib/libgtest_main.a
tools/polly/unittests/ScopPassManager/ScopPassManagerTests: lib/libgtest.a
tools/polly/unittests/ScopPassManager/ScopPassManagerTests: lib/libPolly.a
tools/polly/unittests/ScopPassManager/ScopPassManagerTests: lib/libPollyISL.a
tools/polly/unittests/ScopPassManager/ScopPassManagerTests: lib/libLLVMPasses.a
tools/polly/unittests/ScopPassManager/ScopPassManagerTests: lib/libLLVMipo.a
tools/polly/unittests/ScopPassManager/ScopPassManagerTests: lib/libLLVMIRReader.a
tools/polly/unittests/ScopPassManager/ScopPassManagerTests: lib/libLLVMAsmParser.a
tools/polly/unittests/ScopPassManager/ScopPassManagerTests: lib/libLLVMLinker.a
tools/polly/unittests/ScopPassManager/ScopPassManagerTests: lib/libLLVMTapirOpts.a
tools/polly/unittests/ScopPassManager/ScopPassManagerTests: lib/libLLVMInstrumentation.a
tools/polly/unittests/ScopPassManager/ScopPassManagerTests: lib/libLLVMCodeGen.a
tools/polly/unittests/ScopPassManager/ScopPassManagerTests: lib/libLLVMScalarOpts.a
tools/polly/unittests/ScopPassManager/ScopPassManagerTests: lib/libLLVMInstCombine.a
tools/polly/unittests/ScopPassManager/ScopPassManagerTests: lib/libLLVMBitWriter.a
tools/polly/unittests/ScopPassManager/ScopPassManagerTests: lib/libLLVMTarget.a
tools/polly/unittests/ScopPassManager/ScopPassManagerTests: lib/libLLVMVectorize.a
tools/polly/unittests/ScopPassManager/ScopPassManagerTests: lib/libLLVMTransformUtils.a
tools/polly/unittests/ScopPassManager/ScopPassManagerTests: lib/libLLVMAnalysis.a
tools/polly/unittests/ScopPassManager/ScopPassManagerTests: lib/libLLVMObject.a
tools/polly/unittests/ScopPassManager/ScopPassManagerTests: lib/libLLVMBitReader.a
tools/polly/unittests/ScopPassManager/ScopPassManagerTests: lib/libLLVMMCParser.a
tools/polly/unittests/ScopPassManager/ScopPassManagerTests: lib/libLLVMMC.a
tools/polly/unittests/ScopPassManager/ScopPassManagerTests: lib/libLLVMProfileData.a
tools/polly/unittests/ScopPassManager/ScopPassManagerTests: lib/libLLVMCore.a
tools/polly/unittests/ScopPassManager/ScopPassManagerTests: lib/libLLVMBinaryFormat.a
tools/polly/unittests/ScopPassManager/ScopPassManagerTests: lib/libLLVMSupport.a
tools/polly/unittests/ScopPassManager/ScopPassManagerTests: lib/libLLVMDemangle.a
tools/polly/unittests/ScopPassManager/ScopPassManagerTests: tools/polly/unittests/ScopPassManager/CMakeFiles/ScopPassManagerTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/cilk-plus-futures/Tapir/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ScopPassManagerTests"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/polly/unittests/ScopPassManager && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ScopPassManagerTests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tools/polly/unittests/ScopPassManager/CMakeFiles/ScopPassManagerTests.dir/build: tools/polly/unittests/ScopPassManager/ScopPassManagerTests

.PHONY : tools/polly/unittests/ScopPassManager/CMakeFiles/ScopPassManagerTests.dir/build

tools/polly/unittests/ScopPassManager/CMakeFiles/ScopPassManagerTests.dir/requires: tools/polly/unittests/ScopPassManager/CMakeFiles/ScopPassManagerTests.dir/PassManagerTest.cpp.o.requires

.PHONY : tools/polly/unittests/ScopPassManager/CMakeFiles/ScopPassManagerTests.dir/requires

tools/polly/unittests/ScopPassManager/CMakeFiles/ScopPassManagerTests.dir/clean:
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/polly/unittests/ScopPassManager && $(CMAKE_COMMAND) -P CMakeFiles/ScopPassManagerTests.dir/cmake_clean.cmake
.PHONY : tools/polly/unittests/ScopPassManager/CMakeFiles/ScopPassManagerTests.dir/clean

tools/polly/unittests/ScopPassManager/CMakeFiles/ScopPassManagerTests.dir/depend:
	cd /mnt/cilk-plus-futures/Tapir/src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/cilk-plus-futures/Tapir/src /mnt/cilk-plus-futures/Tapir/src/tools/polly/unittests/ScopPassManager /mnt/cilk-plus-futures/Tapir/src/build /mnt/cilk-plus-futures/Tapir/src/build/tools/polly/unittests/ScopPassManager /mnt/cilk-plus-futures/Tapir/src/build/tools/polly/unittests/ScopPassManager/CMakeFiles/ScopPassManagerTests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tools/polly/unittests/ScopPassManager/CMakeFiles/ScopPassManagerTests.dir/depend
