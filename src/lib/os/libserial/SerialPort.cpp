#include <termios.h>
#include <fcntl.h>
#include <unistd.h>

#include <libserial/SerialPort.hpp>

//==============================================================================
//
// Public methods
//
//==============================================================================
//------------------------------------------------------------------------------
// open
//------------------------------------------------------------------------------
bool SerialPort::open_port(const char *port)
{
    bool rc(false);

    _fd = open(port, O_RDWR | O_NOCTTY | O_NDELAY);
    if (_fd != -1)
    {
        rc = true;
        fcntl(_fd, F_SETFL, 0);
    }

    return rc;
}

//------------------------------------------------------------------------------
// close
//------------------------------------------------------------------------------
void SerialPort::close_port()
{
    close(_fd);
}

//------------------------------------------------------------------------------
// read
//------------------------------------------------------------------------------
uint32_t SerialPort::read(char *buffer)
{
    
}