cmake_minimum_required(VERSION 3.4.0)

project(ldap-escape VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

################################################################################
# cmake-conan
# https://github.com/conan-io/cmake-conan

# Download automatically, you can also just copy the conan.cmake file
if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
  message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
  file(DOWNLOAD "https://github.com/conan-io/cmake-conan/raw/v0.14/conan.cmake"
                "${CMAKE_BINARY_DIR}/conan.cmake")
endif()

include("${CMAKE_BINARY_DIR}/conan.cmake")
conan_cmake_run(
  CONANFILE conanfile.txt
  BASIC_SETUP CMAKE_TARGETS
)

# cmake-conan
# https://github.com/conan-io/cmake-conan
################################################################################

add_library(ldap-escape STATIC
  src/ldap/escape.cpp
)

target_include_directories(ldap-escape
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_compile_options(ldap-escape
  PRIVATE
    $<$<CXX_COMPILER_ID:MSVC>:/W4>
    $<$<AND:$<CXX_COMPILER_ID:MSVC>,$<VERSION_GREATER_EQUAL:${MSVC_VERSION},1900>>:/permissive->
    $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -pedantic -Werror>
)

include(CTest)
enable_testing()

add_subdirectory(test)
