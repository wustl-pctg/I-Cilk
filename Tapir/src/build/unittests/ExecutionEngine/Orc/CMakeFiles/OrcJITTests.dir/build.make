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
include unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/depend.make

# Include the progress variables for this target.
include unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/progress.make

# Include the compile flags for this target's objects.
include unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/flags.make

unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/CompileOnDemandLayerTest.cpp.o: unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/flags.make
unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/CompileOnDemandLayerTest.cpp.o: ../unittests/ExecutionEngine/Orc/CompileOnDemandLayerTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/cilk-plus-futures/Tapir/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/CompileOnDemandLayerTest.cpp.o"
	cd /mnt/cilk-plus-futures/Tapir/src/build/unittests/ExecutionEngine/Orc && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OrcJITTests.dir/CompileOnDemandLayerTest.cpp.o -c /mnt/cilk-plus-futures/Tapir/src/unittests/ExecutionEngine/Orc/CompileOnDemandLayerTest.cpp

unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/CompileOnDemandLayerTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OrcJITTests.dir/CompileOnDemandLayerTest.cpp.i"
	cd /mnt/cilk-plus-futures/Tapir/src/build/unittests/ExecutionEngine/Orc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/cilk-plus-futures/Tapir/src/unittests/ExecutionEngine/Orc/CompileOnDemandLayerTest.cpp > CMakeFiles/OrcJITTests.dir/CompileOnDemandLayerTest.cpp.i

unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/CompileOnDemandLayerTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OrcJITTests.dir/CompileOnDemandLayerTest.cpp.s"
	cd /mnt/cilk-plus-futures/Tapir/src/build/unittests/ExecutionEngine/Orc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/cilk-plus-futures/Tapir/src/unittests/ExecutionEngine/Orc/CompileOnDemandLayerTest.cpp -o CMakeFiles/OrcJITTests.dir/CompileOnDemandLayerTest.cpp.s

unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/CompileOnDemandLayerTest.cpp.o.requires:

.PHONY : unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/CompileOnDemandLayerTest.cpp.o.requires

unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/CompileOnDemandLayerTest.cpp.o.provides: unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/CompileOnDemandLayerTest.cpp.o.requires
	$(MAKE) -f unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/build.make unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/CompileOnDemandLayerTest.cpp.o.provides.build
.PHONY : unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/CompileOnDemandLayerTest.cpp.o.provides

unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/CompileOnDemandLayerTest.cpp.o.provides.build: unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/CompileOnDemandLayerTest.cpp.o


unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/IndirectionUtilsTest.cpp.o: unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/flags.make
unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/IndirectionUtilsTest.cpp.o: ../unittests/ExecutionEngine/Orc/IndirectionUtilsTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/cilk-plus-futures/Tapir/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/IndirectionUtilsTest.cpp.o"
	cd /mnt/cilk-plus-futures/Tapir/src/build/unittests/ExecutionEngine/Orc && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OrcJITTests.dir/IndirectionUtilsTest.cpp.o -c /mnt/cilk-plus-futures/Tapir/src/unittests/ExecutionEngine/Orc/IndirectionUtilsTest.cpp

unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/IndirectionUtilsTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OrcJITTests.dir/IndirectionUtilsTest.cpp.i"
	cd /mnt/cilk-plus-futures/Tapir/src/build/unittests/ExecutionEngine/Orc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/cilk-plus-futures/Tapir/src/unittests/ExecutionEngine/Orc/IndirectionUtilsTest.cpp > CMakeFiles/OrcJITTests.dir/IndirectionUtilsTest.cpp.i

unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/IndirectionUtilsTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OrcJITTests.dir/IndirectionUtilsTest.cpp.s"
	cd /mnt/cilk-plus-futures/Tapir/src/build/unittests/ExecutionEngine/Orc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/cilk-plus-futures/Tapir/src/unittests/ExecutionEngine/Orc/IndirectionUtilsTest.cpp -o CMakeFiles/OrcJITTests.dir/IndirectionUtilsTest.cpp.s

unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/IndirectionUtilsTest.cpp.o.requires:

.PHONY : unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/IndirectionUtilsTest.cpp.o.requires

unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/IndirectionUtilsTest.cpp.o.provides: unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/IndirectionUtilsTest.cpp.o.requires
	$(MAKE) -f unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/build.make unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/IndirectionUtilsTest.cpp.o.provides.build
.PHONY : unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/IndirectionUtilsTest.cpp.o.provides

unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/IndirectionUtilsTest.cpp.o.provides.build: unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/IndirectionUtilsTest.cpp.o


unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/GlobalMappingLayerTest.cpp.o: unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/flags.make
unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/GlobalMappingLayerTest.cpp.o: ../unittests/ExecutionEngine/Orc/GlobalMappingLayerTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/cilk-plus-futures/Tapir/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/GlobalMappingLayerTest.cpp.o"
	cd /mnt/cilk-plus-futures/Tapir/src/build/unittests/ExecutionEngine/Orc && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OrcJITTests.dir/GlobalMappingLayerTest.cpp.o -c /mnt/cilk-plus-futures/Tapir/src/unittests/ExecutionEngine/Orc/GlobalMappingLayerTest.cpp

unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/GlobalMappingLayerTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OrcJITTests.dir/GlobalMappingLayerTest.cpp.i"
	cd /mnt/cilk-plus-futures/Tapir/src/build/unittests/ExecutionEngine/Orc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/cilk-plus-futures/Tapir/src/unittests/ExecutionEngine/Orc/GlobalMappingLayerTest.cpp > CMakeFiles/OrcJITTests.dir/GlobalMappingLayerTest.cpp.i

unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/GlobalMappingLayerTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OrcJITTests.dir/GlobalMappingLayerTest.cpp.s"
	cd /mnt/cilk-plus-futures/Tapir/src/build/unittests/ExecutionEngine/Orc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/cilk-plus-futures/Tapir/src/unittests/ExecutionEngine/Orc/GlobalMappingLayerTest.cpp -o CMakeFiles/OrcJITTests.dir/GlobalMappingLayerTest.cpp.s

unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/GlobalMappingLayerTest.cpp.o.requires:

.PHONY : unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/GlobalMappingLayerTest.cpp.o.requires

unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/GlobalMappingLayerTest.cpp.o.provides: unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/GlobalMappingLayerTest.cpp.o.requires
	$(MAKE) -f unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/build.make unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/GlobalMappingLayerTest.cpp.o.provides.build
.PHONY : unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/GlobalMappingLayerTest.cpp.o.provides

unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/GlobalMappingLayerTest.cpp.o.provides.build: unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/GlobalMappingLayerTest.cpp.o


unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/LazyEmittingLayerTest.cpp.o: unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/flags.make
unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/LazyEmittingLayerTest.cpp.o: ../unittests/ExecutionEngine/Orc/LazyEmittingLayerTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/cilk-plus-futures/Tapir/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/LazyEmittingLayerTest.cpp.o"
	cd /mnt/cilk-plus-futures/Tapir/src/build/unittests/ExecutionEngine/Orc && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OrcJITTests.dir/LazyEmittingLayerTest.cpp.o -c /mnt/cilk-plus-futures/Tapir/src/unittests/ExecutionEngine/Orc/LazyEmittingLayerTest.cpp

unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/LazyEmittingLayerTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OrcJITTests.dir/LazyEmittingLayerTest.cpp.i"
	cd /mnt/cilk-plus-futures/Tapir/src/build/unittests/ExecutionEngine/Orc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/cilk-plus-futures/Tapir/src/unittests/ExecutionEngine/Orc/LazyEmittingLayerTest.cpp > CMakeFiles/OrcJITTests.dir/LazyEmittingLayerTest.cpp.i

unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/LazyEmittingLayerTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OrcJITTests.dir/LazyEmittingLayerTest.cpp.s"
	cd /mnt/cilk-plus-futures/Tapir/src/build/unittests/ExecutionEngine/Orc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/cilk-plus-futures/Tapir/src/unittests/ExecutionEngine/Orc/LazyEmittingLayerTest.cpp -o CMakeFiles/OrcJITTests.dir/LazyEmittingLayerTest.cpp.s

unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/LazyEmittingLayerTest.cpp.o.requires:

.PHONY : unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/LazyEmittingLayerTest.cpp.o.requires

unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/LazyEmittingLayerTest.cpp.o.provides: unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/LazyEmittingLayerTest.cpp.o.requires
	$(MAKE) -f unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/build.make unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/LazyEmittingLayerTest.cpp.o.provides.build
