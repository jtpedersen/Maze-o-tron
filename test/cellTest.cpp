#include "gtest/gtest.h"
#include "gmock/gmock.h"

TEST(suite, name) {
  EXPECT_TRUE(false) << "hello World";
}


int main(int argc, char** argv) { 
    testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS(); 
}
