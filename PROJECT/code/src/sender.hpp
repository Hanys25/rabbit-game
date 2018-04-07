#pragma once

#include "sere_interface.hpp"

class Sender
{
public:
    Sender(const std::string path): file_utilities(path) { }
    ~Sender() = default;
    Sender(const Sender& other) = delete;
    Sender& operator=(const Sender& other) = delete;
    Sender(Sender&& other) = delete;

    void SendToFile(const char key);
private:
    FileUtilities file_utilities;
};
