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
include tools/llvm-ar/CMakeFiles/llvm-ar.dir/depend.make

# Include the progress variables for this target.
include tools/llvm-ar/CMakeFiles/llvm-ar.dir/progress.make

# Include the compile flags for this target's objects.
include tools/llvm-ar/CMakeFiles/llvm-ar.dir/flags.make

tools/llvm-ar/CMakeFiles/llvm-ar.dir/llvm-ar.cpp.o: tools/llvm-ar/CMakeFiles/llvm-ar.dir/flags.make
tools/llvm-ar/CMakeFiles/llvm-ar.dir/llvm-ar.cpp.o: ../tools/llvm-ar/llvm-ar.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/cilk-plus-futures/Tapir/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tools/llvm-ar/CMakeFiles/llvm-ar.dir/llvm-ar.cpp.o"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/llvm-ar && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/llvm-ar.dir/llvm-ar.cpp.o -c /mnt/cilk-plus-futures/Tapir/src/tools/llvm-ar/llvm-ar.cpp

tools/llvm-ar/CMakeFiles/llvm-ar.dir/llvm-ar.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/llvm-ar.dir/llvm-ar.cpp.i"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/llvm-ar && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/cilk-plus-futures/Tapir/src/tools/llvm-ar/llvm-ar.cpp > CMakeFiles/llvm-ar.dir/llvm-ar.cpp.i

tools/llvm-ar/CMakeFiles/llvm-ar.dir/llvm-ar.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/llvm-ar.dir/llvm-ar.cpp.s"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/llvm-ar && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/cilk-plus-futures/Tapir/src/tools/llvm-ar/llvm-ar.cpp -o CMakeFiles/llvm-ar.dir/llvm-ar.cpp.s

tools/llvm-ar/CMakeFiles/llvm-ar.dir/llvm-ar.cpp.o.requires:

.PHONY : tools/llvm-ar/CMakeFiles/llvm-ar.dir/llvm-ar.cpp.o.requires

tools/llvm-ar/CMakeFiles/llvm-ar.dir/llvm-ar.cpp.o.provides: tools/llvm-ar/CMakeFiles/llvm-ar.dir/llvm-ar.cpp.o.requires
	$(MAKE) -f tools/llvm-ar/CMakeFiles/llvm-ar.dir/build.make tools/llvm-ar/CMakeFiles/llvm-ar.dir/llvm-ar.cpp.o.provides.build
.PHONY : tools/llvm-ar/CMakeFiles/llvm-ar.dir/llvm-ar.cpp.o.provides

tools/llvm-ar/CMakeFiles/llvm-ar.dir/llvm-ar.cpp.o.provides.build: tools/llvm-ar/CMakeFiles/llvm-ar.dir/llvm-ar.cpp.o


# Object files for target llvm-ar
llvm__ar_OBJECTS = \
"CMakeFiles/llvm-ar.dir/llvm-ar.cpp.o"

# External object files for target llvm-ar
llvm__ar_EXTERNAL_OBJECTS =

bin/llvm-ar: tools/llvm-ar/CMakeFiles/llvm-ar.dir/llvm-ar.cpp.o
bin/llvm-ar: tools/llvm-ar/CMakeFiles/llvm-ar.dir/build.make
bin/llvm-ar: lib/libLLVMX86CodeGen.a
bin/llvm-ar: lib/libLLVMX86AsmPrinter.a
bin/llvm-ar: lib/libLLVMX86AsmParser.a
bin/llvm-ar: lib/libLLVMX86Desc.a
bin/llvm-ar: lib/libLLVMX86Info.a
bin/llvm-ar: lib/libLLVMX86Disassembler.a
bin/llvm-ar: lib/libLLVMX86Info.a
bin/llvm-ar: lib/libLLVMX86Utils.a
bin/llvm-ar: lib/libLLVMCore.a
bin/llvm-ar: lib/libLLVMDlltoolDriver.a
bin/llvm-ar: lib/libLLVMLibDriver.a
bin/llvm-ar: lib/libLLVMObject.a
bin/llvm-ar: lib/libLLVMSupport.a
bin/llvm-ar: lib/libLLVMAsmPrinter.a
bin/llvm-ar: lib/libLLVMDebugInfoCodeView.a
bin/llvm-ar: lib/libLLVMDebugInfoMSF.a
bin/llvm-ar: lib/libLLVMGlobalISel.a
bin/llvm-ar: lib/libLLVMSelectionDAG.a
bin/llvm-ar: lib/libLLVMCodeGen.a
bin/llvm-ar: lib/libLLVMBitWriter.a
bin/llvm-ar: lib/libLLVMScalarOpts.a
bin/llvm-ar: lib/libLLVMInstCombine.a
bin/llvm-ar: lib/libLLVMTransformUtils.a
bin/llvm-ar: lib/libLLVMTarget.a
bin/llvm-ar: lib/libLLVMAnalysis.a
bin/llvm-ar: lib/libLLVMProfileData.a
bin/llvm-ar: lib/libLLVMX86AsmPrinter.a
bin/llvm-ar: lib/libLLVMX86Utils.a
bin/llvm-ar: lib/libLLVMMCDisassembler.a
bin/llvm-ar: lib/libLLVMObject.a
bin/llvm-ar: lib/libLLVMMCParser.a
bin/llvm-ar: lib/libLLVMMC.a
bin/llvm-ar: lib/libLLVMBitReader.a
bin/llvm-ar: lib/libLLVMCore.a
bin/llvm-ar: lib/libLLVMBinaryFormat.a
bin/llvm-ar: lib/libLLVMOption.a
bin/llvm-ar: lib/libLLVMSupport.a
bin/llvm-ar: lib/libLLVMDemangle.a
bin/llvm-ar: tools/llvm-ar/CMakeFiles/llvm-ar.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/cilk-plus-futures/Tapir/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../bin/llvm-ar"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/llvm-ar && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/llvm-ar.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tools/llvm-ar/CMakeFiles/llvm-ar.dir/build: bin/llvm-ar

.PHONY : tools/llvm-ar/CMakeFiles/llvm-ar.dir/build

tools/llvm-ar/CMakeFiles/llvm-ar.dir/requires: tools/llvm-ar/CMakeFiles/llvm-ar.dir/llvm-ar.cpp.o.requires

.PHONY : tools/llvm-ar/CMakeFiles/llvm-ar.dir/requires

tools/llvm-ar/CMakeFiles/llvm-ar.dir/clean:
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/llvm-ar && $(CMAKE_COMMAND) -P CMakeFiles/llvm-ar.dir/cmake_clean.cmake
.PHONY : tools/llvm-ar/CMakeFiles/llvm-ar.dir/clean

tools/llvm-ar/CMakeFiles/llvm-ar.dir/depend:
	cd /mnt/cilk-plus-futures/Tapir/src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/cilk-plus-futures/Tapir/src /mnt/cilk-plus-futures/Tapir/src/tools/llvm-ar /mnt/cilk-plus-futures/Tapir/src/build /mnt/cilk-plus-futures/Tapir/src/build/tools/llvm-ar /mnt/cilk-plus-futures/Tapir/src/build/tools/llvm-ar/CMakeFiles/llvm-ar.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tools/llvm-ar/CMakeFiles/llvm-ar.dir/depend
