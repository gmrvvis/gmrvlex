
#include "gmrvzeq.h"

#include <gmrvzeq/focus_zeq_generated.h>
#include <gmrvzeq/focus_generated.h>

#include <zeq/event.h>
#include <zeq/vocabulary.h>

#include <cassert>

namespace zeq
{

  namespace gmrv
  {
    Event serializeFocusedIDs( const std::vector< unsigned int >& ids )
    {
      zeq::Event event( EVENT_FOCUSEDIDS );
      flatbuffers::FlatBufferBuilder& fbb = event.getFBB();

      auto serializedIds = fbb.CreateVector( ids.data( ), ids.size( ));

      CreateFocusedIDs( fbb, serializedIds );

      return event;
    }

    std::vector< unsigned int > deserializeFocusedIDs( const Event& event )
    {
      flatbuffers::Vector< uint32_t >* in =
          (flatbuffers::Vector< uint32_t >*)event.getData( );

      std::vector< unsigned int > out( in->Length( ));
      for ( unsigned int i = 0; i < in->Length( ); i++ )
      {
        out[ i ] = in->Get( i );
      }

      return out;
    }
  }
}
