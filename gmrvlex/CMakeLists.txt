source_group(\\ FILES CMakeLists.txt)

flatbuffers_generate_c_headers(GMRVLEX_FBS
  detail/focus.fbs
  detail/playbackoperation.fbs
)

set(GMRVLEX_PUBLIC_HEADERS
  ${COMMON_INCLUDES}
  ${GMRVLEX_FBS_ZEQ_OUTPUTS}
  gmrvlex.h
  enums.h
)

set(GMRVLEX_HEADERS )

set(GMRVLEX_SOURCES
  ${COMMON_SOURCES}
  gmrvlex.cpp
)
set(GMRVLEX_LINK_LIBRARIES zeq)

if(MSVC)
  list(APPEND GMRVLEX_LINK_LIBRARIES Ws2_32)
endif()

list(APPEND CPPCHECK_EXTRA_ARGS
  --suppress=*:${CMAKE_CURRENT_BINARY_DIR}/*_generated.h)

set( PROJECT_INCLUDE_NAME gmrvlex )
add_definitions(-DZEQ_SHARED)
common_library(gmrvlex)
