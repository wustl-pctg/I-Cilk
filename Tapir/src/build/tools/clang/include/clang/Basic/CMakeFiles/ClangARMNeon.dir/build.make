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

# Utility rule file for ClangARMNeon.

# Include the progress variables for this target.
include tools/clang/include/clang/Basic/CMakeFiles/ClangARMNeon.dir/progress.make

tools/clang/include/clang/Basic/CMakeFiles/ClangARMNeon: tools/clang/include/clang/Basic/arm_neon.inc


tools/clang/include/clang/Basic/arm_neon.inc: tools/clang/include/clang/Basic/arm_neon.inc.tmp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/mnt/cilk-plus-futures/Tapir/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Updating arm_neon.inc..."
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/clang/include/clang/Basic && /usr/bin/cmake -E copy_if_different /mnt/cilk-plus-futures/Tapir/src/build/tools/clang/include/clang/Basic/arm_neon.inc.tmp /mnt/cilk-plus-futures/Tapir/src/build/tools/clang/include/clang/Basic/arm_neon.inc

tools/clang/include/clang/Basic/arm_neon.inc.tmp: bin/clang-tblgen
tools/clang/include/clang/Basic/arm_neon.inc.tmp: bin/clang-tblgen
tools/clang/include/clang/Basic/arm_neon.inc.tmp: ../tools/clang/include/clang/Basic/Attr.td
tools/clang/include/clang/Basic/arm_neon.inc.tmp: ../tools/clang/include/clang/Basic/AttrDocs.td
tools/clang/include/clang/Basic/arm_neon.inc.tmp: ../tools/clang/include/clang/Basic/CommentNodes.td
tools/clang/include/clang/Basic/arm_neon.inc.tmp: ../tools/clang/include/clang/Basic/DeclNodes.td
tools/clang/include/clang/Basic/arm_neon.inc.tmp: ../tools/clang/include/clang/Basic/Diagnostic.td
tools/clang/include/clang/Basic/arm_neon.inc.tmp: ../tools/clang/include/clang/Basic/DiagnosticASTKinds.td
tools/clang/include/clang/Basic/arm_neon.inc.tmp: ../tools/clang/include/clang/Basic/DiagnosticAnalysisKinds.td
tools/clang/include/clang/Basic/arm_neon.inc.tmp: ../tools/clang/include/clang/Basic/DiagnosticCategories.td
tools/clang/include/clang/Basic/arm_neon.inc.tmp: ../tools/clang/include/clang/Basic/DiagnosticCommentKinds.td
tools/clang/include/clang/Basic/arm_neon.inc.tmp: ../tools/clang/include/clang/Basic/DiagnosticCommonKinds.td
tools/clang/include/clang/Basic/arm_neon.inc.tmp: ../tools/clang/include/clang/Basic/DiagnosticDocs.td
tools/clang/include/clang/Basic/arm_neon.inc.tmp: ../tools/clang/include/clang/Basic/DiagnosticDriverKinds.td
tools/clang/include/clang/Basic/arm_neon.inc.tmp: ../tools/clang/include/clang/Basic/DiagnosticFrontendKinds.td
tools/clang/include/clang/Basic/arm_neon.inc.tmp: ../tools/clang/include/clang/Basic/DiagnosticGroups.td
tools/clang/include/clang/Basic/arm_neon.inc.tmp: ../tools/clang/include/clang/Basic/DiagnosticLexKinds.td
tools/clang/include/clang/Basic/arm_neon.inc.tmp: ../tools/clang/include/clang/Basic/DiagnosticParseKinds.td
tools/clang/include/clang/Basic/arm_neon.inc.tmp: ../tools/clang/include/clang/Basic/DiagnosticSemaKinds.td
tools/clang/include/clang/Basic/arm_neon.inc.tmp: ../tools/clang/include/clang/Basic/DiagnosticSerializationKinds.td
tools/clang/include/clang/Basic/arm_neon.inc.tmp: ../tools/clang/include/clang/Basic/StmtNodes.td
tools/clang/include/clang/Basic/arm_neon.inc.tmp: ../tools/clang/include/clang/Basic/arm_neon.td
tools/clang/include/clang/Basic/arm_neon.inc.tmp: ../include/llvm/CodeGen/ValueTypes.td
tools/clang/include/clang/Basic/arm_neon.inc.tmp: ../include/llvm/IR/Intrinsics.td
tools/clang/include/clang/Basic/arm_neon.inc.tmp: ../include/llvm/IR/IntrinsicsAArch64.td
tools/clang/include/clang/Basic/arm_neon.inc.tmp: ../include/llvm/IR/IntrinsicsAMDGPU.td
tools/clang/include/clang/Basic/arm_neon.inc.tmp: ../include/llvm/IR/IntrinsicsARM.td
tools/clang/include/clang/Basic/arm_neon.inc.tmp: ../include/llvm/IR/IntrinsicsBPF.td
tools/clang/include/clang/Basic/arm_neon.inc.tmp: ../include/llvm/IR/IntrinsicsMips.td
tools/clang/include/clang/Basic/arm_neon.inc.tmp: ../include/llvm/IR/IntrinsicsPowerPC.td
tools/clang/include/clang/Basic/arm_neon.inc.tmp: ../include/llvm/IR/IntrinsicsSystemZ.td
tools/clang/include/clang/Basic/arm_neon.inc.tmp: ../include/llvm/IR/IntrinsicsWebAssembly.td
tools/clang/include/clang/Basic/arm_neon.inc.tmp: ../include/llvm/IR/IntrinsicsX86.td
tools/clang/include/clang/Basic/arm_neon.inc.tmp: ../include/llvm/IR/IntrinsicsXCore.td
tools/clang/include/clang/Basic/arm_neon.inc.tmp: ../include/llvm/IR/IntrinsicsNVVM.td
tools/clang/include/clang/Basic/arm_neon.inc.tmp: ../include/llvm/IR/Attributes.td
tools/clang/include/clang/Basic/arm_neon.inc.tmp: ../include/llvm/IR/IntrinsicsHexagon.td
tools/clang/include/clang/Basic/arm_neon.inc.tmp: ../include/llvm/Option/OptParser.td
tools/clang/include/clang/Basic/arm_neon.inc.tmp: ../include/llvm/TableGen/SearchableTable.td
tools/clang/include/clang/Basic/arm_neon.inc.tmp: ../include/llvm/Target/GlobalISel/RegisterBank.td
tools/clang/include/clang/Basic/arm_neon.inc.tmp: ../include/llvm/Target/GlobalISel/SelectionDAGCompat.td
tools/clang/include/clang/Basic/arm_neon.inc.tmp: ../include/llvm/Target/GlobalISel/Target.td
tools/clang/include/clang/Basic/arm_neon.inc.tmp: ../include/llvm/Target/GenericOpcodes.td
tools/clang/include/clang/Basic/arm_neon.inc.tmp: ../include/llvm/Target/Target.td
tools/clang/include/clang/Basic/arm_neon.inc.tmp: ../include/llvm/Target/TargetCallingConv.td
tools/clang/include/clang/Basic/arm_neon.inc.tmp: ../include/llvm/Target/TargetItinerary.td
tools/clang/include/clang/Basic/arm_neon.inc.tmp: ../include/llvm/Target/TargetSchedule.td
tools/clang/include/clang/Basic/arm_neon.inc.tmp: ../include/llvm/Target/TargetSelectionDAG.td
tools/clang/include/clang/Basic/arm_neon.inc.tmp: ../tools/clang/include/clang/Basic/arm_neon.td
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/mnt/cilk-plus-futures/Tapir/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building arm_neon.inc..."
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/clang/include/clang/Basic && ../../../../../bin/clang-tblgen -gen-arm-neon-sema -I /mnt/cilk-plus-futures/Tapir/src/tools/clang/include/clang/Basic/../../ -I /mnt/cilk-plus-futures/Tapir/src/tools/clang/include/clang/Basic -I /mnt/cilk-plus-futures/Tapir/src/include /mnt/cilk-plus-futures/Tapir/src/tools/clang/include/clang/Basic/arm_neon.td -o /mnt/cilk-plus-futures/Tapir/src/build/tools/clang/include/clang/Basic/arm_neon.inc.tmp

