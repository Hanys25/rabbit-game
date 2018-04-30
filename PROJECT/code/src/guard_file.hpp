#pragma once

#include <string>

class GuardFile
{
public:
    GuardFile(const std::string _file_name);
    ~GuardFile();
private:
    std::string guard_file_name;
};
