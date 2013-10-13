
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

	// getters inline
	const double GetReactionRate( void ) const { return reaction_rate; };		// note const
	const std::vector< Species > & GetReactants( void ) const { return reactants; };	// return reference to reactants vector
	const std::vector< Species > & GetReactionProducts( void ) const { return products; };	// return reference to reactants vector
	// getters virtual
	// notice that there is no const after closing bracket!
	double GetFlux( void ) const ;

	// setters inline
	void SetReactionRate( double input_rate ){ reaction_rate = input_rate; };
	// setters virtual
	void AddReactants( Species & new_reactant );
	void AddProducts( Species & new_product);

  private:
 	
	double reaction_rate;	
	std::vector<Species>  reactants;	// why is this not a std::vector<Species> &   ? 
	std::vector<Species>  products;
                          
  };
}

#endif //ONCE_REACTION_H
