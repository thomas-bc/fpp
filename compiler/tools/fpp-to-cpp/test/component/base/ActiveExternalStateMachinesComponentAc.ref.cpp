// ======================================================================
// \title  ActiveExternalStateMachinesComponentAc.cpp
// \author Generated by fpp-to-cpp
// \brief  cpp file for ActiveExternalStateMachines component base class
// ======================================================================

#include "Fw/Types/Assert.hpp"
#include "Fw/Types/ExternalString.hpp"
#if FW_ENABLE_TEXT_LOGGING
#include "Fw/Types/String.hpp"
#endif
#include "base/ActiveExternalStateMachinesComponentAc.hpp"

namespace ExternalSm {

  namespace {
    enum MsgTypeEnum {
      ACTIVEEXTERNALSTATEMACHINES_COMPONENT_EXIT = Fw::ActiveComponentBase::ACTIVE_COMPONENT_EXIT,
      EXTERNAL_STATE_MACHINE_SIGNAL,
    };

    // Get the max size by constructing a union of the async input, command, and
    // internal port serialization sizes
    union BuffUnion {
      // Size of buffer for external state machine signals
      // The external SmSignalBuffer stores the signal data
      BYTE externalSmBufferSize[
        2 * sizeof(FwEnumStoreType) + Fw::SmSignalBuffer::SERIALIZED_SIZE
      ];
    };

    // Define a message buffer class large enough to handle all the
    // asynchronous inputs to the component
    class ComponentIpcSerializableBuffer :
      public Fw::SerializeBufferBase
    {

      public:

        enum {
          // Offset into data in buffer: Size of message ID and port number
          DATA_OFFSET = sizeof(FwEnumStoreType) + sizeof(FwIndexType),
          // Max data size
          MAX_DATA_SIZE = sizeof(BuffUnion),
          // Max message size: Size of message id + size of port + max data size
          SERIALIZATION_SIZE = DATA_OFFSET + MAX_DATA_SIZE
        };

        Fw::Serializable::SizeType getBuffCapacity() const {
          return sizeof(m_buff);
        }

        U8* getBuffAddr() {
          return m_buff;
        }

        const U8* getBuffAddr() const {
          return m_buff;
        }

      private:
        // Should be the max of all the input ports serialized sizes...
        U8 m_buff[SERIALIZATION_SIZE];

    };
  }

  // ----------------------------------------------------------------------
  // Component initialization
  // ----------------------------------------------------------------------

  void ActiveExternalStateMachinesComponentBase ::
    init(
        FwSizeType queueDepth,
        FwEnumStoreType instance
    )
  {
    // Initialize base class
    Fw::ActiveComponentBase::init(instance);

    this->m_stateMachine_sm1.init(static_cast<FwEnumStoreType>(SmId::sm1));
    this->m_stateMachine_sm2.init(static_cast<FwEnumStoreType>(SmId::sm2));
    this->m_stateMachine_sm3.init(static_cast<FwEnumStoreType>(SmId::sm3));
    this->m_stateMachine_sm4.init(static_cast<FwEnumStoreType>(SmId::sm4));
    this->m_stateMachine_sm5.init(static_cast<FwEnumStoreType>(SmId::sm5));
    this->m_stateMachine_sm6.init(static_cast<FwEnumStoreType>(SmId::sm6));

    Os::Queue::Status qStat = this->createQueue(
      queueDepth,
      static_cast<FwSizeType>(ComponentIpcSerializableBuffer::SERIALIZATION_SIZE)
    );
    FW_ASSERT(
      Os::Queue::Status::OP_OK == qStat,
      static_cast<FwAssertArgType>(qStat)
    );
  }

  // ----------------------------------------------------------------------
  // Component construction and destruction
  // ----------------------------------------------------------------------

