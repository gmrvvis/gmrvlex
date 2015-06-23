
set( PUBLISHER_SOURCES 
  publisher.cpp
)

set( SUBSCRIBER_SOURCES 
  subscriber.cpp
)

include_directories( ../gmrvzeq )


set( PUBLISHER_LINK_LIBRARIES 
  gmrvzeq
)

set( SUBSCRIBER_LINK_LIBRARIES
  gmrvzeq
)


common_application( publisher )

common_application( subscriber )


