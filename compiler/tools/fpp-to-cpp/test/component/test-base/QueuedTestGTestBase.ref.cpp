// ======================================================================
// \title  QueuedTestGTestBase.cpp
// \author Generated by fpp-to-cpp
// \brief  cpp file for QueuedTest component Google Test harness base class
// ======================================================================

#include "test-base/QueuedTestGTestBase.hpp"

// ----------------------------------------------------------------------
// Construction and destruction
// ----------------------------------------------------------------------

QueuedTestGTestBase ::
  QueuedTestGTestBase(
      const char* const compName,
      const U32 maxHistorySize
  ) :
    QueuedTestTesterBase(compName, maxHistorySize)
{

}

QueuedTestGTestBase ::
  ~QueuedTestGTestBase()
{

}

// ----------------------------------------------------------------------
// From ports
// ----------------------------------------------------------------------

void QueuedTestGTestBase ::
  assertFromPortHistory_size(
      const char* const __callSiteFileName,
      const U32 __callSiteLineNumber,
      const U32 size
  ) const
{
  ASSERT_EQ(size, this->fromPortHistorySize)
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Total size of all from port histories\n"
    << "  Expected: " << size << "\n"
    << "  Actual:   " << this->fromPortHistorySize << "\n";
}

void QueuedTestGTestBase ::
  assert_from_noArgsOut_size(
      const char* const __callSiteFileName,
      const U32 __callSiteLineNumber,
      const U32 size
  ) const
{
  ASSERT_EQ(size, this->fromPortHistorySize_noArgsOut)
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Size of history for noArgsOut\n"
    << "  Expected: " << size << "\n"
    << "  Actual:   " << this->fromPortHistorySize_noArgsOut << "\n";
}

void QueuedTestGTestBase ::
  assert_from_noArgsReturnOut_size(
      const char* const __callSiteFileName,
      const U32 __callSiteLineNumber,
      const U32 size
  ) const
{
  ASSERT_EQ(size, this->fromPortHistorySize_noArgsReturnOut)
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Size of history for noArgsReturnOut\n"
    << "  Expected: " << size << "\n"
    << "  Actual:   " << this->fromPortHistorySize_noArgsReturnOut << "\n";
}

void QueuedTestGTestBase ::
  assert_from_typedOut_size(
      const char* const __callSiteFileName,
      const U32 __callSiteLineNumber,
      const U32 size
  ) const
{
  ASSERT_EQ(size, this->fromPortHistory_typedOut->size())
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Size of history for typedOut\n"
    << "  Expected: " << size << "\n"
    << "  Actual:   " << this->fromPortHistory_typedOut->size() << "\n";
}

void QueuedTestGTestBase ::
  assert_from_typedReturnOut_size(
      const char* const __callSiteFileName,
      const U32 __callSiteLineNumber,
      const U32 size
  ) const
{
  ASSERT_EQ(size, this->fromPortHistory_typedReturnOut->size())
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Size of history for typedReturnOut\n"
    << "  Expected: " << size << "\n"
    << "  Actual:   " << this->fromPortHistory_typedReturnOut->size() << "\n";
}

// ----------------------------------------------------------------------
// Commands
// ----------------------------------------------------------------------

void QueuedTestGTestBase ::
  assertCmdResponse_size(
      const char* const __callSiteFileName,
      const U32 __callSiteLineNumber,
      const U32 size
  ) const
{
  ASSERT_EQ(size, this->cmdResponseHistory->size())
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Size of command response history\n"
    << "  Expected: " << size << "\n"
    << "  Actual:   " << this->cmdResponseHistory->size() << "\n";
}