  ActiveExternalStateMachinesComponentBase ::
    ActiveExternalStateMachinesComponentBase(const char* compName) :
      Fw::ActiveComponentBase(compName),
      m_stateMachine_sm1(this),
      m_stateMachine_sm2(this),
      m_stateMachine_sm3(this),
      m_stateMachine_sm4(this),
      m_stateMachine_sm5(this),
      m_stateMachine_sm6(this)
  {

  }

  ActiveExternalStateMachinesComponentBase ::
    ~ActiveExternalStateMachinesComponentBase()
  {

  }

  // ----------------------------------------------------------------------
  // State getter functions
  // ----------------------------------------------------------------------

  ExternalSm::ActiveExternalStateMachines_S1::ActiveExternalStateMachines_S1_States ActiveExternalStateMachinesComponentBase ::
    sm1_getState() const
  {
    return this->m_stateMachine_sm1.state;
  }

  ExternalSm::ActiveExternalStateMachines_S1::ActiveExternalStateMachines_S1_States ActiveExternalStateMachinesComponentBase ::
    sm2_getState() const
  {
    return this->m_stateMachine_sm2.state;
  }

  ExternalSm::ActiveExternalStateMachines_S2::ActiveExternalStateMachines_S2_States ActiveExternalStateMachinesComponentBase ::
    sm3_getState() const
  {
    return this->m_stateMachine_sm3.state;
  }

  ExternalSm::ActiveExternalStateMachines_S2::ActiveExternalStateMachines_S2_States ActiveExternalStateMachinesComponentBase ::
    sm4_getState() const
  {
    return this->m_stateMachine_sm4.state;
  }

  ExternalSm::ActiveExternalStateMachines_S2::ActiveExternalStateMachines_S2_States ActiveExternalStateMachinesComponentBase ::
    sm5_getState() const
  {
    return this->m_stateMachine_sm5.state;
  }

  ExternalSm::ActiveExternalStateMachines_S2::ActiveExternalStateMachines_S2_States ActiveExternalStateMachinesComponentBase ::
    sm6_getState() const
  {
    return this->m_stateMachine_sm6.state;
  }

  // ----------------------------------------------------------------------
  // Functions for sending signals to external state machines
  // ----------------------------------------------------------------------

  void ActiveExternalStateMachinesComponentBase ::
    sm1_stateMachineInvoke(
        const ExternalSm::ActiveExternalStateMachines_S1_Interface::ActiveExternalStateMachines_S1_Signals signal,
        const Fw::SmSignalBuffer& data
    )
  {

    ComponentIpcSerializableBuffer msg;
    Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;

    // Serialize the message ID
    _status = msg.serialize(static_cast<FwEnumStoreType>(EXTERNAL_STATE_MACHINE_SIGNAL));
    FW_ASSERT (
      _status == Fw::FW_SERIALIZE_OK,
      static_cast<FwAssertArgType>(_status)
    );

    // Fake port number to make message dequeue work
    _status = msg.serialize(static_cast<FwIndexType>(0));
    FW_ASSERT (
      _status == Fw::FW_SERIALIZE_OK,
      static_cast<FwAssertArgType>(_status)
    );

    _status = msg.serialize(static_cast<FwEnumStoreType>(SmId::sm1));
    FW_ASSERT(
      _status == Fw::FW_SERIALIZE_OK,
      static_cast<FwAssertArgType>(_status)
    );

    _status = msg.serialize(static_cast<FwEnumStoreType>(signal));
    FW_ASSERT(
      _status == Fw::FW_SERIALIZE_OK,
      static_cast<FwAssertArgType>(_status)
    );

    _status = msg.serialize(data);
    FW_ASSERT(
      _status == Fw::FW_SERIALIZE_OK,
      static_cast<FwAssertArgType>(_status)
    );

    // Send message
    Os::Queue::BlockingType _block = Os::Queue::BLOCKING;
    Os::Queue::Status qStatus = this->m_queue.send(msg, 1, _block);

    FW_ASSERT(
      qStatus == Os::Queue::OP_OK,
      static_cast<FwAssertArgType>(qStatus)
    );
  }

