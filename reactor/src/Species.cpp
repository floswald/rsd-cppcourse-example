#include "Species.h" // Include the declaration of the Species..

// implementation for the species class
// ====================================


// Constructor of Species class
// note syntactic sugar: the colon at end of first line precedes a list of 
// comma separated values to be initialised. that's an INITIALISER LIST.

// Constructor No 1
reactor::Species::Species(const std::string &input_name):
    name(input_name), concentration(0)
  {
    // do nothing
  }

// Constructor No 2
reactor::Species::Species(const std::string &input_name, double input_concentration):
    name(input_name), concentration(input_concentration)
  {
    // do nothing
  }

// member functions of Species

//const std::string & reactor::Species::GetName() const
//{ 
	//// a function whose return type is a standard string, with no input arguments
	//// the ampersand and const will be explained later.
	//return name; // give the name variable result back
//}

