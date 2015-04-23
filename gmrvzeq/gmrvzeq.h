#ifndef GMRV_ZEQ_VOCABULARY_H
#define GMRV_ZEQ_VOCABULARY_H

#include <zeq/types.h>
#include <zeq/api.h>

#include <gmrvzeq/idscolor_zeq_generated.h>

namespace zeq
{
  namespace gmrv
  {
    namespace data
    {
      struct IDColor
      {
        IDColor(unsigned int id, std::vector<unsigned char> color)
        : _id( id )
        , _color( color.data() )
        {}

        unsigned int Id(){return _id;}
        unsigned char* Color(){return _color;}

        private:

          unsigned int _id;
          unsigned char* _color;

      };

      struct IDColorsArray
      {

      private:
        unsigned int _size;
        IDColor* _idcolors;
      };

    }
    /**
     * Serialize the given JPEG image into an Event of type EVENT_IMAGEJPEG.
     * @param image the JPEG image.
     * @return the serialized event.
     */
    ZEQ_API Event serializeIDsColors( const data::IDColor& colors );

    /**
     * Deserialize the given EVENT_IMAGEJPEG event into an JPEG image.
     * @param event the zeq EVENT_IMAGEJPEG.
     * @return the jpeg image.
     */
    ZEQ_API data::IDColor* deserializeIDsColors( const Event& event );

  }
}
#endif
