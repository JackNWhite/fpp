// ======================================================================
// \title  PassiveSyncContainersOnlyTesterBase.cpp
// \author Generated by fpp-to-cpp
// \brief  cpp file for PassiveSyncContainersOnly component test harness base class
// ======================================================================

#include <cstdlib>
#include <cstring>

#include "test-base/PassiveSyncContainersOnlyTesterBase.hpp"

// ----------------------------------------------------------------------
// Component initialization
// ----------------------------------------------------------------------

void PassiveSyncContainersOnlyTesterBase ::
  init(NATIVE_INT_TYPE instance)
{
  // Initialize base class
  Fw::PassiveComponentBase::init(instance);

  // Connect input port productRequestOut
  for (
    PlatformIntType port = 0;
    port < static_cast<PlatformIntType>(this->getNum_from_productRequestOut());
    port++
  ) {
    this->m_from_productRequestOut[port].init();
    this->m_from_productRequestOut[port].addCallComp(
      this,
      from_productRequestOut_static
    );
    this->m_from_productRequestOut[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
    char portName[120];
    (void) snprintf(
      portName,
      sizeof(portName),
      "%s_from_productRequestOut[%" PRI_PlatformIntType "]",
      this->m_objName,
      port
    );
    this->m_from_productRequestOut[port].setObjName(portName);
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
}

// ----------------------------------------------------------------------
// Connectors for to ports
// ----------------------------------------------------------------------

void PassiveSyncContainersOnlyTesterBase ::
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

// ----------------------------------------------------------------------
// Getters for from ports
// ----------------------------------------------------------------------

Fw::InputDpRequestPort* PassiveSyncContainersOnlyTesterBase ::
  get_from_productRequestOut(NATIVE_INT_TYPE portNum)
{
  FW_ASSERT(
    portNum < this->getNum_from_productRequestOut(),
    static_cast<FwAssertArgType>(portNum)
  );

  return &this->m_from_productRequestOut[portNum];
}

Fw::InputDpSendPort* PassiveSyncContainersOnlyTesterBase ::
  get_from_productSendOut(NATIVE_INT_TYPE portNum)
{
  FW_ASSERT(
    portNum < this->getNum_from_productSendOut(),
    static_cast<FwAssertArgType>(portNum)
  );

  return &this->m_from_productSendOut[portNum];
}

Fw::InputTimePort* PassiveSyncContainersOnlyTesterBase ::
  get_from_timeGetOut(NATIVE_INT_TYPE portNum)
{
  FW_ASSERT(
    portNum < this->getNum_from_timeGetOut(),
    static_cast<FwAssertArgType>(portNum)
  );

  return &this->m_from_timeGetOut[portNum];
}

// ----------------------------------------------------------------------
// Component construction and destruction
// ----------------------------------------------------------------------

PassiveSyncContainersOnlyTesterBase ::
  PassiveSyncContainersOnlyTesterBase(
      const char* const compName,
      const U32 maxHistorySize
  ) :
    Fw::PassiveComponentBase(compName)
{
  // Initialize data product histories
  this->productRequestHistory = new History<DpRequest>(maxHistorySize);
  this->productSendHistory = new History<DpSend>(maxHistorySize);

  // Clear history
  this->clearHistory();
}

PassiveSyncContainersOnlyTesterBase ::
  ~PassiveSyncContainersOnlyTesterBase()
{
  // Destroy product request history
  delete this->productRequestHistory;
  // Destroy product send history
  delete this->productSendHistory;
}

// ----------------------------------------------------------------------
// Getters for port counts
// ----------------------------------------------------------------------

NATIVE_INT_TYPE PassiveSyncContainersOnlyTesterBase ::
  getNum_to_productRecvIn() const
{
  return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_to_productRecvIn));
}

NATIVE_INT_TYPE PassiveSyncContainersOnlyTesterBase ::
  getNum_from_productRequestOut() const
{
  return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_from_productRequestOut));
}

NATIVE_INT_TYPE PassiveSyncContainersOnlyTesterBase ::
  getNum_from_productSendOut() const
{
  return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_from_productSendOut));
}