void QueuedTestGTestBase ::
  assertCmdResponse(
      const char* const __callSiteFileName,
      const U32 __callSiteLineNumber,
      const U32 __index,
      FwOpcodeType opCode,
      U32 cmdSeq,
      Fw::CmdResponse response
  ) const
{
  ASSERT_LT(__index, this->cmdResponseHistory->size())
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Index into command response history\n"
    << "  Expected: Less than size of command response history ("
    << this->cmdResponseHistory->size() << ")\n"
    << "  Actual:   " << __index << "\n";
  const CmdResponse& e = this->cmdResponseHistory->at(__index);
  ASSERT_EQ(opCode, e.opCode)
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Opcode at index "
    << __index
    << " in command response history\n"
    << "  Expected: " << opCode << "\n"
    << "  Actual:   " << e.opCode << "\n";
  ASSERT_EQ(cmdSeq, e.cmdSeq)
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Command sequence number at index "
    << __index
    << " in command response history\n"
    << "  Expected: " << cmdSeq << "\n"
    << "  Actual:   " << e.cmdSeq << "\n";
  ASSERT_EQ(response, e.response)
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Command response at index "
    << __index
    << " in command response history\n"
    << "  Expected: " << response << "\n"
    << "  Actual:   " << e.response << "\n";
}

// ----------------------------------------------------------------------
// Events
// ----------------------------------------------------------------------

void QueuedTestGTestBase ::
  assertEvents_size(
      const char* const __callSiteFileName,
      const U32 __callSiteLineNumber,
      const U32 size
  ) const
{
  ASSERT_EQ(size, this->eventsSize)
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Total size of all event histories\n"
    << "  Expected: " << size << "\n"
    << "  Actual:   " << this->eventsSize << "\n";
}

void QueuedTestGTestBase ::
  assertEvents_EventActivityHigh_size(
      const char* const __callSiteFileName,
      const U32 __callSiteLineNumber,
      const U32 size
  ) const
{
  ASSERT_EQ(size, this->eventsSize_EventActivityHigh)
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Size of history for event EventActivityHigh\n"
    << "  Expected: " << size << "\n"
    << "  Actual:   " << this->eventsSize_EventActivityHigh << "\n";
}

void QueuedTestGTestBase ::
  assertEvents_EventActivityLowThrottled_size(
      const char* const __callSiteFileName,
      const U32 __callSiteLineNumber,
      const U32 size
  ) const
{
  ASSERT_EQ(size, this->eventHistory_EventActivityLowThrottled->size())
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Size of history for event EventActivityLowThrottled\n"
    << "  Expected: " << size << "\n"
    << "  Actual:   " << this->eventHistory_EventActivityLowThrottled->size() << "\n";
}

void QueuedTestGTestBase ::
  assertEvents_EventActivityLowThrottled(
      const char* const __callSiteFileName,
      const U32 __callSiteLineNumber,
      const U32 __index,
      const U32 u32,
      const F32 f32,
      const bool b
  ) const
{
  ASSERT_GT(this->eventHistory_EventActivityLowThrottled->size(), __index)
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Index into history of event EventActivityLowThrottled\n"
    << "  Expected: Less than size of history ("
    << this->eventHistory_EventActivityLowThrottled->size() << ")\n"
    << "  Actual:   " << __index << "\n";
  const EventEntry_EventActivityLowThrottled& _e =
    this->eventHistory_EventActivityLowThrottled->at(__index);
  ASSERT_EQ(u32, _e.u32)
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Value of argument u32 at index "
    << __index
    << " in history of event EventActivityLowThrottled\n"
    << "  Expected: " << u32 << "\n"
    << "  Actual:   " << _e.u32 << "\n";
  ASSERT_EQ(f32, _e.f32)
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Value of argument f32 at index "
    << __index
    << " in history of event EventActivityLowThrottled\n"
    << "  Expected: " << f32 << "\n"
    << "  Actual:   " << _e.f32 << "\n";
  ASSERT_EQ(b, _e.b)
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Value of argument b at index "
    << __index
    << " in history of event EventActivityLowThrottled\n"
    << "  Expected: " << b << "\n"
    << "  Actual:   " << _e.b << "\n";
}

void QueuedTestGTestBase ::
  assertEvents_EventCommand_size(
      const char* const __callSiteFileName,
      const U32 __callSiteLineNumber,
      const U32 size
  ) const
{
  ASSERT_EQ(size, this->eventHistory_EventCommand->size())
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Size of history for event EventCommand\n"
    << "  Expected: " << size << "\n"
    << "  Actual:   " << this->eventHistory_EventCommand->size() << "\n";
}