.PHONY : unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/LazyEmittingLayerTest.cpp.o.provides

unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/LazyEmittingLayerTest.cpp.o.provides.build: unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/LazyEmittingLayerTest.cpp.o


unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/ObjectTransformLayerTest.cpp.o: unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/flags.make
unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/ObjectTransformLayerTest.cpp.o: ../unittests/ExecutionEngine/Orc/ObjectTransformLayerTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/cilk-plus-futures/Tapir/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/ObjectTransformLayerTest.cpp.o"
	cd /mnt/cilk-plus-futures/Tapir/src/build/unittests/ExecutionEngine/Orc && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OrcJITTests.dir/ObjectTransformLayerTest.cpp.o -c /mnt/cilk-plus-futures/Tapir/src/unittests/ExecutionEngine/Orc/ObjectTransformLayerTest.cpp

unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/ObjectTransformLayerTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OrcJITTests.dir/ObjectTransformLayerTest.cpp.i"
	cd /mnt/cilk-plus-futures/Tapir/src/build/unittests/ExecutionEngine/Orc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/cilk-plus-futures/Tapir/src/unittests/ExecutionEngine/Orc/ObjectTransformLayerTest.cpp > CMakeFiles/OrcJITTests.dir/ObjectTransformLayerTest.cpp.i

unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/ObjectTransformLayerTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OrcJITTests.dir/ObjectTransformLayerTest.cpp.s"
	cd /mnt/cilk-plus-futures/Tapir/src/build/unittests/ExecutionEngine/Orc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/cilk-plus-futures/Tapir/src/unittests/ExecutionEngine/Orc/ObjectTransformLayerTest.cpp -o CMakeFiles/OrcJITTests.dir/ObjectTransformLayerTest.cpp.s

unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/ObjectTransformLayerTest.cpp.o.requires:

.PHONY : unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/ObjectTransformLayerTest.cpp.o.requires

unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/ObjectTransformLayerTest.cpp.o.provides: unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/ObjectTransformLayerTest.cpp.o.requires
	$(MAKE) -f unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/build.make unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/ObjectTransformLayerTest.cpp.o.provides.build
.PHONY : unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/ObjectTransformLayerTest.cpp.o.provides

unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/ObjectTransformLayerTest.cpp.o.provides.build: unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/ObjectTransformLayerTest.cpp.o


unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/OrcCAPITest.cpp.o: unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/flags.make
unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/OrcCAPITest.cpp.o: ../unittests/ExecutionEngine/Orc/OrcCAPITest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/cilk-plus-futures/Tapir/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/OrcCAPITest.cpp.o"
	cd /mnt/cilk-plus-futures/Tapir/src/build/unittests/ExecutionEngine/Orc && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OrcJITTests.dir/OrcCAPITest.cpp.o -c /mnt/cilk-plus-futures/Tapir/src/unittests/ExecutionEngine/Orc/OrcCAPITest.cpp

unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/OrcCAPITest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OrcJITTests.dir/OrcCAPITest.cpp.i"
	cd /mnt/cilk-plus-futures/Tapir/src/build/unittests/ExecutionEngine/Orc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/cilk-plus-futures/Tapir/src/unittests/ExecutionEngine/Orc/OrcCAPITest.cpp > CMakeFiles/OrcJITTests.dir/OrcCAPITest.cpp.i

unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/OrcCAPITest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OrcJITTests.dir/OrcCAPITest.cpp.s"
	cd /mnt/cilk-plus-futures/Tapir/src/build/unittests/ExecutionEngine/Orc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/cilk-plus-futures/Tapir/src/unittests/ExecutionEngine/Orc/OrcCAPITest.cpp -o CMakeFiles/OrcJITTests.dir/OrcCAPITest.cpp.s

unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/OrcCAPITest.cpp.o.requires:

.PHONY : unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/OrcCAPITest.cpp.o.requires

unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/OrcCAPITest.cpp.o.provides: unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/OrcCAPITest.cpp.o.requires
	$(MAKE) -f unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/build.make unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/OrcCAPITest.cpp.o.provides.build
.PHONY : unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/OrcCAPITest.cpp.o.provides

unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/OrcCAPITest.cpp.o.provides.build: unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/OrcCAPITest.cpp.o


unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/OrcTestCommon.cpp.o: unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/flags.make
unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/OrcTestCommon.cpp.o: ../unittests/ExecutionEngine/Orc/OrcTestCommon.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/cilk-plus-futures/Tapir/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/OrcTestCommon.cpp.o"
	cd /mnt/cilk-plus-futures/Tapir/src/build/unittests/ExecutionEngine/Orc && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OrcJITTests.dir/OrcTestCommon.cpp.o -c /mnt/cilk-plus-futures/Tapir/src/unittests/ExecutionEngine/Orc/OrcTestCommon.cpp

unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/OrcTestCommon.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OrcJITTests.dir/OrcTestCommon.cpp.i"
	cd /mnt/cilk-plus-futures/Tapir/src/build/unittests/ExecutionEngine/Orc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/cilk-plus-futures/Tapir/src/unittests/ExecutionEngine/Orc/OrcTestCommon.cpp > CMakeFiles/OrcJITTests.dir/OrcTestCommon.cpp.i

unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/OrcTestCommon.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OrcJITTests.dir/OrcTestCommon.cpp.s"
	cd /mnt/cilk-plus-futures/Tapir/src/build/unittests/ExecutionEngine/Orc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/cilk-plus-futures/Tapir/src/unittests/ExecutionEngine/Orc/OrcTestCommon.cpp -o CMakeFiles/OrcJITTests.dir/OrcTestCommon.cpp.s

unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/OrcTestCommon.cpp.o.requires:

.PHONY : unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/OrcTestCommon.cpp.o.requires

unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/OrcTestCommon.cpp.o.provides: unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/OrcTestCommon.cpp.o.requires
	$(MAKE) -f unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/build.make unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/OrcTestCommon.cpp.o.provides.build
.PHONY : unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/OrcTestCommon.cpp.o.provides

unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/OrcTestCommon.cpp.o.provides.build: unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/OrcTestCommon.cpp.o


unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/QueueChannel.cpp.o: unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/flags.make
unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/QueueChannel.cpp.o: ../unittests/ExecutionEngine/Orc/QueueChannel.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/cilk-plus-futures/Tapir/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/QueueChannel.cpp.o"
	cd /mnt/cilk-plus-futures/Tapir/src/build/unittests/ExecutionEngine/Orc && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OrcJITTests.dir/QueueChannel.cpp.o -c /mnt/cilk-plus-futures/Tapir/src/unittests/ExecutionEngine/Orc/QueueChannel.cpp

unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/QueueChannel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OrcJITTests.dir/QueueChannel.cpp.i"
	cd /mnt/cilk-plus-futures/Tapir/src/build/unittests/ExecutionEngine/Orc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/cilk-plus-futures/Tapir/src/unittests/ExecutionEngine/Orc/QueueChannel.cpp > CMakeFiles/OrcJITTests.dir/QueueChannel.cpp.i

unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/QueueChannel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OrcJITTests.dir/QueueChannel.cpp.s"
	cd /mnt/cilk-plus-futures/Tapir/src/build/unittests/ExecutionEngine/Orc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/cilk-plus-futures/Tapir/src/unittests/ExecutionEngine/Orc/QueueChannel.cpp -o CMakeFiles/OrcJITTests.dir/QueueChannel.cpp.s

unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/QueueChannel.cpp.o.requires:

.PHONY : unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/QueueChannel.cpp.o.requires

unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/QueueChannel.cpp.o.provides: unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/QueueChannel.cpp.o.requires
	$(MAKE) -f unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/build.make unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/QueueChannel.cpp.o.provides.build
.PHONY : unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/QueueChannel.cpp.o.provides

unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/QueueChannel.cpp.o.provides.build: unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/QueueChannel.cpp.o


unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/RPCUtilsTest.cpp.o: unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/flags.make
unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/RPCUtilsTest.cpp.o: ../unittests/ExecutionEngine/Orc/RPCUtilsTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/cilk-plus-futures/Tapir/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/RPCUtilsTest.cpp.o"
	cd /mnt/cilk-plus-futures/Tapir/src/build/unittests/ExecutionEngine/Orc && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OrcJITTests.dir/RPCUtilsTest.cpp.o -c /mnt/cilk-plus-futures/Tapir/src/unittests/ExecutionEngine/Orc/RPCUtilsTest.cpp

unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/RPCUtilsTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OrcJITTests.dir/RPCUtilsTest.cpp.i"
	cd /mnt/cilk-plus-futures/Tapir/src/build/unittests/ExecutionEngine/Orc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/cilk-plus-futures/Tapir/src/unittests/ExecutionEngine/Orc/RPCUtilsTest.cpp > CMakeFiles/OrcJITTests.dir/RPCUtilsTest.cpp.i

unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/RPCUtilsTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OrcJITTests.dir/RPCUtilsTest.cpp.s"
	cd /mnt/cilk-plus-futures/Tapir/src/build/unittests/ExecutionEngine/Orc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/cilk-plus-futures/Tapir/src/unittests/ExecutionEngine/Orc/RPCUtilsTest.cpp -o CMakeFiles/OrcJITTests.dir/RPCUtilsTest.cpp.s

unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/RPCUtilsTest.cpp.o.requires:

.PHONY : unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/RPCUtilsTest.cpp.o.requires

unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/RPCUtilsTest.cpp.o.provides: unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/RPCUtilsTest.cpp.o.requires
	$(MAKE) -f unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/build.make unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/RPCUtilsTest.cpp.o.provides.build
.PHONY : unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/RPCUtilsTest.cpp.o.provides

unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/RPCUtilsTest.cpp.o.provides.build: unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/RPCUtilsTest.cpp.o


unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/RTDyldObjectLinkingLayerTest.cpp.o: unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/flags.make
unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/RTDyldObjectLinkingLayerTest.cpp.o: ../unittests/ExecutionEngine/Orc/RTDyldObjectLinkingLayerTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/cilk-plus-futures/Tapir/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/RTDyldObjectLinkingLayerTest.cpp.o"
	cd /mnt/cilk-plus-futures/Tapir/src/build/unittests/ExecutionEngine/Orc && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OrcJITTests.dir/RTDyldObjectLinkingLayerTest.cpp.o -c /mnt/cilk-plus-futures/Tapir/src/unittests/ExecutionEngine/Orc/RTDyldObjectLinkingLayerTest.cpp

unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/RTDyldObjectLinkingLayerTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OrcJITTests.dir/RTDyldObjectLinkingLayerTest.cpp.i"
	cd /mnt/cilk-plus-futures/Tapir/src/build/unittests/ExecutionEngine/Orc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/cilk-plus-futures/Tapir/src/unittests/ExecutionEngine/Orc/RTDyldObjectLinkingLayerTest.cpp > CMakeFiles/OrcJITTests.dir/RTDyldObjectLinkingLayerTest.cpp.i

unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/RTDyldObjectLinkingLayerTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OrcJITTests.dir/RTDyldObjectLinkingLayerTest.cpp.s"
	cd /mnt/cilk-plus-futures/Tapir/src/build/unittests/ExecutionEngine/Orc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/cilk-plus-futures/Tapir/src/unittests/ExecutionEngine/Orc/RTDyldObjectLinkingLayerTest.cpp -o CMakeFiles/OrcJITTests.dir/RTDyldObjectLinkingLayerTest.cpp.s

unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/RTDyldObjectLinkingLayerTest.cpp.o.requires:

.PHONY : unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/RTDyldObjectLinkingLayerTest.cpp.o.requires

unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/RTDyldObjectLinkingLayerTest.cpp.o.provides: unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/RTDyldObjectLinkingLayerTest.cpp.o.requires
	$(MAKE) -f unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/build.make unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/RTDyldObjectLinkingLayerTest.cpp.o.provides.build
.PHONY : unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/RTDyldObjectLinkingLayerTest.cpp.o.provides

unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/RTDyldObjectLinkingLayerTest.cpp.o.provides.build: unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/RTDyldObjectLinkingLayerTest.cpp.o


