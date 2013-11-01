// We write comments like this


#include "Species.h" // Include our own library file for describing a reaction system
#include "Reaction.h" 

int main(int argument_count, char ** command_line_arguments) // Define the main function, which is the entry point to the program.
{ // C++ uses braces to start and end sections of code.
  
  std::cout << "The 'boiler plate' main program is running." << std::endl; // Print out a friendly message.
  // The << symbol is an output operator, while std::cout tells the message to go to "standard output", i.e. your terminal.
  
  reactor::Species calcium("Ca"); // You can declare new variables like this.
  // "Species" is a user defined type, or "class".
  
  std::cout << "A species was created called \"" << calcium.GetName() << "\"" << std::endl; // You use a dot to access a method of a class.
  // To get a quote symbol into a string, escape it with a slash
  // << can be used to chain several outputs together, in this case, a literal string,
  // and the output from calling GetName()

  reactor::Reaction myReaction;
  myReaction.AddReactants( &calcium );
  myReaction.AddProducts( &calcium );

  std::cout << "name in reaction " << myReaction.GetReactants()[0]->GetName() << std::endl;

  std::ostringstream output_buffer;
  output_buffer << myReaction;

  std::cout << output_buffer.str() ;

  return 0; // Exit successfully.
}
