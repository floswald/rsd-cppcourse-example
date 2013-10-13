#include "Species.h" // Include the declaration of the Species..

// implementation for the species class
// ====================================


// Constructor of Species class
// note syntactic sugar: the colon at end of first line precedes a list of 
// comma separated values to be initialised. that's an INITIALISER LIST.

// Constructor No 1
reactor::Species::Species(const std::string &input_name):
    name(input_name), concentration(1), rate_of_change(1)
  {
    // do nothing
  }

// Constructor No 2
reactor::Species::Species(const std::string &input_name, double input_concentration):
    name(input_name), concentration(input_concentration), rate_of_change(1)
  {
    // do nothing
  }

// Constructor No 3
reactor::Species::Species(const std::string &input_name, double input_concentration, double input_rate_of_change):
    name(input_name), concentration(input_concentration), rate_of_change(input_rate_of_change)
  {
    // do nothing
  }
