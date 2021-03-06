/*
 * @file	enums.h
 * @brief
 * @author Sergio E. Galindo <sergio.galindo@urjc.es> 
 * @date
 * @remarks Copyright (c) GMRV/URJC. All rights reserved.
 *					Do not distribute without further notice.
 */

#ifndef __ZEROEQ_GMRV_ENUMS_H__
#define __ZEROEQ_GMRV_ENUMS_H__

namespace zeroeq
{
  namespace gmrv
  {

    enum PlaybackOperation
    {
      PLAY = 0,
      PAUSE,
      STOP,
      ENABLE_LOOP,
      DISABLE_LOOP,
      BEGIN,
      END
    };


  }
}

#endif /* __ZEQ_GMRV_ENUMS_H__ */
