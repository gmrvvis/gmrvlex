
#include "gmrvzeq.h"

#include <iostream>

namespace zeroeq
{
  namespace gmrv
  {

    zeroeq::FBEvent serializeFocusedIDs( const std::vector< unsigned int >& ids )
    {
      zeroeq::FBEvent event( EVENT_FOCUSEDIDS );

      flatbuffers::FlatBufferBuilder& fbb = event.getFBB();

      auto serializedIds = fbb.CreateVector( ids.data( ), ids.size( ));

      FocusedIDsBuilder builder( fbb );

      builder.add_ids( serializedIds );

      fbb.Finish( builder.Finish( ));

      return event;
    }


    std::vector< unsigned int > deserializeFocusedIDs( const zeroeq::FBEvent& event )
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
