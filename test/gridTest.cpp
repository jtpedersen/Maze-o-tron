#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <Cell.h>
#include <Grid.h>

#include <algorithm>

TEST(grid, basic) {
  Grid g(2,2);
}

TEST(grid, noLinks) {
  Grid g(2,2);

  for(int a = 0; a < g.size(); a++) {
    for(int b = 0; b < g.size(); b++) {
      EXPECT_FALSE(g.linked(a, b)) << a << " link " << b;
    }
  }
}

TEST(grid, basicLinks) {
  Grid g(2,2);
  auto a = g.idx(0,0);
  auto b = g.idx(0,1);

  EXPECT_FALSE(g.linked(a,b)) << a << " link " << b;
}

TEST(grid, basicStructure) {
  Grid g(2,2);
  auto a = g.get( g.idx(0,0));
  EXPECT_EQ(a->E, g.idx(1,0));
  EXPECT_EQ(a->S, g.idx(0,1));

  auto b = g.get(g.idx(1,1));
  EXPECT_EQ(b->W, g.idx(0,1));
  EXPECT_EQ(b->N, g.idx(1,0));
}

TEST(grid, addEdge) {
  Grid g(2,2);
  EXPECT_FALSE( g.linked(0,1));
  g.addEdge(0, 1);
  EXPECT_TRUE( g.linked(0,1));
}


// TEST(grid, directionLinks) {
//   Grid g(3,3);
//   auto center = g.get(1,1);
//   center->link( center->E);
//   EXPECT_TRUE( center->linked( center->E));
//   EXPECT_TRUE( center->E->linked( center));
// }

// test(grid, directionLinksW) {
//   Grid g(3,3);
//   auto center = g.get(1,1);
//   center->link( center->W);
//   EXPECT_TRUE( center->linked( center->W));
//   EXPECT_TRUE( center->W->linked( center));
// }

// TEST(grid, directionLinksS) {
//   Grid g(3,3);
//   auto center = g.get(1,1);
//   center->link( center->S);
//   EXPECT_TRUE( center->linked( center->S));
//   EXPECT_TRUE( center->S->linked( center));
// }

// TEST(grid, directionLinksN) {
//   Grid g(3,3);
//   auto center = g.get(1,1);
//   center->link( center->N);
//   EXPECT_TRUE( center->linked( center->N));
//   EXPECT_TRUE( center->N->linked( center));
// }

// TEST(grid, allInThere) {
//   Grid grid(3,3);

//   EXPECT_FALSE(grid.contains((Cell*) 42));
  
//   for(auto& c: grid.cells) {
//     Cell* dirs[] = {c.N, c.E, c.S, c.W};
//     for(auto d: dirs) {
//       if (!d)
// 	continue;
//       EXPECT_TRUE( grid.contains(d));
//     }
//   }
  
// }

// TEST(grid, edgeCount) {
//   Grid g(3,3);
//   EXPECT_EQ(0, g.edgeCount());

//   g.get(1,1)->link( g.get(0,1));
//   EXPECT_EQ(2, g.edgeCount());
// }



int main(int argc, char** argv) { 
  testing::InitGoogleTest(&argc, argv); 
  return RUN_ALL_TESTS(); 
}
