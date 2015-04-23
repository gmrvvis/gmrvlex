source_group(\\ FILES CMakeLists.txt)

function(flatbuffers_generate_c_headers Name)
  set(FLATC_OUTPUTS)
  set(FLATC_ZEQ_OUTPUTS)
  foreach(FILE ${ARGN})
    get_filename_component(FLATC_OUTPUT ${FILE} NAME_WE)
    set(FLATC_ZEQ_OUTPUT
      "${CMAKE_CURRENT_BINARY_DIR}/${FLATC_OUTPUT}_zeq_generated.h")
    set(FLATC_OUTPUT
      "${CMAKE_CURRENT_BINARY_DIR}/${FLATC_OUTPUT}_generated.h")
    list(APPEND FLATC_OUTPUTS ${FLATC_OUTPUT})
    list(APPEND FLATC_ZEQ_OUTPUTS ${FLATC_ZEQ_OUTPUT})

    add_custom_command(OUTPUT ${FLATC_OUTPUT} ${FLATC_ZEQ_OUTPUT}
      COMMAND ${FLATBUFFERS_FLATC_EXECUTABLE}
      ARGS -c -z -o "${CMAKE_CURRENT_BINARY_DIR}/" ${FILE}
      COMMENT "Building C++ headers for ${FILE}"
      DEPENDS ${FILE} ${FLATBUFFERS_FLATC_EXECUTABLE}
      WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
  endforeach()
  set(${Name}_OUTPUTS ${FLATC_OUTPUTS} PARENT_SCOPE)
  set(${Name}_ZEQ_OUTPUTS ${FLATC_ZEQ_OUTPUTS} PARENT_SCOPE)
endfunction()

flatbuffers_generate_c_headers(GMRVZEQ_FBS
  ./idscolor.fbs
)

message(STATUS "Headers to generate: " ${GMRVZEQ_FBS_ZEQ_OUTPUTS})

set(GMRVZEQ_PUBLIC_HEADERS
  ${COMMON_INCLUDES}
  ${GMRVZEQ_FBS_ZEQ_OUTPUTS}
  gmrvzeq.h
)

set(GMRVZEQ_HEADERS )

set(GMRVZEQ_SOURCES ${COMMON_SOURCES}
  gmrvzeq.cpp
)

set(GMRVZEQ_LINK_LIBRARIES ${ZEQ_LIBRARIES})
if(MSVC)
  list(APPEND GMRVZEQ_LINK_LIBRARIES Ws2_32)
endif()

common_library(gmrvzeq)