  void ActiveExternalStateMachinesComponentBase ::
    sm2_stateMachineInvoke(
        const ExternalSm::ActiveExternalStateMachines_S1_Interface::ActiveExternalStateMachines_S1_Signals signal,
        const Fw::SmSignalBuffer& data
    )
  {

    ComponentIpcSerializableBuffer msg;
    Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;

    // Serialize the message ID
    _status = msg.serialize(static_cast<FwEnumStoreType>(EXTERNAL_STATE_MACHINE_SIGNAL));
    FW_ASSERT (
      _status == Fw::FW_SERIALIZE_OK,
      static_cast<FwAssertArgType>(_status)
    );

    // Fake port number to make message dequeue work
    _status = msg.serialize(static_cast<FwIndexType>(0));
    FW_ASSERT (
      _status == Fw::FW_SERIALIZE_OK,
      static_cast<FwAssertArgType>(_status)
    );

    _status = msg.serialize(static_cast<FwEnumStoreType>(SmId::sm2));
    FW_ASSERT(
      _status == Fw::FW_SERIALIZE_OK,
      static_cast<FwAssertArgType>(_status)
    );

    _status = msg.serialize(static_cast<FwEnumStoreType>(signal));
    FW_ASSERT(
      _status == Fw::FW_SERIALIZE_OK,
      static_cast<FwAssertArgType>(_status)
    );

    _status = msg.serialize(data);
    FW_ASSERT(
      _status == Fw::FW_SERIALIZE_OK,
      static_cast<FwAssertArgType>(_status)
    );

    // Send message
    Os::Queue::BlockingType _block = Os::Queue::NONBLOCKING;
    Os::Queue::Status qStatus = this->m_queue.send(msg, 2, _block);

    FW_ASSERT(
      qStatus == Os::Queue::OP_OK,
      static_cast<FwAssertArgType>(qStatus)
    );
  }

  void ActiveExternalStateMachinesComponentBase ::
    sm3_stateMachineInvoke(
        const ExternalSm::ActiveExternalStateMachines_S2_Interface::ActiveExternalStateMachines_S2_Signals signal,
        const Fw::SmSignalBuffer& data
    )
  {

    ComponentIpcSerializableBuffer msg;
    Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;

    // Serialize the message ID
    _status = msg.serialize(static_cast<FwEnumStoreType>(EXTERNAL_STATE_MACHINE_SIGNAL));
    FW_ASSERT (
      _status == Fw::FW_SERIALIZE_OK,
      static_cast<FwAssertArgType>(_status)
    );

    // Fake port number to make message dequeue work
    _status = msg.serialize(static_cast<FwIndexType>(0));
    FW_ASSERT (
      _status == Fw::FW_SERIALIZE_OK,
      static_cast<FwAssertArgType>(_status)
    );

    _status = msg.serialize(static_cast<FwEnumStoreType>(SmId::sm3));
    FW_ASSERT(
      _status == Fw::FW_SERIALIZE_OK,
      static_cast<FwAssertArgType>(_status)
    );

    _status = msg.serialize(static_cast<FwEnumStoreType>(signal));
    FW_ASSERT(
      _status == Fw::FW_SERIALIZE_OK,
      static_cast<FwAssertArgType>(_status)
    );

    _status = msg.serialize(data);
    FW_ASSERT(
      _status == Fw::FW_SERIALIZE_OK,
      static_cast<FwAssertArgType>(_status)
    );

    // Send message
    Os::Queue::BlockingType _block = Os::Queue::NONBLOCKING;
    Os::Queue::Status qStatus = this->m_queue.send(msg, 3, _block);

    if (qStatus == Os::Queue::Status::FULL) {
      this->incNumMsgDropped();
      return;
    }

    FW_ASSERT(
      qStatus == Os::Queue::OP_OK,
      static_cast<FwAssertArgType>(qStatus)
    );
  }

