// ======================================================================
// \title  PassiveGetProductsTesterBase.cpp
// \author Generated by fpp-to-cpp
// \brief  cpp file for PassiveGetProducts component test harness base class
// ======================================================================

#include <cstdlib>
#include <cstring>

#include "test-base/PassiveGetProductsTesterBase.hpp"

// ----------------------------------------------------------------------
// Component initialization
// ----------------------------------------------------------------------

void PassiveGetProductsTesterBase ::
  init(NATIVE_INT_TYPE instance)
{
  // Initialize base class
  Fw::PassiveComponentBase::init(instance);

  // Connect input port productGetOut
  for (
    PlatformIntType port = 0;
    port < static_cast<PlatformIntType>(this->getNum_from_productGetOut());
    port++
  ) {
    this->m_from_productGetOut[port].init();
    this->m_from_productGetOut[port].addCallComp(
      this,
      from_productGetOut_static
    );
    this->m_from_productGetOut[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
    char portName[120];
    (void) snprintf(
      portName,
      sizeof(portName),
      "%s_from_productGetOut[%" PRI_PlatformIntType "]",
      this->m_objName,
      port
    );
    this->m_from_productGetOut[port].setObjName(portName);
#endif
  }

  // Connect input port productSendOut
  for (
    PlatformIntType port = 0;
    port < static_cast<PlatformIntType>(this->getNum_from_productSendOut());
    port++
  ) {
    this->m_from_productSendOut[port].init();
    this->m_from_productSendOut[port].addCallComp(
      this,
      from_productSendOut_static
    );
    this->m_from_productSendOut[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
    char portName[120];
    (void) snprintf(
      portName,
      sizeof(portName),
      "%s_from_productSendOut[%" PRI_PlatformIntType "]",
      this->m_objName,
      port
    );
    this->m_from_productSendOut[port].setObjName(portName);
#endif
  }

  // Connect input port timeGetOut
  for (
    PlatformIntType port = 0;
    port < static_cast<PlatformIntType>(this->getNum_from_timeGetOut());
    port++
  ) {
    this->m_from_timeGetOut[port].init();
    this->m_from_timeGetOut[port].addCallComp(
      this,
      from_timeGetOut_static
    );
    this->m_from_timeGetOut[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
    char portName[120];
    (void) snprintf(
      portName,
      sizeof(portName),
      "%s_from_timeGetOut[%" PRI_PlatformIntType "]",
      this->m_objName,
      port
    );
    this->m_from_timeGetOut[port].setObjName(portName);
#endif
  }

  // Connect input port typedOut
  for (
    PlatformIntType port = 0;
    port < static_cast<PlatformIntType>(this->getNum_from_typedOut());
    port++
  ) {
    this->m_from_typedOut[port].init();
    this->m_from_typedOut[port].addCallComp(
      this,
      from_typedOut_static
    );
    this->m_from_typedOut[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
    char portName[120];
    (void) snprintf(
      portName,
      sizeof(portName),
      "%s_from_typedOut[%" PRI_PlatformIntType "]",
      this->m_objName,
      port
    );
    this->m_from_typedOut[port].setObjName(portName);
#endif
  }

  // Connect input port typedReturnOut
  for (
    PlatformIntType port = 0;
    port < static_cast<PlatformIntType>(this->getNum_from_typedReturnOut());
    port++
  ) {
    this->m_from_typedReturnOut[port].init();
    this->m_from_typedReturnOut[port].addCallComp(
      this,
      from_typedReturnOut_static
    );
    this->m_from_typedReturnOut[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
    char portName[120];
    (void) snprintf(
      portName,
      sizeof(portName),
      "%s_from_typedReturnOut[%" PRI_PlatformIntType "]",
      this->m_objName,
      port
    );
    this->m_from_typedReturnOut[port].setObjName(portName);
#endif
  }

  // Connect output port productRecvIn
  for (
    PlatformIntType port = 0;
    port < static_cast<PlatformIntType>(this->getNum_to_productRecvIn());
    port++
  ) {
    this->m_to_productRecvIn[port].init();

#if FW_OBJECT_NAMES == 1
    char portName[120];
    (void) snprintf(
      portName,
      sizeof(portName),
      "%s_to_productRecvIn[%" PRI_PlatformIntType "]",
      this->m_objName,
      port
    );
    this->m_to_productRecvIn[port].setObjName(portName);
#endif
  }

  // Connect output port noArgsGuarded
  for (
    PlatformIntType port = 0;
    port < static_cast<PlatformIntType>(this->getNum_to_noArgsGuarded());
    port++
  ) {
    this->m_to_noArgsGuarded[port].init();

#if FW_OBJECT_NAMES == 1
    char portName[120];
    (void) snprintf(
      portName,
      sizeof(portName),
      "%s_to_noArgsGuarded[%" PRI_PlatformIntType "]",
      this->m_objName,
      port
    );
    this->m_to_noArgsGuarded[port].setObjName(portName);
#endif
  }

  // Connect output port noArgsReturnGuarded
  for (
    PlatformIntType port = 0;
    port < static_cast<PlatformIntType>(this->getNum_to_noArgsReturnGuarded());
    port++
  ) {
    this->m_to_noArgsReturnGuarded[port].init();

#if FW_OBJECT_NAMES == 1
    char portName[120];
    (void) snprintf(
      portName,
      sizeof(portName),
      "%s_to_noArgsReturnGuarded[%" PRI_PlatformIntType "]",
      this->m_objName,
      port
    );
    this->m_to_noArgsReturnGuarded[port].setObjName(portName);
#endif
  }

  // Connect output port noArgsReturnSync
  for (
    PlatformIntType port = 0;
    port < static_cast<PlatformIntType>(this->getNum_to_noArgsReturnSync());
    port++
  ) {
    this->m_to_noArgsReturnSync[port].init();

#if FW_OBJECT_NAMES == 1
    char portName[120];
    (void) snprintf(
      portName,
      sizeof(portName),
      "%s_to_noArgsReturnSync[%" PRI_PlatformIntType "]",
      this->m_objName,
      port
    );
    this->m_to_noArgsReturnSync[port].setObjName(portName);
#endif
  }

  // Connect output port noArgsSync
  for (
    PlatformIntType port = 0;
    port < static_cast<PlatformIntType>(this->getNum_to_noArgsSync());
    port++
  ) {
    this->m_to_noArgsSync[port].init();

#if FW_OBJECT_NAMES == 1
    char portName[120];
    (void) snprintf(
      portName,
      sizeof(portName),
      "%s_to_noArgsSync[%" PRI_PlatformIntType "]",
      this->m_objName,
      port
    );
    this->m_to_noArgsSync[port].setObjName(portName);
#endif
  }

  // Connect output port typedGuarded
  for (
    PlatformIntType port = 0;
    port < static_cast<PlatformIntType>(this->getNum_to_typedGuarded());
    port++
  ) {
    this->m_to_typedGuarded[port].init();

#if FW_OBJECT_NAMES == 1
    char portName[120];
    (void) snprintf(
      portName,
      sizeof(portName),
      "%s_to_typedGuarded[%" PRI_PlatformIntType "]",
      this->m_objName,
      port
    );
    this->m_to_typedGuarded[port].setObjName(portName);
#endif
  }

  // Connect output port typedReturnGuarded
  for (
    PlatformIntType port = 0;
    port < static_cast<PlatformIntType>(this->getNum_to_typedReturnGuarded());
    port++
  ) {
    this->m_to_typedReturnGuarded[port].init();

#if FW_OBJECT_NAMES == 1
    char portName[120];
    (void) snprintf(
      portName,
      sizeof(portName),
      "%s_to_typedReturnGuarded[%" PRI_PlatformIntType "]",
      this->m_objName,
      port
    );
    this->m_to_typedReturnGuarded[port].setObjName(portName);
#endif
  }

  // Connect output port typedReturnSync
  for (
    PlatformIntType port = 0;
    port < static_cast<PlatformIntType>(this->getNum_to_typedReturnSync());
    port++
  ) {
    this->m_to_typedReturnSync[port].init();

#if FW_OBJECT_NAMES == 1
    char portName[120];
    (void) snprintf(
      portName,
      sizeof(portName),
      "%s_to_typedReturnSync[%" PRI_PlatformIntType "]",
      this->m_objName,
      port
    );
    this->m_to_typedReturnSync[port].setObjName(portName);
#endif
  }

  // Connect output port typedSync
  for (
    PlatformIntType port = 0;
    port < static_cast<PlatformIntType>(this->getNum_to_typedSync());
    port++
  ) {
    this->m_to_typedSync[port].init();

#if FW_OBJECT_NAMES == 1
    char portName[120];
    (void) snprintf(
      portName,
      sizeof(portName),
      "%s_to_typedSync[%" PRI_PlatformIntType "]",
      this->m_objName,
      port
    );
    this->m_to_typedSync[port].setObjName(portName);
#endif
  }
}

// ----------------------------------------------------------------------
// Connectors for to ports
// ----------------------------------------------------------------------

void PassiveGetProductsTesterBase ::
  connect_to_cmdIn(
      NATIVE_INT_TYPE portNum,
      Fw::InputCmdPort* port
  )
{
  FW_ASSERT(
    portNum < this->getNum_to_cmdIn(),
    static_cast<FwAssertArgType>(portNum)
  );

  this->m_to_cmdIn[portNum].addCallPort(port);
}

void PassiveGetProductsTesterBase ::
  connect_to_productRecvIn(
      NATIVE_INT_TYPE portNum,
      Fw::InputDpResponsePort* port
  )
{
  FW_ASSERT(
    portNum < this->getNum_to_productRecvIn(),
    static_cast<FwAssertArgType>(portNum)
  );

  this->m_to_productRecvIn[portNum].addCallPort(port);
}

void PassiveGetProductsTesterBase ::
  connect_to_noArgsGuarded(
      NATIVE_INT_TYPE portNum,
      Ports::InputNoArgsPort* port
  )
{
  FW_ASSERT(
    portNum < this->getNum_to_noArgsGuarded(),
    static_cast<FwAssertArgType>(portNum)
  );

  this->m_to_noArgsGuarded[portNum].addCallPort(port);
}

void PassiveGetProductsTesterBase ::
  connect_to_noArgsReturnGuarded(
      NATIVE_INT_TYPE portNum,
      Ports::InputNoArgsReturnPort* port
  )
{
  FW_ASSERT(
    portNum < this->getNum_to_noArgsReturnGuarded(),
    static_cast<FwAssertArgType>(portNum)
  );

  this->m_to_noArgsReturnGuarded[portNum].addCallPort(port);
}

void PassiveGetProductsTesterBase ::
  connect_to_noArgsReturnSync(
      NATIVE_INT_TYPE portNum,
      Ports::InputNoArgsReturnPort* port
  )
{
  FW_ASSERT(
    portNum < this->getNum_to_noArgsReturnSync(),
    static_cast<FwAssertArgType>(portNum)
  );

  this->m_to_noArgsReturnSync[portNum].addCallPort(port);
}

void PassiveGetProductsTesterBase ::
  connect_to_noArgsSync(
      NATIVE_INT_TYPE portNum,
      Ports::InputNoArgsPort* port
  )
{
  FW_ASSERT(
    portNum < this->getNum_to_noArgsSync(),
    static_cast<FwAssertArgType>(portNum)
  );

  this->m_to_noArgsSync[portNum].addCallPort(port);
}

void PassiveGetProductsTesterBase ::
  connect_to_typedGuarded(
      NATIVE_INT_TYPE portNum,
      Ports::InputTypedPort* port
  )
{
  FW_ASSERT(
    portNum < this->getNum_to_typedGuarded(),
    static_cast<FwAssertArgType>(portNum)
  );

  this->m_to_typedGuarded[portNum].addCallPort(port);
}

void PassiveGetProductsTesterBase ::
  connect_to_typedReturnGuarded(
      NATIVE_INT_TYPE portNum,
      Ports::InputTypedReturnPort* port
  )
{
  FW_ASSERT(
    portNum < this->getNum_to_typedReturnGuarded(),
    static_cast<FwAssertArgType>(portNum)
  );

  this->m_to_typedReturnGuarded[portNum].addCallPort(port);
}

void PassiveGetProductsTesterBase ::
  connect_to_typedReturnSync(
      NATIVE_INT_TYPE portNum,
      Ports::InputTypedReturnPort* port
  )
{
  FW_ASSERT(
    portNum < this->getNum_to_typedReturnSync(),
    static_cast<FwAssertArgType>(portNum)
  );

  this->m_to_typedReturnSync[portNum].addCallPort(port);
}

void PassiveGetProductsTesterBase ::
  connect_to_typedSync(
      NATIVE_INT_TYPE portNum,
      Ports::InputTypedPort* port
  )
{
  FW_ASSERT(
    portNum < this->getNum_to_typedSync(),
    static_cast<FwAssertArgType>(portNum)
  );

  this->m_to_typedSync[portNum].addCallPort(port);
}

// ----------------------------------------------------------------------
// Getters for from ports
// ----------------------------------------------------------------------

Fw::InputCmdRegPort* PassiveGetProductsTesterBase ::
  get_from_cmdRegOut(NATIVE_INT_TYPE portNum)
{
  FW_ASSERT(
    portNum < this->getNum_from_cmdRegOut(),
    static_cast<FwAssertArgType>(portNum)
  );

  return &this->m_from_cmdRegOut[portNum];
}

Fw::InputCmdResponsePort* PassiveGetProductsTesterBase ::
  get_from_cmdResponseOut(NATIVE_INT_TYPE portNum)
{
  FW_ASSERT(
    portNum < this->getNum_from_cmdResponseOut(),
    static_cast<FwAssertArgType>(portNum)
  );

  return &this->m_from_cmdResponseOut[portNum];
}

Fw::InputLogPort* PassiveGetProductsTesterBase ::
  get_from_eventOut(NATIVE_INT_TYPE portNum)
{
  FW_ASSERT(
    portNum < this->getNum_from_eventOut(),
    static_cast<FwAssertArgType>(portNum)
  );

  return &this->m_from_eventOut[portNum];
}

Fw::InputPrmGetPort* PassiveGetProductsTesterBase ::
  get_from_prmGetOut(NATIVE_INT_TYPE portNum)
{
  FW_ASSERT(
    portNum < this->getNum_from_prmGetOut(),
    static_cast<FwAssertArgType>(portNum)
  );

  return &this->m_from_prmGetOut[portNum];
}

Fw::InputPrmSetPort* PassiveGetProductsTesterBase ::
  get_from_prmSetOut(NATIVE_INT_TYPE portNum)
{
  FW_ASSERT(
    portNum < this->getNum_from_prmSetOut(),
    static_cast<FwAssertArgType>(portNum)
  );

  return &this->m_from_prmSetOut[portNum];
}

Fw::InputDpGetPort* PassiveGetProductsTesterBase ::
  get_from_productGetOut(NATIVE_INT_TYPE portNum)
{
  FW_ASSERT(
    portNum < this->getNum_from_productGetOut(),
    static_cast<FwAssertArgType>(portNum)
  );

  return &this->m_from_productGetOut[portNum];
}

Fw::InputDpSendPort* PassiveGetProductsTesterBase ::
  get_from_productSendOut(NATIVE_INT_TYPE portNum)
{
  FW_ASSERT(
    portNum < this->getNum_from_productSendOut(),
    static_cast<FwAssertArgType>(portNum)
  );

  return &this->m_from_productSendOut[portNum];
}

#if FW_ENABLE_TEXT_LOGGING == 1

Fw::InputLogTextPort* PassiveGetProductsTesterBase ::
  get_from_textEventOut(NATIVE_INT_TYPE portNum)
{
  FW_ASSERT(
    portNum < this->getNum_from_textEventOut(),
    static_cast<FwAssertArgType>(portNum)
  );

  return &this->m_from_textEventOut[portNum];
}

#endif

Fw::InputTimePort* PassiveGetProductsTesterBase ::
  get_from_timeGetOut(NATIVE_INT_TYPE portNum)
{
  FW_ASSERT(
    portNum < this->getNum_from_timeGetOut(),
    static_cast<FwAssertArgType>(portNum)
  );

  return &this->m_from_timeGetOut[portNum];
}

Fw::InputTlmPort* PassiveGetProductsTesterBase ::
  get_from_tlmOut(NATIVE_INT_TYPE portNum)
{
  FW_ASSERT(
    portNum < this->getNum_from_tlmOut(),
    static_cast<FwAssertArgType>(portNum)
  );

  return &this->m_from_tlmOut[portNum];
}

Ports::InputTypedPort* PassiveGetProductsTesterBase ::
  get_from_typedOut(NATIVE_INT_TYPE portNum)
{
  FW_ASSERT(
    portNum < this->getNum_from_typedOut(),
    static_cast<FwAssertArgType>(portNum)
  );

  return &this->m_from_typedOut[portNum];
}

Ports::InputTypedReturnPort* PassiveGetProductsTesterBase ::
  get_from_typedReturnOut(NATIVE_INT_TYPE portNum)
{
  FW_ASSERT(
    portNum < this->getNum_from_typedReturnOut(),
    static_cast<FwAssertArgType>(portNum)
  );

  return &this->m_from_typedReturnOut[portNum];
}

// ----------------------------------------------------------------------
// Component construction and destruction
// ----------------------------------------------------------------------

PassiveGetProductsTesterBase ::
  PassiveGetProductsTesterBase(
      const char* const compName,
      const U32 maxHistorySize
  ) :
    Fw::PassiveComponentBase(compName)
{
  // Initialize port histories
  this->fromPortHistory_typedOut = new History<FromPortEntry_typedOut>(maxHistorySize);
  this->fromPortHistory_typedReturnOut = new History<FromPortEntry_typedReturnOut>(maxHistorySize);

  // Initialize data product send history
  this->productSendHistory = new History<DpSend>(maxHistorySize);

  // Clear history
  this->clearHistory();
}

PassiveGetProductsTesterBase ::
  ~PassiveGetProductsTesterBase()
{
  // Destroy port histories
  delete this->fromPortHistory_typedOut;
  delete this->fromPortHistory_typedReturnOut;

  // Destroy product send history
  delete this->productSendHistory;
}

// ----------------------------------------------------------------------
// Handler base-class functions for from ports
// ----------------------------------------------------------------------

void PassiveGetProductsTesterBase ::
  from_typedOut_handlerBase(
      NATIVE_INT_TYPE portNum,
      U32 u32,
      F32 f32,
      bool b,
      const Ports::TypedPortStrings::StringSize80& str1,
      const E& e,
      const A& a,
      const S& s
  )
{
  // Make sure port number is valid
  FW_ASSERT(
    portNum < this->getNum_from_typedOut(),
    static_cast<FwAssertArgType>(portNum)
  );
  this->from_typedOut_handler(
    portNum,
    u32,
    f32,
    b,
    str1,
    e,
    a,
    s
  );
}

F32 PassiveGetProductsTesterBase ::
  from_typedReturnOut_handlerBase(
      NATIVE_INT_TYPE portNum,
      U32 u32,
      F32 f32,
      bool b,
      const Ports::TypedReturnPortStrings::StringSize80& str2,
      const E& e,
      const A& a,
      const S& s
  )
{
  // Make sure port number is valid
  FW_ASSERT(
    portNum < this->getNum_from_typedReturnOut(),
    static_cast<FwAssertArgType>(portNum)
  );
  return this->from_typedReturnOut_handler(
    portNum,
    u32,
    f32,
    b,
    str2,
    e,
    a,
    s
  );
}

// ----------------------------------------------------------------------
// Invocation functions for to ports
// ----------------------------------------------------------------------

void PassiveGetProductsTesterBase ::
  invoke_to_noArgsGuarded(NATIVE_INT_TYPE portNum)
{
  // Make sure port number is valid
  FW_ASSERT(
    portNum < this->getNum_to_noArgsGuarded(),
    static_cast<FwAssertArgType>(portNum)
  );
  this->m_to_noArgsGuarded[portNum].invoke();
}

U32 PassiveGetProductsTesterBase ::
  invoke_to_noArgsReturnGuarded(NATIVE_INT_TYPE portNum)
{
  // Make sure port number is valid
  FW_ASSERT(
    portNum < this->getNum_to_noArgsReturnGuarded(),
    static_cast<FwAssertArgType>(portNum)
  );
  return this->m_to_noArgsReturnGuarded[portNum].invoke();
}

U32 PassiveGetProductsTesterBase ::
  invoke_to_noArgsReturnSync(NATIVE_INT_TYPE portNum)
{
  // Make sure port number is valid
  FW_ASSERT(
    portNum < this->getNum_to_noArgsReturnSync(),
    static_cast<FwAssertArgType>(portNum)
  );
  return this->m_to_noArgsReturnSync[portNum].invoke();
}

void PassiveGetProductsTesterBase ::
  invoke_to_noArgsSync(NATIVE_INT_TYPE portNum)
{
  // Make sure port number is valid
  FW_ASSERT(
    portNum < this->getNum_to_noArgsSync(),
    static_cast<FwAssertArgType>(portNum)
  );
  this->m_to_noArgsSync[portNum].invoke();
}

void PassiveGetProductsTesterBase ::
  invoke_to_typedGuarded(
      NATIVE_INT_TYPE portNum,
      U32 u32,
      F32 f32,
      bool b,
      const Ports::TypedPortStrings::StringSize80& str1,
      const E& e,
      const A& a,
      const S& s
  )
{
  // Make sure port number is valid
  FW_ASSERT(
    portNum < this->getNum_to_typedGuarded(),
    static_cast<FwAssertArgType>(portNum)
  );
  this->m_to_typedGuarded[portNum].invoke(
    u32,
    f32,
    b,
    str1,
    e,
    a,
    s
  );
}

F32 PassiveGetProductsTesterBase ::
  invoke_to_typedReturnGuarded(
      NATIVE_INT_TYPE portNum,
      U32 u32,
      F32 f32,
      bool b,
      const Ports::TypedReturnPortStrings::StringSize80& str2,
      const E& e,
      const A& a,
      const S& s
  )
{
  // Make sure port number is valid
  FW_ASSERT(
    portNum < this->getNum_to_typedReturnGuarded(),
    static_cast<FwAssertArgType>(portNum)
  );
  return this->m_to_typedReturnGuarded[portNum].invoke(
    u32,
    f32,
    b,
    str2,
    e,
    a,
    s
  );
}

F32 PassiveGetProductsTesterBase ::
  invoke_to_typedReturnSync(
      NATIVE_INT_TYPE portNum,
      U32 u32,
      F32 f32,
      bool b,
      const Ports::TypedReturnPortStrings::StringSize80& str2,
      const E& e,
      const A& a,
      const S& s
  )
{
  // Make sure port number is valid
  FW_ASSERT(
    portNum < this->getNum_to_typedReturnSync(),
    static_cast<FwAssertArgType>(portNum)
  );
  return this->m_to_typedReturnSync[portNum].invoke(
    u32,
    f32,
    b,
    str2,
    e,
    a,
    s
  );
}

void PassiveGetProductsTesterBase ::
  invoke_to_typedSync(
      NATIVE_INT_TYPE portNum,
      U32 u32,
      F32 f32,
      bool b,
      const Ports::TypedPortStrings::StringSize80& str1,
      const E& e,
      const A& a,
      const S& s
  )
{
  // Make sure port number is valid
  FW_ASSERT(
    portNum < this->getNum_to_typedSync(),
    static_cast<FwAssertArgType>(portNum)
  );
  this->m_to_typedSync[portNum].invoke(
    u32,
    f32,
    b,
    str1,
    e,
    a,
    s
  );
}

// ----------------------------------------------------------------------
// Getters for port counts
// ----------------------------------------------------------------------

NATIVE_INT_TYPE PassiveGetProductsTesterBase ::
  getNum_to_cmdIn() const
{
  return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_to_cmdIn));
}

NATIVE_INT_TYPE PassiveGetProductsTesterBase ::
  getNum_to_productRecvIn() const
{
  return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_to_productRecvIn));
}

NATIVE_INT_TYPE PassiveGetProductsTesterBase ::
  getNum_to_noArgsGuarded() const
{
  return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_to_noArgsGuarded));
}

