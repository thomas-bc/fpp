// ======================================================================
// \title  EmptyTesterBase.hpp
// \author Generated by fpp-to-cpp
// \brief  hpp file for Empty component test harness base class
// ======================================================================

#ifndef EmptyTesterBase_HPP
#define EmptyTesterBase_HPP

#include <cstdio>

#include "Fw/Comp/PassiveComponentBase.hpp"
#include "Fw/Port/InputSerializePort.hpp"
#include "Fw/Types/Assert.hpp"
#include "test-base/EmptyComponentAc.hpp"

//! \class EmptyTesterBase
//! \brief Auto-generated base for Empty component test harness
class EmptyTesterBase :
  public Fw::PassiveComponentBase
{

  protected:

    // ----------------------------------------------------------------------
    // History types
    // ----------------------------------------------------------------------

  public:

    // ----------------------------------------------------------------------
    // Component initialization
    // ----------------------------------------------------------------------

    //! Initialize object EmptyTesterBase
    virtual void init(
        NATIVE_INT_TYPE instance = 0 //!< The instance number
    );

  protected:

    // ----------------------------------------------------------------------
    // Component construction and destruction
    // ----------------------------------------------------------------------

    //! Construct object EmptyTesterBase
    EmptyTesterBase(
        const char* const compName, //!< The component name
        const U32 maxHistorySize //!< The maximum size of each history
    );

    //! Destroy object EmptyTesterBase
    virtual ~EmptyTesterBase();

};

#endif
