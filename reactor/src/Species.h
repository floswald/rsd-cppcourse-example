#include <string> // use the string capabilities from the standard library

#ifndef ONCE_SPECIES_H
#define ONCE_SPECIES_H

namespace reactor
{

  class Species // A "class" is a user defined type with built-in functions
  {   
  public:
	  // two constructors: one with name only, one with name and initial concentration.
    Species(const std::string &input_name); // Declare constructor function.
    Species(const std::string &input_name, double input_concentration); // Declare constructor function.

	// getters
	// NOTE the const after each
    const  std::string & GetName() const {return name;};// Declare a get name function.
    double GetConcentration() const {return concentration;}

	// setters
    void   SetConcentration(double new_concentration) {concentration=new_concentration;} // Set concentration
    void   AddToConcentration( double change_concentration ) {concentration += change_concentration;};

  private:
    std::string name; // A member variable for the class to store the name of the system.
    double concentration;
    double rate_of_change;
  };
}

#endif //ONCE_SPECIES_H