void QueuedTestGTestBase ::
  assertEvents_EventCommand(
      const char* const __callSiteFileName,
      const U32 __callSiteLineNumber,
      const U32 __index,
      const char* const str1,
      const char* const str2
  ) const
{
  ASSERT_GT(this->eventHistory_EventCommand->size(), __index)
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Index into history of event EventCommand\n"
    << "  Expected: Less than size of history ("
    << this->eventHistory_EventCommand->size() << ")\n"
    << "  Actual:   " << __index << "\n";
  const EventEntry_EventCommand& _e =
    this->eventHistory_EventCommand->at(__index);
  ASSERT_STREQ(str1, _e.str1.toChar())
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Value of argument str1 at index "
    << __index
    << " in history of event EventCommand\n"
    << "  Expected: " << str1 << "\n"
    << "  Actual:   " << _e.str1.toChar() << "\n";
  ASSERT_STREQ(str2, _e.str2.toChar())
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Value of argument str2 at index "
    << __index
    << " in history of event EventCommand\n"
    << "  Expected: " << str2 << "\n"
    << "  Actual:   " << _e.str2.toChar() << "\n";
}

void QueuedTestGTestBase ::
  assertEvents_EventDiagnostic_size(
      const char* const __callSiteFileName,
      const U32 __callSiteLineNumber,
      const U32 size
  ) const
{
  ASSERT_EQ(size, this->eventHistory_EventDiagnostic->size())
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Size of history for event EventDiagnostic\n"
    << "  Expected: " << size << "\n"
    << "  Actual:   " << this->eventHistory_EventDiagnostic->size() << "\n";
}

void QueuedTestGTestBase ::
  assertEvents_EventDiagnostic(
      const char* const __callSiteFileName,
      const U32 __callSiteLineNumber,
      const U32 __index,
      const E& e
  ) const
{
  ASSERT_GT(this->eventHistory_EventDiagnostic->size(), __index)
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Index into history of event EventDiagnostic\n"
    << "  Expected: Less than size of history ("
    << this->eventHistory_EventDiagnostic->size() << ")\n"
    << "  Actual:   " << __index << "\n";
  const EventEntry_EventDiagnostic& _e =
    this->eventHistory_EventDiagnostic->at(__index);
  ASSERT_EQ(e, _e.e)
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Value of argument e at index "
    << __index
    << " in history of event EventDiagnostic\n"
    << "  Expected: " << e << "\n"
    << "  Actual:   " << _e.e << "\n";
}

void QueuedTestGTestBase ::
  assertEvents_EventFatalThrottled_size(
      const char* const __callSiteFileName,
      const U32 __callSiteLineNumber,
      const U32 size
  ) const
{
  ASSERT_EQ(size, this->eventHistory_EventFatalThrottled->size())
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Size of history for event EventFatalThrottled\n"
    << "  Expected: " << size << "\n"
    << "  Actual:   " << this->eventHistory_EventFatalThrottled->size() << "\n";
}

void QueuedTestGTestBase ::
  assertEvents_EventFatalThrottled(
      const char* const __callSiteFileName,
      const U32 __callSiteLineNumber,
      const U32 __index,
      const A& a
  ) const
{
  ASSERT_GT(this->eventHistory_EventFatalThrottled->size(), __index)
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Index into history of event EventFatalThrottled\n"
    << "  Expected: Less than size of history ("
    << this->eventHistory_EventFatalThrottled->size() << ")\n"
    << "  Actual:   " << __index << "\n";
  const EventEntry_EventFatalThrottled& _e =
    this->eventHistory_EventFatalThrottled->at(__index);
  ASSERT_EQ(a, _e.a)
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Value of argument a at index "
    << __index
    << " in history of event EventFatalThrottled\n"
    << "  Expected: " << a << "\n"
    << "  Actual:   " << _e.a << "\n";
}

void QueuedTestGTestBase ::
  assertEvents_EventWarningHigh_size(
      const char* const __callSiteFileName,
      const U32 __callSiteLineNumber,
      const U32 size
  ) const
{
  ASSERT_EQ(size, this->eventHistory_EventWarningHigh->size())
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Size of history for event EventWarningHigh\n"
    << "  Expected: " << size << "\n"
    << "  Actual:   " << this->eventHistory_EventWarningHigh->size() << "\n";
}

