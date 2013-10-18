
#include "Species.h"	// include the Species class
#include <vector>
#include <ostream>

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
	const std::vector< Species * >  GetReactants( void ) const { return reactants; };	// return vector of pointers
	const std::vector< Species * >  GetReactionProducts( void ) const { return products; };	
	// getters virtual
	// notice that there is no const after closing bracket!
	double GetFlux( void ) const ;

	// setters inline
	void SetReactionRate( double input_rate ){ reaction_rate = input_rate; };
	// setters virtual
	void AddReactants( Species * new_reactant );
	void AddProducts( Species * new_product);

	// other member functions
	void AddFluxToRates( double flux );


  private:
 	
	double reaction_rate;	
	std::vector<Species * >  reactants;
	std::vector<Species * >  products;
                          
  };
}

std::ostream & operator<<(std::ostream &s, const reactor::Reaction& reaction);

#endif //ONCE_REACTION_H