  void ActiveExternalStateMachinesComponentBase ::
    sm4_stateMachineInvoke(
        const ExternalSm::ActiveExternalStateMachines_S2_Interface::ActiveExternalStateMachines_S2_Signals signal,
        const Fw::SmSignalBuffer& data
    )
  {

    ComponentIpcSerializableBuffer msg;
    Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;

    // Serialize the message ID
    _status = msg.serialize(static_cast<FwEnumStoreType>(EXTERNAL_STATE_MACHINE_SIGNAL));
    FW_ASSERT (
      _status == Fw::FW_SERIALIZE_OK,
      static_cast<FwAssertArgType>(_status)
    );

    // Fake port number to make message dequeue work
    _status = msg.serialize(static_cast<FwIndexType>(0));
    FW_ASSERT (
      _status == Fw::FW_SERIALIZE_OK,
      static_cast<FwAssertArgType>(_status)
    );

    _status = msg.serialize(static_cast<FwEnumStoreType>(SmId::sm4));
    FW_ASSERT(
      _status == Fw::FW_SERIALIZE_OK,
      static_cast<FwAssertArgType>(_status)
    );

    _status = msg.serialize(static_cast<FwEnumStoreType>(signal));
    FW_ASSERT(
      _status == Fw::FW_SERIALIZE_OK,
      static_cast<FwAssertArgType>(_status)
    );

    _status = msg.serialize(data);
    FW_ASSERT(
      _status == Fw::FW_SERIALIZE_OK,
      static_cast<FwAssertArgType>(_status)
    );

    // Send message
    Os::Queue::BlockingType _block = Os::Queue::NONBLOCKING;
    Os::Queue::Status qStatus = this->m_queue.send(msg, 4, _block);

    FW_ASSERT(
      qStatus == Os::Queue::OP_OK,
      static_cast<FwAssertArgType>(qStatus)
    );
  }

  void ActiveExternalStateMachinesComponentBase ::
    sm5_stateMachineInvoke(
        const ExternalSm::ActiveExternalStateMachines_S2_Interface::ActiveExternalStateMachines_S2_Signals signal,
        const Fw::SmSignalBuffer& data
    )
  {

    ComponentIpcSerializableBuffer msg;
    Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;

    // Serialize the message ID
    _status = msg.serialize(static_cast<FwEnumStoreType>(EXTERNAL_STATE_MACHINE_SIGNAL));
    FW_ASSERT (
      _status == Fw::FW_SERIALIZE_OK,
      static_cast<FwAssertArgType>(_status)
    );

    // Fake port number to make message dequeue work
    _status = msg.serialize(static_cast<FwIndexType>(0));
    FW_ASSERT (
      _status == Fw::FW_SERIALIZE_OK,
      static_cast<FwAssertArgType>(_status)
    );

    _status = msg.serialize(static_cast<FwEnumStoreType>(SmId::sm5));
    FW_ASSERT(
      _status == Fw::FW_SERIALIZE_OK,
      static_cast<FwAssertArgType>(_status)
    );

    _status = msg.serialize(static_cast<FwEnumStoreType>(signal));
    FW_ASSERT(
      _status == Fw::FW_SERIALIZE_OK,
      static_cast<FwAssertArgType>(_status)
    );

    _status = msg.serialize(data);
    FW_ASSERT(
      _status == Fw::FW_SERIALIZE_OK,
      static_cast<FwAssertArgType>(_status)
    );

    // Send message
    Os::Queue::BlockingType _block = Os::Queue::NONBLOCKING;
    Os::Queue::Status qStatus = this->m_queue.send(msg, 0, _block);

    if (qStatus == Os::Queue::Status::FULL) {
      this->sm5_stateMachineOverflowHook(signal, data);
      return;
    }

    FW_ASSERT(
      qStatus == Os::Queue::OP_OK,
      static_cast<FwAssertArgType>(qStatus)
    );
  }