void QueuedTestGTestBase ::
  assertEvents_EventWarningHigh(
      const char* const __callSiteFileName,
      const U32 __callSiteLineNumber,
      const U32 __index,
      const S& s
  ) const
{
  ASSERT_GT(this->eventHistory_EventWarningHigh->size(), __index)
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Index into history of event EventWarningHigh\n"
    << "  Expected: Less than size of history ("
    << this->eventHistory_EventWarningHigh->size() << ")\n"
    << "  Actual:   " << __index << "\n";
  const EventEntry_EventWarningHigh& _e =
    this->eventHistory_EventWarningHigh->at(__index);
  ASSERT_EQ(s, _e.s)
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Value of argument s at index "
    << __index
    << " in history of event EventWarningHigh\n"
    << "  Expected: " << s << "\n"
    << "  Actual:   " << _e.s << "\n";
}

void QueuedTestGTestBase ::
  assertEvents_EventWarningLowThrottled_size(
      const char* const __callSiteFileName,
      const U32 __callSiteLineNumber,
      const U32 size
  ) const
{
  ASSERT_EQ(size, this->eventsSize_EventWarningLowThrottled)
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Size of history for event EventWarningLowThrottled\n"
    << "  Expected: " << size << "\n"
    << "  Actual:   " << this->eventsSize_EventWarningLowThrottled << "\n";
}

// ----------------------------------------------------------------------
// Telemetry
// ----------------------------------------------------------------------

void QueuedTestGTestBase ::
  assertTlm_size(
      const char* const __callSiteFileName,
      const U32 __callSiteLineNumber,
      const U32 size
  ) const
{
  ASSERT_EQ(size, this->tlmSize)
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Total size of all telemetry histories\n"
    << "  Expected: " << size << "\n"
    << "  Actual:   " << this->tlmSize << "\n";
}

void QueuedTestGTestBase ::
  assertTlm_ChannelU32Format_size(
      const char* const __callSiteFileName,
      const U32 __callSiteLineNumber,
      const U32 size
  ) const
{
  ASSERT_EQ(this->tlmHistory_ChannelU32Format->size(), size)
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Size of history for telemetry channel ChannelU32Format\n"
    << "  Expected: " << size << "\n"
    << "  Actual:   " << this->tlmHistory_ChannelU32Format->size() << "\n";
}

void QueuedTestGTestBase ::
  assertTlm_ChannelU32Format(
      const char* const __callSiteFileName,
      const U32 __callSiteLineNumber,
      const U32 __index,
      const U32 val
  ) const
{
  ASSERT_LT(__index, this->tlmHistory_ChannelU32Format->size())
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Index into history of telemetry channel ChannelU32Format\n"
    << "  Expected: Less than size of history ("
    << this->tlmHistory_ChannelU32Format->size() << ")\n"
    << "  Actual:   " << __index << "\n";
  const TlmEntry_ChannelU32Format& _e =
    this->tlmHistory_ChannelU32Format->at(__index);
  ASSERT_EQ(val, _e.arg)
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Value at index "
    << __index
    << " on telemetry channel ChannelU32Format\n"
    << "  Expected: " << val << "\n"
    << "  Actual:   " << _e.arg << "\n";
}

void QueuedTestGTestBase ::
  assertTlm_ChannelF32Format_size(
      const char* const __callSiteFileName,
      const U32 __callSiteLineNumber,
      const U32 size
  ) const
{
  ASSERT_EQ(this->tlmHistory_ChannelF32Format->size(), size)
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Size of history for telemetry channel ChannelF32Format\n"
    << "  Expected: " << size << "\n"
    << "  Actual:   " << this->tlmHistory_ChannelF32Format->size() << "\n";
}

