#include <code/src/guard_file.hpp>

#include <gtest/gtest.h>
#include <memory>
#include <fstream>

namespace constant {

const std::string file_name { "test_file" };
const std::string guard_file_name { file_name + "_guard" };

} // namespace constant

class UtGuardFile: public ::testing::Test
{
public:
protected:
    std::unique_ptr<GuardFile> guard_file { std::make_unique<GuardFile>(constant::file_name) };
};

TEST_F(UtGuardFile, OkCase)
{
    EXPECT_TRUE(std::ifstream(constant::guard_file_name));
    guard_file.reset();
    EXPECT_FALSE(std::ifstream(constant::guard_file_name));
}
