# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#
#   GMRVLEX
#   2015 (c) GMRV / Universidad Rey Juan Carlos
#   gmrv@gmrv.es
#   www.gmrv.es
#
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

# gmrvlex project and version
project(gmrvlex VERSION 0.1.0)
set(gmrvlex_VERSION_ABI 1)


# Disable in source building
if("${PROJECT_SOURCE_DIR}" STREQUAL "${PROJECT_BINARY_DIR}")
  message(FATAL "no in source building allowed.")
endif()

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMake
  ${CMAKE_SOURCE_DIR}/CMake/common)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif(NOT CMAKE_BUILD_TYPE)

if (CMAKE_BUILD_TYPE MATCHES "Debug")
  add_definitions(-DDEBUG)
endif()

include(GitExternal)

include(Common)

# description
set(GMRVLEX_DESCRIPTION "Gmrvlex")
set(COMMON_PROJECT_DOMAIN gmrv.es)

common_find_package(ZeroEQ REQUIRED)
common_find_package(ZeroBuf REQUIRED)
common_find_package_post()

list(APPEND GMRVZEQ_DEPENDENT_LIBRARIES ZeroEQ ZeroBuf )

add_subdirectory(gmrvlex)
add_subdirectory(examples)

include(CPackConfig)
include(DoxygenRule)