NATIVE_INT_TYPE PassiveGetProductsTesterBase ::
  getNum_to_noArgsReturnGuarded() const
{
  return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_to_noArgsReturnGuarded));
}

NATIVE_INT_TYPE PassiveGetProductsTesterBase ::
  getNum_to_noArgsReturnSync() const
{
  return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_to_noArgsReturnSync));
}

NATIVE_INT_TYPE PassiveGetProductsTesterBase ::
  getNum_to_noArgsSync() const
{
  return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_to_noArgsSync));
}

NATIVE_INT_TYPE PassiveGetProductsTesterBase ::
  getNum_to_typedGuarded() const
{
  return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_to_typedGuarded));
}

NATIVE_INT_TYPE PassiveGetProductsTesterBase ::
  getNum_to_typedReturnGuarded() const
{
  return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_to_typedReturnGuarded));
}

NATIVE_INT_TYPE PassiveGetProductsTesterBase ::
  getNum_to_typedReturnSync() const
{
  return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_to_typedReturnSync));
}

NATIVE_INT_TYPE PassiveGetProductsTesterBase ::
  getNum_to_typedSync() const
{
  return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_to_typedSync));
}

NATIVE_INT_TYPE PassiveGetProductsTesterBase ::
  getNum_from_cmdRegOut() const
{
  return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_from_cmdRegOut));
}

