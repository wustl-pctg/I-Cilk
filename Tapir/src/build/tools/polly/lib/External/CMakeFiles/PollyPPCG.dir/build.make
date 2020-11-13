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
include tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/depend.make

# Include the progress variables for this target.
include tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/progress.make

# Include the compile flags for this target's objects.
include tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/flags.make

tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/cuda.c.o: tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/flags.make
tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/cuda.c.o: ../tools/polly/lib/External/ppcg/cuda.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/cilk-plus-futures/Tapir/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/cuda.c.o"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/polly/lib/External && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/PollyPPCG.dir/ppcg/cuda.c.o   -c /mnt/cilk-plus-futures/Tapir/src/tools/polly/lib/External/ppcg/cuda.c

tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/cuda.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/PollyPPCG.dir/ppcg/cuda.c.i"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/polly/lib/External && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/cilk-plus-futures/Tapir/src/tools/polly/lib/External/ppcg/cuda.c > CMakeFiles/PollyPPCG.dir/ppcg/cuda.c.i

tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/cuda.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/PollyPPCG.dir/ppcg/cuda.c.s"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/polly/lib/External && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/cilk-plus-futures/Tapir/src/tools/polly/lib/External/ppcg/cuda.c -o CMakeFiles/PollyPPCG.dir/ppcg/cuda.c.s

tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/cuda.c.o.requires:

.PHONY : tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/cuda.c.o.requires

tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/cuda.c.o.provides: tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/cuda.c.o.requires
	$(MAKE) -f tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/build.make tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/cuda.c.o.provides.build
.PHONY : tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/cuda.c.o.provides

tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/cuda.c.o.provides.build: tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/cuda.c.o


tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/cuda_common.c.o: tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/flags.make
tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/cuda_common.c.o: ../tools/polly/lib/External/ppcg/cuda_common.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/cilk-plus-futures/Tapir/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/cuda_common.c.o"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/polly/lib/External && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/PollyPPCG.dir/ppcg/cuda_common.c.o   -c /mnt/cilk-plus-futures/Tapir/src/tools/polly/lib/External/ppcg/cuda_common.c

tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/cuda_common.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/PollyPPCG.dir/ppcg/cuda_common.c.i"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/polly/lib/External && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/cilk-plus-futures/Tapir/src/tools/polly/lib/External/ppcg/cuda_common.c > CMakeFiles/PollyPPCG.dir/ppcg/cuda_common.c.i

tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/cuda_common.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/PollyPPCG.dir/ppcg/cuda_common.c.s"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/polly/lib/External && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/cilk-plus-futures/Tapir/src/tools/polly/lib/External/ppcg/cuda_common.c -o CMakeFiles/PollyPPCG.dir/ppcg/cuda_common.c.s

tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/cuda_common.c.o.requires:

.PHONY : tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/cuda_common.c.o.requires

tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/cuda_common.c.o.provides: tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/cuda_common.c.o.requires
	$(MAKE) -f tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/build.make tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/cuda_common.c.o.provides.build
.PHONY : tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/cuda_common.c.o.provides

tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/cuda_common.c.o.provides.build: tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/cuda_common.c.o


tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu_array_tile.c.o: tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/flags.make
tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu_array_tile.c.o: ../tools/polly/lib/External/ppcg/gpu_array_tile.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/cilk-plus-futures/Tapir/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu_array_tile.c.o"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/polly/lib/External && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/PollyPPCG.dir/ppcg/gpu_array_tile.c.o   -c /mnt/cilk-plus-futures/Tapir/src/tools/polly/lib/External/ppcg/gpu_array_tile.c

tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu_array_tile.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/PollyPPCG.dir/ppcg/gpu_array_tile.c.i"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/polly/lib/External && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/cilk-plus-futures/Tapir/src/tools/polly/lib/External/ppcg/gpu_array_tile.c > CMakeFiles/PollyPPCG.dir/ppcg/gpu_array_tile.c.i

tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu_array_tile.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/PollyPPCG.dir/ppcg/gpu_array_tile.c.s"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/polly/lib/External && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/cilk-plus-futures/Tapir/src/tools/polly/lib/External/ppcg/gpu_array_tile.c -o CMakeFiles/PollyPPCG.dir/ppcg/gpu_array_tile.c.s

tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu_array_tile.c.o.requires:

.PHONY : tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu_array_tile.c.o.requires

tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu_array_tile.c.o.provides: tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu_array_tile.c.o.requires
	$(MAKE) -f tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/build.make tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu_array_tile.c.o.provides.build
.PHONY : tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu_array_tile.c.o.provides

tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu_array_tile.c.o.provides.build: tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu_array_tile.c.o


tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu.c.o: tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/flags.make
tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu.c.o: ../tools/polly/lib/External/ppcg/gpu.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/cilk-plus-futures/Tapir/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu.c.o"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/polly/lib/External && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/PollyPPCG.dir/ppcg/gpu.c.o   -c /mnt/cilk-plus-futures/Tapir/src/tools/polly/lib/External/ppcg/gpu.c

tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/PollyPPCG.dir/ppcg/gpu.c.i"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/polly/lib/External && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/cilk-plus-futures/Tapir/src/tools/polly/lib/External/ppcg/gpu.c > CMakeFiles/PollyPPCG.dir/ppcg/gpu.c.i

tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/PollyPPCG.dir/ppcg/gpu.c.s"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/polly/lib/External && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/cilk-plus-futures/Tapir/src/tools/polly/lib/External/ppcg/gpu.c -o CMakeFiles/PollyPPCG.dir/ppcg/gpu.c.s

tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu.c.o.requires:

.PHONY : tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu.c.o.requires

tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu.c.o.provides: tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu.c.o.requires
	$(MAKE) -f tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/build.make tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu.c.o.provides.build
.PHONY : tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu.c.o.provides

tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu.c.o.provides.build: tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu.c.o


tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu_group.c.o: tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/flags.make
tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu_group.c.o: ../tools/polly/lib/External/ppcg/gpu_group.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/cilk-plus-futures/Tapir/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu_group.c.o"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/polly/lib/External && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/PollyPPCG.dir/ppcg/gpu_group.c.o   -c /mnt/cilk-plus-futures/Tapir/src/tools/polly/lib/External/ppcg/gpu_group.c

tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu_group.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/PollyPPCG.dir/ppcg/gpu_group.c.i"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/polly/lib/External && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/cilk-plus-futures/Tapir/src/tools/polly/lib/External/ppcg/gpu_group.c > CMakeFiles/PollyPPCG.dir/ppcg/gpu_group.c.i

tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu_group.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/PollyPPCG.dir/ppcg/gpu_group.c.s"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/polly/lib/External && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/cilk-plus-futures/Tapir/src/tools/polly/lib/External/ppcg/gpu_group.c -o CMakeFiles/PollyPPCG.dir/ppcg/gpu_group.c.s

tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu_group.c.o.requires:

.PHONY : tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu_group.c.o.requires

tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu_group.c.o.provides: tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu_group.c.o.requires
	$(MAKE) -f tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/build.make tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu_group.c.o.provides.build
.PHONY : tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu_group.c.o.provides

tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu_group.c.o.provides.build: tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu_group.c.o


tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu_print.c.o: tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/flags.make
tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu_print.c.o: ../tools/polly/lib/External/ppcg/gpu_print.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/cilk-plus-futures/Tapir/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu_print.c.o"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/polly/lib/External && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/PollyPPCG.dir/ppcg/gpu_print.c.o   -c /mnt/cilk-plus-futures/Tapir/src/tools/polly/lib/External/ppcg/gpu_print.c

tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu_print.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/PollyPPCG.dir/ppcg/gpu_print.c.i"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/polly/lib/External && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/cilk-plus-futures/Tapir/src/tools/polly/lib/External/ppcg/gpu_print.c > CMakeFiles/PollyPPCG.dir/ppcg/gpu_print.c.i

tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu_print.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/PollyPPCG.dir/ppcg/gpu_print.c.s"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/polly/lib/External && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/cilk-plus-futures/Tapir/src/tools/polly/lib/External/ppcg/gpu_print.c -o CMakeFiles/PollyPPCG.dir/ppcg/gpu_print.c.s

tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu_print.c.o.requires:

.PHONY : tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu_print.c.o.requires

tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu_print.c.o.provides: tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu_print.c.o.requires
	$(MAKE) -f tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/build.make tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu_print.c.o.provides.build
.PHONY : tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu_print.c.o.provides

tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu_print.c.o.provides.build: tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu_print.c.o


tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu_tree.c.o: tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/flags.make
tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu_tree.c.o: ../tools/polly/lib/External/ppcg/gpu_tree.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/cilk-plus-futures/Tapir/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu_tree.c.o"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/polly/lib/External && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/PollyPPCG.dir/ppcg/gpu_tree.c.o   -c /mnt/cilk-plus-futures/Tapir/src/tools/polly/lib/External/ppcg/gpu_tree.c

tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu_tree.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/PollyPPCG.dir/ppcg/gpu_tree.c.i"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/polly/lib/External && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/cilk-plus-futures/Tapir/src/tools/polly/lib/External/ppcg/gpu_tree.c > CMakeFiles/PollyPPCG.dir/ppcg/gpu_tree.c.i

tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu_tree.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/PollyPPCG.dir/ppcg/gpu_tree.c.s"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/polly/lib/External && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/cilk-plus-futures/Tapir/src/tools/polly/lib/External/ppcg/gpu_tree.c -o CMakeFiles/PollyPPCG.dir/ppcg/gpu_tree.c.s

tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu_tree.c.o.requires:

.PHONY : tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu_tree.c.o.requires

tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu_tree.c.o.provides: tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu_tree.c.o.requires
	$(MAKE) -f tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/build.make tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu_tree.c.o.provides.build
.PHONY : tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu_tree.c.o.provides

tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu_tree.c.o.provides.build: tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu_tree.c.o


tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/ppcg.c.o: tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/flags.make
tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/ppcg.c.o: ../tools/polly/lib/External/ppcg/ppcg.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/cilk-plus-futures/Tapir/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/ppcg.c.o"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/polly/lib/External && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/PollyPPCG.dir/ppcg/ppcg.c.o   -c /mnt/cilk-plus-futures/Tapir/src/tools/polly/lib/External/ppcg/ppcg.c

tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/ppcg.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/PollyPPCG.dir/ppcg/ppcg.c.i"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/polly/lib/External && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/cilk-plus-futures/Tapir/src/tools/polly/lib/External/ppcg/ppcg.c > CMakeFiles/PollyPPCG.dir/ppcg/ppcg.c.i

tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/ppcg.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/PollyPPCG.dir/ppcg/ppcg.c.s"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/polly/lib/External && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/cilk-plus-futures/Tapir/src/tools/polly/lib/External/ppcg/ppcg.c -o CMakeFiles/PollyPPCG.dir/ppcg/ppcg.c.s

tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/ppcg.c.o.requires:

.PHONY : tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/ppcg.c.o.requires

tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/ppcg.c.o.provides: tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/ppcg.c.o.requires
	$(MAKE) -f tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/build.make tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/ppcg.c.o.provides.build
.PHONY : tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/ppcg.c.o.provides

tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/ppcg.c.o.provides.build: tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/ppcg.c.o


tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/ppcg_options.c.o: tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/flags.make
tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/ppcg_options.c.o: ../tools/polly/lib/External/ppcg/ppcg_options.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/cilk-plus-futures/Tapir/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/ppcg_options.c.o"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/polly/lib/External && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/PollyPPCG.dir/ppcg/ppcg_options.c.o   -c /mnt/cilk-plus-futures/Tapir/src/tools/polly/lib/External/ppcg/ppcg_options.c

tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/ppcg_options.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/PollyPPCG.dir/ppcg/ppcg_options.c.i"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/polly/lib/External && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/cilk-plus-futures/Tapir/src/tools/polly/lib/External/ppcg/ppcg_options.c > CMakeFiles/PollyPPCG.dir/ppcg/ppcg_options.c.i

tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/ppcg_options.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/PollyPPCG.dir/ppcg/ppcg_options.c.s"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/polly/lib/External && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/cilk-plus-futures/Tapir/src/tools/polly/lib/External/ppcg/ppcg_options.c -o CMakeFiles/PollyPPCG.dir/ppcg/ppcg_options.c.s

tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/ppcg_options.c.o.requires:

.PHONY : tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/ppcg_options.c.o.requires

tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/ppcg_options.c.o.provides: tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/ppcg_options.c.o.requires
	$(MAKE) -f tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/build.make tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/ppcg_options.c.o.provides.build
.PHONY : tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/ppcg_options.c.o.provides

tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/ppcg_options.c.o.provides.build: tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/ppcg_options.c.o


tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/schedule.c.o: tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/flags.make
tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/schedule.c.o: ../tools/polly/lib/External/ppcg/schedule.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/cilk-plus-futures/Tapir/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/schedule.c.o"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/polly/lib/External && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/PollyPPCG.dir/ppcg/schedule.c.o   -c /mnt/cilk-plus-futures/Tapir/src/tools/polly/lib/External/ppcg/schedule.c

tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/schedule.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/PollyPPCG.dir/ppcg/schedule.c.i"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/polly/lib/External && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/cilk-plus-futures/Tapir/src/tools/polly/lib/External/ppcg/schedule.c > CMakeFiles/PollyPPCG.dir/ppcg/schedule.c.i

tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/schedule.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/PollyPPCG.dir/ppcg/schedule.c.s"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/polly/lib/External && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/cilk-plus-futures/Tapir/src/tools/polly/lib/External/ppcg/schedule.c -o CMakeFiles/PollyPPCG.dir/ppcg/schedule.c.s

tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/schedule.c.o.requires:

.PHONY : tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/schedule.c.o.requires

tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/schedule.c.o.provides: tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/schedule.c.o.requires
	$(MAKE) -f tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/build.make tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/schedule.c.o.provides.build
.PHONY : tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/schedule.c.o.provides

tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/schedule.c.o.provides.build: tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/schedule.c.o


tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/external.c.o: tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/flags.make
tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/external.c.o: ../tools/polly/lib/External/ppcg/external.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/cilk-plus-futures/Tapir/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/external.c.o"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/polly/lib/External && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/PollyPPCG.dir/ppcg/external.c.o   -c /mnt/cilk-plus-futures/Tapir/src/tools/polly/lib/External/ppcg/external.c

tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/external.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/PollyPPCG.dir/ppcg/external.c.i"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/polly/lib/External && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/cilk-plus-futures/Tapir/src/tools/polly/lib/External/ppcg/external.c > CMakeFiles/PollyPPCG.dir/ppcg/external.c.i

tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/external.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/PollyPPCG.dir/ppcg/external.c.s"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/polly/lib/External && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/cilk-plus-futures/Tapir/src/tools/polly/lib/External/ppcg/external.c -o CMakeFiles/PollyPPCG.dir/ppcg/external.c.s

tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/external.c.o.requires:

.PHONY : tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/external.c.o.requires

tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/external.c.o.provides: tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/external.c.o.requires
	$(MAKE) -f tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/build.make tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/external.c.o.provides.build
.PHONY : tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/external.c.o.provides

tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/external.c.o.provides.build: tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/external.c.o


# Object files for target PollyPPCG
PollyPPCG_OBJECTS = \
"CMakeFiles/PollyPPCG.dir/ppcg/cuda.c.o" \
"CMakeFiles/PollyPPCG.dir/ppcg/cuda_common.c.o" \
"CMakeFiles/PollyPPCG.dir/ppcg/gpu_array_tile.c.o" \
"CMakeFiles/PollyPPCG.dir/ppcg/gpu.c.o" \
"CMakeFiles/PollyPPCG.dir/ppcg/gpu_group.c.o" \
"CMakeFiles/PollyPPCG.dir/ppcg/gpu_print.c.o" \
"CMakeFiles/PollyPPCG.dir/ppcg/gpu_tree.c.o" \
"CMakeFiles/PollyPPCG.dir/ppcg/ppcg.c.o" \
"CMakeFiles/PollyPPCG.dir/ppcg/ppcg_options.c.o" \
"CMakeFiles/PollyPPCG.dir/ppcg/schedule.c.o" \
"CMakeFiles/PollyPPCG.dir/ppcg/external.c.o"

# External object files for target PollyPPCG
PollyPPCG_EXTERNAL_OBJECTS =

lib/libPollyPPCG.a: tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/cuda.c.o
lib/libPollyPPCG.a: tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/cuda_common.c.o
lib/libPollyPPCG.a: tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu_array_tile.c.o
lib/libPollyPPCG.a: tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu.c.o
lib/libPollyPPCG.a: tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu_group.c.o
lib/libPollyPPCG.a: tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu_print.c.o
lib/libPollyPPCG.a: tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu_tree.c.o
lib/libPollyPPCG.a: tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/ppcg.c.o
lib/libPollyPPCG.a: tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/ppcg_options.c.o
lib/libPollyPPCG.a: tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/schedule.c.o
lib/libPollyPPCG.a: tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/external.c.o
lib/libPollyPPCG.a: tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/build.make
lib/libPollyPPCG.a: tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/cilk-plus-futures/Tapir/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking C static library ../../../../lib/libPollyPPCG.a"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/polly/lib/External && $(CMAKE_COMMAND) -P CMakeFiles/PollyPPCG.dir/cmake_clean_target.cmake
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/polly/lib/External && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PollyPPCG.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/build: lib/libPollyPPCG.a

.PHONY : tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/build

tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/requires: tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/cuda.c.o.requires
tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/requires: tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/cuda_common.c.o.requires
tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/requires: tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu_array_tile.c.o.requires
tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/requires: tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu.c.o.requires
tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/requires: tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu_group.c.o.requires
tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/requires: tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu_print.c.o.requires
tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/requires: tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/gpu_tree.c.o.requires
tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/requires: tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/ppcg.c.o.requires
tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/requires: tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/ppcg_options.c.o.requires
tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/requires: tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/schedule.c.o.requires
tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/requires: tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/ppcg/external.c.o.requires

.PHONY : tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/requires

tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/clean:
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/polly/lib/External && $(CMAKE_COMMAND) -P CMakeFiles/PollyPPCG.dir/cmake_clean.cmake
.PHONY : tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/clean

tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/depend:
	cd /mnt/cilk-plus-futures/Tapir/src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/cilk-plus-futures/Tapir/src /mnt/cilk-plus-futures/Tapir/src/tools/polly/lib/External /mnt/cilk-plus-futures/Tapir/src/build /mnt/cilk-plus-futures/Tapir/src/build/tools/polly/lib/External /mnt/cilk-plus-futures/Tapir/src/build/tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tools/polly/lib/External/CMakeFiles/PollyPPCG.dir/depend
