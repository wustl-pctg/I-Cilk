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

# Utility rule file for MtTableGen.

# Include the progress variables for this target.
include tools/llvm-mt/CMakeFiles/MtTableGen.dir/progress.make

tools/llvm-mt/CMakeFiles/MtTableGen: tools/llvm-mt/Opts.inc


tools/llvm-mt/Opts.inc: tools/llvm-mt/Opts.inc.tmp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/mnt/cilk-plus-futures/Tapir/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Updating Opts.inc..."
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/llvm-mt && /usr/bin/cmake -E copy_if_different /mnt/cilk-plus-futures/Tapir/src/build/tools/llvm-mt/Opts.inc.tmp /mnt/cilk-plus-futures/Tapir/src/build/tools/llvm-mt/Opts.inc

tools/llvm-mt/Opts.inc.tmp: bin/llvm-tblgen
tools/llvm-mt/Opts.inc.tmp: bin/llvm-tblgen
tools/llvm-mt/Opts.inc.tmp: ../tools/llvm-mt/Opts.td
tools/llvm-mt/Opts.inc.tmp: ../include/llvm/CodeGen/ValueTypes.td
tools/llvm-mt/Opts.inc.tmp: ../include/llvm/IR/Intrinsics.td
tools/llvm-mt/Opts.inc.tmp: ../include/llvm/IR/IntrinsicsAArch64.td
tools/llvm-mt/Opts.inc.tmp: ../include/llvm/IR/IntrinsicsAMDGPU.td
tools/llvm-mt/Opts.inc.tmp: ../include/llvm/IR/IntrinsicsARM.td
tools/llvm-mt/Opts.inc.tmp: ../include/llvm/IR/IntrinsicsBPF.td
tools/llvm-mt/Opts.inc.tmp: ../include/llvm/IR/IntrinsicsMips.td
tools/llvm-mt/Opts.inc.tmp: ../include/llvm/IR/IntrinsicsPowerPC.td
tools/llvm-mt/Opts.inc.tmp: ../include/llvm/IR/IntrinsicsSystemZ.td
tools/llvm-mt/Opts.inc.tmp: ../include/llvm/IR/IntrinsicsWebAssembly.td
tools/llvm-mt/Opts.inc.tmp: ../include/llvm/IR/IntrinsicsX86.td
tools/llvm-mt/Opts.inc.tmp: ../include/llvm/IR/IntrinsicsXCore.td
tools/llvm-mt/Opts.inc.tmp: ../include/llvm/IR/IntrinsicsNVVM.td
tools/llvm-mt/Opts.inc.tmp: ../include/llvm/IR/Attributes.td
tools/llvm-mt/Opts.inc.tmp: ../include/llvm/IR/IntrinsicsHexagon.td
tools/llvm-mt/Opts.inc.tmp: ../include/llvm/Option/OptParser.td
tools/llvm-mt/Opts.inc.tmp: ../include/llvm/TableGen/SearchableTable.td
tools/llvm-mt/Opts.inc.tmp: ../include/llvm/Target/GlobalISel/RegisterBank.td
tools/llvm-mt/Opts.inc.tmp: ../include/llvm/Target/GlobalISel/SelectionDAGCompat.td
tools/llvm-mt/Opts.inc.tmp: ../include/llvm/Target/GlobalISel/Target.td
tools/llvm-mt/Opts.inc.tmp: ../include/llvm/Target/GenericOpcodes.td
tools/llvm-mt/Opts.inc.tmp: ../include/llvm/Target/Target.td
tools/llvm-mt/Opts.inc.tmp: ../include/llvm/Target/TargetCallingConv.td
tools/llvm-mt/Opts.inc.tmp: ../include/llvm/Target/TargetItinerary.td
tools/llvm-mt/Opts.inc.tmp: ../include/llvm/Target/TargetSchedule.td
tools/llvm-mt/Opts.inc.tmp: ../include/llvm/Target/TargetSelectionDAG.td
tools/llvm-mt/Opts.inc.tmp: ../tools/llvm-mt/Opts.td
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/mnt/cilk-plus-futures/Tapir/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building Opts.inc..."
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/llvm-mt && ../../bin/llvm-tblgen -gen-opt-parser-defs -I /mnt/cilk-plus-futures/Tapir/src/tools/llvm-mt -I /mnt/cilk-plus-futures/Tapir/src/include /mnt/cilk-plus-futures/Tapir/src/tools/llvm-mt/Opts.td -o /mnt/cilk-plus-futures/Tapir/src/build/tools/llvm-mt/Opts.inc.tmp

MtTableGen: tools/llvm-mt/CMakeFiles/MtTableGen
MtTableGen: tools/llvm-mt/Opts.inc
MtTableGen: tools/llvm-mt/Opts.inc.tmp
MtTableGen: tools/llvm-mt/CMakeFiles/MtTableGen.dir/build.make

.PHONY : MtTableGen

# Rule to build all files generated by this target.
tools/llvm-mt/CMakeFiles/MtTableGen.dir/build: MtTableGen

.PHONY : tools/llvm-mt/CMakeFiles/MtTableGen.dir/build

tools/llvm-mt/CMakeFiles/MtTableGen.dir/clean:
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/llvm-mt && $(CMAKE_COMMAND) -P CMakeFiles/MtTableGen.dir/cmake_clean.cmake
.PHONY : tools/llvm-mt/CMakeFiles/MtTableGen.dir/clean

tools/llvm-mt/CMakeFiles/MtTableGen.dir/depend:
	cd /mnt/cilk-plus-futures/Tapir/src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/cilk-plus-futures/Tapir/src /mnt/cilk-plus-futures/Tapir/src/tools/llvm-mt /mnt/cilk-plus-futures/Tapir/src/build /mnt/cilk-plus-futures/Tapir/src/build/tools/llvm-mt /mnt/cilk-plus-futures/Tapir/src/build/tools/llvm-mt/CMakeFiles/MtTableGen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tools/llvm-mt/CMakeFiles/MtTableGen.dir/depend