void QueuedTestGTestBase ::
  assertTlm_ChannelF32Format(
      const char* const __callSiteFileName,
      const U32 __callSiteLineNumber,
      const U32 __index,
      const F32 val
  ) const
{
  ASSERT_LT(__index, this->tlmHistory_ChannelF32Format->size())
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Index into history of telemetry channel ChannelF32Format\n"
    << "  Expected: Less than size of history ("
    << this->tlmHistory_ChannelF32Format->size() << ")\n"
    << "  Actual:   " << __index << "\n";
  const TlmEntry_ChannelF32Format& _e =
    this->tlmHistory_ChannelF32Format->at(__index);
  ASSERT_EQ(val, _e.arg)
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Value at index "
    << __index
    << " on telemetry channel ChannelF32Format\n"
    << "  Expected: " << val << "\n"
    << "  Actual:   " << _e.arg << "\n";
}

void QueuedTestGTestBase ::
  assertTlm_ChannelStringFormat_size(
      const char* const __callSiteFileName,
      const U32 __callSiteLineNumber,
      const U32 size
  ) const
{
  ASSERT_EQ(this->tlmHistory_ChannelStringFormat->size(), size)
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Size of history for telemetry channel ChannelStringFormat\n"
    << "  Expected: " << size << "\n"
    << "  Actual:   " << this->tlmHistory_ChannelStringFormat->size() << "\n";
}

void QueuedTestGTestBase ::
  assertTlm_ChannelStringFormat(
      const char* const __callSiteFileName,
      const U32 __callSiteLineNumber,
      const U32 __index,
      const char* const val
  ) const
{
  ASSERT_LT(__index, this->tlmHistory_ChannelStringFormat->size())
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Index into history of telemetry channel ChannelStringFormat\n"
    << "  Expected: Less than size of history ("
    << this->tlmHistory_ChannelStringFormat->size() << ")\n"
    << "  Actual:   " << __index << "\n";
  const TlmEntry_ChannelStringFormat& _e =
    this->tlmHistory_ChannelStringFormat->at(__index);
  ASSERT_STREQ(val, _e.arg.toChar())
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Value at index "
    << __index
    << " on telemetry channel ChannelStringFormat\n"
    << "  Expected: " << val << "\n"
    << "  Actual:   " << _e.arg << "\n";
}

void QueuedTestGTestBase ::
  assertTlm_ChannelEnum_size(
      const char* const __callSiteFileName,
      const U32 __callSiteLineNumber,
      const U32 size
  ) const
{
  ASSERT_EQ(this->tlmHistory_ChannelEnum->size(), size)
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Size of history for telemetry channel ChannelEnum\n"
    << "  Expected: " << size << "\n"
    << "  Actual:   " << this->tlmHistory_ChannelEnum->size() << "\n";
}

void QueuedTestGTestBase ::
  assertTlm_ChannelEnum(
      const char* const __callSiteFileName,
      const U32 __callSiteLineNumber,
      const U32 __index,
      const E& val
  ) const
{
  ASSERT_LT(__index, this->tlmHistory_ChannelEnum->size())
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Index into history of telemetry channel ChannelEnum\n"
    << "  Expected: Less than size of history ("
    << this->tlmHistory_ChannelEnum->size() << ")\n"
    << "  Actual:   " << __index << "\n";
  const TlmEntry_ChannelEnum& _e =
    this->tlmHistory_ChannelEnum->at(__index);
  ASSERT_EQ(val, _e.arg)
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Value at index "
    << __index
    << " on telemetry channel ChannelEnum\n"
    << "  Expected: " << val << "\n"
    << "  Actual:   " << _e.arg << "\n";
}

void QueuedTestGTestBase ::
  assertTlm_ChannelArrayFreq_size(
      const char* const __callSiteFileName,
      const U32 __callSiteLineNumber,
      const U32 size
  ) const
{
  ASSERT_EQ(this->tlmHistory_ChannelArrayFreq->size(), size)
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Size of history for telemetry channel ChannelArrayFreq\n"
    << "  Expected: " << size << "\n"
    << "  Actual:   " << this->tlmHistory_ChannelArrayFreq->size() << "\n";
}

