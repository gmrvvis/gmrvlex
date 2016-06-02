source_group(\\ FILES CMakeLists.txt)

list(APPEND CPPCHECK_EXTRA_ARGS
  --suppress=*:${CMAKE_CURRENT_BINARY_DIR}/*_generated.h)

include(zerobufGenerateCxx)
set(__outdir ${PROJECT_BINARY_DIR}/include/gmrvlex)

set(GMRVLEX_DATA_DIR ${__outdir})
set(GMRVLEX_DATA_FBS 
	focus.fbs
	playbackoperation.fbs
)

zerobuf_generate_cxx(GMRVLEX_DATA ${GMRVLEX_DATA_DIR} ${GMRVLEX_DATA_FBS})

set(GMRVLEX_PUBLIC_HEADERS
  ${COMMON_INCLUDES}
  ${GMRVLEX_DATA_HEADERS}
  enums.h
)

set(GMRVLEX_HEADERS )

set(GMRVLEX_SOURCES
  ${COMMON_SOURCES}
  ${GMRVLEX_DATA_SOURCES}
)
set(GMRVLEX_LINK_LIBRARIES ZeroEQ ZeroBuf)

if(MSVC)
  list(APPEND GMRVLEX_LINK_LIBRARIES Ws2_32)
endif()

set( PROJECT_INCLUDE_NAME gmrvlex )
add_definitions(-DZEROEQ_SHARED)
common_library(gmrvlex)
