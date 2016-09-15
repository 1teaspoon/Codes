#include <iostream>
#include <string>

// Inline functions
// Inline functions remove the function call within the compiled code, 
// and copy the compiled function directly to where it's called

// What are the advantages and disadvantages of this?  
// How could we test them?

inline int inlineSquare(int x, int y)
{
  return x * y;
}

int square(int x, int y)
{
  return x * y;
}


void printSection(std::string title){
  // finish in class
}

int main(int argc, char **argv) {
    
  //printSection("Performing Square function");
  
  // Add a for loop that you can use to test inlineSquaure and Square.
  // You could manually add timers to your code, or a profiler. However, 
  // for simplicity we'll use the linux "time" command.
  
  
}