void QueuedTestGTestBase ::
  assertTlm_ChannelArrayFreq(
      const char* const __callSiteFileName,
      const U32 __callSiteLineNumber,
      const U32 __index,
      const A& val
  ) const
{
  ASSERT_LT(__index, this->tlmHistory_ChannelArrayFreq->size())
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Index into history of telemetry channel ChannelArrayFreq\n"
    << "  Expected: Less than size of history ("
    << this->tlmHistory_ChannelArrayFreq->size() << ")\n"
    << "  Actual:   " << __index << "\n";
  const TlmEntry_ChannelArrayFreq& _e =
    this->tlmHistory_ChannelArrayFreq->at(__index);
  ASSERT_EQ(val, _e.arg)
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Value at index "
    << __index
    << " on telemetry channel ChannelArrayFreq\n"
    << "  Expected: " << val << "\n"
    << "  Actual:   " << _e.arg << "\n";
}

void QueuedTestGTestBase ::
  assertTlm_ChannelStructFreq_size(
      const char* const __callSiteFileName,
      const U32 __callSiteLineNumber,
      const U32 size
  ) const
{
  ASSERT_EQ(this->tlmHistory_ChannelStructFreq->size(), size)
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Size of history for telemetry channel ChannelStructFreq\n"
    << "  Expected: " << size << "\n"
    << "  Actual:   " << this->tlmHistory_ChannelStructFreq->size() << "\n";
}

void QueuedTestGTestBase ::
  assertTlm_ChannelStructFreq(
      const char* const __callSiteFileName,
      const U32 __callSiteLineNumber,
      const U32 __index,
      const S& val
  ) const
{
  ASSERT_LT(__index, this->tlmHistory_ChannelStructFreq->size())
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Index into history of telemetry channel ChannelStructFreq\n"
    << "  Expected: Less than size of history ("
    << this->tlmHistory_ChannelStructFreq->size() << ")\n"
    << "  Actual:   " << __index << "\n";
  const TlmEntry_ChannelStructFreq& _e =
    this->tlmHistory_ChannelStructFreq->at(__index);
  ASSERT_EQ(val, _e.arg)
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Value at index "
    << __index
    << " on telemetry channel ChannelStructFreq\n"
    << "  Expected: " << val << "\n"
    << "  Actual:   " << _e.arg << "\n";
}

void QueuedTestGTestBase ::
  assertTlm_ChannelU32Limits_size(
      const char* const __callSiteFileName,
      const U32 __callSiteLineNumber,
      const U32 size
  ) const
{
  ASSERT_EQ(this->tlmHistory_ChannelU32Limits->size(), size)
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Size of history for telemetry channel ChannelU32Limits\n"
    << "  Expected: " << size << "\n"
    << "  Actual:   " << this->tlmHistory_ChannelU32Limits->size() << "\n";
}

void QueuedTestGTestBase ::
  assertTlm_ChannelU32Limits(
      const char* const __callSiteFileName,
      const U32 __callSiteLineNumber,
      const U32 __index,
      const U32 val
  ) const
{
  ASSERT_LT(__index, this->tlmHistory_ChannelU32Limits->size())
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Index into history of telemetry channel ChannelU32Limits\n"
    << "  Expected: Less than size of history ("
    << this->tlmHistory_ChannelU32Limits->size() << ")\n"
    << "  Actual:   " << __index << "\n";
  const TlmEntry_ChannelU32Limits& _e =
    this->tlmHistory_ChannelU32Limits->at(__index);
  ASSERT_EQ(val, _e.arg)
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Value at index "
    << __index
    << " on telemetry channel ChannelU32Limits\n"
    << "  Expected: " << val << "\n"
    << "  Actual:   " << _e.arg << "\n";
}

void QueuedTestGTestBase ::
  assertTlm_ChannelF32Limits_size(
      const char* const __callSiteFileName,
      const U32 __callSiteLineNumber,
      const U32 size
  ) const
{
  ASSERT_EQ(this->tlmHistory_ChannelF32Limits->size(), size)
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Size of history for telemetry channel ChannelF32Limits\n"
    << "  Expected: " << size << "\n"
    << "  Actual:   " << this->tlmHistory_ChannelF32Limits->size() << "\n";
}