NATIVE_INT_TYPE PassiveGetProductsTesterBase ::
  getNum_from_cmdResponseOut() const
{
  return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_from_cmdResponseOut));
}

NATIVE_INT_TYPE PassiveGetProductsTesterBase ::
  getNum_from_eventOut() const
{
  return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_from_eventOut));
}

NATIVE_INT_TYPE PassiveGetProductsTesterBase ::
  getNum_from_prmGetOut() const
{
  return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_from_prmGetOut));
}

NATIVE_INT_TYPE PassiveGetProductsTesterBase ::
  getNum_from_prmSetOut() const
{
  return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_from_prmSetOut));
}

NATIVE_INT_TYPE PassiveGetProductsTesterBase ::
  getNum_from_productGetOut() const
{
  return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_from_productGetOut));
}

NATIVE_INT_TYPE PassiveGetProductsTesterBase ::
  getNum_from_productSendOut() const
{
  return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_from_productSendOut));
}

#if FW_ENABLE_TEXT_LOGGING == 1

NATIVE_INT_TYPE PassiveGetProductsTesterBase ::
  getNum_from_textEventOut() const
{
  return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_from_textEventOut));
}

#endif

NATIVE_INT_TYPE PassiveGetProductsTesterBase ::
  getNum_from_timeGetOut() const
{
  return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_from_timeGetOut));
}

