#include "../src/Message1.h"
#include <gtest/gtest.h>

TEST(reflection, message)
{

    EXPECT_NO_THROW(AutoFactory::ProduceShared("message1"));
    auto ps = AutoFactory::ProduceShared("message1");

    std::string message = ps->show();
    EXPECT_STREQ("Message1", message.c_str());
    EXPECT_THROW(AutoFactory::ProduceShared("message2"), std::invalid_argument);
}
