set( GMRVZEQPUBLISHER_SOURCES
  publisher.cpp
)

set( GMRVZEQSUBSCRIBER_SOURCES
  subscriber.cpp
)

include_directories( ../gmrvzeq )


set( GMRVZEQPUBLISHER_LINK_LIBRARIES
  gmrvzeq
)

set( GMRVZEQSUBSCRIBER_LINK_LIBRARIES
  gmrvzeq
)

common_application( gmrvzeqPublisher )
common_application( gmrvzeqSubscriber )
