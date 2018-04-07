#pragma once

#include <exception>
#include <sstream>

class MyException: public std::exception
{
public:
    MyException(const std::string string_message, const char* function, const std::uint32_t line):
        error_message { createMessage(string_message, function, line) } {}
private:
    const std::string createMessage(const std::string message,
                                    const char* function,
                                    const std::uint32_t line)
    {
        std::stringstream _error_message;
        _error_message << message << " Funkcja: " << function << ", line: " << line;
        return _error_message.str();
    }

    virtual const char* what() const throw()
    {
        return error_message.c_str();
    }

    const std::string error_message;
};
