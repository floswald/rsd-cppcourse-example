
#include "Species.h"	// include the Species class
#include <vector>

#ifndef ONCE_REACTION_H
#define ONCE_REACTION_H

namespace reactor
{

  class Reaction {
  public:
	// constructor(s)
	Reaction( double input_rate );
	Reaction( void );

	// getters
	// NOTE the const after each
	double GetReactionRate( void ) const { return reaction_rate; };
	double GetReactionProduct( void ) const { return reaction_product; };
	std::vector<Species> GetReactants( void ) const { return reactants; };

	// setters
	void SetReactionRate( double input_rate ){ reaction_rate = input_rate; };
	void AddReactants( Species new_reactant );

  private:
 	
	double reaction_rate;	
	double reaction_product;	
	std::vector<Species> reactants;
                          
  };
}

#endif //ONCE_REACTION_H
