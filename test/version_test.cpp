#include <gtest/gtest.h>
#include "lib.h"

TEST(test_version_valid, test_version_valid)
{
    ASSERT_TRUE(version() > 0);
}
