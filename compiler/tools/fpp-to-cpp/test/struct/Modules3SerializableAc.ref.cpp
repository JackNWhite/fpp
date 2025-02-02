// ======================================================================
// \title  Modules3SerializableAc.cpp
// \author Generated by fpp-to-cpp
// \brief  cpp file for Modules3 struct
// ======================================================================

#include "cstdio"
#include "cstring"

#include "Fw/Types/Assert.hpp"
#include "Fw/Types/StringUtils.hpp"
#include "Modules3SerializableAc.hpp"

// ----------------------------------------------------------------------
// Constructors
// ----------------------------------------------------------------------

Modules3 ::
  Modules3() :
    Serializable(),
    x(M::Modules1(0, 0.0f))
{
  for (NATIVE_UINT_TYPE i = 0; i < 3; i++) {
    this->arr[i] = M::Modules2(M::Modules1(0, 0.0f));
  }
}

Modules3 ::
  Modules3(
      const M::Modules2& x,
      const Type_of_arr& arr
  ) :
    Serializable(),
    x(x)
{
  for (NATIVE_UINT_TYPE i = 0; i < 3; i++) {
    this->arr[i] = arr[i];
  }
}

Modules3 ::
  Modules3(const Modules3& obj) :
    Serializable(),
    x(obj.x)
{
  for (NATIVE_UINT_TYPE i = 0; i < 3; i++) {
    this->arr[i] = obj.arr[i];
  }
}

Modules3 ::
  Modules3(
      const M::Modules2& x,
      const M::Modules2& arr
  ) :
    Serializable(),
    x(x)
{
  for (NATIVE_UINT_TYPE i = 0; i < 3; i++) {
    this->arr[i] = arr;
  }
}

// ----------------------------------------------------------------------
// Operators
// ----------------------------------------------------------------------

Modules3& Modules3 ::
  operator=(const Modules3& obj)
{
  if (this == &obj) {
    return *this;
  }

  set(obj.x, obj.arr);
  return *this;
}

bool Modules3 ::
  operator==(const Modules3& obj) const
{
  // Compare non-array members
  if (!(this->x == obj.x)) {
    return false;
  }

  // Compare array members
  if (!(this->arr == obj.arr)) {
    for (NATIVE_UINT_TYPE i = 0; i < 3; i++) {
      if (!(this->arr[i] == obj.arr[i])) {
        return false;
      }
    }
  }

  return true;
}

bool Modules3 ::
  operator!=(const Modules3& obj) const
{
  return !(*this == obj);
}

#ifdef BUILD_UT

std::ostream& operator<<(std::ostream& os, const Modules3& obj) {
  Fw::String s;
  obj.toString(s);
  os << s.toChar();
  return os;
}

#endif

// ----------------------------------------------------------------------
// Member functions
// ----------------------------------------------------------------------

Fw::SerializeStatus Modules3 ::
  serialize(Fw::SerializeBufferBase& buffer) const
{
  Fw::SerializeStatus status;

  status = buffer.serialize(this->x);
  if (status != Fw::FW_SERIALIZE_OK) {
    return status;
  }
  for (NATIVE_UINT_TYPE i = 0; i < 3; i++) {
    status = buffer.serialize(this->arr[i]);
    if (status != Fw::FW_SERIALIZE_OK) {
      return status;
    }
  }

  return status;
}

Fw::SerializeStatus Modules3 ::
  deserialize(Fw::SerializeBufferBase& buffer)
{
  Fw::SerializeStatus status;

  status = buffer.deserialize(this->x);
  if (status != Fw::FW_SERIALIZE_OK) {
    return status;
  }
  for (NATIVE_UINT_TYPE i = 0; i < 3; i++) {
    status = buffer.deserialize(this->arr[i]);
    if (status != Fw::FW_SERIALIZE_OK) {
      return status;
    }
  }

  return status;
}

#if FW_SERIALIZABLE_TO_STRING

void Modules3 ::
  toString(Fw::StringBase& sb) const
{
  static const char* formatString =
    "( "
    "x = %s, "
    "arr = [ %s, "
    "%s, "
    "%s ]"
    " )";

  // Declare strings to hold any serializable toString() arguments
  Fw::String xStr;
  Fw::String arrStr[3];

  // Call toString for arrays and serializable types
  this->x.toString(xStr);
  for (NATIVE_UINT_TYPE i = 0; i < 3; i++) {
    this->arr[i].toString(arrStr[i]);
  }

  char outputString[FW_SERIALIZABLE_TO_STRING_BUFFER_SIZE];
  (void) snprintf(
    outputString,
    FW_SERIALIZABLE_TO_STRING_BUFFER_SIZE,
    formatString,
    xStr.toChar(),
    arrStr[0].toChar(),
    arrStr[1].toChar(),
    arrStr[2].toChar()
  );

  outputString[FW_SERIALIZABLE_TO_STRING_BUFFER_SIZE-1] = 0; // NULL terminate
  sb = outputString;
}

#endif

// ----------------------------------------------------------------------
// Setter functions
// ----------------------------------------------------------------------

void Modules3 ::
  set(
      const M::Modules2& x,
      const Type_of_arr& arr
  )
{
  this->x = x;

  for (NATIVE_UINT_TYPE i = 0; i < 3; i++) {
    this->arr[i] = arr[i];
  }
}

void Modules3 ::
  setx(const M::Modules2& x)
{
  this->x = x;
}

void Modules3 ::
  setarr(const Type_of_arr& arr)
{
  for (NATIVE_UINT_TYPE i = 0; i < 3; i++) {
    this->arr[i] = arr[i];
  }
}
