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
include lib/Target/X86/TargetInfo/CMakeFiles/LLVMX86Info.dir/depend.make

# Include the progress variables for this target.
include lib/Target/X86/TargetInfo/CMakeFiles/LLVMX86Info.dir/progress.make

# Include the compile flags for this target's objects.
include lib/Target/X86/TargetInfo/CMakeFiles/LLVMX86Info.dir/flags.make

lib/Target/X86/TargetInfo/CMakeFiles/LLVMX86Info.dir/X86TargetInfo.cpp.o: lib/Target/X86/TargetInfo/CMakeFiles/LLVMX86Info.dir/flags.make
lib/Target/X86/TargetInfo/CMakeFiles/LLVMX86Info.dir/X86TargetInfo.cpp.o: ../lib/Target/X86/TargetInfo/X86TargetInfo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/cilk-plus-futures/Tapir/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/Target/X86/TargetInfo/CMakeFiles/LLVMX86Info.dir/X86TargetInfo.cpp.o"
	cd /mnt/cilk-plus-futures/Tapir/src/build/lib/Target/X86/TargetInfo && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LLVMX86Info.dir/X86TargetInfo.cpp.o -c /mnt/cilk-plus-futures/Tapir/src/lib/Target/X86/TargetInfo/X86TargetInfo.cpp

lib/Target/X86/TargetInfo/CMakeFiles/LLVMX86Info.dir/X86TargetInfo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LLVMX86Info.dir/X86TargetInfo.cpp.i"
	cd /mnt/cilk-plus-futures/Tapir/src/build/lib/Target/X86/TargetInfo && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/cilk-plus-futures/Tapir/src/lib/Target/X86/TargetInfo/X86TargetInfo.cpp > CMakeFiles/LLVMX86Info.dir/X86TargetInfo.cpp.i

lib/Target/X86/TargetInfo/CMakeFiles/LLVMX86Info.dir/X86TargetInfo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LLVMX86Info.dir/X86TargetInfo.cpp.s"
	cd /mnt/cilk-plus-futures/Tapir/src/build/lib/Target/X86/TargetInfo && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/cilk-plus-futures/Tapir/src/lib/Target/X86/TargetInfo/X86TargetInfo.cpp -o CMakeFiles/LLVMX86Info.dir/X86TargetInfo.cpp.s

lib/Target/X86/TargetInfo/CMakeFiles/LLVMX86Info.dir/X86TargetInfo.cpp.o.requires:

.PHONY : lib/Target/X86/TargetInfo/CMakeFiles/LLVMX86Info.dir/X86TargetInfo.cpp.o.requires

lib/Target/X86/TargetInfo/CMakeFiles/LLVMX86Info.dir/X86TargetInfo.cpp.o.provides: lib/Target/X86/TargetInfo/CMakeFiles/LLVMX86Info.dir/X86TargetInfo.cpp.o.requires
	$(MAKE) -f lib/Target/X86/TargetInfo/CMakeFiles/LLVMX86Info.dir/build.make lib/Target/X86/TargetInfo/CMakeFiles/LLVMX86Info.dir/X86TargetInfo.cpp.o.provides.build
.PHONY : lib/Target/X86/TargetInfo/CMakeFiles/LLVMX86Info.dir/X86TargetInfo.cpp.o.provides

lib/Target/X86/TargetInfo/CMakeFiles/LLVMX86Info.dir/X86TargetInfo.cpp.o.provides.build: lib/Target/X86/TargetInfo/CMakeFiles/LLVMX86Info.dir/X86TargetInfo.cpp.o


# Object files for target LLVMX86Info
LLVMX86Info_OBJECTS = \
"CMakeFiles/LLVMX86Info.dir/X86TargetInfo.cpp.o"

# External object files for target LLVMX86Info
LLVMX86Info_EXTERNAL_OBJECTS =

lib/libLLVMX86Info.a: lib/Target/X86/TargetInfo/CMakeFiles/LLVMX86Info.dir/X86TargetInfo.cpp.o
lib/libLLVMX86Info.a: lib/Target/X86/TargetInfo/CMakeFiles/LLVMX86Info.dir/build.make
lib/libLLVMX86Info.a: lib/Target/X86/TargetInfo/CMakeFiles/LLVMX86Info.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/cilk-plus-futures/Tapir/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../../../libLLVMX86Info.a"
	cd /mnt/cilk-plus-futures/Tapir/src/build/lib/Target/X86/TargetInfo && $(CMAKE_COMMAND) -P CMakeFiles/LLVMX86Info.dir/cmake_clean_target.cmake
	cd /mnt/cilk-plus-futures/Tapir/src/build/lib/Target/X86/TargetInfo && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LLVMX86Info.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/Target/X86/TargetInfo/CMakeFiles/LLVMX86Info.dir/build: lib/libLLVMX86Info.a

.PHONY : lib/Target/X86/TargetInfo/CMakeFiles/LLVMX86Info.dir/build

lib/Target/X86/TargetInfo/CMakeFiles/LLVMX86Info.dir/requires: lib/Target/X86/TargetInfo/CMakeFiles/LLVMX86Info.dir/X86TargetInfo.cpp.o.requires

.PHONY : lib/Target/X86/TargetInfo/CMakeFiles/LLVMX86Info.dir/requires

lib/Target/X86/TargetInfo/CMakeFiles/LLVMX86Info.dir/clean:
	cd /mnt/cilk-plus-futures/Tapir/src/build/lib/Target/X86/TargetInfo && $(CMAKE_COMMAND) -P CMakeFiles/LLVMX86Info.dir/cmake_clean.cmake
.PHONY : lib/Target/X86/TargetInfo/CMakeFiles/LLVMX86Info.dir/clean

lib/Target/X86/TargetInfo/CMakeFiles/LLVMX86Info.dir/depend:
	cd /mnt/cilk-plus-futures/Tapir/src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/cilk-plus-futures/Tapir/src /mnt/cilk-plus-futures/Tapir/src/lib/Target/X86/TargetInfo /mnt/cilk-plus-futures/Tapir/src/build /mnt/cilk-plus-futures/Tapir/src/build/lib/Target/X86/TargetInfo /mnt/cilk-plus-futures/Tapir/src/build/lib/Target/X86/TargetInfo/CMakeFiles/LLVMX86Info.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/Target/X86/TargetInfo/CMakeFiles/LLVMX86Info.dir/depend

