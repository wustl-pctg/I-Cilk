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
include tools/clang/unittests/StaticAnalyzer/CMakeFiles/StaticAnalysisTests.dir/depend.make

# Include the progress variables for this target.
include tools/clang/unittests/StaticAnalyzer/CMakeFiles/StaticAnalysisTests.dir/progress.make

# Include the compile flags for this target's objects.
include tools/clang/unittests/StaticAnalyzer/CMakeFiles/StaticAnalysisTests.dir/flags.make

tools/clang/unittests/StaticAnalyzer/CMakeFiles/StaticAnalysisTests.dir/AnalyzerOptionsTest.cpp.o: tools/clang/unittests/StaticAnalyzer/CMakeFiles/StaticAnalysisTests.dir/flags.make
tools/clang/unittests/StaticAnalyzer/CMakeFiles/StaticAnalysisTests.dir/AnalyzerOptionsTest.cpp.o: ../tools/clang/unittests/StaticAnalyzer/AnalyzerOptionsTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/cilk-plus-futures/Tapir/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tools/clang/unittests/StaticAnalyzer/CMakeFiles/StaticAnalysisTests.dir/AnalyzerOptionsTest.cpp.o"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/clang/unittests/StaticAnalyzer && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/StaticAnalysisTests.dir/AnalyzerOptionsTest.cpp.o -c /mnt/cilk-plus-futures/Tapir/src/tools/clang/unittests/StaticAnalyzer/AnalyzerOptionsTest.cpp

tools/clang/unittests/StaticAnalyzer/CMakeFiles/StaticAnalysisTests.dir/AnalyzerOptionsTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/StaticAnalysisTests.dir/AnalyzerOptionsTest.cpp.i"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/clang/unittests/StaticAnalyzer && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/cilk-plus-futures/Tapir/src/tools/clang/unittests/StaticAnalyzer/AnalyzerOptionsTest.cpp > CMakeFiles/StaticAnalysisTests.dir/AnalyzerOptionsTest.cpp.i

tools/clang/unittests/StaticAnalyzer/CMakeFiles/StaticAnalysisTests.dir/AnalyzerOptionsTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/StaticAnalysisTests.dir/AnalyzerOptionsTest.cpp.s"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/clang/unittests/StaticAnalyzer && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/cilk-plus-futures/Tapir/src/tools/clang/unittests/StaticAnalyzer/AnalyzerOptionsTest.cpp -o CMakeFiles/StaticAnalysisTests.dir/AnalyzerOptionsTest.cpp.s

tools/clang/unittests/StaticAnalyzer/CMakeFiles/StaticAnalysisTests.dir/AnalyzerOptionsTest.cpp.o.requires:

.PHONY : tools/clang/unittests/StaticAnalyzer/CMakeFiles/StaticAnalysisTests.dir/AnalyzerOptionsTest.cpp.o.requires

tools/clang/unittests/StaticAnalyzer/CMakeFiles/StaticAnalysisTests.dir/AnalyzerOptionsTest.cpp.o.provides: tools/clang/unittests/StaticAnalyzer/CMakeFiles/StaticAnalysisTests.dir/AnalyzerOptionsTest.cpp.o.requires
	$(MAKE) -f tools/clang/unittests/StaticAnalyzer/CMakeFiles/StaticAnalysisTests.dir/build.make tools/clang/unittests/StaticAnalyzer/CMakeFiles/StaticAnalysisTests.dir/AnalyzerOptionsTest.cpp.o.provides.build
.PHONY : tools/clang/unittests/StaticAnalyzer/CMakeFiles/StaticAnalysisTests.dir/AnalyzerOptionsTest.cpp.o.provides

tools/clang/unittests/StaticAnalyzer/CMakeFiles/StaticAnalysisTests.dir/AnalyzerOptionsTest.cpp.o.provides.build: tools/clang/unittests/StaticAnalyzer/CMakeFiles/StaticAnalysisTests.dir/AnalyzerOptionsTest.cpp.o


# Object files for target StaticAnalysisTests
StaticAnalysisTests_OBJECTS = \
"CMakeFiles/StaticAnalysisTests.dir/AnalyzerOptionsTest.cpp.o"

# External object files for target StaticAnalysisTests
StaticAnalysisTests_EXTERNAL_OBJECTS =

