source_group(\\ FILES CMakeLists.txt)

flatbuffers_generate_c_headers(GMRVZEQ_FBS
  idscolor.fbs
)

message("-------------" ${GMRVZEQ_FBS_ZEQ_OUTPUTS})


set(GMRVZEQ_PUBLIC_HEADERS ${COMMON_INCLUDES}
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

