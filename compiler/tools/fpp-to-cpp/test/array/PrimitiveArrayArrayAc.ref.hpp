// ======================================================================
// \title  PrimitiveArrayArrayAc.hpp
// \author Generated by fpp-to-cpp
// \brief  hpp file for PrimitiveArray array
// ======================================================================

#ifndef PrimitiveArrayArrayAc_HPP
#define PrimitiveArrayArrayAc_HPP

#include "Fw/Types/BasicTypes.hpp"
#include "Fw/Types/Serializable.hpp"
#include "Fw/Types/String.hpp"

#include "PrimitiveF64ArrayAc.hpp"

//! An array of arrays
class PrimitiveArray :
  public Fw::Serializable
{

  public:

    // ----------------------------------------------------------------------
    // Types
    // ----------------------------------------------------------------------

    //! The element type
    typedef M::PrimitiveF64 ElementType;

  public:

    // ----------------------------------------------------------------------
    // Constants
    // ----------------------------------------------------------------------

    enum {
      //! The size of the array
      SIZE = 5,
      //! The size of the serial representation
      SERIALIZED_SIZE = SIZE * M::PrimitiveF64::SERIALIZED_SIZE,
    };

  public:

    // ----------------------------------------------------------------------
    // Constructors
    // ----------------------------------------------------------------------

    //! Constructor (default value)
    PrimitiveArray();

    //! Constructor (user-provided value)
    PrimitiveArray(
        const ElementType (&a)[SIZE] //!< The array
    );

    //! Constructor (single element)
    PrimitiveArray(
        const ElementType& e //!< The element
    );

    //! Constructor (multiple elements)
    PrimitiveArray(
        const ElementType& e1, //!< Element 1
        const ElementType& e2, //!< Element 2
        const ElementType& e3, //!< Element 3
        const ElementType& e4, //!< Element 4
        const ElementType& e5 //!< Element 5
    );

    //! Copy Constructor
    PrimitiveArray(
        const PrimitiveArray& obj //!< The source object
    );

  public:

    // ----------------------------------------------------------------------
    // Operators
    // ----------------------------------------------------------------------

    //! Subscript operator
    ElementType& operator[](
        const U32 i //!< The subscript index
    );

    //! Const subscript operator
    const ElementType& operator[](
        const U32 i //!< The subscript index
    ) const;

    //! Copy assignment operator (object)
    PrimitiveArray& operator=(
        const PrimitiveArray& obj //!< The source object
    );

    //! Copy assignment operator (raw array)
    PrimitiveArray& operator=(
        const ElementType (&a)[SIZE] //!< The source array
    );

    //! Copy assignment operator (single element)
    PrimitiveArray& operator=(
        const ElementType& e //!< The element
    );

    //! Equality operator
    bool operator==(
        const PrimitiveArray& obj //!< The other object
    ) const;

    //! Inequality operator
    bool operator!=(
        const PrimitiveArray& obj //!< The other object
    ) const;

#ifdef BUILD_UT

    //! Ostream operator
    friend std::ostream& operator<<(
        std::ostream& os, //!< The ostream
        const PrimitiveArray& obj //!< The object
    );

#endif

  public:

    // ----------------------------------------------------------------------
    // Member functions
    // ----------------------------------------------------------------------

    //! Serialization
    Fw::SerializeStatus serialize(
        Fw::SerializeBufferBase& buffer //!< The serial buffer
    ) const;

    //! Deserialization
    Fw::SerializeStatus deserialize(
        Fw::SerializeBufferBase& buffer //!< The serial buffer
    );

#if FW_ARRAY_TO_STRING || BUILD_UT

    //! Convert array to string
    void toString(
        Fw::StringBase& sb //!< The StringBase object to hold the result
    ) const;

#endif

  private:

    // ----------------------------------------------------------------------
    // Member variables
    // ----------------------------------------------------------------------

    //! The array elements
    ElementType elements[SIZE];

};

#endif
