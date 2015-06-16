#include <iostream>

#include <zeq/zeq.h>
#include <lunchbox/uri.h>

#include <gmrvzeq.h>

#include <functional>
#include <boost/bind.hpp>


#define NUM_SELECTIONS 10000

void OnFocusEvent( const zeq::Event& event )
{
  std::cout << "Aqui";
  std::vector< unsigned int > in = zeq::gmrv::deserializeFocusedIDs( event );

  std::cout << "Recieve focus event contaning: " << std::endl;

  for ( unsigned int i = 0; i < in.size( ); i++ )
  {
    std::cout << in[ i ] << "  ";
  }
  std::cout << std::endl;

}

int main( int argc, char * argv[] )
{
  if ( argc < 2 )
    return -1;

  lunchbox::URI uri( argv[1] );

  zeq::Subscriber subscriber( uri );
  subscriber.registerHandler( zeq::gmrv::EVENT_FOCUSEDIDS,
      boost::bind( OnFocusEvent, _1 ));


  while ( true )
  {
    std::cout << "Waiting... " << std::endl;

    subscriber.receive( 1000 );
  }

  return 0;
}
