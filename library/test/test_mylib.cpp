#include "gtest/gtest.h"

#include "mylib/mylib.h"

TEST(mylib_init_should, return_zero)
{
    ASSERT_EQ(0, mylib_init());
}
