// ======================================================================
// \title  ActiveParamsTesterBase.hpp
// \author Generated by fpp-to-cpp
// \brief  hpp file for ActiveParams component test harness base class
// ======================================================================

#ifndef ActiveParamsTesterBase_HPP
#define ActiveParamsTesterBase_HPP

#include <cstdio>

#include "Fw/Comp/PassiveComponentBase.hpp"
#include "Fw/Port/InputSerializePort.hpp"
#include "Fw/Types/Assert.hpp"
#include "test-base/ActiveParamsComponentAc.hpp"

//! \class ActiveParamsTesterBase
//! \brief Auto-generated base for ActiveParams component test harness
class ActiveParamsTesterBase :
  public Fw::PassiveComponentBase
{

  protected:

    // ----------------------------------------------------------------------
    // History class
    // ----------------------------------------------------------------------

    //! \class History
    //! \brief A history of port inputs
    //!
    template<typename T>
    class History
    {

      public:

        //! Create a History
        History(
           const U32 maxSize //!< The maximum history size
        ) :
          numEntries(0),
          maxSize(maxSize)
        {
          this->entries = new T[maxSize];
        }

        //! Destroy a History
        ~History()
        {
          delete[] this->entries;
        }

        //! Clear the history
        //!
        void clear()
        {
          this->numEntries = 0;
        }

        //! Push an item onto the history
        //!
        void push_back(
            T entry //!< The item
        )
        {
          FW_ASSERT(this->numEntries < this->maxSize);
          entries[this->numEntries++] = entry;
        }

        //! Get an item at an index
        //!
        //! \return The item at index i
        T at(
            const U32 i //!< The index
        ) const
        {
          FW_ASSERT(i < this->numEntries);
          return entries[i];
        }

        //! Get the number of entries in the history
        //!
        //! \return The number of entries in the history
        U32 size() const
        {
          return this->numEntries;
        }

      private:

        //! The number of entries in the history
        U32 numEntries;

        //! The maximum history size
        const U32 maxSize;

        //! The entries
        T* entries;

    };

  protected:

    // ----------------------------------------------------------------------
    // History types
    // ----------------------------------------------------------------------

    //! A history entry for port from_typedOut
    struct FromPortEntry_typedOut {
      U32 u32;
      F32 f32;
      bool b;
      TypedPortStrings::StringSize80 str1;
      E e;
      A a;
      S s;
    };

    //! A history entry for port from_typedReturnOut
    struct FromPortEntry_typedReturnOut {
      U32 u32;
      F32 f32;
      bool b;
      TypedReturnPortStrings::StringSize80 str2;
      E e;
      A a;
      S s;
    };

    //! A type representing a command response
    struct CmdResponse {
      FwOpcodeType opCode;
      U32 cmdSeq;
      Fw::CmdResponse response;
    };

  public:

    // ----------------------------------------------------------------------
    // Component initialization
    // ----------------------------------------------------------------------

    //! Initialize object ActiveParamsTesterBase
    virtual void init(
        NATIVE_INT_TYPE instance = 0 //!< The instance number
    );

  public:

    // ----------------------------------------------------------------------
    // Connectors for to ports
    // ----------------------------------------------------------------------

    //! Connect port to cmdIn[portNum]
    void connect_to_cmdIn(
        NATIVE_INT_TYPE portNum, //!< The port number
        Fw::InputCmdPort* port //!< The input port
    );

    //! Connect port to noArgsAsync[portNum]
    void connect_to_noArgsAsync(
        NATIVE_INT_TYPE portNum, //!< The port number
        InputNoArgsPort* port //!< The input port
    );

    //! Connect port to noArgsGuarded[portNum]
    void connect_to_noArgsGuarded(
        NATIVE_INT_TYPE portNum, //!< The port number
        InputNoArgsPort* port //!< The input port
    );

    //! Connect port to noArgsReturnGuarded[portNum]
    void connect_to_noArgsReturnGuarded(
        NATIVE_INT_TYPE portNum, //!< The port number
        InputNoArgsReturnPort* port //!< The input port
    );

    //! Connect port to noArgsReturnSync[portNum]
    void connect_to_noArgsReturnSync(
        NATIVE_INT_TYPE portNum, //!< The port number
        InputNoArgsReturnPort* port //!< The input port
    );

    //! Connect port to noArgsSync[portNum]
    void connect_to_noArgsSync(
        NATIVE_INT_TYPE portNum, //!< The port number
        InputNoArgsPort* port //!< The input port
    );

    //! Connect port to typedAsync[portNum]
    void connect_to_typedAsync(
        NATIVE_INT_TYPE portNum, //!< The port number
        InputTypedPort* port //!< The input port
    );

    //! Connect port to typedAsyncAssert[portNum]
    void connect_to_typedAsyncAssert(
        NATIVE_INT_TYPE portNum, //!< The port number
        InputTypedPort* port //!< The input port
    );

    //! Connect port to typedAsyncBlockPriority[portNum]
    void connect_to_typedAsyncBlockPriority(
        NATIVE_INT_TYPE portNum, //!< The port number
        InputTypedPort* port //!< The input port
    );

    //! Connect port to typedAsyncDropPriority[portNum]
    void connect_to_typedAsyncDropPriority(
        NATIVE_INT_TYPE portNum, //!< The port number
        InputTypedPort* port //!< The input port
    );

    //! Connect port to typedGuarded[portNum]
    void connect_to_typedGuarded(
        NATIVE_INT_TYPE portNum, //!< The port number
        InputTypedPort* port //!< The input port
    );

    //! Connect port to typedReturnGuarded[portNum]
    void connect_to_typedReturnGuarded(
        NATIVE_INT_TYPE portNum, //!< The port number
        InputTypedReturnPort* port //!< The input port
    );

    //! Connect port to typedReturnSync[portNum]
    void connect_to_typedReturnSync(
        NATIVE_INT_TYPE portNum, //!< The port number
        InputTypedReturnPort* port //!< The input port
    );

    //! Connect port to typedSync[portNum]
    void connect_to_typedSync(
        NATIVE_INT_TYPE portNum, //!< The port number
        InputTypedPort* port //!< The input port
    );

  public:

    // ----------------------------------------------------------------------
    // Getters for from ports
    // ----------------------------------------------------------------------

    //! Get from port at index
    //!
    //! \return from_cmdRegOut[portNum]
    Fw::InputCmdRegPort* get_from_cmdRegOut(
        NATIVE_INT_TYPE portNum //!< The port number
    );

    //! Get from port at index
    //!
    //! \return from_cmdResponseOut[portNum]
    Fw::InputCmdResponsePort* get_from_cmdResponseOut(
        NATIVE_INT_TYPE portNum //!< The port number
    );

    //! Get from port at index
    //!
    //! \return from_eventOut[portNum]
    Fw::InputLogPort* get_from_eventOut(
        NATIVE_INT_TYPE portNum //!< The port number
    );

    //! Get from port at index
    //!
    //! \return from_prmGetOut[portNum]
    Fw::InputPrmGetPort* get_from_prmGetOut(
        NATIVE_INT_TYPE portNum //!< The port number
    );

    //! Get from port at index
    //!
    //! \return from_prmSetOut[portNum]
    Fw::InputPrmSetPort* get_from_prmSetOut(
        NATIVE_INT_TYPE portNum //!< The port number
    );

#if FW_ENABLE_TEXT_LOGGING == 1

    //! Get from port at index
    //!
    //! \return from_textEventOut[portNum]
    Fw::InputLogTextPort* get_from_textEventOut(
        NATIVE_INT_TYPE portNum //!< The port number
    );

#endif

    //! Get from port at index
    //!
    //! \return from_timeGetOut[portNum]
    Fw::InputTimePort* get_from_timeGetOut(
        NATIVE_INT_TYPE portNum //!< The port number
    );

    //! Get from port at index
    //!
    //! \return from_tlmOut[portNum]
    Fw::InputTlmPort* get_from_tlmOut(
        NATIVE_INT_TYPE portNum //!< The port number
    );

    //! Get from port at index
    //!
    //! \return from_typedOut[portNum]
    InputTypedPort* get_from_typedOut(
        NATIVE_INT_TYPE portNum //!< The port number
    );

    //! Get from port at index
    //!
    //! \return from_typedReturnOut[portNum]
    InputTypedReturnPort* get_from_typedReturnOut(
        NATIVE_INT_TYPE portNum //!< The port number
    );

  protected:

    // ----------------------------------------------------------------------
    // Component construction and destruction
    // ----------------------------------------------------------------------

    //! Construct object ActiveParamsTesterBase
    ActiveParamsTesterBase(
        const char* const compName, //!< The component name
        const U32 maxHistorySize //!< The maximum size of each history
    );

    //! Destroy object ActiveParamsTesterBase
    virtual ~ActiveParamsTesterBase();

  protected:

    // ----------------------------------------------------------------------
    // Handlers to implement for from ports
    // ----------------------------------------------------------------------

    //! Handler for input port from_typedOut
    virtual void from_typedOut_handler(
        NATIVE_INT_TYPE portNum, //!< The port number
        U32 u32, //!< A U32
        F32 f32, //!< An F32
        bool b, //!< A boolean
        const TypedPortStrings::StringSize80& str1, //!< A string
        const E& e, //!< An enum
        const A& a, //!< An array
        const S& s //!< A struct
    ) = 0;

    //! Handler for input port from_typedReturnOut
    virtual F32 from_typedReturnOut_handler(
        NATIVE_INT_TYPE portNum, //!< The port number
        U32 u32, //!< A U32
        F32 f32, //!< An F32
        bool b, //!< A boolean
        const TypedReturnPortStrings::StringSize80& str2, //!< A string
        const E& e, //!< An enum
        const A& a, //!< An array
        const S& s //!< A struct
    ) = 0;

  protected:

    // ----------------------------------------------------------------------
    // Handler base-class functions for from ports
    // ----------------------------------------------------------------------

    //! Handler base-class function for from_typedOut
    void from_typedOut_handlerBase(
        NATIVE_INT_TYPE portNum, //!< The port number
        U32 u32, //!< A U32
        F32 f32, //!< An F32
        bool b, //!< A boolean
        const TypedPortStrings::StringSize80& str1, //!< A string
        const E& e, //!< An enum
        const A& a, //!< An array
        const S& s //!< A struct
    );

    //! Handler base-class function for from_typedReturnOut
    F32 from_typedReturnOut_handlerBase(
        NATIVE_INT_TYPE portNum, //!< The port number
        U32 u32, //!< A U32
        F32 f32, //!< An F32
        bool b, //!< A boolean
        const TypedReturnPortStrings::StringSize80& str2, //!< A string
        const E& e, //!< An enum
        const A& a, //!< An array
        const S& s //!< A struct
    );

  protected:

    // ----------------------------------------------------------------------
    // Invocation functions for to ports
    // ----------------------------------------------------------------------

    //! Invoke the to port connected to noArgsAsync
    void invoke_to_noArgsAsync(
        NATIVE_INT_TYPE portNum //!< The port number
    );

    //! Invoke the to port connected to noArgsGuarded
    void invoke_to_noArgsGuarded(
        NATIVE_INT_TYPE portNum //!< The port number
    );

    //! Invoke the to port connected to noArgsReturnGuarded
    U32 invoke_to_noArgsReturnGuarded(
        NATIVE_INT_TYPE portNum //!< The port number
    );

    //! Invoke the to port connected to noArgsReturnSync
    U32 invoke_to_noArgsReturnSync(
        NATIVE_INT_TYPE portNum //!< The port number
    );

    //! Invoke the to port connected to noArgsSync
    void invoke_to_noArgsSync(
        NATIVE_INT_TYPE portNum //!< The port number
    );

    //! Invoke the to port connected to typedAsync
    void invoke_to_typedAsync(
        NATIVE_INT_TYPE portNum, //!< The port number
        U32 u32, //!< A U32
        F32 f32, //!< An F32
        bool b, //!< A boolean
        const TypedPortStrings::StringSize80& str1, //!< A string
        const E& e, //!< An enum
        const A& a, //!< An array
        const S& s //!< A struct
    );

    //! Invoke the to port connected to typedAsyncAssert
    void invoke_to_typedAsyncAssert(
        NATIVE_INT_TYPE portNum, //!< The port number
        U32 u32, //!< A U32
        F32 f32, //!< An F32
        bool b, //!< A boolean
        const TypedPortStrings::StringSize80& str1, //!< A string
        const E& e, //!< An enum
        const A& a, //!< An array
        const S& s //!< A struct
    );

    //! Invoke the to port connected to typedAsyncBlockPriority
    void invoke_to_typedAsyncBlockPriority(
        NATIVE_INT_TYPE portNum, //!< The port number
        U32 u32, //!< A U32
        F32 f32, //!< An F32
        bool b, //!< A boolean
        const TypedPortStrings::StringSize80& str1, //!< A string
        const E& e, //!< An enum
        const A& a, //!< An array
        const S& s //!< A struct
    );

    //! Invoke the to port connected to typedAsyncDropPriority
    void invoke_to_typedAsyncDropPriority(
        NATIVE_INT_TYPE portNum, //!< The port number
        U32 u32, //!< A U32
        F32 f32, //!< An F32
        bool b, //!< A boolean
        const TypedPortStrings::StringSize80& str1, //!< A string
        const E& e, //!< An enum
        const A& a, //!< An array
        const S& s //!< A struct
    );

    //! Invoke the to port connected to typedGuarded
    void invoke_to_typedGuarded(
        NATIVE_INT_TYPE portNum, //!< The port number
        U32 u32, //!< A U32
        F32 f32, //!< An F32
        bool b, //!< A boolean
        const TypedPortStrings::StringSize80& str1, //!< A string
        const E& e, //!< An enum
        const A& a, //!< An array
        const S& s //!< A struct
    );

    //! Invoke the to port connected to typedReturnGuarded
    F32 invoke_to_typedReturnGuarded(
        NATIVE_INT_TYPE portNum, //!< The port number
        U32 u32, //!< A U32
        F32 f32, //!< An F32
        bool b, //!< A boolean
        const TypedReturnPortStrings::StringSize80& str2, //!< A string
        const E& e, //!< An enum
        const A& a, //!< An array
        const S& s //!< A struct
    );

    //! Invoke the to port connected to typedReturnSync
    F32 invoke_to_typedReturnSync(
        NATIVE_INT_TYPE portNum, //!< The port number
        U32 u32, //!< A U32
        F32 f32, //!< An F32
        bool b, //!< A boolean
        const TypedReturnPortStrings::StringSize80& str2, //!< A string
        const E& e, //!< An enum
        const A& a, //!< An array
        const S& s //!< A struct
    );

    //! Invoke the to port connected to typedSync
    void invoke_to_typedSync(
        NATIVE_INT_TYPE portNum, //!< The port number
        U32 u32, //!< A U32
        F32 f32, //!< An F32
        bool b, //!< A boolean
        const TypedPortStrings::StringSize80& str1, //!< A string
        const E& e, //!< An enum
        const A& a, //!< An array
        const S& s //!< A struct
    );

  protected:

    // ----------------------------------------------------------------------
    // Getters for port counts
    // ----------------------------------------------------------------------

    //! Get the number of to_cmdIn ports
    //!
    //! \return The number of to_cmdIn ports
    NATIVE_INT_TYPE getNum_to_cmdIn() const;

    //! Get the number of to_noArgsAsync ports
    //!
    //! \return The number of to_noArgsAsync ports
    NATIVE_INT_TYPE getNum_to_noArgsAsync() const;

    //! Get the number of to_noArgsGuarded ports
    //!
    //! \return The number of to_noArgsGuarded ports
    NATIVE_INT_TYPE getNum_to_noArgsGuarded() const;

    //! Get the number of to_noArgsReturnGuarded ports
    //!
    //! \return The number of to_noArgsReturnGuarded ports
    NATIVE_INT_TYPE getNum_to_noArgsReturnGuarded() const;

    //! Get the number of to_noArgsReturnSync ports
    //!
    //! \return The number of to_noArgsReturnSync ports
    NATIVE_INT_TYPE getNum_to_noArgsReturnSync() const;

    //! Get the number of to_noArgsSync ports
    //!
    //! \return The number of to_noArgsSync ports
    NATIVE_INT_TYPE getNum_to_noArgsSync() const;

    //! Get the number of to_typedAsync ports
    //!
    //! \return The number of to_typedAsync ports
    NATIVE_INT_TYPE getNum_to_typedAsync() const;

    //! Get the number of to_typedAsyncAssert ports
    //!
    //! \return The number of to_typedAsyncAssert ports
    NATIVE_INT_TYPE getNum_to_typedAsyncAssert() const;

    //! Get the number of to_typedAsyncBlockPriority ports
    //!
    //! \return The number of to_typedAsyncBlockPriority ports
    NATIVE_INT_TYPE getNum_to_typedAsyncBlockPriority() const;

    //! Get the number of to_typedAsyncDropPriority ports
    //!
    //! \return The number of to_typedAsyncDropPriority ports
    NATIVE_INT_TYPE getNum_to_typedAsyncDropPriority() const;

    //! Get the number of to_typedGuarded ports
    //!
    //! \return The number of to_typedGuarded ports
    NATIVE_INT_TYPE getNum_to_typedGuarded() const;

    //! Get the number of to_typedReturnGuarded ports
    //!
    //! \return The number of to_typedReturnGuarded ports
    NATIVE_INT_TYPE getNum_to_typedReturnGuarded() const;

    //! Get the number of to_typedReturnSync ports
    //!
    //! \return The number of to_typedReturnSync ports
    NATIVE_INT_TYPE getNum_to_typedReturnSync() const;

    //! Get the number of to_typedSync ports
    //!
    //! \return The number of to_typedSync ports
    NATIVE_INT_TYPE getNum_to_typedSync() const;

    //! Get the number of from_cmdRegOut ports
    //!
    //! \return The number of from_cmdRegOut ports
    NATIVE_INT_TYPE getNum_from_cmdRegOut() const;

    //! Get the number of from_cmdResponseOut ports
    //!
    //! \return The number of from_cmdResponseOut ports
    NATIVE_INT_TYPE getNum_from_cmdResponseOut() const;

    //! Get the number of from_eventOut ports
    //!
    //! \return The number of from_eventOut ports
    NATIVE_INT_TYPE getNum_from_eventOut() const;

    //! Get the number of from_prmGetOut ports
    //!
    //! \return The number of from_prmGetOut ports
    NATIVE_INT_TYPE getNum_from_prmGetOut() const;

    //! Get the number of from_prmSetOut ports
    //!
    //! \return The number of from_prmSetOut ports
    NATIVE_INT_TYPE getNum_from_prmSetOut() const;

#if FW_ENABLE_TEXT_LOGGING == 1

    //! Get the number of from_textEventOut ports
    //!
    //! \return The number of from_textEventOut ports
    NATIVE_INT_TYPE getNum_from_textEventOut() const;

#endif

    //! Get the number of from_timeGetOut ports
    //!
    //! \return The number of from_timeGetOut ports
    NATIVE_INT_TYPE getNum_from_timeGetOut() const;

    //! Get the number of from_tlmOut ports
    //!
    //! \return The number of from_tlmOut ports
    NATIVE_INT_TYPE getNum_from_tlmOut() const;

    //! Get the number of from_typedOut ports
    //!
    //! \return The number of from_typedOut ports
    NATIVE_INT_TYPE getNum_from_typedOut() const;

    //! Get the number of from_typedReturnOut ports
    //!
    //! \return The number of from_typedReturnOut ports
    NATIVE_INT_TYPE getNum_from_typedReturnOut() const;

  protected:

    // ----------------------------------------------------------------------
    // Connection status queries for to ports
    // ----------------------------------------------------------------------

    //! Check whether port to_cmdIn is connected
    //!
    //! \return Whether port to_cmdIn is connected
    bool isConnected_to_cmdIn(
        NATIVE_INT_TYPE portNum //!< The port number
    );

    //! Check whether port to_noArgsAsync is connected
    //!
    //! \return Whether port to_noArgsAsync is connected
    bool isConnected_to_noArgsAsync(
        NATIVE_INT_TYPE portNum //!< The port number
    );

    //! Check whether port to_noArgsGuarded is connected
    //!
    //! \return Whether port to_noArgsGuarded is connected
    bool isConnected_to_noArgsGuarded(
        NATIVE_INT_TYPE portNum //!< The port number
    );

    //! Check whether port to_noArgsReturnGuarded is connected
    //!
    //! \return Whether port to_noArgsReturnGuarded is connected
    bool isConnected_to_noArgsReturnGuarded(
        NATIVE_INT_TYPE portNum //!< The port number
    );

    //! Check whether port to_noArgsReturnSync is connected
    //!
    //! \return Whether port to_noArgsReturnSync is connected
    bool isConnected_to_noArgsReturnSync(
        NATIVE_INT_TYPE portNum //!< The port number
    );

    //! Check whether port to_noArgsSync is connected
    //!
    //! \return Whether port to_noArgsSync is connected
    bool isConnected_to_noArgsSync(
        NATIVE_INT_TYPE portNum //!< The port number
    );

    //! Check whether port to_typedAsync is connected
    //!
    //! \return Whether port to_typedAsync is connected
    bool isConnected_to_typedAsync(
        NATIVE_INT_TYPE portNum //!< The port number
    );

    //! Check whether port to_typedAsyncAssert is connected
    //!
    //! \return Whether port to_typedAsyncAssert is connected
    bool isConnected_to_typedAsyncAssert(
        NATIVE_INT_TYPE portNum //!< The port number
    );

    //! Check whether port to_typedAsyncBlockPriority is connected
    //!
    //! \return Whether port to_typedAsyncBlockPriority is connected
    bool isConnected_to_typedAsyncBlockPriority(
        NATIVE_INT_TYPE portNum //!< The port number
    );

    //! Check whether port to_typedAsyncDropPriority is connected
    //!
    //! \return Whether port to_typedAsyncDropPriority is connected
    bool isConnected_to_typedAsyncDropPriority(
        NATIVE_INT_TYPE portNum //!< The port number
    );

    //! Check whether port to_typedGuarded is connected
    //!
    //! \return Whether port to_typedGuarded is connected
    bool isConnected_to_typedGuarded(
        NATIVE_INT_TYPE portNum //!< The port number
    );

    //! Check whether port to_typedReturnGuarded is connected
    //!
    //! \return Whether port to_typedReturnGuarded is connected
    bool isConnected_to_typedReturnGuarded(
        NATIVE_INT_TYPE portNum //!< The port number
    );

    //! Check whether port to_typedReturnSync is connected
    //!
    //! \return Whether port to_typedReturnSync is connected
    bool isConnected_to_typedReturnSync(
        NATIVE_INT_TYPE portNum //!< The port number
    );

    //! Check whether port to_typedSync is connected
    //!
    //! \return Whether port to_typedSync is connected
    bool isConnected_to_typedSync(
        NATIVE_INT_TYPE portNum //!< The port number
    );

  protected:

    // ----------------------------------------------------------------------
    // Functions for testing commands
    // ----------------------------------------------------------------------

    //! Handle a command response
    virtual void cmdResponseIn(
        FwOpcodeType opCode, //!< The opcode
        U32 cmdSeq, //!< The command sequence number
        Fw::CmdResponse response //!< The command response
    );

    //! Send command buffers directly (used for intentional command encoding errors)
    void sendRawCmd(
        FwOpcodeType opCode, //!< The opcode
        U32 cmdSeq, //!< The command sequence number
        Fw::CmdArgBuffer& buf //!< The command argument buffer
    );

  protected:

    // ----------------------------------------------------------------------
    // Functions to test parameters
    // ----------------------------------------------------------------------

    //! Set parameter ParamU32
    void paramSet_ParamU32(
        const U32& val, //!< The parameter value
        Fw::ParamValid valid //!< The parameter valid flag
    );

    //! Send parameter ParamU32
    void paramSend_ParamU32(
        NATIVE_INT_TYPE instance, //!< The component instance
        U32 cmdSeq //!< The command sequence number
    );

    //! Save parameter ParamU32
    void paramSave_ParamU32(
        NATIVE_INT_TYPE instance, //!< The component instance
        U32 cmdSeq //!< The command sequence number
    );

    //! Set parameter ParamF64
    void paramSet_ParamF64(
        const F64& val, //!< The parameter value
        Fw::ParamValid valid //!< The parameter valid flag
    );

    //! Send parameter ParamF64
    void paramSend_ParamF64(
        NATIVE_INT_TYPE instance, //!< The component instance
        U32 cmdSeq //!< The command sequence number
    );

    //! Save parameter ParamF64
    void paramSave_ParamF64(
        NATIVE_INT_TYPE instance, //!< The component instance
        U32 cmdSeq //!< The command sequence number
    );

    //! Set parameter ParamString
    void paramSet_ParamString(
        const Fw::ParamString& val, //!< The parameter value
        Fw::ParamValid valid //!< The parameter valid flag
    );

    //! Send parameter ParamString
    void paramSend_ParamString(
        NATIVE_INT_TYPE instance, //!< The component instance
        U32 cmdSeq //!< The command sequence number
    );

    //! Save parameter ParamString
    void paramSave_ParamString(
        NATIVE_INT_TYPE instance, //!< The component instance
        U32 cmdSeq //!< The command sequence number
    );

    //! Set parameter ParamEnum
    void paramSet_ParamEnum(
        const E& val, //!< The parameter value
        Fw::ParamValid valid //!< The parameter valid flag
    );

    //! Send parameter ParamEnum
    void paramSend_ParamEnum(
        NATIVE_INT_TYPE instance, //!< The component instance
        U32 cmdSeq //!< The command sequence number
    );

    //! Save parameter ParamEnum
    void paramSave_ParamEnum(
        NATIVE_INT_TYPE instance, //!< The component instance
        U32 cmdSeq //!< The command sequence number
    );

    //! Set parameter ParamArray
    void paramSet_ParamArray(
        const A& val, //!< The parameter value
        Fw::ParamValid valid //!< The parameter valid flag
    );

    //! Send parameter ParamArray
    void paramSend_ParamArray(
        NATIVE_INT_TYPE instance, //!< The component instance
        U32 cmdSeq //!< The command sequence number
    );

    //! Save parameter ParamArray
    void paramSave_ParamArray(
        NATIVE_INT_TYPE instance, //!< The component instance
        U32 cmdSeq //!< The command sequence number
    );

    //! Set parameter ParamStruct
    void paramSet_ParamStruct(
        const S& val, //!< The parameter value
        Fw::ParamValid valid //!< The parameter valid flag
    );

    //! Send parameter ParamStruct
    void paramSend_ParamStruct(
        NATIVE_INT_TYPE instance, //!< The component instance
        U32 cmdSeq //!< The command sequence number
    );

    //! Save parameter ParamStruct
    void paramSave_ParamStruct(
        NATIVE_INT_TYPE instance, //!< The component instance
        U32 cmdSeq //!< The command sequence number
    );

  protected:

    // ----------------------------------------------------------------------
    // Functions to test time
    // ----------------------------------------------------------------------

    //! Set the test time for events and telemetry
    void setTestTime(
        Fw::Time& timeTag //!< The time
    );

  protected:

    // ----------------------------------------------------------------------
    // History functions
    // ----------------------------------------------------------------------

    //! Clear all history
    void clearHistory();

    //! Clear from port history
    void clearFromPortHistory();

    //! Push an entry on the history for from_typedOut
    void pushFromPortEntry_typedOut(
        U32 u32, //!< A U32
        F32 f32, //!< An F32
        bool b, //!< A boolean
        const TypedPortStrings::StringSize80& str1, //!< A string
        const E& e, //!< An enum
        const A& a, //!< An array
        const S& s //!< A struct
    );

    //! Push an entry on the history for from_typedReturnOut
    void pushFromPortEntry_typedReturnOut(
        U32 u32, //!< A U32
        F32 f32, //!< An F32
        bool b, //!< A boolean
        const TypedReturnPortStrings::StringSize80& str2, //!< A string
        const E& e, //!< An enum
        const A& a, //!< An array
        const S& s //!< A struct
    );

  private:

    // ----------------------------------------------------------------------
    // Static functions for output ports
    // ----------------------------------------------------------------------

    //! Static function for port from_cmdRegOut
    static void from_cmdRegOut_static(
        Fw::PassiveComponentBase* const callComp, //!< The component instance
        NATIVE_INT_TYPE portNum, //!< The port number
        FwOpcodeType opCode //!< Command Op Code
    );

    //! Static function for port from_cmdResponseOut
    static void from_cmdResponseOut_static(
        Fw::PassiveComponentBase* const callComp, //!< The component instance
        NATIVE_INT_TYPE portNum, //!< The port number
        FwOpcodeType opCode, //!< Command Op Code
        U32 cmdSeq, //!< Command Sequence
        const Fw::CmdResponse& response //!< The command response argument
    );

    //! Static function for port from_prmGetOut
    static Fw::ParamValid from_prmGetOut_static(
        Fw::PassiveComponentBase* const callComp, //!< The component instance
        NATIVE_INT_TYPE portNum, //!< The port number
        FwPrmIdType id, //!< Parameter ID
        Fw::ParamBuffer& val //!< Buffer containing serialized parameter value
    );

    //! Static function for port from_prmSetOut
    static void from_prmSetOut_static(
        Fw::PassiveComponentBase* const callComp, //!< The component instance
        NATIVE_INT_TYPE portNum, //!< The port number
        FwPrmIdType id, //!< Parameter ID
        Fw::ParamBuffer& val //!< Buffer containing serialized parameter value
    );

    //! Static function for port from_timeGetOut
    static void from_timeGetOut_static(
        Fw::PassiveComponentBase* const callComp, //!< The component instance
        NATIVE_INT_TYPE portNum, //!< The port number
        Fw::Time& time //!< The time tag
    );

    //! Static function for port from_typedOut
    static void from_typedOut_static(
        Fw::PassiveComponentBase* const callComp, //!< The component instance
        NATIVE_INT_TYPE portNum, //!< The port number
        U32 u32, //!< A U32
        F32 f32, //!< An F32
        bool b, //!< A boolean
        const TypedPortStrings::StringSize80& str1, //!< A string
        const E& e, //!< An enum
        const A& a, //!< An array
        const S& s //!< A struct
    );

    //! Static function for port from_typedReturnOut
    static F32 from_typedReturnOut_static(
        Fw::PassiveComponentBase* const callComp, //!< The component instance
        NATIVE_INT_TYPE portNum, //!< The port number
        U32 u32, //!< A U32
        F32 f32, //!< An F32
        bool b, //!< A boolean
        const TypedReturnPortStrings::StringSize80& str2, //!< A string
        const E& e, //!< An enum
        const A& a, //!< An array
        const S& s //!< A struct
    );

  protected:

    // ----------------------------------------------------------------------
    // History member variables
    // ----------------------------------------------------------------------

    //! The total number of port entries
    U32 fromPortHistorySize;

    //! The history for from_typedOut
    History<FromPortEntry_typedOut>* fromPortHistory_typedOut;

    //! The history for from_typedReturnOut
    History<FromPortEntry_typedReturnOut>* fromPortHistory_typedReturnOut;

    //! The command response history
    History<CmdResponse>* cmdResponseHistory;

  private:

    // ----------------------------------------------------------------------
    // To ports
    // ----------------------------------------------------------------------

    //! To port connected to cmdIn
    Fw::OutputCmdPort m_to_cmdIn[1];

    //! To port connected to noArgsAsync
    OutputNoArgsPort m_to_noArgsAsync[1];

    //! To port connected to noArgsGuarded
    OutputNoArgsPort m_to_noArgsGuarded[1];

    //! To port connected to noArgsReturnGuarded
    OutputNoArgsReturnPort m_to_noArgsReturnGuarded[1];

    //! To port connected to noArgsReturnSync
    OutputNoArgsReturnPort m_to_noArgsReturnSync[3];

    //! To port connected to noArgsSync
    OutputNoArgsPort m_to_noArgsSync[3];

    //! To port connected to typedAsync
    OutputTypedPort m_to_typedAsync[1];

    //! To port connected to typedAsyncAssert
    OutputTypedPort m_to_typedAsyncAssert[1];

    //! To port connected to typedAsyncBlockPriority
    OutputTypedPort m_to_typedAsyncBlockPriority[1];

    //! To port connected to typedAsyncDropPriority
    OutputTypedPort m_to_typedAsyncDropPriority[1];

    //! To port connected to typedGuarded
    OutputTypedPort m_to_typedGuarded[1];

    //! To port connected to typedReturnGuarded
    OutputTypedReturnPort m_to_typedReturnGuarded[1];

    //! To port connected to typedReturnSync
    OutputTypedReturnPort m_to_typedReturnSync[3];

    //! To port connected to typedSync
    OutputTypedPort m_to_typedSync[3];

  private:

    // ----------------------------------------------------------------------
    // From ports
    // ----------------------------------------------------------------------

    //! From port connected to cmdRegOut
    Fw::InputCmdRegPort m_from_cmdRegOut[1];

    //! From port connected to cmdResponseOut
    Fw::InputCmdResponsePort m_from_cmdResponseOut[1];

    //! From port connected to eventOut
    Fw::InputLogPort m_from_eventOut[1];

    //! From port connected to prmGetOut
    Fw::InputPrmGetPort m_from_prmGetOut[1];

    //! From port connected to prmSetOut
    Fw::InputPrmSetPort m_from_prmSetOut[1];

#if FW_ENABLE_TEXT_LOGGING == 1

    //! From port connected to textEventOut
    Fw::InputLogTextPort m_from_textEventOut[1];

#endif

    //! From port connected to timeGetOut
    Fw::InputTimePort m_from_timeGetOut[1];

    //! From port connected to tlmOut
    Fw::InputTlmPort m_from_tlmOut[1];

    //! From port connected to typedOut
    InputTypedPort m_from_typedOut[1];

    //! From port connected to typedReturnOut
    InputTypedReturnPort m_from_typedReturnOut[1];

  private:

    // ----------------------------------------------------------------------
    // Parameter validity flags
    // ----------------------------------------------------------------------

    //! True if parameter ParamU32 was successfully received
    Fw::ParamValid m_param_ParamU32_valid;

    //! True if parameter ParamF64 was successfully received
    Fw::ParamValid m_param_ParamF64_valid;

    //! True if parameter ParamString was successfully received
    Fw::ParamValid m_param_ParamString_valid;

    //! True if parameter ParamEnum was successfully received
    Fw::ParamValid m_param_ParamEnum_valid;

    //! True if parameter ParamArray was successfully received
    Fw::ParamValid m_param_ParamArray_valid;

    //! True if parameter ParamStruct was successfully received
    Fw::ParamValid m_param_ParamStruct_valid;

  private:

    // ----------------------------------------------------------------------
    // Parameter variables
    // ----------------------------------------------------------------------

    //! Parameter ParamU32
    U32 m_param_ParamU32;

    //! Parameter ParamF64
    F64 m_param_ParamF64;

    //! Parameter ParamString
    Fw::ParamString m_param_ParamString;

    //! Parameter ParamEnum
    E m_param_ParamEnum;

    //! Parameter ParamArray
    A m_param_ParamArray;

    //! Parameter ParamStruct
    S m_param_ParamStruct;

  private:

    // ----------------------------------------------------------------------
    // Time variables
    // ----------------------------------------------------------------------

    //! Test time stamp
    Fw::Time m_testTime;

};

#endif
