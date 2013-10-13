
#include "Reaction.h" // also includes Species.h
#include <gtest/gtest.h> 

using namespace reactor;


// define test fixture
// ===================
class ReactionTest: public ::testing::Test {
protected:
    Reaction myReaction;
    Species calcium;
    Species hydrogen;
    ReactionTest():
        myReaction(5.0),
        calcium("Ca"),
        hydrogen("H")
    {
    };
};


// Test wheter can set rate
TEST_F(ReactionTest, CanSetRate) { 
  myReaction.SetReactionRate( 1.1 );
  EXPECT_EQ( 1.1 , myReaction.GetReactionRate());
}

// Test whether can Get Rate
TEST_F(ReactionTest, ReactionHasRate) { // First argument is test 
                                        // fixture, second is test name
  EXPECT_EQ(5.0, myReaction.GetReactionRate()); // Assert that the reaction 
                                        // rate should be as expected
}

// Test if we can add a reactant to Reaction
TEST_F(ReactionTest, CanAddReactant){
	myReaction.AddReactants( calcium );
	EXPECT_EQ("Ca", myReaction.GetReactants()[0].GetName() );
}

// Test if we can add two reactants to Reaction
// NOTE: calcium is not preserved from previous test, because 
// the test fixture has the class members PROTECTED!
TEST_F(ReactionTest, CanAddSecondReactant){
	myReaction.AddReactants( calcium );
	myReaction.AddReactants( hydrogen );
	EXPECT_EQ("Ca", myReaction.GetReactants()[0].GetName() );
	EXPECT_EQ("H", myReaction.GetReactants()[1].GetName() );
}

// Test whether can add reactants and get concentrations out of reaction object
TEST_F(ReactionTest, CanGetConcentrationFromReaction) {
	// set a concentration rate for both reactants
	calcium.SetConcentration( 1.5 );
	hydrogen.SetConcentration( 1.0 );
	// add to myReaction
	myReaction.AddReactants( calcium );
	myReaction.AddReactants( hydrogen );
	EXPECT_EQ(1.5 , myReaction.GetReactants()[0].GetConcentration() );
	EXPECT_EQ(1.0 , myReaction.GetReactants()[1].GetConcentration() );
}

// Test whether flux computes correctly
TEST_F(ReactionTest, CanGetFlux) {
	// set a concentration rate for both reactants
	calcium.SetConcentration( 1.5 );
	hydrogen.SetConcentration( 1.0 );
	// add to myReaction
	myReaction.AddReactants( calcium );
	myReaction.AddReactants( hydrogen );
	// compute flux = reaction_rate * concentration1 * concentration2
	EXPECT_EQ( 5.0 * 1.5 * 1.0 , myReaction.GetFlux() );
}







// Tests outside of fixture
// ========================

TEST(ReactionTestIndividual, ConstructorWorks) { 
  Reaction R(1.1);
  EXPECT_EQ( 1.1 , R.GetReactionRate());
}


int main(int argc, char **argv) { // A main function scaffold to call the tests
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
