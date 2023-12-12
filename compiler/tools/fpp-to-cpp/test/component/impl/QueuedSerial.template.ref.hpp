// ======================================================================
// \title  QueuedSerial.hpp
// \author [user name]
// \brief  hpp file for QueuedSerial component implementation class
// ======================================================================

#ifndef QueuedSerial_HPP
#define QueuedSerial_HPP

#include "QueuedSerialComponentAc.hpp"

class QueuedSerial :
  public QueuedSerialComponentBase
{

  public:

    // ----------------------------------------------------------------------
    // Component construction and destruction
    // ----------------------------------------------------------------------

    //! Construct QueuedSerial object
    QueuedSerial(
        const char* const compName //!< The component name
    );

    //! Destroy QueuedSerial object
    ~QueuedSerial();

  PRIVATE:

    // ----------------------------------------------------------------------
    // Handler implementations for user-defined typed input ports
    // ----------------------------------------------------------------------

    //! Handler implementation for noArgsAsync
    //!
    //! A typed async input port
    void noArgsAsync_handler(
        NATIVE_INT_TYPE portNum //!< The port number
    );

    //! Handler implementation for noArgsGuarded
    //!
    //! A typed guarded input
    void noArgsGuarded_handler(
        NATIVE_INT_TYPE portNum //!< The port number
    );

    //! Handler implementation for noArgsReturnGuarded
    //!
    //! A typed guarded input
    U32 noArgsReturnGuarded_handler(
        NATIVE_INT_TYPE portNum //!< The port number
    );

    //! Handler implementation for noArgsReturnSync
    //!
    //! A typed sync input port
    U32 noArgsReturnSync_handler(
        NATIVE_INT_TYPE portNum //!< The port number
    );

    //! Handler implementation for noArgsSync
    //!
    //! A typed sync input port
    void noArgsSync_handler(
        NATIVE_INT_TYPE portNum //!< The port number
    );

    //! Handler implementation for typedAsync
    //!
    //! A typed async input port
    void typedAsync_handler(
        NATIVE_INT_TYPE portNum, //!< The port number
        U32 u32, //!< A U32
        F32 f32, //!< An F32
        bool b, //!< A boolean
        const Ports::TypedPortStrings::StringSize80& str1, //!< A string
        const E& e, //!< An enum
        const A& a, //!< An array
        const S& s //!< A struct
    );

    //! Handler implementation for typedAsyncAssert
    //!
    //! A typed async input port with queue full behavior and priority
    void typedAsyncAssert_handler(
        NATIVE_INT_TYPE portNum, //!< The port number
        U32 u32, //!< A U32
        F32 f32, //!< An F32
        bool b, //!< A boolean
        const Ports::TypedPortStrings::StringSize80& str1, //!< A string
        const E& e, //!< An enum
        const A& a, //!< An array
        const S& s //!< A struct
    );

    //! Handler implementation for typedAsyncBlockPriority
    //!
    //! A typed async input port with queue full behavior and priority
    void typedAsyncBlockPriority_handler(
        NATIVE_INT_TYPE portNum, //!< The port number
        U32 u32, //!< A U32
        F32 f32, //!< An F32
        bool b, //!< A boolean
        const Ports::TypedPortStrings::StringSize80& str1, //!< A string
        const E& e, //!< An enum
        const A& a, //!< An array
        const S& s //!< A struct
    );

    //! Handler implementation for typedAsyncDropPriority
    //!
    //! A typed async input port with queue full behavior and priority
    void typedAsyncDropPriority_handler(
        NATIVE_INT_TYPE portNum, //!< The port number
        U32 u32, //!< A U32
        F32 f32, //!< An F32
        bool b, //!< A boolean
        const Ports::TypedPortStrings::StringSize80& str1, //!< A string
        const E& e, //!< An enum
        const A& a, //!< An array
        const S& s //!< A struct
    );

    //! Handler implementation for typedGuarded
    //!
    //! A typed guarded input
    void typedGuarded_handler(
        NATIVE_INT_TYPE portNum, //!< The port number
        U32 u32, //!< A U32
        F32 f32, //!< An F32
        bool b, //!< A boolean
        const Ports::TypedPortStrings::StringSize80& str1, //!< A string
        const E& e, //!< An enum
        const A& a, //!< An array
        const S& s //!< A struct
    );

    //! Handler implementation for typedReturnGuarded
    //!
    //! A typed guarded input with a return type
    F32 typedReturnGuarded_handler(
        NATIVE_INT_TYPE portNum, //!< The port number
        U32 u32, //!< A U32
        F32 f32, //!< An F32
        bool b, //!< A boolean
        const Ports::TypedReturnPortStrings::StringSize80& str2, //!< A string
        const E& e, //!< An enum
        const A& a, //!< An array
        const S& s //!< A struct
    );

    //! Handler implementation for typedReturnSync
    //!
    //! A typed sync input port with a return type
    F32 typedReturnSync_handler(
        NATIVE_INT_TYPE portNum, //!< The port number
        U32 u32, //!< A U32
        F32 f32, //!< An F32
        bool b, //!< A boolean
        const Ports::TypedReturnPortStrings::StringSize80& str2, //!< A string
        const E& e, //!< An enum
        const A& a, //!< An array
        const S& s //!< A struct
    );

    //! Handler implementation for typedSync
    //!
    //! A typed sync input port
    void typedSync_handler(
        NATIVE_INT_TYPE portNum, //!< The port number
        U32 u32, //!< A U32
        F32 f32, //!< An F32
        bool b, //!< A boolean
        const Ports::TypedPortStrings::StringSize80& str1, //!< A string
        const E& e, //!< An enum
        const A& a, //!< An array
        const S& s //!< A struct
    );

  PRIVATE:

    // ----------------------------------------------------------------------
    // Handler implementations for user-defined serial input ports
    // ----------------------------------------------------------------------

    //! Handler implementation for serialAsync
    //!
    //! A serial async input port
    void serialAsync_handler(
        NATIVE_INT_TYPE portNum, //!< The port number
        Fw::SerializeBufferBase& buffer //!< The serialization buffer
    );

    //! Handler implementation for serialAsyncAssert
    //!
    //! A serial async input port with queue full behavior and priority
    void serialAsyncAssert_handler(
        NATIVE_INT_TYPE portNum, //!< The port number
        Fw::SerializeBufferBase& buffer //!< The serialization buffer
    );

    //! Handler implementation for serialAsyncBlockPriority
    //!
    //! A serial async input port with queue full behavior and priority
    void serialAsyncBlockPriority_handler(
        NATIVE_INT_TYPE portNum, //!< The port number
        Fw::SerializeBufferBase& buffer //!< The serialization buffer
    );

    //! Handler implementation for serialAsyncDropPriority
    //!
    //! A serial async input port with queue full behavior and priority
    void serialAsyncDropPriority_handler(
        NATIVE_INT_TYPE portNum, //!< The port number
        Fw::SerializeBufferBase& buffer //!< The serialization buffer
    );

    //! Handler implementation for serialGuarded
    //!
    //! A serial guarded input
    void serialGuarded_handler(
        NATIVE_INT_TYPE portNum, //!< The port number
        Fw::SerializeBufferBase& buffer //!< The serialization buffer
    );

    //! Handler implementation for serialSync
    //!
    //! A serial sync input port
    void serialSync_handler(
        NATIVE_INT_TYPE portNum, //!< The port number
        Fw::SerializeBufferBase& buffer //!< The serialization buffer
    );

  PRIVATE:

    // ----------------------------------------------------------------------
    // Handler implementations for commands
    // ----------------------------------------------------------------------

    //! Handler implementation for command CMD_SYNC
    //!
    //! A sync command with no params
    void CMD_SYNC_cmdHandler(
        FwOpcodeType opCode, //!< The opcode
        U32 cmdSeq //!< The command sequence number
    );

    //! Handler implementation for command CMD_SYNC_PRIMITIVE
    //!
    //! An async command with primitive params
    void CMD_SYNC_PRIMITIVE_cmdHandler(
        FwOpcodeType opCode, //!< The opcode
        U32 cmdSeq, //!< The command sequence number
        U32 u32, //!< A U32
        F32 f32, //!< An F32
        bool b //!< A boolean
    );

    //! Handler implementation for command CMD_SYNC_STRING
    //!
    //! A sync command with string params
    void CMD_SYNC_STRING_cmdHandler(
        FwOpcodeType opCode, //!< The opcode
        U32 cmdSeq, //!< The command sequence number
        const Fw::CmdStringArg& str1, //!< A string
        const Fw::CmdStringArg& str2 //!< Another string
    );

    //! Handler implementation for command CMD_SYNC_ENUM
    //!
    //! A sync command with enum params
    void CMD_SYNC_ENUM_cmdHandler(
        FwOpcodeType opCode, //!< The opcode
        U32 cmdSeq, //!< The command sequence number
        E e //!< An enum
    );

    //! Handler implementation for command CMD_SYNC_ARRAY
    //!
    //! A sync command with array params
    void CMD_SYNC_ARRAY_cmdHandler(
        FwOpcodeType opCode, //!< The opcode
        U32 cmdSeq, //!< The command sequence number
        A a //!< An array
    );

    //! Handler implementation for command CMD_SYNC_STRUCT
    //!
    //! A sync command with struct params
    void CMD_SYNC_STRUCT_cmdHandler(
        FwOpcodeType opCode, //!< The opcode
        U32 cmdSeq, //!< The command sequence number
        S s //!< A struct
    );

    //! Handler implementation for command CMD_GUARDED
    //!
    //! A guarded command with no params
    void CMD_GUARDED_cmdHandler(
        FwOpcodeType opCode, //!< The opcode
        U32 cmdSeq //!< The command sequence number
    );

    //! Handler implementation for command CMD_GUARDED_PRIMITIVE
    //!
    //! A guarded command with primitive params
    void CMD_GUARDED_PRIMITIVE_cmdHandler(
        FwOpcodeType opCode, //!< The opcode
        U32 cmdSeq, //!< The command sequence number
        U32 u32, //!< A U32
        F32 f32, //!< An F32
        bool b //!< A boolean
    );

    //! Handler implementation for command CMD_GUARDED_STRING
    //!
    //! A guarded command with string params
    void CMD_GUARDED_STRING_cmdHandler(
        FwOpcodeType opCode, //!< The opcode
        U32 cmdSeq, //!< The command sequence number
        const Fw::CmdStringArg& str1, //!< A string
        const Fw::CmdStringArg& str2 //!< Another string
    );

    //! Handler implementation for command CMD_GUARDED_ENUM
    //!
    //! A guarded command with enum params
    void CMD_GUARDED_ENUM_cmdHandler(
        FwOpcodeType opCode, //!< The opcode
        U32 cmdSeq, //!< The command sequence number
        E e //!< An enum
    );

    //! Handler implementation for command CMD_GUARDED_ARRAY
    //!
    //! A guarded command with array params
    void CMD_GUARDED_ARRAY_cmdHandler(
        FwOpcodeType opCode, //!< The opcode
        U32 cmdSeq, //!< The command sequence number
        A a //!< An array
    );

    //! Handler implementation for command CMD_GUARDED_STRUCT
    //!
    //! A guarded command with struct params
    void CMD_GUARDED_STRUCT_cmdHandler(
        FwOpcodeType opCode, //!< The opcode
        U32 cmdSeq, //!< The command sequence number
        S s //!< A struct
    );

    //! Handler implementation for command CMD_ASYNC
    //!
    //! An async command with no params
    void CMD_ASYNC_cmdHandler(
        FwOpcodeType opCode, //!< The opcode
        U32 cmdSeq //!< The command sequence number
    );

    //! Handler implementation for command CMD_PRIORITY
    //!
    //! A command with priority
    void CMD_PRIORITY_cmdHandler(
        FwOpcodeType opCode, //!< The opcode
        U32 cmdSeq //!< The command sequence number
    );

    //! Handler implementation for command CMD_PARAMS_PRIORITY
    //!
    //! A command with params and priority
    void CMD_PARAMS_PRIORITY_cmdHandler(
        FwOpcodeType opCode, //!< The opcode
        U32 cmdSeq, //!< The command sequence number
        U32 u32
    );

    //! Handler implementation for command CMD_DROP
    //!
    //! A command with queue full behavior
    void CMD_DROP_cmdHandler(
        FwOpcodeType opCode, //!< The opcode
        U32 cmdSeq //!< The command sequence number
    );

    //! Handler implementation for command CMD_PARAMS_PRIORITY_DROP
    //!
    //! A command with params, priority, and queue full behavior
    void CMD_PARAMS_PRIORITY_DROP_cmdHandler(
        FwOpcodeType opCode, //!< The opcode
        U32 cmdSeq, //!< The command sequence number
        U32 u32
    );

  PRIVATE:

    // ----------------------------------------------------------------------
    // Handler implementations for user-defined internal interfaces
    // ----------------------------------------------------------------------

    //! Handler implementation for internalArray
    //!
    //! An internal port with array params
    void internalArray_internalInterfaceHandler(
        const A& a //!< An array
    );

    //! Handler implementation for internalEnum
    //!
    //! An internal port with enum params
    void internalEnum_internalInterfaceHandler(
        const E& e //!< An enum
    );

    //! Handler implementation for internalPrimitive
    //!
    //! An internal port with primitive params and priority
    void internalPrimitive_internalInterfaceHandler(
        U32 u32, //!< A U32
        F32 f32, //!< An F32
        bool b //!< A boolean
    );

    //! Handler implementation for internalPriorityDrop
    //!
    //! An internal port with priority and queue full behavior
    void internalPriorityDrop_internalInterfaceHandler();

    //! Handler implementation for internalString
    //!
    //! An internal port with string params
    void internalString_internalInterfaceHandler(
        const Fw::InternalInterfaceString& str1, //!< A string
        const Fw::InternalInterfaceString& str2 //!< Another string
    );

    //! Handler implementation for internalStruct
    //!
    //! An internal port with struct params with priority and queue full behavior
    void internalStruct_internalInterfaceHandler(
        const S& s //!< A struct
    );

};

#endif
