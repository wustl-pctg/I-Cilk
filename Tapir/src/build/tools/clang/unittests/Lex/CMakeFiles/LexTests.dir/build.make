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
include tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/depend.make

# Include the progress variables for this target.
include tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/progress.make

# Include the compile flags for this target's objects.
include tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/flags.make

tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/HeaderMapTest.cpp.o: tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/flags.make
tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/HeaderMapTest.cpp.o: ../tools/clang/unittests/Lex/HeaderMapTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/cilk-plus-futures/Tapir/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/HeaderMapTest.cpp.o"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/clang/unittests/Lex && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LexTests.dir/HeaderMapTest.cpp.o -c /mnt/cilk-plus-futures/Tapir/src/tools/clang/unittests/Lex/HeaderMapTest.cpp

tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/HeaderMapTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LexTests.dir/HeaderMapTest.cpp.i"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/clang/unittests/Lex && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/cilk-plus-futures/Tapir/src/tools/clang/unittests/Lex/HeaderMapTest.cpp > CMakeFiles/LexTests.dir/HeaderMapTest.cpp.i

tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/HeaderMapTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LexTests.dir/HeaderMapTest.cpp.s"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/clang/unittests/Lex && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/cilk-plus-futures/Tapir/src/tools/clang/unittests/Lex/HeaderMapTest.cpp -o CMakeFiles/LexTests.dir/HeaderMapTest.cpp.s

tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/HeaderMapTest.cpp.o.requires:

.PHONY : tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/HeaderMapTest.cpp.o.requires

tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/HeaderMapTest.cpp.o.provides: tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/HeaderMapTest.cpp.o.requires
	$(MAKE) -f tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/build.make tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/HeaderMapTest.cpp.o.provides.build
.PHONY : tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/HeaderMapTest.cpp.o.provides

tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/HeaderMapTest.cpp.o.provides.build: tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/HeaderMapTest.cpp.o


tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/LexerTest.cpp.o: tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/flags.make
tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/LexerTest.cpp.o: ../tools/clang/unittests/Lex/LexerTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/cilk-plus-futures/Tapir/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/LexerTest.cpp.o"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/clang/unittests/Lex && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LexTests.dir/LexerTest.cpp.o -c /mnt/cilk-plus-futures/Tapir/src/tools/clang/unittests/Lex/LexerTest.cpp

tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/LexerTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LexTests.dir/LexerTest.cpp.i"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/clang/unittests/Lex && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/cilk-plus-futures/Tapir/src/tools/clang/unittests/Lex/LexerTest.cpp > CMakeFiles/LexTests.dir/LexerTest.cpp.i

tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/LexerTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LexTests.dir/LexerTest.cpp.s"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/clang/unittests/Lex && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/cilk-plus-futures/Tapir/src/tools/clang/unittests/Lex/LexerTest.cpp -o CMakeFiles/LexTests.dir/LexerTest.cpp.s

tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/LexerTest.cpp.o.requires:

.PHONY : tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/LexerTest.cpp.o.requires

tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/LexerTest.cpp.o.provides: tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/LexerTest.cpp.o.requires
	$(MAKE) -f tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/build.make tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/LexerTest.cpp.o.provides.build
.PHONY : tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/LexerTest.cpp.o.provides

tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/LexerTest.cpp.o.provides.build: tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/LexerTest.cpp.o


tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/PPCallbacksTest.cpp.o: tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/flags.make
tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/PPCallbacksTest.cpp.o: ../tools/clang/unittests/Lex/PPCallbacksTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/cilk-plus-futures/Tapir/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/PPCallbacksTest.cpp.o"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/clang/unittests/Lex && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LexTests.dir/PPCallbacksTest.cpp.o -c /mnt/cilk-plus-futures/Tapir/src/tools/clang/unittests/Lex/PPCallbacksTest.cpp

tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/PPCallbacksTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LexTests.dir/PPCallbacksTest.cpp.i"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/clang/unittests/Lex && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/cilk-plus-futures/Tapir/src/tools/clang/unittests/Lex/PPCallbacksTest.cpp > CMakeFiles/LexTests.dir/PPCallbacksTest.cpp.i

tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/PPCallbacksTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LexTests.dir/PPCallbacksTest.cpp.s"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/clang/unittests/Lex && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/cilk-plus-futures/Tapir/src/tools/clang/unittests/Lex/PPCallbacksTest.cpp -o CMakeFiles/LexTests.dir/PPCallbacksTest.cpp.s

tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/PPCallbacksTest.cpp.o.requires:

.PHONY : tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/PPCallbacksTest.cpp.o.requires

tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/PPCallbacksTest.cpp.o.provides: tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/PPCallbacksTest.cpp.o.requires
	$(MAKE) -f tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/build.make tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/PPCallbacksTest.cpp.o.provides.build
.PHONY : tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/PPCallbacksTest.cpp.o.provides

tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/PPCallbacksTest.cpp.o.provides.build: tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/PPCallbacksTest.cpp.o


tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/PPConditionalDirectiveRecordTest.cpp.o: tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/flags.make
tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/PPConditionalDirectiveRecordTest.cpp.o: ../tools/clang/unittests/Lex/PPConditionalDirectiveRecordTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/cilk-plus-futures/Tapir/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/PPConditionalDirectiveRecordTest.cpp.o"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/clang/unittests/Lex && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LexTests.dir/PPConditionalDirectiveRecordTest.cpp.o -c /mnt/cilk-plus-futures/Tapir/src/tools/clang/unittests/Lex/PPConditionalDirectiveRecordTest.cpp

tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/PPConditionalDirectiveRecordTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LexTests.dir/PPConditionalDirectiveRecordTest.cpp.i"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/clang/unittests/Lex && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/cilk-plus-futures/Tapir/src/tools/clang/unittests/Lex/PPConditionalDirectiveRecordTest.cpp > CMakeFiles/LexTests.dir/PPConditionalDirectiveRecordTest.cpp.i

tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/PPConditionalDirectiveRecordTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LexTests.dir/PPConditionalDirectiveRecordTest.cpp.s"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/clang/unittests/Lex && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/cilk-plus-futures/Tapir/src/tools/clang/unittests/Lex/PPConditionalDirectiveRecordTest.cpp -o CMakeFiles/LexTests.dir/PPConditionalDirectiveRecordTest.cpp.s

tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/PPConditionalDirectiveRecordTest.cpp.o.requires:

.PHONY : tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/PPConditionalDirectiveRecordTest.cpp.o.requires

tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/PPConditionalDirectiveRecordTest.cpp.o.provides: tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/PPConditionalDirectiveRecordTest.cpp.o.requires
	$(MAKE) -f tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/build.make tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/PPConditionalDirectiveRecordTest.cpp.o.provides.build
.PHONY : tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/PPConditionalDirectiveRecordTest.cpp.o.provides

tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/PPConditionalDirectiveRecordTest.cpp.o.provides.build: tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/PPConditionalDirectiveRecordTest.cpp.o


# Object files for target LexTests
LexTests_OBJECTS = \
"CMakeFiles/LexTests.dir/HeaderMapTest.cpp.o" \
"CMakeFiles/LexTests.dir/LexerTest.cpp.o" \
"CMakeFiles/LexTests.dir/PPCallbacksTest.cpp.o" \
"CMakeFiles/LexTests.dir/PPConditionalDirectiveRecordTest.cpp.o"

# External object files for target LexTests
LexTests_EXTERNAL_OBJECTS =

tools/clang/unittests/Lex/LexTests: tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/HeaderMapTest.cpp.o
tools/clang/unittests/Lex/LexTests: tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/LexerTest.cpp.o
tools/clang/unittests/Lex/LexTests: tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/PPCallbacksTest.cpp.o
tools/clang/unittests/Lex/LexTests: tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/PPConditionalDirectiveRecordTest.cpp.o
tools/clang/unittests/Lex/LexTests: tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/build.make
tools/clang/unittests/Lex/LexTests: lib/libLLVMSupport.a
tools/clang/unittests/Lex/LexTests: lib/libLLVMSupport.a
tools/clang/unittests/Lex/LexTests: lib/libgtest_main.a
tools/clang/unittests/Lex/LexTests: lib/libgtest.a
tools/clang/unittests/Lex/LexTests: lib/libclangAST.a
tools/clang/unittests/Lex/LexTests: lib/libclangBasic.a
tools/clang/unittests/Lex/LexTests: lib/libclangLex.a
tools/clang/unittests/Lex/LexTests: lib/libclangParse.a
tools/clang/unittests/Lex/LexTests: lib/libclangSema.a
tools/clang/unittests/Lex/LexTests: lib/libclangAnalysis.a
tools/clang/unittests/Lex/LexTests: lib/libclangEdit.a
tools/clang/unittests/Lex/LexTests: lib/libclangAST.a
tools/clang/unittests/Lex/LexTests: lib/libclangLex.a
tools/clang/unittests/Lex/LexTests: lib/libclangBasic.a
tools/clang/unittests/Lex/LexTests: lib/libLLVMCore.a
tools/clang/unittests/Lex/LexTests: lib/libLLVMBinaryFormat.a
tools/clang/unittests/Lex/LexTests: lib/libLLVMMCParser.a
tools/clang/unittests/Lex/LexTests: lib/libLLVMMC.a
tools/clang/unittests/Lex/LexTests: lib/libLLVMSupport.a
tools/clang/unittests/Lex/LexTests: lib/libLLVMDemangle.a
tools/clang/unittests/Lex/LexTests: tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/cilk-plus-futures/Tapir/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable LexTests"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/clang/unittests/Lex && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LexTests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/build: tools/clang/unittests/Lex/LexTests

.PHONY : tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/build

tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/requires: tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/HeaderMapTest.cpp.o.requires
tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/requires: tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/LexerTest.cpp.o.requires
tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/requires: tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/PPCallbacksTest.cpp.o.requires
tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/requires: tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/PPConditionalDirectiveRecordTest.cpp.o.requires

.PHONY : tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/requires

tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/clean:
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/clang/unittests/Lex && $(CMAKE_COMMAND) -P CMakeFiles/LexTests.dir/cmake_clean.cmake
.PHONY : tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/clean

tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/depend:
	cd /mnt/cilk-plus-futures/Tapir/src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/cilk-plus-futures/Tapir/src /mnt/cilk-plus-futures/Tapir/src/tools/clang/unittests/Lex /mnt/cilk-plus-futures/Tapir/src/build /mnt/cilk-plus-futures/Tapir/src/build/tools/clang/unittests/Lex /mnt/cilk-plus-futures/Tapir/src/build/tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tools/clang/unittests/Lex/CMakeFiles/LexTests.dir/depend

