#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <Cell.h>
#include <Grid.h>

TEST(grid, basic) {
  Grid g(2,2);
}

TEST(grid, noLinks) {
  Grid g(2,2);
  for(auto a: g.cells)
    for(auto b: g.cells)
      EXPECT_FALSE(a.linked(&b)) << a << " link " << b;
}

TEST(grid, basicLinks) {
  Grid g(2,2);
  auto a = g.get(0,0);
  auto b = g.get(0,1);

  EXPECT_FALSE(a->linked(b)) << a << " link " << b;
}

TEST(grid, basicStructure) {
  Grid g(2,2);
  auto a = g.get(0,0);
  EXPECT_EQ(a->E, g.get(1,0));
  EXPECT_EQ(a->S, g.get(0,1));

  auto b = g.get(1,1);
  EXPECT_EQ(b->W, g.get(0,1));
  EXPECT_EQ(b->N, g.get(1,0));
}

TEST(gridd, edgeCount) {
  Grid g(3,3);
  EXPECT_EQ(0, g.edgeCount());

  g.get(1,1)->link( g.get(0,1));
  EXPECT_EQ(2, g.edgeCount());
}

int main(int argc, char** argv) { 
    testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS(); 
}
