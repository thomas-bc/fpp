// ======================================================================
// \title  ActiveExternalStateMachinesComponentAc.hpp
// \author Generated by fpp-to-cpp
// \brief  hpp file for ActiveExternalStateMachines component base class
// ======================================================================

#ifndef ExternalSm_ActiveExternalStateMachinesComponentAc_HPP
#define ExternalSm_ActiveExternalStateMachinesComponentAc_HPP

#include "ActiveExternalStateMachines_S1.hpp"
#include "ActiveExternalStateMachines_S2.hpp"
#include "FpConfig.hpp"
#include "Fw/Comp/ActiveComponentBase.hpp"
#include "Fw/Port/InputSerializePort.hpp"
#include "Fw/Port/OutputSerializePort.hpp"

namespace ExternalSm {

  //! \class ActiveExternalStateMachinesComponentBase
  //! \brief Auto-generated base for ActiveExternalStateMachines component
  //!
  //! An active component with external state machines
  class ActiveExternalStateMachinesComponentBase :
    public Fw::ActiveComponentBase, public ExternalSm::ActiveExternalStateMachines_S1_Interface, public ExternalSm::ActiveExternalStateMachines_S2_Interface
  {

      // ----------------------------------------------------------------------
      // Friend classes
      // ----------------------------------------------------------------------

      //! Friend class for white-box testing
      friend class ActiveExternalStateMachinesComponentBaseFriend;

    PROTECTED:

      // ----------------------------------------------------------------------
      // Constants
      // ----------------------------------------------------------------------

      //! State machine identifiers
      enum class SmId : FwEnumStoreType {
        sm1,
        sm2,
        sm3,
        sm4,
        sm5,
        sm6,
      };

    public:

      // ----------------------------------------------------------------------
      // Component initialization
      // ----------------------------------------------------------------------

      //! Initialize ActiveExternalStateMachinesComponentBase object
      void init(
          FwSizeType queueDepth, //!< The queue depth
          FwEnumStoreType instance = 0 //!< The instance number
      );

    PROTECTED:

      // ----------------------------------------------------------------------
      // Component construction and destruction
      // ----------------------------------------------------------------------

      //! Construct ActiveExternalStateMachinesComponentBase object
      ActiveExternalStateMachinesComponentBase(
          const char* compName = "" //!< The component name
      );

      //! Destroy ActiveExternalStateMachinesComponentBase object
      virtual ~ActiveExternalStateMachinesComponentBase();

    PROTECTED:

      // ----------------------------------------------------------------------
      // Overflow hooks for external state machine instances
      //
      // When sending a signal to a state machine instance, if
      // the queue overflows and the instance is marked with 'hook' behavior,
      // the corresponding function here is called.
      // ----------------------------------------------------------------------

      //! Overflow hook for state machine sm5
      virtual void sm5_stateMachineOverflowHook(
          const ExternalSm::ActiveExternalStateMachines_S2_Interface::ActiveExternalStateMachines_S2_Signals signal, //!< The state machine signal
          const Fw::SmSignalBuffer& data //!< The state machine data
      ) = 0;

    PROTECTED:

      // ----------------------------------------------------------------------
      // Functions for sending signals to external state machines
      // ----------------------------------------------------------------------

      //! Send a signal to state machine instance sm1
      void sm1_stateMachineInvoke(
          const ExternalSm::ActiveExternalStateMachines_S1_Interface::ActiveExternalStateMachines_S1_Signals signal, //!< The state machine signal
          const Fw::SmSignalBuffer& data //!< The state machine data
      );

      //! Send a signal to state machine instance sm2
      void sm2_stateMachineInvoke(
          const ExternalSm::ActiveExternalStateMachines_S1_Interface::ActiveExternalStateMachines_S1_Signals signal, //!< The state machine signal
          const Fw::SmSignalBuffer& data //!< The state machine data
      );

      //! Send a signal to state machine instance sm3
      void sm3_stateMachineInvoke(
          const ExternalSm::ActiveExternalStateMachines_S2_Interface::ActiveExternalStateMachines_S2_Signals signal, //!< The state machine signal
          const Fw::SmSignalBuffer& data //!< The state machine data
      );

      //! Send a signal to state machine instance sm4
      void sm4_stateMachineInvoke(
          const ExternalSm::ActiveExternalStateMachines_S2_Interface::ActiveExternalStateMachines_S2_Signals signal, //!< The state machine signal
          const Fw::SmSignalBuffer& data //!< The state machine data
      );

      //! Send a signal to state machine instance sm5
      void sm5_stateMachineInvoke(
          const ExternalSm::ActiveExternalStateMachines_S2_Interface::ActiveExternalStateMachines_S2_Signals signal, //!< The state machine signal
          const Fw::SmSignalBuffer& data //!< The state machine data
      );

      //! Send a signal to state machine instance sm6
      void sm6_stateMachineInvoke(
          const ExternalSm::ActiveExternalStateMachines_S2_Interface::ActiveExternalStateMachines_S2_Signals signal, //!< The state machine signal
          const Fw::SmSignalBuffer& data //!< The state machine data
      );

    PRIVATE:

      // ----------------------------------------------------------------------
      // Message dispatch functions
      // ----------------------------------------------------------------------

      //! Called in the message loop to dispatch a message from the queue
      virtual MsgDispatchStatus doDispatch();

    PRIVATE:

      // ----------------------------------------------------------------------
      // State machine instances
      // ----------------------------------------------------------------------

      //! State machine sm1
      ExternalSm::ActiveExternalStateMachines_S1 m_stateMachine_sm1;

      //! State machine sm2
      ExternalSm::ActiveExternalStateMachines_S1 m_stateMachine_sm2;

      //! State machine sm3
      ExternalSm::ActiveExternalStateMachines_S2 m_stateMachine_sm3;

      //! State machine sm4
      ExternalSm::ActiveExternalStateMachines_S2 m_stateMachine_sm4;

      //! State machine sm5
      ExternalSm::ActiveExternalStateMachines_S2 m_stateMachine_sm5;

      //! State machine sm6
      ExternalSm::ActiveExternalStateMachines_S2 m_stateMachine_sm6;

  };

}

#endif