NATIVE_INT_TYPE PassiveGetProductsTesterBase ::
  getNum_from_tlmOut() const
{
  return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_from_tlmOut));
}

NATIVE_INT_TYPE PassiveGetProductsTesterBase ::
  getNum_from_typedOut() const
{
  return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_from_typedOut));
}

NATIVE_INT_TYPE PassiveGetProductsTesterBase ::
  getNum_from_typedReturnOut() const
{
  return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_from_typedReturnOut));
}

// ----------------------------------------------------------------------
// Connection status queries for to ports
// ----------------------------------------------------------------------

bool PassiveGetProductsTesterBase ::
  isConnected_to_cmdIn(NATIVE_INT_TYPE portNum)
{
  FW_ASSERT(
    portNum < this->getNum_to_cmdIn(),
    static_cast<FwAssertArgType>(portNum)
  );

  return this->m_to_cmdIn[portNum].isConnected();
}

bool PassiveGetProductsTesterBase ::
  isConnected_to_productRecvIn(NATIVE_INT_TYPE portNum)
{
  FW_ASSERT(
    portNum < this->getNum_to_productRecvIn(),
    static_cast<FwAssertArgType>(portNum)
  );

  return this->m_to_productRecvIn[portNum].isConnected();
}

bool PassiveGetProductsTesterBase ::
  isConnected_to_noArgsGuarded(NATIVE_INT_TYPE portNum)
{
  FW_ASSERT(
    portNum < this->getNum_to_noArgsGuarded(),
    static_cast<FwAssertArgType>(portNum)
  );

  return this->m_to_noArgsGuarded[portNum].isConnected();
}

