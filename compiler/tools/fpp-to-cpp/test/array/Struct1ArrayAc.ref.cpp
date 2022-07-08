// ======================================================================
// \title  Struct1ArrayAc.cpp
// \author Generated by fpp-to-cpp
// \brief  cpp file for Struct1 array
// ======================================================================

#include <cstring>
#include <cstdio>
#include <cinttypes>

#include "Fw/Types/Assert.hpp"
#include "Fw/Types/StringUtils.hpp"

#include "Struct1ArrayAc.hpp"

// ----------------------------------------------------------------------
// Constructors
// ----------------------------------------------------------------------

Struct1 ::
  Struct1() :
    Serializable()
{
  // Construct using element-wise constructor
  *this = Struct1(
    M::S1(0.0f, 0.0, 0, 0, 0, 0, 0, 0, 0, 0, false, ""),
    M::S1(0.0f, 0.0, 0, 0, 0, 0, 0, 0, 0, 0, false, ""),
    M::S1(0.0f, 0.0, 0, 0, 0, 0, 0, 0, 0, 0, false, ""),
    M::S1(0.0f, 0.0, 0, 0, 0, 0, 0, 0, 0, 0, false, ""),
    M::S1(0.0f, 0.0, 0, 0, 0, 0, 0, 0, 0, 0, false, "")
  );
}

Struct1 ::
  Struct1(const ElementType (&a)[SIZE]) :
    Serializable()
{
  for (U32 index = 0; index < SIZE; index++) {
    this->elements[index] = a[index];
  }
}

Struct1 ::
  Struct1(const ElementType& e) :
    Serializable()
{
  for (U32 index = 0; index < SIZE; index++) {
    this->elements[index] = e;
  }
}

Struct1 ::
  Struct1(
      const ElementType& e1,
      const ElementType& e2,
      const ElementType& e3,
      const ElementType& e4,
      const ElementType& e5
  ) :
    Serializable()
{
  this->elements[0] = e1;
  this->elements[1] = e2;
  this->elements[2] = e3;
  this->elements[3] = e4;
  this->elements[4] = e5;
}

Struct1 ::
  Struct1(const Struct1& obj) :
    Serializable()
{
  for (U32 index = 0; index < SIZE; index++) {
    this->elements[index] = obj.elements[index];
  }
}

// ----------------------------------------------------------------------
// Operators
// ----------------------------------------------------------------------

Struct1::ElementType& Struct1 ::
  operator[](const U32 i)
{
  FW_ASSERT(i < SIZE);
  return this->elements[i];
}

const Struct1::ElementType& Struct1 ::
  operator[](const U32 i) const
{
  FW_ASSERT(i < SIZE);
  return this->elements[i];
}

Struct1& Struct1 ::
  operator=(const Struct1& obj)
{
  if (this == &obj) {
    return *this;
  }

  for (U32 index = 0; index < SIZE; index++) {
    this->elements[index] = obj.elements[index];
  }
  return *this;
}

Struct1& Struct1 ::
  operator=(const ElementType (&a)[SIZE])
{
  for (U32 index = 0; index < SIZE; index++) {
    this->elements[index] = a[index];
  }
  return *this;
}

Struct1& Struct1 ::
  operator=(const ElementType& e)
{
  for (U32 index = 0; index < SIZE; index++) {
    this->elements[index] = e;
  }
  return *this;
}

bool Struct1 ::
  operator==(const Struct1& obj) const
{
  for (U32 index = 0; index < SIZE; index++) {
    if (!((*this)[index] == obj[index])) {
      return false;
    }
  }
  return true;
}

bool Struct1 ::
  operator!=(const Struct1& obj) const
{
  return !(*this == obj);
}

#ifdef BUILD_UT

std::ostream& operator<<(std::ostream& os, const Struct1& obj) {
  Fw::String s;
  obj.toString(s);
  os << s;
  return os;
}

#endif

// ----------------------------------------------------------------------
// Member functions
// ----------------------------------------------------------------------

Fw::SerializeStatus Struct1 ::
  serialize(Fw::SerializeBufferBase& buffer) const
{
  Fw::SerializeStatus status = Fw::FW_SERIALIZE_OK;
  for (U32 index = 0; index < SIZE; index++) {
    status = buffer.serialize((*this)[index]);
    if (status != Fw::FW_SERIALIZE_OK) {
      return status;
    }
  }
  return status;
}

Fw::SerializeStatus Struct1 ::
  deserialize(Fw::SerializeBufferBase& buffer)
{
  Fw::SerializeStatus status = Fw::FW_SERIALIZE_OK;
  for (U32 index = 0; index < SIZE; index++) {
    status = buffer.deserialize((*this)[index]);
    if (status != Fw::FW_SERIALIZE_OK) {
      return status;
    }
  }
  return status;
}

#if FW_ARRAY_TO_STRING || BUILD_UT

void Struct1 ::
  toString(Fw::StringBase& sb) const
{
  static const char *formatString = "[ "
    "%s "
    "%s "
    "%s "
    "%s "
    "%s ]";

  // Call toString for arrays and serializable types
  Fw::String str0;
  Fw::String str1;
  Fw::String str2;
  Fw::String str3;
  Fw::String str4;

  this->elements[0].toString(str0);
  this->elements[1].toString(str1);
  this->elements[2].toString(str2);
  this->elements[3].toString(str3);
  this->elements[4].toString(str4);

  // Declare strings to hold any serializable toString() arguments
  char outputString[FW_ARRAY_TO_STRING_BUFFER_SIZE];
  (void) snprintf(
    outputString,
    FW_ARRAY_TO_STRING_BUFFER_SIZE,
    formatString,
    str0.toChar(),
    str1.toChar(),
    str2.toChar(),
    str3.toChar(),
    str4.toChar()
  );

  outputString[FW_ARRAY_TO_STRING_BUFFER_SIZE-1] = 0; // NULL terminate
  sb = outputString;
}

#endif
