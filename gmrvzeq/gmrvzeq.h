#ifndef GMRV_ZEQ_VOCABULARY_H
#define GMRV_ZEQ_VOCABULARY_H

#include <zeroeq/zeroeq.h>

#include <gmrvzeq/focus_zeroeq_generated.h>

#include <vector>

namespace zeroeq
{
  namespace gmrv
  {

    ZEROEQ_API
    FBEvent serializeFocusedIDs( const std::vector< unsigned int >& ids );

    ZEROEQ_API
    std::vector< unsigned int > deserializeFocusedIDs( const FBEvent& event );

  }
}
#endif
