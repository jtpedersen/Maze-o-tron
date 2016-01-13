#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <Cell.h>

TEST(cell, lt) {
  Cell a(0,0);
  Cell b(1,1);

  EXPECT_LT(a,b) << a << "<" << b;
}

TEST(cell, noLink) {
  Cell a(0,0);
  Cell b(1,1);

  EXPECT_FALSE(a.linked(&b));
  EXPECT_FALSE(b.linked(&a));
}

TEST(cell, link) {
  Cell a(0,0);
  Cell b(1,1);

  a.link(&b);
  EXPECT_TRUE(a.linked(&b));
  EXPECT_TRUE(b.linked(&a));
}

TEST(cell, E) {
  Cell a(0,0);
  Cell b(1,1);

  a.E = &b;
  a.link(&b);

  EXPECT_TRUE(a.linked(a.E));
  EXPECT_TRUE(a.E->linked(&a));
}

int main(int argc, char** argv) { 
    testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS(); 
}
