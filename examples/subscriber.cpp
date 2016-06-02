#include <iostream>

#include <zeroeq/zeroeq.h>
#include <servus/uri.h>

#include <functional>

#include <gmrvlex/focus.h>

#define NUM_SELECTIONS 10000

zeroeq::gmrv::FocusedIDs receivedIds;

typedef std::shared_ptr< servus::Serializable > SerializablePtr;

void onFocusReceive( )
{
  std::cout << "Received focusids: ";
  zeroeq::gmrv::FocusedIDs::Ids& ids = receivedIds.getIds( );

  for( unsigned int i = 0; i < ids.size( ); ++i )
  {
    std::cout << ids[ i ] << " ";
  }

  std::cout << std::endl;
}

int main( int /*argc*/, char ** /*argv[]*/ )
{

  std::cout << "Creating subscriber..." << std::endl;

  zeroeq::Subscriber subscriber;
  receivedIds.registerDeserializedCallback( [ & ] { onFocusReceive( );} );

  subscriber.subscribe( receivedIds );

  while ( true )
  {
    std::cout << "Waiting... " << std::endl;

    subscriber.receive( 1000 );
  }

  return 0;
}
