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

# Utility rule file for XRayFDRLoggingTest-x86_64.

# Include the progress variables for this target.
include projects/compiler-rt/lib/xray/tests/unit/CMakeFiles/XRayFDRLoggingTest-x86_64.dir/progress.make

projects/compiler-rt/lib/xray/tests/unit/CMakeFiles/XRayFDRLoggingTest-x86_64: projects/compiler-rt/lib/xray/tests/unit/fdr_logging_test.cc.x86_64.o
projects/compiler-rt/lib/xray/tests/unit/CMakeFiles/XRayFDRLoggingTest-x86_64: projects/compiler-rt/lib/xray/tests/unit/xray_unit_test_main.cc.x86_64.o
projects/compiler-rt/lib/xray/tests/unit/CMakeFiles/XRayFDRLoggingTest-x86_64: projects/compiler-rt/lib/xray/tests/unit/gtest-all.cc.x86_64.o
projects/compiler-rt/lib/xray/tests/unit/CMakeFiles/XRayFDRLoggingTest-x86_64: lib/libgtest_main.a
projects/compiler-rt/lib/xray/tests/unit/CMakeFiles/XRayFDRLoggingTest-x86_64: bin/clang
	cd /mnt/cilk-plus-futures/Tapir/src/build/projects/compiler-rt/lib/xray/tests/unit && ../../../../../../bin/clang fdr_logging_test.cc.x86_64.o xray_unit_test_main.cc.x86_64.o gtest-all.cc.x86_64.o -o /mnt/cilk-plus-futures/Tapir/src/build/projects/compiler-rt/lib/xray/tests/unit/XRayFDRLoggingTest-x86_64 -Wl,-allow-shlib-undefined -m64 -lstdc++ -lm -lpthread -lpthread -L/mnt/cilk-plus-futures/Tapir/src/build/./lib/clang/5.0.0/lib/linux -lclang_rt.xray-x86_64 -ldl -lrt

projects/compiler-rt/lib/xray/tests/unit/fdr_logging_test.cc.x86_64.o: lib/libgtest_main.a
projects/compiler-rt/lib/xray/tests/unit/fdr_logging_test.cc.x86_64.o: lib/libgtest_main.a
projects/compiler-rt/lib/xray/tests/unit/fdr_logging_test.cc.x86_64.o: lib/libgtest_main.a
projects/compiler-rt/lib/xray/tests/unit/fdr_logging_test.cc.x86_64.o: lib/libgtest_main.a
projects/compiler-rt/lib/xray/tests/unit/fdr_logging_test.cc.x86_64.o: bin/clang
projects/compiler-rt/lib/xray/tests/unit/fdr_logging_test.cc.x86_64.o: ../projects/compiler-rt/lib/xray/tests/unit/fdr_logging_test.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/mnt/cilk-plus-futures/Tapir/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating fdr_logging_test.cc.x86_64.o"
	cd /mnt/cilk-plus-futures/Tapir/src/build/projects/compiler-rt/lib/xray/tests/unit && ../../../../../../bin/clang -fPIC -fvisibility-inlines-hidden -Werror=date-time -std=c++11 -Wall -W -Wno-unused-parameter -Wwrite-strings -Wcast-qual -Wno-missing-field-initializers -pedantic -Wno-long-long -Wno-maybe-uninitialized -Wdelete-non-virtual-dtor -Wno-comment -ffunction-sections -fdata-sections -Wall -std=c++11 -Wno-unused-parameter -Wno-unknown-warning-option -fPIC -fno-builtin -fno-exceptions -fomit-frame-pointer -funwind-tables -fno-stack-protector -fvisibility=hidden -fvisibility-inlines-hidden -fno-lto -O3 -g -Wno-variadic-macros -Wno-non-virtual-dtor -DGTEST_NO_LLVM_RAW_OSTREAM=1 -DGTEST_HAS_RTTI=0 -I/mnt/cilk-plus-futures/Tapir/src/utils/unittest/googletest/include -I/mnt/cilk-plus-futures/Tapir/src/utils/unittest/googletest -I/mnt/cilk-plus-futures/Tapir/src/projects/compiler-rt/include -I/mnt/cilk-plus-futures/Tapir/src/projects/compiler-rt/lib/xray -I/mnt/cilk-plus-futures/Tapir/src/projects/compiler-rt/lib -m64 -c -o fdr_logging_test.cc.x86_64.o /mnt/cilk-plus-futures/Tapir/src/projects/compiler-rt/lib/xray/tests/unit/fdr_logging_test.cc

