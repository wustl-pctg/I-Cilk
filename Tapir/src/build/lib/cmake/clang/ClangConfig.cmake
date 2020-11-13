# This file allows users to call find_package(Clang) and pick up our targets.



find_package(LLVM REQUIRED CONFIG
             HINTS "/mnt/cilk-plus-futures/Tapir/src/build/lib/cmake/llvm")

set(CLANG_EXPORTED_TARGETS "clangBasic;clangLex;clangParse;clangAST;clangDynamicASTMatchers;clangASTMatchers;clangSema;clangCodeGen;clangAnalysis;clangEdit;clangRewrite;clangARCMigrate;clangDriver;clangSerialization;clangRewriteFrontend;clangFrontend;clangFrontendTool;clangToolingCore;clangToolingRefactor;clangTooling;clangIndex;clangStaticAnalyzerCore;clangStaticAnalyzerCheckers;clangStaticAnalyzerFrontend;clangFormat;clang;clang-format;clang-import-test;libclang")
set(CLANG_CMAKE_DIR "/mnt/cilk-plus-futures/Tapir/src/build/lib/cmake/clang")
set(CLANG_INCLUDE_DIRS "/mnt/cilk-plus-futures/Tapir/src/tools/clang/include;/mnt/cilk-plus-futures/Tapir/src/build/tools/clang/include")

# Provide all our library targets to users.
include("/mnt/cilk-plus-futures/Tapir/src/build/lib/cmake/clang/ClangTargets.cmake")