  void ActiveExternalStateMachinesComponentBase ::
    sm6_stateMachineInvoke(
        const ExternalSm::ActiveExternalStateMachines_S2_Interface::ActiveExternalStateMachines_S2_Signals signal,
        const Fw::SmSignalBuffer& data
    )
  {

    ComponentIpcSerializableBuffer msg;
    Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;

    // Serialize the message ID
    _status = msg.serialize(static_cast<FwEnumStoreType>(EXTERNAL_STATE_MACHINE_SIGNAL));
    FW_ASSERT (
      _status == Fw::FW_SERIALIZE_OK,
      static_cast<FwAssertArgType>(_status)
    );

    // Fake port number to make message dequeue work
    _status = msg.serialize(static_cast<FwIndexType>(0));
    FW_ASSERT (
      _status == Fw::FW_SERIALIZE_OK,
      static_cast<FwAssertArgType>(_status)
    );

    _status = msg.serialize(static_cast<FwEnumStoreType>(SmId::sm6));
    FW_ASSERT(
      _status == Fw::FW_SERIALIZE_OK,
      static_cast<FwAssertArgType>(_status)
    );

    _status = msg.serialize(static_cast<FwEnumStoreType>(signal));
    FW_ASSERT(
      _status == Fw::FW_SERIALIZE_OK,
      static_cast<FwAssertArgType>(_status)
    );

    _status = msg.serialize(data);
    FW_ASSERT(
      _status == Fw::FW_SERIALIZE_OK,
      static_cast<FwAssertArgType>(_status)
    );

    // Send message
    Os::Queue::BlockingType _block = Os::Queue::NONBLOCKING;
    Os::Queue::Status qStatus = this->m_queue.send(msg, 0, _block);

    FW_ASSERT(
      qStatus == Os::Queue::OP_OK,
      static_cast<FwAssertArgType>(qStatus)
    );
  }

  // ----------------------------------------------------------------------
  // Message dispatch functions
  // ----------------------------------------------------------------------

