# Install script for directory: /mnt/cilk-plus-futures/Tapir/src/projects/compiler-rt/include

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/clang/5.0.0/include/sanitizer" TYPE FILE PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ FILES
    "/mnt/cilk-plus-futures/Tapir/src/projects/compiler-rt/include/sanitizer/allocator_interface.h"
    "/mnt/cilk-plus-futures/Tapir/src/projects/compiler-rt/include/sanitizer/asan_interface.h"
    "/mnt/cilk-plus-futures/Tapir/src/projects/compiler-rt/include/sanitizer/common_interface_defs.h"
    "/mnt/cilk-plus-futures/Tapir/src/projects/compiler-rt/include/sanitizer/coverage_interface.h"
    "/mnt/cilk-plus-futures/Tapir/src/projects/compiler-rt/include/sanitizer/dfsan_interface.h"
    "/mnt/cilk-plus-futures/Tapir/src/projects/compiler-rt/include/sanitizer/esan_interface.h"
    "/mnt/cilk-plus-futures/Tapir/src/projects/compiler-rt/include/sanitizer/linux_syscall_hooks.h"
    "/mnt/cilk-plus-futures/Tapir/src/projects/compiler-rt/include/sanitizer/lsan_interface.h"
    "/mnt/cilk-plus-futures/Tapir/src/projects/compiler-rt/include/sanitizer/msan_interface.h"
    "/mnt/cilk-plus-futures/Tapir/src/projects/compiler-rt/include/sanitizer/tsan_interface.h"
    "/mnt/cilk-plus-futures/Tapir/src/projects/compiler-rt/include/sanitizer/tsan_interface_atomic.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/clang/5.0.0/include/xray" TYPE FILE PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ FILES
    "/mnt/cilk-plus-futures/Tapir/src/projects/compiler-rt/include/xray/xray_interface.h"
    "/mnt/cilk-plus-futures/Tapir/src/projects/compiler-rt/include/xray/xray_log_interface.h"
    )
endif()

