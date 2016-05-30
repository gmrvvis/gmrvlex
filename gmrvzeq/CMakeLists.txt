source_group(\\ FILES CMakeLists.txt)

list(APPEND CPPCHECK_EXTRA_ARGS
  --suppress=*:${CMAKE_CURRENT_BINARY_DIR}/*_generated.h)

include(zerobufGenerateCxx)
set(__outdir ${PROJECT_BINARY_DIR}/include/gmrvzeq)

set(GMRVZEQ_DATA_DIR ${__outdir})
set(GMRVZEQ_DATA_FBS focus.fbs)

zerobuf_generate_cxx(GMRVZEQ_DATA ${GMRVZEQ_DATA_DIR} ${GMRVZEQ_DATA_FBS})

set(GMRVZEQ_PUBLIC_HEADERS
  ${COMMON_INCLUDES}
  ${GMRVZEQ_DATA_HEADERS}
)

set(GMRVZEQ_HEADERS )

set(GMRVZEQ_SOURCES
  ${COMMON_SOURCES}
  ${GMRVZEQ_DATA_SOURCES}
)
set(GMRVZEQ_LINK_LIBRARIES ZeroEQ ZeroBuf)

if(MSVC)
  list(APPEND GMRVZEQ_LINK_LIBRARIES Ws2_32)
endif()

set( PROJECT_INCLUDE_NAME gmrvzeq )
add_definitions(-DZEQ_SHARED)
common_library(gmrvzeq)
