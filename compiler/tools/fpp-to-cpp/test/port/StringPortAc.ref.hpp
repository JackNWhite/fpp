// ======================================================================
// \title  StringPortAc.hpp
// \author Generated by fpp-to-cpp
// \brief  hpp file for String port
// ======================================================================

#ifndef StringPortAc_HPP
#define StringPortAc_HPP

#include "FpConfig.hpp"
#include "Fw/Cmd/CmdArgBuffer.hpp"
#include "Fw/Comp/PassiveComponentBase.hpp"
#include "Fw/Port/InputPortBase.hpp"
#include "Fw/Port/OutputPortBase.hpp"
#include "Fw/Types/Serializable.hpp"
#include "Fw/Types/StringType.hpp"

// ----------------------------------------------------------------------
// StringSize80 class
// ----------------------------------------------------------------------

class StringSize80 :
  public Fw::StringBase
{

  public:

    enum {
      //! The size of the string length plus the size of the string buffer
      SERIALIZED_SIZE = sizeof(FwBuffSizeType) + 80
    };

    //! Default constructor
    StringSize80();

    //! Char array constructor
    StringSize80(const char* src);

    //! String base constructor
    StringSize80(const Fw::StringBase& src);

    //! Copy constructor
    StringSize80(const StringSize80& src);

    //! Destructor
    ~StringSize80();

    //! Copy assignment operator
    StringSize80& operator=(const StringSize80& other);

    //! String base assignment operator
    StringSize80& operator=(const Fw::StringBase& other);

    //! char* assignment operator
    StringSize80& operator=(const char* other);

    //! Retrieves char buffer of string
    const char* toChar() const;

    NATIVE_UINT_TYPE getCapacity() const;

  private:

    char m_buf[80]; //!< Buffer for string storage

};

// ----------------------------------------------------------------------
// StringSize100 class
// ----------------------------------------------------------------------

class StringSize100 :
  public Fw::StringBase
{

  public:

    enum {
      //! The size of the string length plus the size of the string buffer
      SERIALIZED_SIZE = sizeof(FwBuffSizeType) + 100
    };

    //! Default constructor
    StringSize100();

    //! Char array constructor
    StringSize100(const char* src);

    //! String base constructor
    StringSize100(const Fw::StringBase& src);

    //! Copy constructor
    StringSize100(const StringSize100& src);

    //! Destructor
    ~StringSize100();

    //! Copy assignment operator
    StringSize100& operator=(const StringSize100& other);

    //! String base assignment operator
    StringSize100& operator=(const Fw::StringBase& other);

    //! char* assignment operator
    StringSize100& operator=(const char* other);

    //! Retrieves char buffer of string
    const char* toChar() const;

    NATIVE_UINT_TYPE getCapacity() const;

  private:

    char m_buf[100]; //!< Buffer for string storage

};

//! Input String port
//! A port with string parameters
class InputStringPort :
  public Fw::InputPortBase
{

  public:

    // ----------------------------------------------------------------------
    // Constants
    // ----------------------------------------------------------------------

    enum {
      //! The size of the serial representations of the port arguments
      SERIALIZED_SIZE =
        StringSize80::SERIALIZED_SIZE +
        StringSize80::SERIALIZED_SIZE +
        StringSize100::SERIALIZED_SIZE +
        StringSize100::SERIALIZED_SIZE
    };

  public:

    // ----------------------------------------------------------------------
    // Types
    // ----------------------------------------------------------------------

    //! The port callback function type
    typedef void (*CompFuncPtr)(
      Fw::PassiveComponentBase* callComp,
      NATIVE_INT_TYPE portNum,
      const StringSize80& str80,
      StringSize80& str80Ref,
      const StringSize100& str100,
      StringSize100& str100Ref
    );

  public:

    // ----------------------------------------------------------------------
    // Input Port Member functions
    // ----------------------------------------------------------------------

    //! Constructor
    InputStringPort();

    //! Initialization function
    void init();

    //! Register a component
    void addCallComp(
        Fw::PassiveComponentBase* callComp, //!< The containing component
        CompFuncPtr funcPtr //!< The port callback function
    );

    //! Invoke a port interface
    void invoke(
        const StringSize80& str80, //!< A string of size 80
        StringSize80& str80Ref,
        const StringSize100& str100, //!< A string of size 100
        StringSize100& str100Ref
    );

  private:

  private:

    // ----------------------------------------------------------------------
    // Member variables
    // ----------------------------------------------------------------------

    //! The pointer to the port callback function
    CompFuncPtr m_func;

};

//! Output String port
//! A port with string parameters
class OutputStringPort :
  public Fw::OutputPortBase
{

  public:

    // ----------------------------------------------------------------------
    // Output Port Member functions
    // ----------------------------------------------------------------------

    //! Constructor
    OutputStringPort();

    //! Initialization function
    void init();

    //! Register an input port
    void addCallPort(
        InputStringPort* callPort //!< The input port
    );

    //! Invoke a port interface
    void invoke(
        const StringSize80& str80, //!< A string of size 80
        StringSize80& str80Ref,
        const StringSize100& str100, //!< A string of size 100
        StringSize100& str100Ref
    );

  private:

    // ----------------------------------------------------------------------
    // Member variables
    // ----------------------------------------------------------------------

    //! The pointer to the input port
    InputStringPort* m_port;

};

#endif
