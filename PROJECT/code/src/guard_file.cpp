#include "guard_file.hpp"

#include <fstream>
#include <iostream> // TODO - change to loger

GuardFile::GuardFile(const std::string file_name):
    guard_file_name { file_name + "_guard" }
{
    if (std::ifstream(guard_file_name)) {
        std::cerr << "File already exists: " << guard_file_name << std::endl; // TODO - loger
        std::cerr << "(Pewnie źle zakończyłeś program... usun go teraz recznie)" << std::endl; // TODO - loger
    }
    while (std::ifstream(guard_file_name)) {}
    std::ofstream { guard_file_name.c_str() };
}

GuardFile::~GuardFile()
{
    std::remove(guard_file_name.c_str());
}
