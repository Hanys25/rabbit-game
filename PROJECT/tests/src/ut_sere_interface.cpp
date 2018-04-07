#include <code/src/my_exception.hpp>
#include <code/src/sere_interface.hpp>

#include <gtest/gtest.h>
#include <string>

namespace constant {

const std::string file_name { "bin/plik.txt" };

} // namespace constant

class UtFileUtilities: public ::testing::Test
{
protected:
    void SetUp() override
    {
        EXPECT_FALSE(std::ifstream(constant::file_name));
    }

    void TearDown() override
    {
        EXPECT_FALSE(std::ifstream(constant::file_name));
    }

    void ExpectFileExistAndRemoveIt()
    {
        EXPECT_TRUE(std::ifstream(constant::file_name));
        file.RemoveFile();
    }

    void manualWritToFile(const std::string message)
    {
        std::fstream handle_to_file;
        handle_to_file.open(constant::file_name, std::ios::out);
        handle_to_file << message;
        handle_to_file.close();
    }

    FileUtilities file { constant::file_name };
};

TEST_F(UtFileUtilities, CreateFile)
{
    file.CreateFile();
    ExpectFileExistAndRemoveIt();
}

TEST_F(UtFileUtilities, SaveToFileWhileFileDoesnotExist)
{
    file.SaveToFile('e');
    ExpectFileExistAndRemoveIt();
}

TEST_F(UtFileUtilities, SaveToFileWhileFileExist)
{
    file.CreateFile();
    EXPECT_TRUE(std::ifstream(constant::file_name));
    file.SaveToFile('e');
    ExpectFileExistAndRemoveIt();
}

TEST_F(UtFileUtilities, ReadFromFileWhileFileDoesnotExist)
{
    EXPECT_THROW(file.ReadFile(), MyException);
}

TEST_F(UtFileUtilities, ReadFromFileWhileEmptyFileExist)
{
    file.CreateFile();
    EXPECT_TRUE(std::ifstream(constant::file_name));
    const char empty_char { file.ReadFile() };
    EXPECT_EQ(empty_char, '\0');
    ExpectFileExistAndRemoveIt();
}

TEST_F(UtFileUtilities, SaveAndReadFromFile)
{
    file.SaveToFile('e');
    EXPECT_EQ(file.ReadFile(), 'e');
    ExpectFileExistAndRemoveIt();
}

TEST_F(UtFileUtilities, SaveAndReadFromFileFewTimes)
{
    file.SaveToFile('e');
    EXPECT_EQ(file.ReadFile(), 'e');
    EXPECT_EQ(file.ReadFile(), 'e');
    file.SaveToFile('s');
    EXPECT_EQ(file.ReadFile(), 's');
    EXPECT_EQ(file.ReadFile(), 's');
    file.SaveToFile('b');
    file.SaveToFile('f');
    EXPECT_EQ(file.ReadFile(), 'f');
    EXPECT_EQ(file.ReadFile(), 'f');
    file.SaveToFile('b');
    file.SaveToFile('f');
    file.SaveToFile('g');
    file.SaveToFile('h');
    EXPECT_EQ(file.ReadFile(), 'h');
    EXPECT_EQ(file.ReadFile(), 'h');
    ExpectFileExistAndRemoveIt();
}

TEST_F(UtFileUtilities, ReadFromFile)
{
    manualWritToFile("some string\n more");
    EXPECT_EQ(file.ReadFile(), 's');
    EXPECT_EQ(file.ReadFile(), 's');
    manualWritToFile("enother string\n more");
    EXPECT_EQ(file.ReadFile(), 'e');
    EXPECT_EQ(file.ReadFile(), 'e');
    ExpectFileExistAndRemoveIt();
}
