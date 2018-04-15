#include <code/src/my_exception.hpp>
#include <code/src/receiver.hpp>

#include <gtest/gtest.h>
#include <string>

namespace constant {

const std::string file_name { "bin/plik.txt" };

} // namespace constant

class UtReceiver: public ::testing::Test
{
protected:
    Receiver receive { constant::file_name };
};

TEST_F(UtReceiver, ReceiveFileDoesnotExist)
{
    EXPECT_THROW(receive.ReceiveFromFile(), MyException);
}
