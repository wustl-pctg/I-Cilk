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

# Utility rule file for DllOptionsTableGen.

# Include the progress variables for this target.
include lib/ToolDrivers/llvm-dlltool/CMakeFiles/DllOptionsTableGen.dir/progress.make

lib/ToolDrivers/llvm-dlltool/CMakeFiles/DllOptionsTableGen: lib/ToolDrivers/llvm-dlltool/Options.inc


lib/ToolDrivers/llvm-dlltool/Options.inc: lib/ToolDrivers/llvm-dlltool/Options.inc.tmp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/mnt/cilk-plus-futures/Tapir/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Updating Options.inc..."
	cd /mnt/cilk-plus-futures/Tapir/src/build/lib/ToolDrivers/llvm-dlltool && /usr/bin/cmake -E copy_if_different /mnt/cilk-plus-futures/Tapir/src/build/lib/ToolDrivers/llvm-dlltool/Options.inc.tmp /mnt/cilk-plus-futures/Tapir/src/build/lib/ToolDrivers/llvm-dlltool/Options.inc

lib/ToolDrivers/llvm-dlltool/Options.inc.tmp: bin/llvm-tblgen
lib/ToolDrivers/llvm-dlltool/Options.inc.tmp: bin/llvm-tblgen
lib/ToolDrivers/llvm-dlltool/Options.inc.tmp: ../lib/ToolDrivers/llvm-dlltool/Options.td
lib/ToolDrivers/llvm-dlltool/Options.inc.tmp: ../include/llvm/CodeGen/ValueTypes.td
lib/ToolDrivers/llvm-dlltool/Options.inc.tmp: ../include/llvm/IR/Intrinsics.td
lib/ToolDrivers/llvm-dlltool/Options.inc.tmp: ../include/llvm/IR/IntrinsicsAArch64.td
lib/ToolDrivers/llvm-dlltool/Options.inc.tmp: ../include/llvm/IR/IntrinsicsAMDGPU.td
lib/ToolDrivers/llvm-dlltool/Options.inc.tmp: ../include/llvm/IR/IntrinsicsARM.td
lib/ToolDrivers/llvm-dlltool/Options.inc.tmp: ../include/llvm/IR/IntrinsicsBPF.td
lib/ToolDrivers/llvm-dlltool/Options.inc.tmp: ../include/llvm/IR/IntrinsicsMips.td
lib/ToolDrivers/llvm-dlltool/Options.inc.tmp: ../include/llvm/IR/IntrinsicsPowerPC.td
lib/ToolDrivers/llvm-dlltool/Options.inc.tmp: ../include/llvm/IR/IntrinsicsSystemZ.td
lib/ToolDrivers/llvm-dlltool/Options.inc.tmp: ../include/llvm/IR/IntrinsicsWebAssembly.td
lib/ToolDrivers/llvm-dlltool/Options.inc.tmp: ../include/llvm/IR/IntrinsicsX86.td
lib/ToolDrivers/llvm-dlltool/Options.inc.tmp: ../include/llvm/IR/IntrinsicsXCore.td
lib/ToolDrivers/llvm-dlltool/Options.inc.tmp: ../include/llvm/IR/IntrinsicsNVVM.td
lib/ToolDrivers/llvm-dlltool/Options.inc.tmp: ../include/llvm/IR/Attributes.td
lib/ToolDrivers/llvm-dlltool/Options.inc.tmp: ../include/llvm/IR/IntrinsicsHexagon.td
lib/ToolDrivers/llvm-dlltool/Options.inc.tmp: ../include/llvm/Option/OptParser.td
lib/ToolDrivers/llvm-dlltool/Options.inc.tmp: ../include/llvm/TableGen/SearchableTable.td
lib/ToolDrivers/llvm-dlltool/Options.inc.tmp: ../include/llvm/Target/GlobalISel/RegisterBank.td
lib/ToolDrivers/llvm-dlltool/Options.inc.tmp: ../include/llvm/Target/GlobalISel/SelectionDAGCompat.td
lib/ToolDrivers/llvm-dlltool/Options.inc.tmp: ../include/llvm/Target/GlobalISel/Target.td
lib/ToolDrivers/llvm-dlltool/Options.inc.tmp: ../include/llvm/Target/GenericOpcodes.td
lib/ToolDrivers/llvm-dlltool/Options.inc.tmp: ../include/llvm/Target/Target.td
lib/ToolDrivers/llvm-dlltool/Options.inc.tmp: ../include/llvm/Target/TargetCallingConv.td
lib/ToolDrivers/llvm-dlltool/Options.inc.tmp: ../include/llvm/Target/TargetItinerary.td
lib/ToolDrivers/llvm-dlltool/Options.inc.tmp: ../include/llvm/Target/TargetSchedule.td
lib/ToolDrivers/llvm-dlltool/Options.inc.tmp: ../include/llvm/Target/TargetSelectionDAG.td
lib/ToolDrivers/llvm-dlltool/Options.inc.tmp: ../lib/ToolDrivers/llvm-dlltool/Options.td
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/mnt/cilk-plus-futures/Tapir/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building Options.inc..."
	cd /mnt/cilk-plus-futures/Tapir/src/build/lib/ToolDrivers/llvm-dlltool && ../../../bin/llvm-tblgen -gen-opt-parser-defs -I /mnt/cilk-plus-futures/Tapir/src/lib/ToolDrivers/llvm-dlltool -I /mnt/cilk-plus-futures/Tapir/src/include /mnt/cilk-plus-futures/Tapir/src/lib/ToolDrivers/llvm-dlltool/Options.td -o /mnt/cilk-plus-futures/Tapir/src/build/lib/ToolDrivers/llvm-dlltool/Options.inc.tmp

