
#include "gmrvzeq.h"

namespace zeq
{

  namespace gmrv
  {

    ::zeq::Event serializeIDsColors( const data::IDColor& colors )
    {
      ::zeq::Event event( EVENT_IDCOLOR );
      flatbuffers::FlatBufferBuilder& fbb = event.getFBB();
      auto imageData = fbb.CreateVector( image.getDataPtr(),
                                         image.getSizeInBytes( ));

      ImageJPEGBuilder builder( fbb );
      builder.add_data( imageData );

      fbb.Finish( builder.Finish() );
      return event;
    }

    data::IDColor* deserializeIDsColors( const ::zeq::Event& event )
    {

    }


  }
}
