// ======================================================================
// \title  QueuedParamsTester.cpp
// \author Generated by fpp-to-cpp
// \brief  cpp file for QueuedParams component test harness implementation class
// ======================================================================

#include "QueuedParamsTester.hpp"

// ----------------------------------------------------------------------
// Construction and destruction
// ----------------------------------------------------------------------

QueuedParamsTester ::
  QueuedParamsTester() :
    QueuedParamsGTestBase("QueuedParamsTester", QueuedParamsTester::MAX_HISTORY_SIZE),
    component("QueuedParams")
{
  this->initComponents();
  this->connectPorts();
}

QueuedParamsTester ::
  ~QueuedParamsTester()
{

}

// ----------------------------------------------------------------------
// Tests
// ----------------------------------------------------------------------

void QueuedParamsTester ::
  toDo()
{
  // TODO
}

// ----------------------------------------------------------------------
// Handlers for typed from ports
// ----------------------------------------------------------------------

void QueuedParamsTester ::
  from_typedOut_handler(
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
  // TODO
}

F32 QueuedParamsTester ::
  from_typedReturnOut_handler(
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
  // TODO return
}