void QueuedTestGTestBase ::
  assertTlm_ChannelF32Limits(
      const char* const __callSiteFileName,
      const U32 __callSiteLineNumber,
      const U32 __index,
      const F32 val
  ) const
{
  ASSERT_LT(__index, this->tlmHistory_ChannelF32Limits->size())
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Index into history of telemetry channel ChannelF32Limits\n"
    << "  Expected: Less than size of history ("
    << this->tlmHistory_ChannelF32Limits->size() << ")\n"
    << "  Actual:   " << __index << "\n";
  const TlmEntry_ChannelF32Limits& _e =
    this->tlmHistory_ChannelF32Limits->at(__index);
  ASSERT_EQ(val, _e.arg)
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Value at index "
    << __index
    << " on telemetry channel ChannelF32Limits\n"
    << "  Expected: " << val << "\n"
    << "  Actual:   " << _e.arg << "\n";
}

void QueuedTestGTestBase ::
  assertTlm_ChannelF64_size(
      const char* const __callSiteFileName,
      const U32 __callSiteLineNumber,
      const U32 size
  ) const
{
  ASSERT_EQ(this->tlmHistory_ChannelF64->size(), size)
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Size of history for telemetry channel ChannelF64\n"
    << "  Expected: " << size << "\n"
    << "  Actual:   " << this->tlmHistory_ChannelF64->size() << "\n";
}

void QueuedTestGTestBase ::
  assertTlm_ChannelF64(
      const char* const __callSiteFileName,
      const U32 __callSiteLineNumber,
      const U32 __index,
      const F64 val
  ) const
{
  ASSERT_LT(__index, this->tlmHistory_ChannelF64->size())
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Index into history of telemetry channel ChannelF64\n"
    << "  Expected: Less than size of history ("
    << this->tlmHistory_ChannelF64->size() << ")\n"
    << "  Actual:   " << __index << "\n";
  const TlmEntry_ChannelF64& _e =
    this->tlmHistory_ChannelF64->at(__index);
  ASSERT_EQ(val, _e.arg)
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Value at index "
    << __index
    << " on telemetry channel ChannelF64\n"
    << "  Expected: " << val << "\n"
    << "  Actual:   " << _e.arg << "\n";
}

void QueuedTestGTestBase ::
  assertTlm_ChannelU32OnChange_size(
      const char* const __callSiteFileName,
      const U32 __callSiteLineNumber,
      const U32 size
  ) const
{
  ASSERT_EQ(this->tlmHistory_ChannelU32OnChange->size(), size)
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Size of history for telemetry channel ChannelU32OnChange\n"
    << "  Expected: " << size << "\n"
    << "  Actual:   " << this->tlmHistory_ChannelU32OnChange->size() << "\n";
}

void QueuedTestGTestBase ::
  assertTlm_ChannelU32OnChange(
      const char* const __callSiteFileName,
      const U32 __callSiteLineNumber,
      const U32 __index,
      const U32 val
  ) const
{
  ASSERT_LT(__index, this->tlmHistory_ChannelU32OnChange->size())
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Index into history of telemetry channel ChannelU32OnChange\n"
    << "  Expected: Less than size of history ("
    << this->tlmHistory_ChannelU32OnChange->size() << ")\n"
    << "  Actual:   " << __index << "\n";
  const TlmEntry_ChannelU32OnChange& _e =
    this->tlmHistory_ChannelU32OnChange->at(__index);
  ASSERT_EQ(val, _e.arg)
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Value at index "
    << __index
    << " on telemetry channel ChannelU32OnChange\n"
    << "  Expected: " << val << "\n"
    << "  Actual:   " << _e.arg << "\n";
}

void QueuedTestGTestBase ::
  assertTlm_ChannelEnumOnChange_size(
      const char* const __callSiteFileName,
      const U32 __callSiteLineNumber,
      const U32 size
  ) const
{
  ASSERT_EQ(this->tlmHistory_ChannelEnumOnChange->size(), size)
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Size of history for telemetry channel ChannelEnumOnChange\n"
    << "  Expected: " << size << "\n"
    << "  Actual:   " << this->tlmHistory_ChannelEnumOnChange->size() << "\n";
}