# Object files for target OrcJITTests
OrcJITTests_OBJECTS = \
"CMakeFiles/OrcJITTests.dir/CompileOnDemandLayerTest.cpp.o" \
"CMakeFiles/OrcJITTests.dir/IndirectionUtilsTest.cpp.o" \
"CMakeFiles/OrcJITTests.dir/GlobalMappingLayerTest.cpp.o" \
"CMakeFiles/OrcJITTests.dir/LazyEmittingLayerTest.cpp.o" \
"CMakeFiles/OrcJITTests.dir/ObjectTransformLayerTest.cpp.o" \
"CMakeFiles/OrcJITTests.dir/OrcCAPITest.cpp.o" \
"CMakeFiles/OrcJITTests.dir/OrcTestCommon.cpp.o" \
"CMakeFiles/OrcJITTests.dir/QueueChannel.cpp.o" \
"CMakeFiles/OrcJITTests.dir/RPCUtilsTest.cpp.o" \
"CMakeFiles/OrcJITTests.dir/RTDyldObjectLinkingLayerTest.cpp.o"

# External object files for target OrcJITTests
OrcJITTests_EXTERNAL_OBJECTS =

unittests/ExecutionEngine/Orc/OrcJITTests: unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/CompileOnDemandLayerTest.cpp.o
unittests/ExecutionEngine/Orc/OrcJITTests: unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/IndirectionUtilsTest.cpp.o
unittests/ExecutionEngine/Orc/OrcJITTests: unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/GlobalMappingLayerTest.cpp.o
unittests/ExecutionEngine/Orc/OrcJITTests: unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/LazyEmittingLayerTest.cpp.o
unittests/ExecutionEngine/Orc/OrcJITTests: unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/ObjectTransformLayerTest.cpp.o
unittests/ExecutionEngine/Orc/OrcJITTests: unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/OrcCAPITest.cpp.o
unittests/ExecutionEngine/Orc/OrcJITTests: unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/OrcTestCommon.cpp.o
unittests/ExecutionEngine/Orc/OrcJITTests: unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/QueueChannel.cpp.o
unittests/ExecutionEngine/Orc/OrcJITTests: unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/RPCUtilsTest.cpp.o
unittests/ExecutionEngine/Orc/OrcJITTests: unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/RTDyldObjectLinkingLayerTest.cpp.o
unittests/ExecutionEngine/Orc/OrcJITTests: unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/build.make
unittests/ExecutionEngine/Orc/OrcJITTests: lib/libLLVMCore.a
unittests/ExecutionEngine/Orc/OrcJITTests: lib/libLLVMExecutionEngine.a
unittests/ExecutionEngine/Orc/OrcJITTests: lib/libLLVMObject.a
unittests/ExecutionEngine/Orc/OrcJITTests: lib/libLLVMOrcJIT.a
unittests/ExecutionEngine/Orc/OrcJITTests: lib/libLLVMRuntimeDyld.a
unittests/ExecutionEngine/Orc/OrcJITTests: lib/libLLVMSupport.a
unittests/ExecutionEngine/Orc/OrcJITTests: lib/libLLVMSupport.a
unittests/ExecutionEngine/Orc/OrcJITTests: lib/libLLVMX86CodeGen.a
unittests/ExecutionEngine/Orc/OrcJITTests: lib/libLLVMX86AsmPrinter.a
unittests/ExecutionEngine/Orc/OrcJITTests: lib/libLLVMX86AsmParser.a
unittests/ExecutionEngine/Orc/OrcJITTests: lib/libLLVMX86Desc.a
unittests/ExecutionEngine/Orc/OrcJITTests: lib/libLLVMX86Info.a
unittests/ExecutionEngine/Orc/OrcJITTests: lib/libLLVMX86Disassembler.a
unittests/ExecutionEngine/Orc/OrcJITTests: lib/libLLVMX86Info.a
unittests/ExecutionEngine/Orc/OrcJITTests: lib/libLLVMX86Utils.a
unittests/ExecutionEngine/Orc/OrcJITTests: lib/libgtest_main.a
unittests/ExecutionEngine/Orc/OrcJITTests: lib/libgtest.a
unittests/ExecutionEngine/Orc/OrcJITTests: lib/libLLVMExecutionEngine.a
unittests/ExecutionEngine/Orc/OrcJITTests: lib/libLLVMRuntimeDyld.a
unittests/ExecutionEngine/Orc/OrcJITTests: lib/libLLVMAsmPrinter.a
unittests/ExecutionEngine/Orc/OrcJITTests: lib/libLLVMDebugInfoCodeView.a
unittests/ExecutionEngine/Orc/OrcJITTests: lib/libLLVMDebugInfoMSF.a
unittests/ExecutionEngine/Orc/OrcJITTests: lib/libLLVMGlobalISel.a
unittests/ExecutionEngine/Orc/OrcJITTests: lib/libLLVMSelectionDAG.a
unittests/ExecutionEngine/Orc/OrcJITTests: lib/libLLVMCodeGen.a
unittests/ExecutionEngine/Orc/OrcJITTests: lib/libLLVMTarget.a
unittests/ExecutionEngine/Orc/OrcJITTests: lib/libLLVMBitWriter.a
unittests/ExecutionEngine/Orc/OrcJITTests: lib/libLLVMScalarOpts.a
unittests/ExecutionEngine/Orc/OrcJITTests: lib/libLLVMInstCombine.a
unittests/ExecutionEngine/Orc/OrcJITTests: lib/libLLVMTransformUtils.a
unittests/ExecutionEngine/Orc/OrcJITTests: lib/libLLVMAnalysis.a
unittests/ExecutionEngine/Orc/OrcJITTests: lib/libLLVMProfileData.a
unittests/ExecutionEngine/Orc/OrcJITTests: lib/libLLVMObject.a
unittests/ExecutionEngine/Orc/OrcJITTests: lib/libLLVMBitReader.a
unittests/ExecutionEngine/Orc/OrcJITTests: lib/libLLVMX86AsmPrinter.a
unittests/ExecutionEngine/Orc/OrcJITTests: lib/libLLVMX86Utils.a
unittests/ExecutionEngine/Orc/OrcJITTests: lib/libLLVMCore.a
unittests/ExecutionEngine/Orc/OrcJITTests: lib/libLLVMBinaryFormat.a
unittests/ExecutionEngine/Orc/OrcJITTests: lib/libLLVMMCParser.a
unittests/ExecutionEngine/Orc/OrcJITTests: lib/libLLVMMCDisassembler.a
unittests/ExecutionEngine/Orc/OrcJITTests: lib/libLLVMMC.a
unittests/ExecutionEngine/Orc/OrcJITTests: lib/libLLVMSupport.a
unittests/ExecutionEngine/Orc/OrcJITTests: lib/libLLVMDemangle.a
unittests/ExecutionEngine/Orc/OrcJITTests: unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/cilk-plus-futures/Tapir/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable OrcJITTests"
	cd /mnt/cilk-plus-futures/Tapir/src/build/unittests/ExecutionEngine/Orc && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/OrcJITTests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/build: unittests/ExecutionEngine/Orc/OrcJITTests

