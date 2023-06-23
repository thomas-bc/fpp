// ======================================================================
// \title  ActiveTelemetry.cpp
// \author Generated by fpp-to-cpp
// \brief  cpp file for ActiveTelemetry component implementation class
// ======================================================================

#include "ActiveTelemetry.hpp"
#include "FpConfig.hpp"

// ----------------------------------------------------------------------
// Component construction and destruction
// ----------------------------------------------------------------------

ActiveTelemetry ::
  ActiveTelemetry(const char* const compName) :
    ActiveTelemetryComponentBase(compName)
{

}

ActiveTelemetry ::
  ~ActiveTelemetry()
{

}

// ----------------------------------------------------------------------
// Handler implementations for user-defined typed input ports
// ----------------------------------------------------------------------

void ActiveTelemetry ::
  noArgsAsync_handler(NATIVE_INT_TYPE portNum)
{
  // TODO
}

void ActiveTelemetry ::
  noArgsGuarded_handler(NATIVE_INT_TYPE portNum)
{
  // TODO
}

U32 ActiveTelemetry ::
  noArgsReturnGuarded_handler(NATIVE_INT_TYPE portNum)
{
  // TODO return
}

U32 ActiveTelemetry ::
  noArgsReturnSync_handler(NATIVE_INT_TYPE portNum)
{
  // TODO return
}

void ActiveTelemetry ::
  noArgsSync_handler(NATIVE_INT_TYPE portNum)
{
  // TODO
}

void ActiveTelemetry ::
  typedAsync_handler(
      NATIVE_INT_TYPE portNum,
      U32 u32,
      F32 f32,
      bool b,
      const TypedPortStrings::StringSize80& str1,
      const E& e,
      const A& a,
      const S& s
  )
{
  // TODO
}

void ActiveTelemetry ::
  typedAsyncAssert_handler(
      NATIVE_INT_TYPE portNum,
      U32 u32,
      F32 f32,
      bool b,
      const TypedPortStrings::StringSize80& str1,
      const E& e,
      const A& a,
      const S& s
  )
{
  // TODO
}

void ActiveTelemetry ::
  typedAsyncBlockPriority_handler(
      NATIVE_INT_TYPE portNum,
      U32 u32,
      F32 f32,
      bool b,
      const TypedPortStrings::StringSize80& str1,
      const E& e,
      const A& a,
      const S& s
  )
{
  // TODO
}

void ActiveTelemetry ::
  typedAsyncDropPriority_handler(
      NATIVE_INT_TYPE portNum,
      U32 u32,
      F32 f32,
      bool b,
      const TypedPortStrings::StringSize80& str1,
      const E& e,
      const A& a,
      const S& s
  )
{
  // TODO
}

void ActiveTelemetry ::
  typedGuarded_handler(
      NATIVE_INT_TYPE portNum,
      U32 u32,
      F32 f32,
      bool b,
      const TypedPortStrings::StringSize80& str1,
      const E& e,
      const A& a,
      const S& s
  )
{
  // TODO
}

F32 ActiveTelemetry ::
  typedReturnGuarded_handler(
      NATIVE_INT_TYPE portNum,
      U32 u32,
      F32 f32,
      bool b,
      const TypedReturnPortStrings::StringSize80& str2,
      const E& e,
      const A& a,
      const S& s
  )
{
  // TODO return
}

F32 ActiveTelemetry ::
  typedReturnSync_handler(
      NATIVE_INT_TYPE portNum,
      U32 u32,
      F32 f32,
      bool b,
      const TypedReturnPortStrings::StringSize80& str2,
      const E& e,
      const A& a,
      const S& s
  )
{
  // TODO return
}

void ActiveTelemetry ::
  typedSync_handler(
      NATIVE_INT_TYPE portNum,
      U32 u32,
      F32 f32,
      bool b,
      const TypedPortStrings::StringSize80& str1,
      const E& e,
      const A& a,
      const S& s
  )
{
  // TODO
}
