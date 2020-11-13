# Install script for directory: /mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers

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

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "clang-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/clang/5.0.0/include" TYPE FILE PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ FILES
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/adxintrin.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/altivec.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/ammintrin.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/arm_acle.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/armintr.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/avx2intrin.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/avx512bwintrin.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/avx512cdintrin.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/avx512vpopcntdqintrin.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/avx512dqintrin.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/avx512erintrin.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/avx512fintrin.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/avx512ifmaintrin.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/avx512ifmavlintrin.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/avx512pfintrin.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/avx512vbmiintrin.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/avx512vbmivlintrin.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/avx512vlbwintrin.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/avx512vlcdintrin.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/avx512vldqintrin.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/avx512vlintrin.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/avxintrin.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/bmi2intrin.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/bmiintrin.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/__clang_cuda_builtin_vars.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/__clang_cuda_cmath.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/__clang_cuda_complex_builtins.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/__clang_cuda_intrinsics.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/__clang_cuda_math_forward_declares.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/__clang_cuda_runtime_wrapper.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/clzerointrin.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/cpuid.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/clflushoptintrin.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/emmintrin.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/f16cintrin.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/float.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/fma4intrin.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/fmaintrin.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/fxsrintrin.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/htmintrin.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/htmxlintrin.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/ia32intrin.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/immintrin.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/intrin.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/inttypes.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/iso646.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/limits.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/lwpintrin.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/lzcntintrin.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/mm3dnow.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/mmintrin.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/mm_malloc.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/module.modulemap"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/msa.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/mwaitxintrin.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/nmmintrin.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/opencl-c.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/pkuintrin.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/pmmintrin.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/popcntintrin.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/prfchwintrin.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/rdseedintrin.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/rtmintrin.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/s390intrin.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/shaintrin.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/smmintrin.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/stdalign.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/stdarg.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/stdatomic.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/stdbool.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/stddef.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/__stddef_max_align_t.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/stdint.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/stdnoreturn.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/tbmintrin.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/tgmath.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/tmmintrin.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/unwind.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/vadefs.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/varargs.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/vecintrin.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/wmmintrin.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/__wmmintrin_aes.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/__wmmintrin_pclmul.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/x86intrin.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/xmmintrin.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/xopintrin.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/xsavecintrin.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/xsaveintrin.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/xsaveoptintrin.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/xsavesintrin.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/xtestintrin.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/cilk/cilk.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/cilk/cilk_api.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/cilk/cilk_api_linux.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/cilk/cilk_stub.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/cilk/cilk_undocumented.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/cilk/common.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/cilk/holder.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/cilk/hyperobject_base.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/cilk/metaprogramming.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/cilk/reducer.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/cilk/reducer_file.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/cilk/reducer_list.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/cilk/reducer_max.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/cilk/reducer_min.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/cilk/reducer_min_max.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/cilk/reducer_opadd.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/cilk/reducer_opand.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/cilk/reducer_opmul.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/cilk/reducer_opor.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/cilk/reducer_opxor.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/cilk/reducer_ostream.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/cilk/reducer_string.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/cilktools/cilkscreen.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/cilktools/cilkview.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/cilktools/fake_mutex.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/cilktools/lock_guard.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/internal/abi.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/internal/cilk_fake.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/internal/cilk_version.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/internal/metacall.h"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/internal/rev.mk"
    "/mnt/cilk-plus-futures/Tapir/src/build/tools/clang/lib/Headers/arm_neon.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "clang-headers")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/clang/5.0.0/include/cuda_wrappers" TYPE FILE PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ FILES
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/cuda_wrappers/algorithm"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/cuda_wrappers/complex"
    "/mnt/cilk-plus-futures/Tapir/src/tools/clang/lib/Headers/cuda_wrappers/new"
    )
endif()

