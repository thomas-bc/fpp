// ======================================================================
// \title  PassiveGetProductPortsOnlyComponentAc.cpp
// \author Generated by fpp-to-cpp
// \brief  cpp file for PassiveGetProductPortsOnly component base class
// ======================================================================

#include "Fw/Types/Assert.hpp"
#if FW_ENABLE_TEXT_LOGGING
#include "Fw/Types/String.hpp"
#endif
#include "base/PassiveGetProductPortsOnlyComponentAc.hpp"

// ----------------------------------------------------------------------
// Component initialization
// ----------------------------------------------------------------------

void PassiveGetProductPortsOnlyComponentBase ::
  init(FwEnumStoreType instance)
{
  // Initialize base class
  Fw::PassiveComponentBase::init(instance);

  // Connect output port productGetOut
  for (
    FwIndexType port = 0;
    port < static_cast<FwIndexType>(this->getNum_productGetOut_OutputPorts());
    port++
  ) {
    this->m_productGetOut_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
    Fw::ObjectName portName;
    portName.format(
      "%s_productGetOut_OutputPort[%" PRI_PlatformIntType "]",
      this->m_objName.toChar(),
      port
    );
    this->m_productGetOut_OutputPort[port].setObjName(portName.toChar());
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
}

// ----------------------------------------------------------------------
// Connect input ports to special output ports
// ----------------------------------------------------------------------

void PassiveGetProductPortsOnlyComponentBase ::
  set_productGetOut_OutputPort(
      FwIndexType portNum,
      Fw::InputDpGetPort* port
  )
{
  FW_ASSERT(
    portNum < this->getNum_productGetOut_OutputPorts(),
    static_cast<FwAssertArgType>(portNum)
  );

  this->m_productGetOut_OutputPort[portNum].addCallPort(port);
}

void PassiveGetProductPortsOnlyComponentBase ::
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

void PassiveGetProductPortsOnlyComponentBase ::
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

PassiveGetProductPortsOnlyComponentBase ::
  PassiveGetProductPortsOnlyComponentBase(const char* compName) :
    Fw::PassiveComponentBase(compName)
{

}

PassiveGetProductPortsOnlyComponentBase ::
  ~PassiveGetProductPortsOnlyComponentBase()
{

}

// ----------------------------------------------------------------------
// Getters for numbers of special output ports
// ----------------------------------------------------------------------

FwIndexType PassiveGetProductPortsOnlyComponentBase ::
  getNum_productGetOut_OutputPorts() const
{
  return static_cast<FwIndexType>(FW_NUM_ARRAY_ELEMENTS(this->m_productGetOut_OutputPort));
}

FwIndexType PassiveGetProductPortsOnlyComponentBase ::
  getNum_productSendOut_OutputPorts() const
{
  return static_cast<FwIndexType>(FW_NUM_ARRAY_ELEMENTS(this->m_productSendOut_OutputPort));
}

// ----------------------------------------------------------------------
// Connection status queries for special output ports
// ----------------------------------------------------------------------

bool PassiveGetProductPortsOnlyComponentBase ::
  isConnected_productGetOut_OutputPort(FwIndexType portNum)
{
  FW_ASSERT(
    portNum < this->getNum_productGetOut_OutputPorts(),
    static_cast<FwAssertArgType>(portNum)
  );

  return this->m_productGetOut_OutputPort[portNum].isConnected();
}

bool PassiveGetProductPortsOnlyComponentBase ::
  isConnected_productSendOut_OutputPort(FwIndexType portNum)
{
  FW_ASSERT(
    portNum < this->getNum_productSendOut_OutputPorts(),
    static_cast<FwAssertArgType>(portNum)
  );

  return this->m_productSendOut_OutputPort[portNum].isConnected();
}

// ----------------------------------------------------------------------
// Invocation functions for special output ports
// ----------------------------------------------------------------------

Fw::Success PassiveGetProductPortsOnlyComponentBase ::
  productGetOut_out(
      FwIndexType portNum,
      FwDpIdType id,
      FwSizeType dataSize,
      Fw::Buffer& buffer
  )
{
  FW_ASSERT(
    portNum < this->getNum_productGetOut_OutputPorts(),
    static_cast<FwAssertArgType>(portNum)
  );
  return this->m_productGetOut_OutputPort[portNum].invoke(
    id,
    dataSize,
    buffer
  );
}

void PassiveGetProductPortsOnlyComponentBase ::
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
