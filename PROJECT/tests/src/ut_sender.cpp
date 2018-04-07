#include <code/src/sender.hpp>

#include <gtest/gtest.h>
#include <string>

namespace constant {

const std::string file_name { "bin/plik.txt" };

} // namespace constant

class UtSender: public ::testing::Test
{
protected:
    Sender sender { constant::file_name };
};

TEST_F(UtSender, SendToFile)
{
    sender.SendToFile('e');
}
