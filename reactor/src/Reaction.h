
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
	const std::vector< Species > & GetReactants( void ) const { return reactants; };	// return reference to reactants vector
	const std::vector< Species > & GetReactionProducts( void ) const { return products; };	// return reference to reactants vector

	// setters
	void SetReactionRate( double input_rate ){ reaction_rate = input_rate; };
	void AddReactants( Species & new_reactant );
	void AddProducts( Species & new_product);

  private:
 	
	double reaction_rate;	
	std::vector<Species>  reactants;	// why is this not a std::vector<Species> &   ? 
	std::vector<Species>  products;
                          
  };
}

#endif //ONCE_REACTION_H
