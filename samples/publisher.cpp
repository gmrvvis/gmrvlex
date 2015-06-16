#include <iostream>

#include <zeq/zeq.h>
#include <lunchbox/uri.h>

#include <gmrvzeq.h>


#define NUM_SELECTIONS 10000

int main( int argc, char * argv[] )
{
  if ( argc < 2 )
    return -1;

  lunchbox::URI uri( argv[1] );

  zeq::Publisher publisher( uri );

  std::vector< unsigned int > data;

  for ( unsigned int i = 0; i < NUM_SELECTIONS; i++ )
  {
    data.push_back( i );
    publisher.publish( zeq::gmrv::serializeFocusedIDs( data ));
    std::cout << "Send FocusedIDs Event" << std::endl;
  }

  return 0;
}
