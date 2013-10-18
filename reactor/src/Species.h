#include <string> // use the string capabilities from the standard library

#ifndef ONCE_SPECIES_H
#define ONCE_SPECIES_H

namespace reactor
{

  class Species // A "class" is a user defined type with built-in functions
  {   
  public:
	  // three constructors
    Species(const std::string &input_name); // Declare constructor function.
    Species(const std::string &input_name, double input_concentration); // Declare constructor function.
    Species(const std::string &input_name, double input_concentration, double input_rate_of_change); // Declare constructor function.

	// getters
	// NOTE the const after each
    const  std::string & GetName() const {return name;};// Declare a get name function.
    double GetConcentration() const {return concentration;}
    double GetRateOfChange() const {return rate_of_change;}

	// setters
    void   SetConcentration(double new_concentration) {concentration=new_concentration;} // Set concentration
    void   AddToConcentration( double change_concentration ) {concentration += change_concentration;};
    void   ResetConcentration( void ) {concentration = 0;};
    void   ContributeToRateOfChange( double flux ) { rate_of_change += flux ;};

	// other member functions

  private:
    std::string name; // A member variable for the class to store the name of the system.
    double concentration;
    double rate_of_change;
  };
}

#endif //ONCE_SPECIES_H
