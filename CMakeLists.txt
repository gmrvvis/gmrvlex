# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#
#   GMRVZEQ
#   2015 (c) GMRV / Universidad Rey Juan Carlos
#   gmrv@gmrv.es
#   www.gmrv.es
#
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
cmake_minimum_required(VERSION 2.8)
project(gmrvzeq)

# Disable in source building
if("${PROJECT_SOURCE_DIR}" STREQUAL "${PROJECT_BINARY_DIR}")
  message(FATAL "no in source building allowed.")
endif()

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMake
  ${CMAKE_SOURCE_DIR}/CMake/common)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif(NOT CMAKE_BUILD_TYPE)

if (CMAKE_BUILD_TYPE MATCHES "Debug")
  add_definitions(-DDEBUG)
endif()

include(GitExternal)

# gmrvzeq version
set(LAST_RELEASE 0.0.0)
set(VERSION_MAJOR "0")
set(VERSION_MINOR "1")
set(VERSION_PATCH "0")
set(VERSION_ABI 1)

# description
set(GMRVZEQ_DESCRIPTION "Gmrvzeq")
set(GMRVZEQ_DEPENDENT_LIBRARIES zeq FlatBuffers )

set(COMMON_PROJECT_DOMAIN gmrv.es)

include(Common)
include(FindPackages)

# library subdirectory
add_subdirectory(gmrvzeq)

add_subdirectory(examples)

include(CPackConfig)
include(DoxygenRule)
