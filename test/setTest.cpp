#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "Set.h"

TEST(set, makeset) {
  Set s(1);
  EXPECT_EQ(0, s.find(0));
}

TEST(set, makeMore) {
  Set s(7);
  EXPECT_NE(1, s.find(0));
  EXPECT_EQ(6, s.find(6));
}

TEST(set, link) {
  Set s(2);
  EXPECT_NE(s.find(0), s.find(1));
  s.link(1, 0);
  EXPECT_EQ(s.find(0), s.find(1));
}

TEST(set, linkMore) {
  Set s(4);
  s.link(1, 0);
  s.link(2, 3);
  EXPECT_EQ(s.find(2), s.find(3));
  EXPECT_NE(s.find(1), s.find(3));
}


TEST(set, ranking) {
  Set s(4);
  s.link(1, 0);
  s.link(1, 2);
  s.link(1, 3);
  EXPECT_EQ(s.find(2), s.find(3));
  EXPECT_EQ(s.find(1), s.find(3));
  EXPECT_EQ(s.find(0), s.find(3));
  
  s.dump();
}


int main(int argc, char** argv) { 
    testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS(); 
}