bool PassiveGetProductsTesterBase ::
  isConnected_to_noArgsReturnGuarded(NATIVE_INT_TYPE portNum)
{
  FW_ASSERT(
    portNum < this->getNum_to_noArgsReturnGuarded(),
    static_cast<FwAssertArgType>(portNum)
  );

  return this->m_to_noArgsReturnGuarded[portNum].isConnected();
}

bool PassiveGetProductsTesterBase ::
  isConnected_to_noArgsReturnSync(NATIVE_INT_TYPE portNum)
{
  FW_ASSERT(
    portNum < this->getNum_to_noArgsReturnSync(),
    static_cast<FwAssertArgType>(portNum)
  );

  return this->m_to_noArgsReturnSync[portNum].isConnected();
}

bool PassiveGetProductsTesterBase ::
  isConnected_to_noArgsSync(NATIVE_INT_TYPE portNum)
{
  FW_ASSERT(
    portNum < this->getNum_to_noArgsSync(),
    static_cast<FwAssertArgType>(portNum)
  );

  return this->m_to_noArgsSync[portNum].isConnected();
}

bool PassiveGetProductsTesterBase ::
  isConnected_to_typedGuarded(NATIVE_INT_TYPE portNum)
{
  FW_ASSERT(
    portNum < this->getNum_to_typedGuarded(),
    static_cast<FwAssertArgType>(portNum)
  );

  return this->m_to_typedGuarded[portNum].isConnected();
}