void QueuedTestGTestBase ::
  assertTlm_ChannelEnumOnChange(
      const char* const __callSiteFileName,
      const U32 __callSiteLineNumber,
      const U32 __index,
      const E& val
  ) const
{
  ASSERT_LT(__index, this->tlmHistory_ChannelEnumOnChange->size())
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Index into history of telemetry channel ChannelEnumOnChange\n"
    << "  Expected: Less than size of history ("
    << this->tlmHistory_ChannelEnumOnChange->size() << ")\n"
    << "  Actual:   " << __index << "\n";
  const TlmEntry_ChannelEnumOnChange& _e =
    this->tlmHistory_ChannelEnumOnChange->at(__index);
  ASSERT_EQ(val, _e.arg)
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Value at index "
    << __index
    << " on telemetry channel ChannelEnumOnChange\n"
    << "  Expected: " << val << "\n"
    << "  Actual:   " << _e.arg << "\n";
}

// ----------------------------------------------------------------------
// Data Product Request
// ----------------------------------------------------------------------

void QueuedTestGTestBase ::
  assertProductRequest_size(
      const char* const __callSiteFileName,
      const U32 __callSiteLineNumber,
      const U32 size
  ) const
{
  ASSERT_EQ(size, this->productRequestHistory->size())
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Size of product request history\n"
    << "  Expected: " << size << "\n"
    << "  Actual:   " << this->productRequestHistory->size() << "\n";
}

void QueuedTestGTestBase ::
  assertProductRequest(
      const char* const __callSiteFileName,
      const U32 __callSiteLineNumber,
      const U32 __index,
      FwDpIdType id,
      FwSizeType size
  ) const
{
  ASSERT_LT(__index, this->productRequestHistory->size())
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Index into product request history\n"
    << "  Expected: Less than size of product request history ("
    << this->productRequestHistory->size() << ")\n"
    << "  Actual:   " << __index << "\n";
  const DpRequest& e = this->productRequestHistory->at(__index);
  ASSERT_EQ(id, e.id)
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Id at index "
    << __index
    << " in product request history\n"
    << "  Expected: " << id << "\n"
    << "  Actual:   " << e.id << "\n";
  ASSERT_EQ(size, e.size)
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Size at index "
    << __index
    << " in product request history\n"
    << "  Expected: " << size << "\n"
    << "  Actual:   " << e.size << "\n";
}

// ----------------------------------------------------------------------
// Data Product Send
// ----------------------------------------------------------------------

void QueuedTestGTestBase ::
  assertProductSend_size(
      const char* const __callSiteFileName,
      const U32 __callSiteLineNumber,
      const U32 size
  ) const
{
  ASSERT_EQ(size, this->productSendHistory->size())
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Size of product send history\n"
    << "  Expected: " << size << "\n"
    << "  Actual:   " << this->productSendHistory->size() << "\n";
}

void QueuedTestGTestBase ::
  assertProductSend(
      const char* const __callSiteFileName,
      const U32 __callSiteLineNumber,
      const U32 __index,
      FwDpIdType id,
      FwDpPriorityType priority,
      const Fw::Time& timeTag,
      Fw::DpCfg::ProcType::SerialType procTypes,
      const Fw::DpContainer::Header::UserData& userData,
      Fw::DpState dpState,
      FwSizeType dataSize,
      Fw::Buffer& historyBuffer
  ) const
{
  ASSERT_LT(__index, this->productSendHistory->size())
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Index into product send history\n"
    << "  Expected: Less than size of product send history ("
    << this->productSendHistory->size() << ")\n"
    << "  Actual:   " << __index << "\n";
  const DpSend& e = this->productSendHistory->at(__index);
  // Set the history buffer output
  historyBuffer = e.buffer;
  // Check the container id
  ASSERT_EQ(e.id, id)
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Container ID at index " << __index << " in product send history\n"
    << "  Expected: " << id << "\n"
    << "  Actual:   " << e.id << "\n";
  // Check the header
  Fw::TestUtil::DpContainerHeader header;
  header.deserialize(__callSiteFileName, __callSiteLineNumber, historyBuffer);
  header.check(
      __callSiteFileName,
      __callSiteLineNumber,
      historyBuffer,
      id,
      priority,
      timeTag,
      procTypes,
      userData,
      dpState,
      dataSize
  );
}
