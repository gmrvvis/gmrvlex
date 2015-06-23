
#include "gmrvzeq.h"

#include <gmrvzeq/focus_generated.h>


#include <zeq/event.h>
#include <zeq/vocabulary.h>

#include <iostream>

namespace zeq
{
  namespace gmrv
  {

    Event serializeFocusedIDs( const std::vector< unsigned int >& ids )
    {
      zeq::Event event( EVENT_FOCUSEDIDS );

      flatbuffers::FlatBufferBuilder& fbb = event.getFBB();

      auto serializedIds = fbb.CreateVector( ids.data( ), ids.size( ));

      FocusedIDsBuilder builder( fbb );

      builder.add_ids( serializedIds );

      fbb.Finish( builder.Finish( ));

      return event;
    }


    std::vector< unsigned int > deserializeFocusedIDs( const Event& event )
    {

      auto data = flatbuffers::GetRoot<FocusedIDs>( event.getData( ));

      std::vector< unsigned int> out( data->ids( )->Length( ));

      for ( unsigned int i = 0; i < data->ids( )->Length( ); i++ )
      {
        out[ i ] = data->ids( )->Get( i );
      }

      return out;
    }

  }
}