bool PassiveGetProductsTesterBase ::
  isConnected_to_typedReturnGuarded(NATIVE_INT_TYPE portNum)
{
  FW_ASSERT(
    portNum < this->getNum_to_typedReturnGuarded(),
    static_cast<FwAssertArgType>(portNum)
  );

  return this->m_to_typedReturnGuarded[portNum].isConnected();
}

bool PassiveGetProductsTesterBase ::
  isConnected_to_typedReturnSync(NATIVE_INT_TYPE portNum)
{
  FW_ASSERT(
    portNum < this->getNum_to_typedReturnSync(),
    static_cast<FwAssertArgType>(portNum)
  );

  return this->m_to_typedReturnSync[portNum].isConnected();
}

bool PassiveGetProductsTesterBase ::
  isConnected_to_typedSync(NATIVE_INT_TYPE portNum)
{
  FW_ASSERT(
    portNum < this->getNum_to_typedSync(),
    static_cast<FwAssertArgType>(portNum)
  );

  return this->m_to_typedSync[portNum].isConnected();
}

// ----------------------------------------------------------------------
// Functions to test time
// ----------------------------------------------------------------------

void PassiveGetProductsTesterBase ::
  setTestTime(Fw::Time& timeTag)
{
  this->m_testTime = timeTag;
}