projects/compiler-rt/lib/xray/tests/unit/xray_unit_test_main.cc.x86_64.o: lib/libgtest_main.a
projects/compiler-rt/lib/xray/tests/unit/xray_unit_test_main.cc.x86_64.o: lib/libgtest_main.a
projects/compiler-rt/lib/xray/tests/unit/xray_unit_test_main.cc.x86_64.o: bin/clang
projects/compiler-rt/lib/xray/tests/unit/xray_unit_test_main.cc.x86_64.o: ../projects/compiler-rt/lib/xray/tests/unit/xray_unit_test_main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/mnt/cilk-plus-futures/Tapir/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating xray_unit_test_main.cc.x86_64.o"
	cd /mnt/cilk-plus-futures/Tapir/src/build/projects/compiler-rt/lib/xray/tests/unit && ../../../../../../bin/clang -fPIC -fvisibility-inlines-hidden -Werror=date-time -std=c++11 -Wall -W -Wno-unused-parameter -Wwrite-strings -Wcast-qual -Wno-missing-field-initializers -pedantic -Wno-long-long -Wno-maybe-uninitialized -Wdelete-non-virtual-dtor -Wno-comment -ffunction-sections -fdata-sections -Wall -std=c++11 -Wno-unused-parameter -Wno-unknown-warning-option -fPIC -fno-builtin -fno-exceptions -fomit-frame-pointer -funwind-tables -fno-stack-protector -fvisibility=hidden -fvisibility-inlines-hidden -fno-lto -O3 -g -Wno-variadic-macros -Wno-non-virtual-dtor -DGTEST_NO_LLVM_RAW_OSTREAM=1 -DGTEST_HAS_RTTI=0 -I/mnt/cilk-plus-futures/Tapir/src/utils/unittest/googletest/include -I/mnt/cilk-plus-futures/Tapir/src/utils/unittest/googletest -I/mnt/cilk-plus-futures/Tapir/src/projects/compiler-rt/include -I/mnt/cilk-plus-futures/Tapir/src/projects/compiler-rt/lib/xray -I/mnt/cilk-plus-futures/Tapir/src/projects/compiler-rt/lib -m64 -c -o xray_unit_test_main.cc.x86_64.o /mnt/cilk-plus-futures/Tapir/src/projects/compiler-rt/lib/xray/tests/unit/xray_unit_test_main.cc

