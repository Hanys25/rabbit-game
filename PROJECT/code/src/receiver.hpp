#pragma once

#include "sere_interface.hpp"

class Receiver
{
public:
    Receiver(const std::string path) : file_utilities{ path } { }
    ~Receiver() = default;
    Receiver(const Receiver& other) = delete;
    Receiver& operator=(const Receiver& other) = delete;
    Receiver(Receiver&& other) = delete;

    char ReceiveFromFile();
private:
    FileUtilities file_utilities;
};