// ----------------------------------------------------------------------
// Functions for testing data products
// ----------------------------------------------------------------------

Fw::Success::T PassiveGetProductsTesterBase ::
  productGetIn(
      FwDpIdType id,
      FwSizeType size,
      Fw::Buffer& buffer
  )
{
  (void) buffer;
  DpGet e = { id, size };
  this->productGetHistory->push_back(e);
  // Default behavior: do not allocate a buffer and return FAILURE
  // Client code can override this behavior
  return Fw::Success::FAILURE;
}

void PassiveGetProductsTesterBase ::
  productSendIn(
      FwDpIdType id,
      Fw::Buffer buffer
  )
{
  DpSend e = { id, buffer };
  this->productSendHistory->push_back(e);
}

// ----------------------------------------------------------------------
// History functions
// ----------------------------------------------------------------------

void PassiveGetProductsTesterBase ::
  clearHistory()
{
  this->clearFromPortHistory();
  this->productGetHistory->clear();
  this->productSendHistory->clear();
}

void PassiveGetProductsTesterBase ::
  clearFromPortHistory()
{
  this->fromPortHistorySize = 0;
  this->fromPortHistory_typedOut->clear();
  this->fromPortHistory_typedReturnOut->clear();
}

void PassiveGetProductsTesterBase ::
  pushFromPortEntry_typedOut(
      U32 u32,
      F32 f32,
      bool b,
      const Ports::TypedPortStrings::StringSize80& str1,
      const E& e,
      const A& a,
      const S& s
  )
{
  FromPortEntry_typedOut _e = {
    u32,
    f32,
    b,
    str1,
    e,
    a,
    s
  };
  this->fromPortHistory_typedOut->push_back(_e);
  this->fromPortHistorySize++;
}

