// ======================================================================
// \title  QueuedAsyncProductPortsOnlyComponentAc.cpp
// \author Generated by fpp-to-cpp
// \brief  cpp file for QueuedAsyncProductPortsOnly component base class
// ======================================================================

#include "Fw/Types/Assert.hpp"
#include "Fw/Types/ExternalString.hpp"
#if FW_ENABLE_TEXT_LOGGING
#include "Fw/Types/String.hpp"
#endif
#include "base/QueuedAsyncProductPortsOnlyComponentAc.hpp"

namespace {
  enum MsgTypeEnum {
    QUEUEDASYNCPRODUCTPORTSONLY_COMPONENT_EXIT = Fw::ActiveComponentBase::ACTIVE_COMPONENT_EXIT,
    PRODUCTRECVIN_DPRESPONSE,
  };

  // Get the max size by constructing a union of the async input, command, and
  // internal port serialization sizes
  union BuffUnion {
    BYTE productRecvInPortSize[Fw::InputDpResponsePort::SERIALIZED_SIZE];
  };

  // Define a message buffer class large enough to handle all the
  // asynchronous inputs to the component
  class ComponentIpcSerializableBuffer :
    public Fw::SerializeBufferBase
  {

    public:

      enum {
        // Max. message size = size of data + message id + port
        SERIALIZATION_SIZE =
          sizeof(BuffUnion) +
          sizeof(FwEnumStoreType) +
          sizeof(FwIndexType)
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

void QueuedAsyncProductPortsOnlyComponentBase ::
  init(
      FwSizeType queueDepth,
      FwEnumStoreType instance
  )
{
  // Initialize base class
  Fw::QueuedComponentBase::init(instance);

  // Connect input port productRecvIn
  for (
    FwIndexType port = 0;
    port < static_cast<FwIndexType>(this->getNum_productRecvIn_InputPorts());
    port++
  ) {
    this->m_productRecvIn_InputPort[port].init();
    this->m_productRecvIn_InputPort[port].addCallComp(
      this,
      m_p_productRecvIn_in
    );
    this->m_productRecvIn_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
    Fw::ObjectName portName;
    portName.format(
      "%s_productRecvIn_InputPort[%" PRI_PlatformIntType "]",
      this->m_objName.toChar(),
      port
    );
    this->m_productRecvIn_InputPort[port].setObjName(portName.toChar());
#endif
  }

  // Connect output port productRequestOut
  for (
    FwIndexType port = 0;
    port < static_cast<FwIndexType>(this->getNum_productRequestOut_OutputPorts());
    port++
  ) {
    this->m_productRequestOut_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
    Fw::ObjectName portName;
    portName.format(
      "%s_productRequestOut_OutputPort[%" PRI_PlatformIntType "]",
      this->m_objName.toChar(),
      port
    );
    this->m_productRequestOut_OutputPort[port].setObjName(portName.toChar());
#endif
  }

  // Connect output port productSendOut
  for (
    FwIndexType port = 0;
    port < static_cast<FwIndexType>(this->getNum_productSendOut_OutputPorts());
    port++
  ) {
    this->m_productSendOut_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
    Fw::ObjectName portName;
    portName.format(
      "%s_productSendOut_OutputPort[%" PRI_PlatformIntType "]",
      this->m_objName.toChar(),
      port
    );
    this->m_productSendOut_OutputPort[port].setObjName(portName.toChar());
#endif
  }

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
// Getters for special input ports
// ----------------------------------------------------------------------

Fw::InputDpResponsePort* QueuedAsyncProductPortsOnlyComponentBase ::
  get_productRecvIn_InputPort(FwIndexType portNum)
{
  FW_ASSERT(
    portNum < this->getNum_productRecvIn_InputPorts(),
    static_cast<FwAssertArgType>(portNum)
  );

  return &this->m_productRecvIn_InputPort[portNum];
}

// ----------------------------------------------------------------------
// Connect input ports to special output ports
// ----------------------------------------------------------------------

void QueuedAsyncProductPortsOnlyComponentBase ::
  set_productRequestOut_OutputPort(
      FwIndexType portNum,
      Fw::InputDpRequestPort* port
  )
{
  FW_ASSERT(
    portNum < this->getNum_productRequestOut_OutputPorts(),
    static_cast<FwAssertArgType>(portNum)
  );

  this->m_productRequestOut_OutputPort[portNum].addCallPort(port);
}

void QueuedAsyncProductPortsOnlyComponentBase ::
  set_productSendOut_OutputPort(
      FwIndexType portNum,
      Fw::InputDpSendPort* port
  )
{
  FW_ASSERT(
    portNum < this->getNum_productSendOut_OutputPorts(),
    static_cast<FwAssertArgType>(portNum)
  );

  this->m_productSendOut_OutputPort[portNum].addCallPort(port);
}

#if FW_PORT_SERIALIZATION

// ----------------------------------------------------------------------
// Connect serial input ports to special output ports
// ----------------------------------------------------------------------

void QueuedAsyncProductPortsOnlyComponentBase ::
  set_productRequestOut_OutputPort(
      FwIndexType portNum,
      Fw::InputSerializePort* port
  )
{
  FW_ASSERT(
    portNum < this->getNum_productRequestOut_OutputPorts(),
    static_cast<FwAssertArgType>(portNum)
  );

  this->m_productRequestOut_OutputPort[portNum].registerSerialPort(port);
}

void QueuedAsyncProductPortsOnlyComponentBase ::
  set_productSendOut_OutputPort(
      FwIndexType portNum,
      Fw::InputSerializePort* port
  )
{
  FW_ASSERT(
    portNum < this->getNum_productSendOut_OutputPorts(),
    static_cast<FwAssertArgType>(portNum)
  );

  this->m_productSendOut_OutputPort[portNum].registerSerialPort(port);
}

#endif

// ----------------------------------------------------------------------
// Component construction and destruction
// ----------------------------------------------------------------------

QueuedAsyncProductPortsOnlyComponentBase ::
  QueuedAsyncProductPortsOnlyComponentBase(const char* compName) :
    Fw::QueuedComponentBase(compName)
{

}

QueuedAsyncProductPortsOnlyComponentBase ::
  ~QueuedAsyncProductPortsOnlyComponentBase()
{

}

// ----------------------------------------------------------------------
// Getters for numbers of special input ports
// ----------------------------------------------------------------------

FwIndexType QueuedAsyncProductPortsOnlyComponentBase ::
  getNum_productRecvIn_InputPorts() const
{
  return static_cast<FwIndexType>(FW_NUM_ARRAY_ELEMENTS(this->m_productRecvIn_InputPort));
}

// ----------------------------------------------------------------------
// Getters for numbers of special output ports
// ----------------------------------------------------------------------

FwIndexType QueuedAsyncProductPortsOnlyComponentBase ::
  getNum_productRequestOut_OutputPorts() const
{
  return static_cast<FwIndexType>(FW_NUM_ARRAY_ELEMENTS(this->m_productRequestOut_OutputPort));
}

FwIndexType QueuedAsyncProductPortsOnlyComponentBase ::
  getNum_productSendOut_OutputPorts() const
{
  return static_cast<FwIndexType>(FW_NUM_ARRAY_ELEMENTS(this->m_productSendOut_OutputPort));
}

// ----------------------------------------------------------------------
// Connection status queries for special output ports
// ----------------------------------------------------------------------

bool QueuedAsyncProductPortsOnlyComponentBase ::
  isConnected_productRequestOut_OutputPort(FwIndexType portNum)
{
  FW_ASSERT(
    portNum < this->getNum_productRequestOut_OutputPorts(),
    static_cast<FwAssertArgType>(portNum)
  );

  return this->m_productRequestOut_OutputPort[portNum].isConnected();
}

bool QueuedAsyncProductPortsOnlyComponentBase ::
  isConnected_productSendOut_OutputPort(FwIndexType portNum)
{
  FW_ASSERT(
    portNum < this->getNum_productSendOut_OutputPorts(),
    static_cast<FwAssertArgType>(portNum)
  );

  return this->m_productSendOut_OutputPort[portNum].isConnected();
}

// ----------------------------------------------------------------------
// Port handler base-class functions for special input ports
//
// Call these functions directly to bypass the corresponding ports
// ----------------------------------------------------------------------

void QueuedAsyncProductPortsOnlyComponentBase ::
  productRecvIn_handlerBase(
      FwIndexType portNum,
      FwDpIdType id,
      const Fw::Buffer& buffer,
      const Fw::Success& status
  )
{
  // Make sure port number is valid
  FW_ASSERT(
    portNum < this->getNum_productRecvIn_InputPorts(),
    static_cast<FwAssertArgType>(portNum)
  );

  // Call pre-message hook
  productRecvIn_preMsgHook(
    portNum,
    id,
    buffer,
    status
  );
  ComponentIpcSerializableBuffer msg;
  Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;

  // Serialize message ID
  _status = msg.serialize(
    static_cast<FwEnumStoreType>(PRODUCTRECVIN_DPRESPONSE)
  );
  FW_ASSERT(
    _status == Fw::FW_SERIALIZE_OK,
    static_cast<FwAssertArgType>(_status)
  );

  // Serialize port number
  _status = msg.serialize(portNum);
  FW_ASSERT(
    _status == Fw::FW_SERIALIZE_OK,
    static_cast<FwAssertArgType>(_status)
  );

  // Serialize argument id
  _status = msg.serialize(id);
  FW_ASSERT(
    _status == Fw::FW_SERIALIZE_OK,
    static_cast<FwAssertArgType>(_status)
  );

  // Serialize argument buffer
  _status = msg.serialize(buffer);
  FW_ASSERT(
    _status == Fw::FW_SERIALIZE_OK,
    static_cast<FwAssertArgType>(_status)
  );

  // Serialize argument status
  _status = msg.serialize(status);
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
// Pre-message hooks for special async input ports
//
// Each of these functions is invoked just before processing a message
// on the corresponding port. By default, they do nothing. You can
// override them to provide specific pre-message behavior.
// ----------------------------------------------------------------------

void QueuedAsyncProductPortsOnlyComponentBase ::
  productRecvIn_preMsgHook(
      FwIndexType portNum,
      FwDpIdType id,
      const Fw::Buffer& buffer,
      const Fw::Success& status
  )
{
  // Default: no-op
}

// ----------------------------------------------------------------------
// Invocation functions for special output ports
// ----------------------------------------------------------------------

void QueuedAsyncProductPortsOnlyComponentBase ::
  productRequestOut_out(
      FwIndexType portNum,
      FwDpIdType id,
      FwSizeType dataSize
  )
{
  FW_ASSERT(
    portNum < this->getNum_productRequestOut_OutputPorts(),
    static_cast<FwAssertArgType>(portNum)
  );
  this->m_productRequestOut_OutputPort[portNum].invoke(
    id,
    dataSize
  );
}

void QueuedAsyncProductPortsOnlyComponentBase ::
  productSendOut_out(
      FwIndexType portNum,
      FwDpIdType id,
      const Fw::Buffer& buffer
  )
{
  FW_ASSERT(
    portNum < this->getNum_productSendOut_OutputPorts(),
    static_cast<FwAssertArgType>(portNum)
  );
  this->m_productSendOut_OutputPort[portNum].invoke(
    id,
    buffer
  );
}

// ----------------------------------------------------------------------
// Message dispatch functions
// ----------------------------------------------------------------------

Fw::QueuedComponentBase::MsgDispatchStatus QueuedAsyncProductPortsOnlyComponentBase ::
  doDispatch()
{
  ComponentIpcSerializableBuffer msg;
  FwQueuePriorityType priority = 0;

  Os::Queue::Status msgStatus = this->m_queue.receive(
    msg,
    Os::Queue::NONBLOCKING,
    priority
  );
  if (Os::Queue::Status::EMPTY == msgStatus) {
    return Fw::QueuedComponentBase::MSG_DISPATCH_EMPTY;
  }
  else {
    FW_ASSERT(
      msgStatus == Os::Queue::OP_OK,
      static_cast<FwAssertArgType>(msgStatus)
    );
  }

  // Reset to beginning of buffer
  msg.resetDeser();

  FwEnumStoreType desMsg = 0;
  Fw::SerializeStatus deserStatus = msg.deserialize(desMsg);
  FW_ASSERT(
    deserStatus == Fw::FW_SERIALIZE_OK,
    static_cast<FwAssertArgType>(deserStatus)
  );

  MsgTypeEnum msgType = static_cast<MsgTypeEnum>(desMsg);

  if (msgType == QUEUEDASYNCPRODUCTPORTSONLY_COMPONENT_EXIT) {
    return MSG_DISPATCH_EXIT;
  }

  FwIndexType portNum = 0;
  deserStatus = msg.deserialize(portNum);
  FW_ASSERT(
    deserStatus == Fw::FW_SERIALIZE_OK,
    static_cast<FwAssertArgType>(deserStatus)
  );

  switch (msgType) {
    // Handle async input port productRecvIn
    case PRODUCTRECVIN_DPRESPONSE: {
      // Deserialize argument id
      FwDpIdType id;
      deserStatus = msg.deserialize(id);
      FW_ASSERT(
        deserStatus == Fw::FW_SERIALIZE_OK,
        static_cast<FwAssertArgType>(deserStatus)
      );

      // Deserialize argument buffer
      Fw::Buffer buffer;
      deserStatus = msg.deserialize(buffer);
      FW_ASSERT(
        deserStatus == Fw::FW_SERIALIZE_OK,
        static_cast<FwAssertArgType>(deserStatus)
      );

      // Deserialize argument status
      Fw::Success status;
      deserStatus = msg.deserialize(status);
      FW_ASSERT(
        deserStatus == Fw::FW_SERIALIZE_OK,
        static_cast<FwAssertArgType>(deserStatus)
      );
      // Call handler function
      this->productRecvIn_handler(
        portNum,
        id,
        buffer,
        status
      );

      break;
    }

    default:
      return MSG_DISPATCH_ERROR;
  }

  return MSG_DISPATCH_OK;
}

// ----------------------------------------------------------------------
// Calls for messages received on special input ports
// ----------------------------------------------------------------------

void QueuedAsyncProductPortsOnlyComponentBase ::
  m_p_productRecvIn_in(
      Fw::PassiveComponentBase* callComp,
      FwIndexType portNum,
      FwDpIdType id,
      const Fw::Buffer& buffer,
      const Fw::Success& status
  )
{
  FW_ASSERT(callComp);
  QueuedAsyncProductPortsOnlyComponentBase* compPtr = static_cast<QueuedAsyncProductPortsOnlyComponentBase*>(callComp);
  compPtr->productRecvIn_handlerBase(
    portNum,
    id,
    buffer,
    status
  );
}

// ----------------------------------------------------------------------
// Private data product handling functions
// ----------------------------------------------------------------------

void QueuedAsyncProductPortsOnlyComponentBase ::
  productRecvIn_handler(
      const FwIndexType portNum,
      FwDpIdType id,
      const Fw::Buffer& buffer,
      const Fw::Success& status
  )
{
  (void) portNum;
  (void) id;
  (void) buffer;
  (void) status;
  // No data products defined
}
