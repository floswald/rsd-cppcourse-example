
#include "Reaction.h" 

// implementation for the reactor class
// ====================================


// Constructors
reactor::Reaction::Reaction( double input_rate ) :
	reaction_rate( input_rate )
{
}

reactor::Reaction::Reaction( void ) :
	reaction_rate( 1.1 )
{
}

// member functions of Reaction

void reactor::Reaction::AddReactants( reactor::Species * new_reactant ){ reactants.push_back( new_reactant ); };
void reactor::Reaction::AddProducts( reactor::Species * new_product){ products.push_back( new_product); };

// Get Flux of Reaction
// multiply reaction_rate with Concentration of each reactant
double reactor::Reaction::GetFlux( void ) const {
	double flux = reaction_rate;	// initiate at constant rate of reaction

	for (std::vector< reactor::Species * >::const_iterator elt  = reactants.begin();	// if method is const, iterator must be const as well
			                                       elt != reactants.end();
												   elt ++ ) {
		flux *= (*elt)->GetConcentration() ;	// First dereference the pointer to Species elt with (*elt), then get it's concentration
	}
	return flux;
}

