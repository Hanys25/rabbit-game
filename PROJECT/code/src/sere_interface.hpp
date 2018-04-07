#pragma once

#include <string>
#include <fstream>

class FileUtilities
{
public:
    FileUtilities (const std::string _file_name_with_path) : file_name_with_path(_file_name_with_path) {}
    void CreateFile();
    void SaveToFile(const char key);
    const char ReadFile();
    void RemoveFile();
private:
    void OpenFileToWriteWithClear();
    void OpenFileToRead();
    void CloseFile();

    std::fstream file;
    const std::string file_name_with_path;
};