ClangARMNeon: tools/clang/include/clang/Basic/CMakeFiles/ClangARMNeon
ClangARMNeon: tools/clang/include/clang/Basic/arm_neon.inc
ClangARMNeon: tools/clang/include/clang/Basic/arm_neon.inc.tmp
ClangARMNeon: tools/clang/include/clang/Basic/CMakeFiles/ClangARMNeon.dir/build.make

.PHONY : ClangARMNeon

# Rule to build all files generated by this target.
tools/clang/include/clang/Basic/CMakeFiles/ClangARMNeon.dir/build: ClangARMNeon

.PHONY : tools/clang/include/clang/Basic/CMakeFiles/ClangARMNeon.dir/build

tools/clang/include/clang/Basic/CMakeFiles/ClangARMNeon.dir/clean:
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/clang/include/clang/Basic && $(CMAKE_COMMAND) -P CMakeFiles/ClangARMNeon.dir/cmake_clean.cmake
.PHONY : tools/clang/include/clang/Basic/CMakeFiles/ClangARMNeon.dir/clean

tools/clang/include/clang/Basic/CMakeFiles/ClangARMNeon.dir/depend:
	cd /mnt/cilk-plus-futures/Tapir/src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/cilk-plus-futures/Tapir/src /mnt/cilk-plus-futures/Tapir/src/tools/clang/include/clang/Basic /mnt/cilk-plus-futures/Tapir/src/build /mnt/cilk-plus-futures/Tapir/src/build/tools/clang/include/clang/Basic /mnt/cilk-plus-futures/Tapir/src/build/tools/clang/include/clang/Basic/CMakeFiles/ClangARMNeon.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tools/clang/include/clang/Basic/CMakeFiles/ClangARMNeon.dir/depend