  Fw::QueuedComponentBase::MsgDispatchStatus ActiveExternalStateMachinesComponentBase ::
    doDispatch()
  {
    ComponentIpcSerializableBuffer msg;
    FwQueuePriorityType priority = 0;

    Os::Queue::Status msgStatus = this->m_queue.receive(
      msg,
      Os::Queue::BLOCKING,
      priority
    );
    FW_ASSERT(
      msgStatus == Os::Queue::OP_OK,
      static_cast<FwAssertArgType>(msgStatus)
    );

    // Reset to beginning of buffer
    msg.resetDeser();

    FwEnumStoreType desMsg = 0;
    Fw::SerializeStatus deserStatus = msg.deserialize(desMsg);
    FW_ASSERT(
      deserStatus == Fw::FW_SERIALIZE_OK,
      static_cast<FwAssertArgType>(deserStatus)
    );

    MsgTypeEnum msgType = static_cast<MsgTypeEnum>(desMsg);

    if (msgType == ACTIVEEXTERNALSTATEMACHINES_COMPONENT_EXIT) {
      return MSG_DISPATCH_EXIT;
    }

    FwIndexType portNum = 0;
    deserStatus = msg.deserialize(portNum);
    FW_ASSERT(
      deserStatus == Fw::FW_SERIALIZE_OK,
      static_cast<FwAssertArgType>(deserStatus)
    );

    switch (msgType) {

      // Handle signals to external state machines
      case EXTERNAL_STATE_MACHINE_SIGNAL: {

        // Deserialize the state machine ID to an FwEnumStoreType
        FwEnumStoreType enumStoreSmId = 0;
        Fw::SerializeStatus deserStatus = msg.deserialize(enumStoreSmId);
        FW_ASSERT(
          deserStatus == Fw::FW_SERIALIZE_OK,
          static_cast<FwAssertArgType>(deserStatus)
        );
        // Cast it to the correct type
        SmId stateMachineId = static_cast<SmId>(enumStoreSmId);

        // Deserialize the state machine signal to an FwEnumStoreType.
        // This value will be cast to the correct type in the
        // switch statement that calls the state machine update function.
        FwEnumStoreType enumStoreSmSignal = 0;
        deserStatus = msg.deserialize(enumStoreSmSignal);
        FW_ASSERT(
          deserStatus == Fw::FW_SERIALIZE_OK,
          static_cast<FwAssertArgType>(deserStatus)
        );

        // Deserialize the state machine data
        Fw::SmSignalBuffer data;
        deserStatus = msg.deserialize(data);
        FW_ASSERT(
          Fw::FW_SERIALIZE_OK == deserStatus,
          static_cast<FwAssertArgType>(deserStatus)
        );

        // Make sure there was no data left over.
        // That means the buffer size was incorrect.
        FW_ASSERT(
          msg.getBuffLeft() == 0,
          static_cast<FwAssertArgType>(msg.getBuffLeft())
        );

        // Call the state machine update function
        switch (stateMachineId) {

          case SmId::sm1: {
            ExternalSm::ActiveExternalStateMachines_S1_Interface::ActiveExternalStateMachines_S1_Signals signal =
              static_cast<ExternalSm::ActiveExternalStateMachines_S1_Interface::ActiveExternalStateMachines_S1_Signals>(enumStoreSmSignal);
            this->m_stateMachine_sm1.update(static_cast<FwEnumStoreType>(stateMachineId), signal, data);
            break;
          }

          case SmId::sm2: {
            ExternalSm::ActiveExternalStateMachines_S1_Interface::ActiveExternalStateMachines_S1_Signals signal =
              static_cast<ExternalSm::ActiveExternalStateMachines_S1_Interface::ActiveExternalStateMachines_S1_Signals>(enumStoreSmSignal);
            this->m_stateMachine_sm2.update(static_cast<FwEnumStoreType>(stateMachineId), signal, data);
            break;
          }

          case SmId::sm3: {
            ExternalSm::ActiveExternalStateMachines_S2_Interface::ActiveExternalStateMachines_S2_Signals signal =
              static_cast<ExternalSm::ActiveExternalStateMachines_S2_Interface::ActiveExternalStateMachines_S2_Signals>(enumStoreSmSignal);
            this->m_stateMachine_sm3.update(static_cast<FwEnumStoreType>(stateMachineId), signal, data);
            break;
          }

          case SmId::sm4: {
            ExternalSm::ActiveExternalStateMachines_S2_Interface::ActiveExternalStateMachines_S2_Signals signal =
              static_cast<ExternalSm::ActiveExternalStateMachines_S2_Interface::ActiveExternalStateMachines_S2_Signals>(enumStoreSmSignal);
            this->m_stateMachine_sm4.update(static_cast<FwEnumStoreType>(stateMachineId), signal, data);
            break;
          }

          case SmId::sm5: {
            ExternalSm::ActiveExternalStateMachines_S2_Interface::ActiveExternalStateMachines_S2_Signals signal =
              static_cast<ExternalSm::ActiveExternalStateMachines_S2_Interface::ActiveExternalStateMachines_S2_Signals>(enumStoreSmSignal);
            this->m_stateMachine_sm5.update(static_cast<FwEnumStoreType>(stateMachineId), signal, data);
            break;
          }

          case SmId::sm6: {
            ExternalSm::ActiveExternalStateMachines_S2_Interface::ActiveExternalStateMachines_S2_Signals signal =
              static_cast<ExternalSm::ActiveExternalStateMachines_S2_Interface::ActiveExternalStateMachines_S2_Signals>(enumStoreSmSignal);
            this->m_stateMachine_sm6.update(static_cast<FwEnumStoreType>(stateMachineId), signal, data);
            break;
          }

          default:
            return MSG_DISPATCH_ERROR;
        }

        break;
      }

      default:
        return MSG_DISPATCH_ERROR;
    }

    return MSG_DISPATCH_OK;
  }

}
