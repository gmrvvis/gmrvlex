set( GMRVLEXPUBLISHER_SOURCES
  publisher.cpp
)

set( GMRVLEXSUBSCRIBER_SOURCES
  subscriber.cpp
)

include_directories( ../gmrvlex )


set( GMRVLEXPUBLISHER_LINK_LIBRARIES
  gmrvlex
)

set( GMRVLEXSUBSCRIBER_LINK_LIBRARIES
  gmrvlex
)

common_application( gmrvlexPublisher )
common_application( gmrvlexSubscriber )
