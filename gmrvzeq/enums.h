/*
 * @file	enums.h
 * @brief
 * @author Sergio E. Galindo <sergio.galindo@urjc.es> 
 * @date
 * @remarks Copyright (c) GMRV/URJC. All rights reserved.
 *					Do not distribute without further notice.
 */

#ifndef __ENUMS_H__
#define __ENUMS_H__

namespace zeq
{
  namespace gmrv
  {

    enum PlaybackOperation
    {
      PLAY = 0,
      PAUSE,
      STOP,
      REPEAT,
      NO_REPEAT,
      RESTART,
      FINISH
    };


  }
}



#endif /* __ENUMS_H__ */
