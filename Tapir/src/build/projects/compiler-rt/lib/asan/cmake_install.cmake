# Install script for directory: /mnt/cilk-plus-futures/Tapir/src/projects/compiler-rt/lib/asan

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

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "clang_rt.asan-x86_64")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/clang/5.0.0/lib/linux" TYPE STATIC_LIBRARY FILES "/mnt/cilk-plus-futures/Tapir/src/build/lib/clang/5.0.0/lib/linux/libclang_rt.asan-x86_64.a")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "clang_rt.asan_cxx-x86_64")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/clang/5.0.0/lib/linux" TYPE STATIC_LIBRARY FILES "/mnt/cilk-plus-futures/Tapir/src/build/lib/clang/5.0.0/lib/linux/libclang_rt.asan_cxx-x86_64.a")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "clang_rt.asan-preinit-x86_64")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/clang/5.0.0/lib/linux" TYPE STATIC_LIBRARY FILES "/mnt/cilk-plus-futures/Tapir/src/build/lib/clang/5.0.0/lib/linux/libclang_rt.asan-preinit-x86_64.a")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "clang_rt.asan-dynamic-x86_64")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/clang/5.0.0/lib/linux/libclang_rt.asan-x86_64.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/clang/5.0.0/lib/linux/libclang_rt.asan-x86_64.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/clang/5.0.0/lib/linux/libclang_rt.asan-x86_64.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/clang/5.0.0/lib/linux" TYPE SHARED_LIBRARY FILES "/mnt/cilk-plus-futures/Tapir/src/build/lib/clang/5.0.0/lib/linux/libclang_rt.asan-x86_64.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/clang/5.0.0/lib/linux/libclang_rt.asan-x86_64.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/clang/5.0.0/lib/linux/libclang_rt.asan-x86_64.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/clang/5.0.0/lib/linux/libclang_rt.asan-x86_64.so")
    endif()
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/clang/5.0.0/lib/linux" TYPE FILE FILES "/mnt/cilk-plus-futures/Tapir/src/build/lib/clang/5.0.0/lib/linux/libclang_rt.asan_cxx-x86_64.a.syms")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/clang/5.0.0/lib/linux" TYPE FILE FILES "/mnt/cilk-plus-futures/Tapir/src/build/lib/clang/5.0.0/lib/linux/libclang_rt.asan-x86_64.a.syms")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "asan")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/clang/5.0.0" TYPE FILE FILES "/mnt/cilk-plus-futures/Tapir/src/projects/compiler-rt/lib/asan/asan_blacklist.txt")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/mnt/cilk-plus-futures/Tapir/src/build/projects/compiler-rt/lib/asan/scripts/cmake_install.cmake")
  include("/mnt/cilk-plus-futures/Tapir/src/build/projects/compiler-rt/lib/asan/tests/cmake_install.cmake")

endif()

