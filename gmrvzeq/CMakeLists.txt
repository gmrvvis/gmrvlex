source_group(\\ FILES CMakeLists.txt)

flatbuffers_generate_c_headers(GMRVZEQ_FBS
  detail/focus.fbs
  detail/playbackoperation.fbs
)

set(GMRVZEQ_PUBLIC_HEADERS
  ${COMMON_INCLUDES}
  ${GMRVZEQ_FBS_ZEQ_OUTPUTS}
  gmrvzeq.h
  enums.h
)

set(GMRVZEQ_HEADERS )

set(GMRVZEQ_SOURCES
  ${COMMON_SOURCES}
  gmrvzeq.cpp
)
set(GMRVZEQ_LINK_LIBRARIES zeq)

if(MSVC)
  list(APPEND GMRVZEQ_LINK_LIBRARIES Ws2_32)
endif()

list(APPEND CPPCHECK_EXTRA_ARGS
  --suppress=*:${CMAKE_CURRENT_BINARY_DIR}/*_generated.h)

set( PROJECT_INCLUDE_NAME gmrvzeq )
add_definitions(-DZEQ_SHARED)
common_library(gmrvzeq)
