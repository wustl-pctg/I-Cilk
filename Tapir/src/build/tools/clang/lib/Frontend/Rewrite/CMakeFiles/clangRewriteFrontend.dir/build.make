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
include tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/depend.make

# Include the progress variables for this target.
include tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/progress.make

# Include the compile flags for this target's objects.
include tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/flags.make

tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/FixItRewriter.cpp.o: tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/flags.make
tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/FixItRewriter.cpp.o: ../tools/clang/lib/Frontend/Rewrite/FixItRewriter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/cilk-plus-futures/Tapir/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/FixItRewriter.cpp.o"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/clang/lib/Frontend/Rewrite && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/clangRewriteFrontend.dir/FixItRewriter.cpp.o -c /mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Frontend/Rewrite/FixItRewriter.cpp

tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/FixItRewriter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/clangRewriteFrontend.dir/FixItRewriter.cpp.i"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/clang/lib/Frontend/Rewrite && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Frontend/Rewrite/FixItRewriter.cpp > CMakeFiles/clangRewriteFrontend.dir/FixItRewriter.cpp.i

tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/FixItRewriter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/clangRewriteFrontend.dir/FixItRewriter.cpp.s"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/clang/lib/Frontend/Rewrite && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Frontend/Rewrite/FixItRewriter.cpp -o CMakeFiles/clangRewriteFrontend.dir/FixItRewriter.cpp.s

tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/FixItRewriter.cpp.o.requires:

.PHONY : tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/FixItRewriter.cpp.o.requires

tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/FixItRewriter.cpp.o.provides: tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/FixItRewriter.cpp.o.requires
	$(MAKE) -f tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/build.make tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/FixItRewriter.cpp.o.provides.build
.PHONY : tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/FixItRewriter.cpp.o.provides

tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/FixItRewriter.cpp.o.provides.build: tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/FixItRewriter.cpp.o


tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/FrontendActions.cpp.o: tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/flags.make
tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/FrontendActions.cpp.o: ../tools/clang/lib/Frontend/Rewrite/FrontendActions.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/cilk-plus-futures/Tapir/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/FrontendActions.cpp.o"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/clang/lib/Frontend/Rewrite && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/clangRewriteFrontend.dir/FrontendActions.cpp.o -c /mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Frontend/Rewrite/FrontendActions.cpp

tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/FrontendActions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/clangRewriteFrontend.dir/FrontendActions.cpp.i"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/clang/lib/Frontend/Rewrite && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Frontend/Rewrite/FrontendActions.cpp > CMakeFiles/clangRewriteFrontend.dir/FrontendActions.cpp.i

tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/FrontendActions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/clangRewriteFrontend.dir/FrontendActions.cpp.s"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/clang/lib/Frontend/Rewrite && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Frontend/Rewrite/FrontendActions.cpp -o CMakeFiles/clangRewriteFrontend.dir/FrontendActions.cpp.s

tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/FrontendActions.cpp.o.requires:

.PHONY : tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/FrontendActions.cpp.o.requires

tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/FrontendActions.cpp.o.provides: tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/FrontendActions.cpp.o.requires
	$(MAKE) -f tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/build.make tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/FrontendActions.cpp.o.provides.build
.PHONY : tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/FrontendActions.cpp.o.provides

tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/FrontendActions.cpp.o.provides.build: tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/FrontendActions.cpp.o


tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/HTMLPrint.cpp.o: tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/flags.make
tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/HTMLPrint.cpp.o: ../tools/clang/lib/Frontend/Rewrite/HTMLPrint.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/cilk-plus-futures/Tapir/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/HTMLPrint.cpp.o"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/clang/lib/Frontend/Rewrite && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/clangRewriteFrontend.dir/HTMLPrint.cpp.o -c /mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Frontend/Rewrite/HTMLPrint.cpp

tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/HTMLPrint.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/clangRewriteFrontend.dir/HTMLPrint.cpp.i"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/clang/lib/Frontend/Rewrite && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Frontend/Rewrite/HTMLPrint.cpp > CMakeFiles/clangRewriteFrontend.dir/HTMLPrint.cpp.i

tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/HTMLPrint.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/clangRewriteFrontend.dir/HTMLPrint.cpp.s"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/clang/lib/Frontend/Rewrite && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Frontend/Rewrite/HTMLPrint.cpp -o CMakeFiles/clangRewriteFrontend.dir/HTMLPrint.cpp.s

tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/HTMLPrint.cpp.o.requires:

.PHONY : tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/HTMLPrint.cpp.o.requires

tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/HTMLPrint.cpp.o.provides: tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/HTMLPrint.cpp.o.requires
	$(MAKE) -f tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/build.make tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/HTMLPrint.cpp.o.provides.build
.PHONY : tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/HTMLPrint.cpp.o.provides

tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/HTMLPrint.cpp.o.provides.build: tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/HTMLPrint.cpp.o


tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/InclusionRewriter.cpp.o: tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/flags.make
tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/InclusionRewriter.cpp.o: ../tools/clang/lib/Frontend/Rewrite/InclusionRewriter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/cilk-plus-futures/Tapir/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/InclusionRewriter.cpp.o"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/clang/lib/Frontend/Rewrite && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/clangRewriteFrontend.dir/InclusionRewriter.cpp.o -c /mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Frontend/Rewrite/InclusionRewriter.cpp

tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/InclusionRewriter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/clangRewriteFrontend.dir/InclusionRewriter.cpp.i"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/clang/lib/Frontend/Rewrite && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Frontend/Rewrite/InclusionRewriter.cpp > CMakeFiles/clangRewriteFrontend.dir/InclusionRewriter.cpp.i

tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/InclusionRewriter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/clangRewriteFrontend.dir/InclusionRewriter.cpp.s"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/clang/lib/Frontend/Rewrite && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Frontend/Rewrite/InclusionRewriter.cpp -o CMakeFiles/clangRewriteFrontend.dir/InclusionRewriter.cpp.s

tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/InclusionRewriter.cpp.o.requires:

.PHONY : tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/InclusionRewriter.cpp.o.requires

tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/InclusionRewriter.cpp.o.provides: tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/InclusionRewriter.cpp.o.requires
	$(MAKE) -f tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/build.make tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/InclusionRewriter.cpp.o.provides.build
.PHONY : tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/InclusionRewriter.cpp.o.provides

tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/InclusionRewriter.cpp.o.provides.build: tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/InclusionRewriter.cpp.o


tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/RewriteMacros.cpp.o: tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/flags.make
tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/RewriteMacros.cpp.o: ../tools/clang/lib/Frontend/Rewrite/RewriteMacros.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/cilk-plus-futures/Tapir/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/RewriteMacros.cpp.o"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/clang/lib/Frontend/Rewrite && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/clangRewriteFrontend.dir/RewriteMacros.cpp.o -c /mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Frontend/Rewrite/RewriteMacros.cpp

tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/RewriteMacros.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/clangRewriteFrontend.dir/RewriteMacros.cpp.i"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/clang/lib/Frontend/Rewrite && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Frontend/Rewrite/RewriteMacros.cpp > CMakeFiles/clangRewriteFrontend.dir/RewriteMacros.cpp.i

tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/RewriteMacros.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/clangRewriteFrontend.dir/RewriteMacros.cpp.s"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/clang/lib/Frontend/Rewrite && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Frontend/Rewrite/RewriteMacros.cpp -o CMakeFiles/clangRewriteFrontend.dir/RewriteMacros.cpp.s

tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/RewriteMacros.cpp.o.requires:

.PHONY : tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/RewriteMacros.cpp.o.requires

tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/RewriteMacros.cpp.o.provides: tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/RewriteMacros.cpp.o.requires
	$(MAKE) -f tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/build.make tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/RewriteMacros.cpp.o.provides.build
.PHONY : tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/RewriteMacros.cpp.o.provides

tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/RewriteMacros.cpp.o.provides.build: tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/RewriteMacros.cpp.o


tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/RewriteModernObjC.cpp.o: tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/flags.make
tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/RewriteModernObjC.cpp.o: ../tools/clang/lib/Frontend/Rewrite/RewriteModernObjC.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/cilk-plus-futures/Tapir/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/RewriteModernObjC.cpp.o"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/clang/lib/Frontend/Rewrite && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/clangRewriteFrontend.dir/RewriteModernObjC.cpp.o -c /mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Frontend/Rewrite/RewriteModernObjC.cpp

tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/RewriteModernObjC.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/clangRewriteFrontend.dir/RewriteModernObjC.cpp.i"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/clang/lib/Frontend/Rewrite && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Frontend/Rewrite/RewriteModernObjC.cpp > CMakeFiles/clangRewriteFrontend.dir/RewriteModernObjC.cpp.i

tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/RewriteModernObjC.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/clangRewriteFrontend.dir/RewriteModernObjC.cpp.s"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/clang/lib/Frontend/Rewrite && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Frontend/Rewrite/RewriteModernObjC.cpp -o CMakeFiles/clangRewriteFrontend.dir/RewriteModernObjC.cpp.s

tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/RewriteModernObjC.cpp.o.requires:

.PHONY : tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/RewriteModernObjC.cpp.o.requires

tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/RewriteModernObjC.cpp.o.provides: tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/RewriteModernObjC.cpp.o.requires
	$(MAKE) -f tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/build.make tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/RewriteModernObjC.cpp.o.provides.build
.PHONY : tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/RewriteModernObjC.cpp.o.provides

tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/RewriteModernObjC.cpp.o.provides.build: tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/RewriteModernObjC.cpp.o


tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/RewriteObjC.cpp.o: tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/flags.make
tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/RewriteObjC.cpp.o: ../tools/clang/lib/Frontend/Rewrite/RewriteObjC.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/cilk-plus-futures/Tapir/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/RewriteObjC.cpp.o"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/clang/lib/Frontend/Rewrite && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/clangRewriteFrontend.dir/RewriteObjC.cpp.o -c /mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Frontend/Rewrite/RewriteObjC.cpp

tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/RewriteObjC.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/clangRewriteFrontend.dir/RewriteObjC.cpp.i"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/clang/lib/Frontend/Rewrite && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Frontend/Rewrite/RewriteObjC.cpp > CMakeFiles/clangRewriteFrontend.dir/RewriteObjC.cpp.i

tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/RewriteObjC.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/clangRewriteFrontend.dir/RewriteObjC.cpp.s"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/clang/lib/Frontend/Rewrite && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Frontend/Rewrite/RewriteObjC.cpp -o CMakeFiles/clangRewriteFrontend.dir/RewriteObjC.cpp.s

tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/RewriteObjC.cpp.o.requires:

.PHONY : tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/RewriteObjC.cpp.o.requires

tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/RewriteObjC.cpp.o.provides: tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/RewriteObjC.cpp.o.requires
	$(MAKE) -f tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/build.make tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/RewriteObjC.cpp.o.provides.build
.PHONY : tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/RewriteObjC.cpp.o.provides

tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/RewriteObjC.cpp.o.provides.build: tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/RewriteObjC.cpp.o


tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/RewriteTest.cpp.o: tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/flags.make
tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/RewriteTest.cpp.o: ../tools/clang/lib/Frontend/Rewrite/RewriteTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/cilk-plus-futures/Tapir/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/RewriteTest.cpp.o"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/clang/lib/Frontend/Rewrite && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/clangRewriteFrontend.dir/RewriteTest.cpp.o -c /mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Frontend/Rewrite/RewriteTest.cpp

tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/RewriteTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/clangRewriteFrontend.dir/RewriteTest.cpp.i"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/clang/lib/Frontend/Rewrite && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Frontend/Rewrite/RewriteTest.cpp > CMakeFiles/clangRewriteFrontend.dir/RewriteTest.cpp.i

tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/RewriteTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/clangRewriteFrontend.dir/RewriteTest.cpp.s"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/clang/lib/Frontend/Rewrite && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Frontend/Rewrite/RewriteTest.cpp -o CMakeFiles/clangRewriteFrontend.dir/RewriteTest.cpp.s

tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/RewriteTest.cpp.o.requires:

.PHONY : tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/RewriteTest.cpp.o.requires

tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/RewriteTest.cpp.o.provides: tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/RewriteTest.cpp.o.requires
	$(MAKE) -f tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/build.make tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/RewriteTest.cpp.o.provides.build
.PHONY : tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/RewriteTest.cpp.o.provides

tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/RewriteTest.cpp.o.provides.build: tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/RewriteTest.cpp.o


# Object files for target clangRewriteFrontend
clangRewriteFrontend_OBJECTS = \
"CMakeFiles/clangRewriteFrontend.dir/FixItRewriter.cpp.o" \
"CMakeFiles/clangRewriteFrontend.dir/FrontendActions.cpp.o" \
"CMakeFiles/clangRewriteFrontend.dir/HTMLPrint.cpp.o" \
"CMakeFiles/clangRewriteFrontend.dir/InclusionRewriter.cpp.o" \
"CMakeFiles/clangRewriteFrontend.dir/RewriteMacros.cpp.o" \
"CMakeFiles/clangRewriteFrontend.dir/RewriteModernObjC.cpp.o" \
"CMakeFiles/clangRewriteFrontend.dir/RewriteObjC.cpp.o" \
"CMakeFiles/clangRewriteFrontend.dir/RewriteTest.cpp.o"

# External object files for target clangRewriteFrontend
clangRewriteFrontend_EXTERNAL_OBJECTS =

lib/libclangRewriteFrontend.a: tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/FixItRewriter.cpp.o
lib/libclangRewriteFrontend.a: tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/FrontendActions.cpp.o
lib/libclangRewriteFrontend.a: tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/HTMLPrint.cpp.o
lib/libclangRewriteFrontend.a: tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/InclusionRewriter.cpp.o
lib/libclangRewriteFrontend.a: tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/RewriteMacros.cpp.o
lib/libclangRewriteFrontend.a: tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/RewriteModernObjC.cpp.o
lib/libclangRewriteFrontend.a: tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/RewriteObjC.cpp.o
lib/libclangRewriteFrontend.a: tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/RewriteTest.cpp.o
lib/libclangRewriteFrontend.a: tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/build.make
lib/libclangRewriteFrontend.a: tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/cilk-plus-futures/Tapir/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX static library ../../../../../lib/libclangRewriteFrontend.a"
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/clang/lib/Frontend/Rewrite && $(CMAKE_COMMAND) -P CMakeFiles/clangRewriteFrontend.dir/cmake_clean_target.cmake
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/clang/lib/Frontend/Rewrite && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/clangRewriteFrontend.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/build: lib/libclangRewriteFrontend.a

.PHONY : tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/build

tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/requires: tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/FixItRewriter.cpp.o.requires
tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/requires: tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/FrontendActions.cpp.o.requires
tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/requires: tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/HTMLPrint.cpp.o.requires
tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/requires: tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/InclusionRewriter.cpp.o.requires
tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/requires: tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/RewriteMacros.cpp.o.requires
tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/requires: tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/RewriteModernObjC.cpp.o.requires
tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/requires: tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/RewriteObjC.cpp.o.requires
tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/requires: tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/RewriteTest.cpp.o.requires

.PHONY : tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/requires

tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/clean:
	cd /mnt/cilk-plus-futures/Tapir/src/build/tools/clang/lib/Frontend/Rewrite && $(CMAKE_COMMAND) -P CMakeFiles/clangRewriteFrontend.dir/cmake_clean.cmake
.PHONY : tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/clean

tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/depend:
	cd /mnt/cilk-plus-futures/Tapir/src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/cilk-plus-futures/Tapir/src /mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Frontend/Rewrite /mnt/cilk-plus-futures/Tapir/src/build /mnt/cilk-plus-futures/Tapir/src/build/tools/clang/lib/Frontend/Rewrite /mnt/cilk-plus-futures/Tapir/src/build/tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tools/clang/lib/Frontend/Rewrite/CMakeFiles/clangRewriteFrontend.dir/depend

