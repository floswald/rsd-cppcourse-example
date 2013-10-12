
#include "Reaction.h" // Include the code that we are testing
#include <gtest/gtest.h> // Include the google test framework

using namespace reactor;

TEST(ReactionTest, CanSetRate) { 
  Reaction R;
  R.SetReactionRate( 1.1 );
  EXPECT_EQ( 1.1 , R.GetReactionRate());
}



int main(int argc, char **argv) { // A main function scaffold to call the tests
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