NATIVE_INT_TYPE PassiveSyncContainersOnlyTesterBase ::
  getNum_from_timeGetOut() const
{
  return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_from_timeGetOut));
}

// ----------------------------------------------------------------------
// Connection status queries for to ports
// ----------------------------------------------------------------------

bool PassiveSyncContainersOnlyTesterBase ::
  isConnected_to_productRecvIn(NATIVE_INT_TYPE portNum)
{
  FW_ASSERT(
    portNum < this->getNum_to_productRecvIn(),
    static_cast<FwAssertArgType>(portNum)
  );

  return this->m_to_productRecvIn[portNum].isConnected();
}

// ----------------------------------------------------------------------
// Functions to test time
// ----------------------------------------------------------------------

void PassiveSyncContainersOnlyTesterBase ::
  setTestTime(const Fw::Time& timeTag)
{
  this->m_testTime = timeTag;
}

// ----------------------------------------------------------------------
// Functions for testing data products
// ----------------------------------------------------------------------

void PassiveSyncContainersOnlyTesterBase ::
  pushProductRequestEntry(
      FwDpIdType id,
      FwSizeType size
  )
{
  DpRequest e = { id, size };
  this->productRequestHistory->push_back(e);
}

void PassiveSyncContainersOnlyTesterBase ::
  productRequest_handler(
      FwDpIdType id,
      FwSizeType size
  )
{
  this->pushProductRequestEntry(id, size);
}

void PassiveSyncContainersOnlyTesterBase ::
  sendProductResponse(
      FwDpIdType id,
      const Fw::Buffer& buffer,
      const Fw::Success& status
  )
{
  FW_ASSERT(this->getNum_to_productRecvIn() > 0);
  FW_ASSERT(this->m_to_productRecvIn[0].isConnected());
  this->m_to_productRecvIn[0].invoke(id, buffer, status);
}

void PassiveSyncContainersOnlyTesterBase ::
  pushProductSendEntry(
      FwDpIdType id,
      const Fw::Buffer& buffer
  )
{
  DpSend e = { id, buffer };
  this->productSendHistory->push_back(e);
}

void PassiveSyncContainersOnlyTesterBase ::
  productSend_handler(
      FwDpIdType id,
      const Fw::Buffer& buffer
  )
{
  this->pushProductSendEntry(id, buffer);
}

// ----------------------------------------------------------------------
// History functions
// ----------------------------------------------------------------------

void PassiveSyncContainersOnlyTesterBase ::
  clearHistory()
{
  this->productRequestHistory->clear();
  this->productSendHistory->clear();
}

// ----------------------------------------------------------------------
// Static functions for output ports
// ----------------------------------------------------------------------

void PassiveSyncContainersOnlyTesterBase ::
  from_productRequestOut_static(
      Fw::PassiveComponentBase* const callComp,
      NATIVE_INT_TYPE portNum,
      FwDpIdType id,
      FwSizeType size
  )
{
  PassiveSyncContainersOnlyTesterBase* _testerBase = static_cast<PassiveSyncContainersOnlyTesterBase*>(callComp);
  _testerBase->productRequest_handler(id, size);
}

void PassiveSyncContainersOnlyTesterBase ::
  from_productSendOut_static(
      Fw::PassiveComponentBase* const callComp,
      NATIVE_INT_TYPE portNum,
      FwDpIdType id,
      const Fw::Buffer& buffer
  )
{
  PassiveSyncContainersOnlyTesterBase* _testerBase = static_cast<PassiveSyncContainersOnlyTesterBase*>(callComp);
  _testerBase->productSend_handler(id, buffer);
}

void PassiveSyncContainersOnlyTesterBase ::
  from_timeGetOut_static(
      Fw::PassiveComponentBase* const callComp,
      NATIVE_INT_TYPE portNum,
      Fw::Time& time
  )
{
  PassiveSyncContainersOnlyTesterBase* _testerBase = static_cast<PassiveSyncContainersOnlyTesterBase*>(callComp);
  time = _testerBase->m_testTime;
}