DllOptionsTableGen: lib/ToolDrivers/llvm-dlltool/CMakeFiles/DllOptionsTableGen
DllOptionsTableGen: lib/ToolDrivers/llvm-dlltool/Options.inc
DllOptionsTableGen: lib/ToolDrivers/llvm-dlltool/Options.inc.tmp
DllOptionsTableGen: lib/ToolDrivers/llvm-dlltool/CMakeFiles/DllOptionsTableGen.dir/build.make

.PHONY : DllOptionsTableGen

# Rule to build all files generated by this target.
lib/ToolDrivers/llvm-dlltool/CMakeFiles/DllOptionsTableGen.dir/build: DllOptionsTableGen

.PHONY : lib/ToolDrivers/llvm-dlltool/CMakeFiles/DllOptionsTableGen.dir/build

lib/ToolDrivers/llvm-dlltool/CMakeFiles/DllOptionsTableGen.dir/clean:
	cd /mnt/cilk-plus-futures/Tapir/src/build/lib/ToolDrivers/llvm-dlltool && $(CMAKE_COMMAND) -P CMakeFiles/DllOptionsTableGen.dir/cmake_clean.cmake
.PHONY : lib/ToolDrivers/llvm-dlltool/CMakeFiles/DllOptionsTableGen.dir/clean

lib/ToolDrivers/llvm-dlltool/CMakeFiles/DllOptionsTableGen.dir/depend:
	cd /mnt/cilk-plus-futures/Tapir/src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/cilk-plus-futures/Tapir/src /mnt/cilk-plus-futures/Tapir/src/lib/ToolDrivers/llvm-dlltool /mnt/cilk-plus-futures/Tapir/src/build /mnt/cilk-plus-futures/Tapir/src/build/lib/ToolDrivers/llvm-dlltool /mnt/cilk-plus-futures/Tapir/src/build/lib/ToolDrivers/llvm-dlltool/CMakeFiles/DllOptionsTableGen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/ToolDrivers/llvm-dlltool/CMakeFiles/DllOptionsTableGen.dir/depend

