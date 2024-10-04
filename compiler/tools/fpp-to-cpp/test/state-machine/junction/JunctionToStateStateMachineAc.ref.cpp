// ======================================================================
// \title  JunctionToStateStateMachineAc.cpp
// \author Generated by fpp-to-cpp
// \brief  cpp file for JunctionToState state machine
// ======================================================================

#include "Fw/Types/Assert.hpp"
#include "junction/JunctionToStateStateMachineAc.hpp"

namespace FppTest {

  namespace SmJunction {

    // ----------------------------------------------------------------------
    // Constructors and Destructors
    // ----------------------------------------------------------------------

    JunctionToStateStateMachineBase ::
      JunctionToStateStateMachineBase()
    {

    }

    JunctionToStateStateMachineBase ::
      ~JunctionToStateStateMachineBase()
    {

    }

    // ----------------------------------------------------------------------
    // Initialization
    // ----------------------------------------------------------------------

    void JunctionToStateStateMachineBase ::
      init(const FwEnumStoreType id)
    {
      this->m_id = id;
      this->enter_S1(Signal::__FPRIME_AC_INITIAL_TRANSITION);
    }

    // ----------------------------------------------------------------------
    // Send signal functions
    // ----------------------------------------------------------------------

    void JunctionToStateStateMachineBase ::
      sendSignal_s()
    {
      switch (this->m_state) {
        case State::S1:
          this->enter_S1_J(Signal::s);
          break;
        case State::S2_S3:
          break;
        default:
          FW_ASSERT(0, static_cast<FwAssertArgType>(this->m_state));
          break;
      }
    }

    // ----------------------------------------------------------------------
    // State and junction entry
    // ----------------------------------------------------------------------

    void JunctionToStateStateMachineBase ::
      enter_S2(Signal signal)
    {
      this->action_enterS2(signal);
      this->action_a(signal);
      this->enter_S2_S3(signal);
    }

    void JunctionToStateStateMachineBase ::
      enter_S2_S3(Signal signal)
    {
      this->action_enterS3(signal);
      this->m_state = State::S2_S3;
    }

    void JunctionToStateStateMachineBase ::
      enter_S1(Signal signal)
    {
      this->m_state = State::S1;
    }

    void JunctionToStateStateMachineBase ::
      enter_S1_J(Signal signal)
    {
      if (this->guard_g(signal)) {
        this->action_exitS1(signal);
        this->action_a(signal);
        this->enter_S2(signal);
      }
      else {
        this->action_exitS1(signal);
        this->action_a(signal);
        this->action_enterS2(signal);
        this->enter_S2_S3(signal);
      }
    }

  }

}
