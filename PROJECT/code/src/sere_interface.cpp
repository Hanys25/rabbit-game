#include "guard_file.hpp"
#include "my_exception.hpp"
#include "sere_interface.hpp"

#include <iostream> // TODO - change to loger
#include <memory>

void FileUtilities::OpenFileToWriteWithClear()
{
    file.open(file_name_with_path, std::ios::out);
    if (!file.good()) {
        throw MyException("Some error while write to file.", __func__, __LINE__);
    }
}

void FileUtilities::OpenFileToRead()
{
    file.open(file_name_with_path, std::ios::in);
    if (!file.good()) {
        throw MyException("File doesn't exist.", __func__, __LINE__);
    }
}

void FileUtilities::CloseFile()
{
    file.close();
}

void FileUtilities::CreateFile()
{
    std::unique_ptr<GuardFile> guard { std::make_unique<GuardFile>(file_name_with_path) };
    if (std::ifstream(file_name_with_path)) {
        std::cout << "File already exist." << std::endl; // TODO - loger
    }
    std::ofstream { file_name_with_path.c_str() };
}

void FileUtilities::SaveToFile(const char key)
{
    OpenFileToWriteWithClear();
    file << key;
    CloseFile();
}

const char FileUtilities::ReadFile()
{
    char key;
    std::unique_ptr<GuardFile> guard { std::make_unique<GuardFile>(file_name_with_path) };
    OpenFileToRead();
    file >> key;
    CloseFile();
    return key;
}

void FileUtilities::RemoveFile()
{
    std::unique_ptr<GuardFile> guard { std::make_unique<GuardFile>(file_name_with_path) };
    if (std::remove(file_name_with_path.c_str())) {
        std::cout << "File doesn't exist." << std::endl; // TODO - loger
    }
}
