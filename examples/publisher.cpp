#include <iostream>

#include <zeroeq/zeroeq.h>
#include <servus/uri.h>

#include <ctime>

#include <gmrvlex/focus.h>

#define NUM_SELECTIONS 100

void delay( unsigned int delay_ )
{
  std::clock_t starTime = std::clock( );
  bool endTime = false;

  while( !endTime )
  {
    endTime = (( unsigned int ) (( std::clock( ) - starTime ) * 1000 /
                                 CLOCKS_PER_SEC )) >= delay_;
  }

}

int main( int /*argc*/, char ** /*argv[]*/ )
{

  zeroeq::Publisher publisher;

  zeroeq::gmrv::FocusedIDs focusIDs;

  for ( unsigned int i = 0; i < NUM_SELECTIONS; i++ )
  {
    focusIDs.getIds( ).push_back( i );

    publisher.publish( focusIDs );
    std::cout << "Sent FocusedIDs Event" << std::endl;
    delay( 100 );
  }

  return 0;
}
