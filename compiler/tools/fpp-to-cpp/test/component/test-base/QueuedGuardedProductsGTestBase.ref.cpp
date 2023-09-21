// ======================================================================
// \title  QueuedGuardedProductsGTestBase.cpp
// \author Generated by fpp-to-cpp
// \brief  cpp file for QueuedGuardedProducts component Google Test harness base class
// ======================================================================

#include "test-base/QueuedGuardedProductsGTestBase.hpp"

// ----------------------------------------------------------------------
// Construction and destruction
// ----------------------------------------------------------------------

QueuedGuardedProductsGTestBase ::
  QueuedGuardedProductsGTestBase(
      const char* const compName,
      const U32 maxHistorySize
  ) :
    QueuedGuardedProductsTesterBase(compName, maxHistorySize)
{

}

QueuedGuardedProductsGTestBase ::
  ~QueuedGuardedProductsGTestBase()
{

}

// ----------------------------------------------------------------------
// From ports
// ----------------------------------------------------------------------

void QueuedGuardedProductsGTestBase ::
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

void QueuedGuardedProductsGTestBase ::
  assert_from_typedOut(
      const char* const __callSiteFileName,
      const U32 __callSiteLineNumber,
      const U32 size
  ) const
{
  ASSERT_EQ(size, this->fromPortHistory_typedOut->size())
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Size of history for from_typedOut\n"
    << "  Expected: " << size << "\n"
    << "  Actual:   " << this->fromPortHistory_typedOut->size() << "\n";
}

void QueuedGuardedProductsGTestBase ::
  assert_from_typedReturnOut(
      const char* const __callSiteFileName,
      const U32 __callSiteLineNumber,
      const U32 size
  ) const
{
  ASSERT_EQ(size, this->fromPortHistory_typedOut->size())
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Size of history for from_typedOut\n"
    << "  Expected: " << size << "\n"
    << "  Actual:   " << this->fromPortHistory_typedReturnOut->size() << "\n";
}

// ----------------------------------------------------------------------
// Data Product Request
// ----------------------------------------------------------------------

void QueuedGuardedProductsGTestBase ::
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

void QueuedGuardedProductsGTestBase ::
  assertCmdResponse(
      const char* const __callSiteFileName,
      const U32 __callSiteLineNumber,
      const U32 __index,
      FwOpcodeType opCode,
      U32 cmdSeq,
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

void QueuedGuardedProductsGTestBase ::
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

void QueuedGuardedProductsGTestBase ::
  assertCmdResponse(
      const char* const __callSiteFileName,
      const U32 __callSiteLineNumber,
      const U32 __index,
      FwOpcodeType opCode,
      U32 cmdSeq,
      FwDpIdType id,
      Fw::Buffer buffer
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
  ASSERT_EQ(id, e.id)
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Id at index "
    << __index
    << " in product send history\n"
    << "  Expected: " << id << "\n"
    << "  Actual:   " << e.id << "\n";
  ASSERT_EQ(buffer, e.buffer)
    << "\n"
    << __callSiteFileName << ":" << __callSiteLineNumber << "\n"
    << "  Value:    Size at index "
    << __index
    << " in product send history\n"
    << "  Expected: " << buffer << "\n"
    << "  Actual:   " << e.buffer << "\n";
}