tools/clang/unittests/StaticAnalyzer/StaticAnalysisTests: tools/clang/unittests/StaticAnalyzer/CMakeFiles/StaticAnalysisTests.dir/AnalyzerOptionsTest.cpp.o
tools/clang/unittests/StaticAnalyzer/StaticAnalysisTests: tools/clang/unittests/StaticAnalyzer/CMakeFiles/StaticAnalysisTests.dir/build.make
tools/clang/unittests/StaticAnalyzer/StaticAnalysisTests: lib/libLLVMSupport.a
tools/clang/unittests/StaticAnalyzer/StaticAnalysisTests: lib/libLLVMSupport.a
tools/clang/unittests/StaticAnalyzer/StaticAnalysisTests: lib/libgtest_main.a
tools/clang/unittests/StaticAnalyzer/StaticAnalysisTests: lib/libgtest.a
tools/clang/unittests/StaticAnalyzer/StaticAnalysisTests: lib/libclangBasic.a
tools/clang/unittests/StaticAnalyzer/StaticAnalysisTests: lib/libclangAnalysis.a
tools/clang/unittests/StaticAnalyzer/StaticAnalysisTests: lib/libclangStaticAnalyzerCore.a
tools/clang/unittests/StaticAnalyzer/StaticAnalysisTests: lib/libclangAnalysis.a
tools/clang/unittests/StaticAnalyzer/StaticAnalysisTests: lib/libclangAST.a
tools/clang/unittests/StaticAnalyzer/StaticAnalysisTests: lib/libclangRewrite.a
tools/clang/unittests/StaticAnalyzer/StaticAnalysisTests: lib/libclangLex.a
tools/clang/unittests/StaticAnalyzer/StaticAnalysisTests: lib/libclangBasic.a
tools/clang/unittests/StaticAnalyzer/StaticAnalysisTests: lib/libLLVMCore.a
tools/clang/unittests/StaticAnalyzer/StaticAnalysisTests: lib/libLLVMBinaryFormat.a
tools/clang/unittests/StaticAnalyzer/StaticAnalysisTests: lib/libLLVMMC.a
tools/clang/unittests/StaticAnalyzer/StaticAnalysisTests: lib/libLLVMSupport.a
tools/clang/unittests/StaticAnalyzer/StaticAnalysisTests: lib/libLLVMDemangle.a
tools/clang/unittests/StaticAnalyzer/StaticAnalysisTests: tools/clang/unittests/StaticAnalyzer/CMakeFiles/StaticAnalysisTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/cilk-plus-futures/Tapir/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable StaticAnalysisTests"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/clang/unittests/StaticAnalyzer && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/StaticAnalysisTests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tools/clang/unittests/StaticAnalyzer/CMakeFiles/StaticAnalysisTests.dir/build: tools/clang/unittests/StaticAnalyzer/StaticAnalysisTests

.PHONY : tools/clang/unittests/StaticAnalyzer/CMakeFiles/StaticAnalysisTests.dir/build

tools/clang/unittests/StaticAnalyzer/CMakeFiles/StaticAnalysisTests.dir/requires: tools/clang/unittests/StaticAnalyzer/CMakeFiles/StaticAnalysisTests.dir/AnalyzerOptionsTest.cpp.o.requires

.PHONY : tools/clang/unittests/StaticAnalyzer/CMakeFiles/StaticAnalysisTests.dir/requires

tools/clang/unittests/StaticAnalyzer/CMakeFiles/StaticAnalysisTests.dir/clean:
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/clang/unittests/StaticAnalyzer && $(CMAKE_COMMAND) -P CMakeFiles/StaticAnalysisTests.dir/cmake_clean.cmake
.PHONY : tools/clang/unittests/StaticAnalyzer/CMakeFiles/StaticAnalysisTests.dir/clean

tools/clang/unittests/StaticAnalyzer/CMakeFiles/StaticAnalysisTests.dir/depend:
	cd /mnt/cilk-plus-futures/Tapir/src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/cilk-plus-futures/Tapir/src /mnt/cilk-plus-futures/Tapir/src/tools/clang/unittests/StaticAnalyzer /mnt/cilk-plus-futures/Tapir/src/build /mnt/cilk-plus-futures/Tapir/src/build/tools/clang/unittests/StaticAnalyzer /mnt/cilk-plus-futures/Tapir/src/build/tools/clang/unittests/StaticAnalyzer/CMakeFiles/StaticAnalysisTests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tools/clang/unittests/StaticAnalyzer/CMakeFiles/StaticAnalysisTests.dir/depend

