cmake_minimum_required(VERSION 3.10)
project(MyLLVMPass)

find_package(LLVM REQUIRED CONFIG)
add_definitions(${LLVM_DEFINITIONS})
include_directories(${LLVM_INCLUDE_DIRS})
link_directories(${LLVM_LIBRARY_DIRS})

# add_subdirectory(src)

# find_package(LLVM REQUIRED CONFIG)
# list(APPEND CMAKE_MODULE_PATH "${LLVM_CMAKE_DIR}")
# include_directories(${LLVM_INCLUDE_DIRS})
# add_definitions(${LLVM_DEFINITIONS})

# add_library(PIMVectorizationPass MODULE
#     PIMVectorizationPass.cpp
# )
add_library(MyPass MODULE src/MyPass.cpp)
# add_executable(opt_with_mypass src/MyPass.cpp)
# target_link_libraries(opt_with_mypass LLVMCore LLVMIRReader LLVMTransformUtils)

# LLVM is (typically) built with no C++ RTTI. We need to match that;
# otherwise, we'll get linker errors about missing RTTI data.
# set_target_properties(MyPass PROPERTIES
#     COMPILE_FLAGS "-fno-rtti"
# )

# add_library(MyPass MODULE src/MyPass.cpp)
# add_library(MyPass SHARED src/MyPass.cpp)
target_link_libraries(MyPass LLVMCore LLVMIRReader LLVMTransformUtils)
