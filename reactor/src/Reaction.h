
#include "Species.h"	// include the Species class

#ifndef ONCE_REACTION_H
#define ONCE_REACTION_H

namespace reactor
{

  class Reaction {
  public:
	// constructor(s)

	// getters
	// NOTE the const after each
	double GetReactionRate( void ) const { return reaction_rate; };

	// setters
	void SetReactionRate( double input_rate ){ reaction_rate = input_rate; };

  private:
 	
	double reaction_rate;	
                          
  };
}

#endif //ONCE_REACTION_H
