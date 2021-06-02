// ====================================================================== 
// \title  BasicTopologyAc.hpp
// \author Generated by fpp-to-cpp
// \brief  hpp file for Basic topology
//
// \copyright
// Copyright (c) 2021 California Institute of Technology.
// U.S. Government sponsorship acknowledged.
// All rights reserved.
// ======================================================================

#ifndef M_BasicTopologyAc_HPP
#define M_BasicTopologyAc_HPP

#include "BasicTopologyDefs.hpp"
#include "C1.hpp"
#include "C2.hpp"

namespace M {

  // ----------------------------------------------------------------------
  // Constants
  // ----------------------------------------------------------------------

  namespace ConfigConstants {
    namespace c1 {
      enum {
        X = 0,
        Y = 1
      };
    }
  }

  namespace BaseIds {
    enum {
      c1 = 0x100,
      c2 = 0x200,
    }
  }

  namespace InstanceIds {
    enum {
      c1,
      c2,
    }
  }

  namespace Priorities {
    enum {
      c1 = 1,
    }
  }

  namespace QueueSizes {
    enum {
      c1 = 10,
    }
  }

  namespace StackSizes {
    enum {
      c1 = 1024,
    }
  }

  namespace TaskIds {
    enum {
      c1,
    }
  }

}

#endif