projects/compiler-rt/lib/xray/tests/unit/gtest-all.cc.x86_64.o: lib/libgtest_main.a
projects/compiler-rt/lib/xray/tests/unit/gtest-all.cc.x86_64.o: lib/libgtest_main.a
projects/compiler-rt/lib/xray/tests/unit/gtest-all.cc.x86_64.o: lib/libgtest_main.a
projects/compiler-rt/lib/xray/tests/unit/gtest-all.cc.x86_64.o: bin/clang
projects/compiler-rt/lib/xray/tests/unit/gtest-all.cc.x86_64.o: ../utils/unittest/googletest/src/gtest-all.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/mnt/cilk-plus-futures/Tapir/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Generating gtest-all.cc.x86_64.o"
	cd /mnt/cilk-plus-futures/Tapir/src/build/projects/compiler-rt/lib/xray/tests/unit && ../../../../../../bin/clang -fPIC -fvisibility-inlines-hidden -Werror=date-time -std=c++11 -Wall -W -Wno-unused-parameter -Wwrite-strings -Wcast-qual -Wno-missing-field-initializers -pedantic -Wno-long-long -Wno-maybe-uninitialized -Wdelete-non-virtual-dtor -Wno-comment -ffunction-sections -fdata-sections -Wall -std=c++11 -Wno-unused-parameter -Wno-unknown-warning-option -fPIC -fno-builtin -fno-exceptions -fomit-frame-pointer -funwind-tables -fno-stack-protector -fvisibility=hidden -fvisibility-inlines-hidden -fno-lto -O3 -g -Wno-variadic-macros -Wno-non-virtual-dtor -DGTEST_NO_LLVM_RAW_OSTREAM=1 -DGTEST_HAS_RTTI=0 -I/mnt/cilk-plus-futures/Tapir/src/utils/unittest/googletest/include -I/mnt/cilk-plus-futures/Tapir/src/utils/unittest/googletest -I/mnt/cilk-plus-futures/Tapir/src/projects/compiler-rt/include -I/mnt/cilk-plus-futures/Tapir/src/projects/compiler-rt/lib/xray -I/mnt/cilk-plus-futures/Tapir/src/projects/compiler-rt/lib -m64 -c -o gtest-all.cc.x86_64.o /mnt/cilk-plus-futures/Tapir/src/utils/unittest/googletest/src/gtest-all.cc

XRayFDRLoggingTest-x86_64: projects/compiler-rt/lib/xray/tests/unit/CMakeFiles/XRayFDRLoggingTest-x86_64
XRayFDRLoggingTest-x86_64: projects/compiler-rt/lib/xray/tests/unit/fdr_logging_test.cc.x86_64.o
XRayFDRLoggingTest-x86_64: projects/compiler-rt/lib/xray/tests/unit/xray_unit_test_main.cc.x86_64.o
XRayFDRLoggingTest-x86_64: projects/compiler-rt/lib/xray/tests/unit/gtest-all.cc.x86_64.o
XRayFDRLoggingTest-x86_64: projects/compiler-rt/lib/xray/tests/unit/CMakeFiles/XRayFDRLoggingTest-x86_64.dir/build.make

.PHONY : XRayFDRLoggingTest-x86_64

# Rule to build all files generated by this target.
projects/compiler-rt/lib/xray/tests/unit/CMakeFiles/XRayFDRLoggingTest-x86_64.dir/build: XRayFDRLoggingTest-x86_64

.PHONY : projects/compiler-rt/lib/xray/tests/unit/CMakeFiles/XRayFDRLoggingTest-x86_64.dir/build

projects/compiler-rt/lib/xray/tests/unit/CMakeFiles/XRayFDRLoggingTest-x86_64.dir/clean:
	cd /mnt/cilk-plus-futures/Tapir/src/build/projects/compiler-rt/lib/xray/tests/unit && $(CMAKE_COMMAND) -P CMakeFiles/XRayFDRLoggingTest-x86_64.dir/cmake_clean.cmake
.PHONY : projects/compiler-rt/lib/xray/tests/unit/CMakeFiles/XRayFDRLoggingTest-x86_64.dir/clean

projects/compiler-rt/lib/xray/tests/unit/CMakeFiles/XRayFDRLoggingTest-x86_64.dir/depend:
	cd /mnt/cilk-plus-futures/Tapir/src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/cilk-plus-futures/Tapir/src /mnt/cilk-plus-futures/Tapir/src/projects/compiler-rt/lib/xray/tests/unit /mnt/cilk-plus-futures/Tapir/src/build /mnt/cilk-plus-futures/Tapir/src/build/projects/compiler-rt/lib/xray/tests/unit /mnt/cilk-plus-futures/Tapir/src/build/projects/compiler-rt/lib/xray/tests/unit/CMakeFiles/XRayFDRLoggingTest-x86_64.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : projects/compiler-rt/lib/xray/tests/unit/CMakeFiles/XRayFDRLoggingTest-x86_64.dir/depend

