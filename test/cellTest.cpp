#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <Cell.h>
#include <Grid.h>

class CellTest : public ::testing::Test {
public:
  CellTest() {
    grid = new Grid(3,3);
  }
  ~CellTest() {
    delete grid;
  }

public:
  Grid *grid;
};

TEST_F(CellTest, instantiate) {
  Cell c(grid,0,0);
}

int main(int argc, char** argv) { 
    testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS(); 
}