void PassiveGetProductsTesterBase ::
  pushFromPortEntry_typedReturnOut(
      U32 u32,
      F32 f32,
      bool b,
      const Ports::TypedReturnPortStrings::StringSize80& str2,
      const E& e,
      const A& a,
      const S& s
  )
{
  FromPortEntry_typedReturnOut _e = {
    u32,
    f32,
    b,
    str2,
    e,
    a,
    s
  };
  this->fromPortHistory_typedReturnOut->push_back(_e);
  this->fromPortHistorySize++;
}

// ----------------------------------------------------------------------
// Static functions for output ports
// ----------------------------------------------------------------------

Fw::Success PassiveGetProductsTesterBase ::
  from_productGetOut_static(
      Fw::PassiveComponentBase* const callComp,
      NATIVE_INT_TYPE portNum,
      FwDpIdType id,
      FwSizeType size,
      Fw::Buffer& buffer
  )
{
  PassiveGetProductsTesterBase* _testerBase = static_cast<PassiveGetProductsTesterBase*>(callComp);
  return _testerBase->productGetIn(id, size, buffer);
}

void PassiveGetProductsTesterBase ::
  from_productSendOut_static(
      Fw::PassiveComponentBase* const callComp,
      NATIVE_INT_TYPE portNum,
      FwDpIdType id,
      const Fw::Buffer& buffer
  )
{
  PassiveGetProductsTesterBase* _testerBase = static_cast<PassiveGetProductsTesterBase*>(callComp);
  _testerBase->productSendIn(id, buffer);
}

void PassiveGetProductsTesterBase ::
  from_timeGetOut_static(
      Fw::PassiveComponentBase* const callComp,
      NATIVE_INT_TYPE portNum,
      Fw::Time& time
  )
{
  PassiveGetProductsTesterBase* _testerBase = static_cast<PassiveGetProductsTesterBase*>(callComp);
  time = _testerBase->m_testTime;
}

void PassiveGetProductsTesterBase ::
  from_typedOut_static(
      Fw::PassiveComponentBase* const callComp,
      NATIVE_INT_TYPE portNum,
      U32 u32,
      F32 f32,
      bool b,
      const Ports::TypedPortStrings::StringSize80& str1,
      const E& e,
      const A& a,
      const S& s
  )
{
  FW_ASSERT(callComp != nullptr);
  PassiveGetProductsTesterBase* _testerBase = static_cast<PassiveGetProductsTesterBase*>(callComp);
  _testerBase->from_typedOut_handlerBase(
    portNum,
    u32,
    f32,
    b,
    str1,
    e,
    a,
    s
  );
}

F32 PassiveGetProductsTesterBase ::
  from_typedReturnOut_static(
      Fw::PassiveComponentBase* const callComp,
      NATIVE_INT_TYPE portNum,
      U32 u32,
      F32 f32,
      bool b,
      const Ports::TypedReturnPortStrings::StringSize80& str2,
      const E& e,
      const A& a,
      const S& s
  )
{
  FW_ASSERT(callComp != nullptr);
  PassiveGetProductsTesterBase* _testerBase = static_cast<PassiveGetProductsTesterBase*>(callComp);
  return _testerBase->from_typedReturnOut_handlerBase(
    portNum,
    u32,
    f32,
    b,
    str2,
    e,
    a,
    s
  );
}
