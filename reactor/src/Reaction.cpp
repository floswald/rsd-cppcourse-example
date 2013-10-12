
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

// member functions of Species

void reactor::Reaction::AddReactants( reactor::Species new_reactant ){ reactants.push_back( new_reactant ); };