.PHONY : unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/build

unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/requires: unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/CompileOnDemandLayerTest.cpp.o.requires
unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/requires: unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/IndirectionUtilsTest.cpp.o.requires
unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/requires: unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/GlobalMappingLayerTest.cpp.o.requires
unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/requires: unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/LazyEmittingLayerTest.cpp.o.requires
unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/requires: unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/ObjectTransformLayerTest.cpp.o.requires
unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/requires: unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/OrcCAPITest.cpp.o.requires
unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/requires: unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/OrcTestCommon.cpp.o.requires
unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/requires: unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/QueueChannel.cpp.o.requires
unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/requires: unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/RPCUtilsTest.cpp.o.requires
unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/requires: unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/RTDyldObjectLinkingLayerTest.cpp.o.requires

.PHONY : unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/requires

unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/clean:
	cd /mnt/cilk-plus-futures/Tapir/src/build/unittests/ExecutionEngine/Orc && $(CMAKE_COMMAND) -P CMakeFiles/OrcJITTests.dir/cmake_clean.cmake
.PHONY : unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/clean

unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/depend:
	cd /mnt/cilk-plus-futures/Tapir/src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/cilk-plus-futures/Tapir/src /mnt/cilk-plus-futures/Tapir/src/unittests/ExecutionEngine/Orc /mnt/cilk-plus-futures/Tapir/src/build /mnt/cilk-plus-futures/Tapir/src/build/unittests/ExecutionEngine/Orc /mnt/cilk-plus-futures/Tapir/src/build/unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : unittests/ExecutionEngine/Orc/CMakeFiles/OrcJITTests.dir/depend

