#include "Species.h" // Include the code that we are testing
#include <gtest/gtest.h> // Include the google test framework

using namespace reactor;



// Test that the system has a name as expected.
TEST(SpeciesTest, SpeciesHasAName) { // First argument is test group, second is test name
  Species mySpecies("SomeName"); // Create a species with a specified name
  EXPECT_EQ("SomeName", mySpecies.GetName()); // Assert that the name should be as expected
}

// Test first constructor: default values
// ======================================
  
TEST(SpeciesTest, SpeciesHasADefaultConcentration) {
  Species mySpecies("SomeName"); 
  EXPECT_EQ(1, mySpecies.GetConcentration()); 
}

TEST(SpeciesTest, SpeciesHasADefaultRate) { 
  Species mySpecies("SomeName"); 
  EXPECT_EQ(1, mySpecies.GetRateOfChange()); 
}

// Test that we can set a concentration
TEST(SpeciesTest, CanSetSpeciesConcentration) { // First argument is test group, second is test name
  Species mySpecies("SomeName"); // Create a species with a specified name
  EXPECT_EQ(1, mySpecies.GetConcentration()); // check that default constructor initializes at zero concentration.
  mySpecies.SetConcentration(2.0);
  EXPECT_EQ(2.0, mySpecies.GetConcentration()); 
}

// Test second constructor
TEST(SpeciesTest, SecondConstructorSetsConcentration) {
	//initialize a Species
	Species mySpecies("thatName",14.5);
	EXPECT_EQ(14.5, mySpecies.GetConcentration());
}

// Test third constructor
TEST(SpeciesTest, ThirdConstructorSetsRate) {
	//initialize a Species
	Species mySpecies("thatName",14.5,1.5);
	EXPECT_EQ(14.5, mySpecies.GetConcentration());
	EXPECT_EQ(1.5, mySpecies.GetRateOfChange());
}

// Test can add to concentraction
TEST(SpeciesTest, CanAddToConcentration) {
	//initialize a Species
	Species mySpecies("thatName",0.5);
	// add to concentration
	mySpecies.AddToConcentration( 0.6 );
	EXPECT_EQ(1.1 , mySpecies.GetConcentration());
}

// Can Reset Concentration
TEST(SpeciesTest, ResetConcentration){
	Species mySpecies("Calcium",1.1);
	EXPECT_EQ(1.1 , mySpecies.GetConcentration());
	mySpecies.ResetConcentration();
	EXPECT_EQ(0 , mySpecies.GetConcentration());
}

// Contribute to Rate of change
TEST(SpeciesTest, CanContributeToRate) {
	Species mySpecies("Calcium",1.0);
	mySpecies.ContributeToRateOfChange( 0.4 );
	EXPECT_EQ( 1.4 , mySpecies.GetRateOfChange());
}




int main(int argc, char **argv) { // A main function scaffold to call the tests
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
