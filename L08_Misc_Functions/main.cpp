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

// Try to modify variable with normal data type passing
void modifyInt( int A);

// Tries to modify variable with pass by reference
void modifyReferenceInt( int &A);

void printSection(std::string title){
  // finish in class
}

int main(int argc, char **argv) {
    
  //printSection("Performing Square function");
  
  // Add a for loop that you can use to test inlineSquaure and Square.
  // You could manually add timers to your code, or a profiler. However, 
  // for simplicity we'll use the linux "time" command.
  
  
  //printSection("References");
  
  // References allow us to create aliases for variables
  // They're most useful for functions where we don't want to make new copies of the data.
  
  std::string myName = "Jeffrey";
  std::string * myName_ptr = &myName;
  std::string & stillMyName = myName;
  std::string & alsoMyName = *(myName_ptr);
  
  std::cout << "myName = " << myName << std::endl;
  std::cout << "Address of myName_ptr: " << myName_ptr << std::endl;
  std::cout << "Address of alsoMyName: " << &alsoMyName << std::endl;
  
  std::cout << std::endl;
  std::cout << "assign stillMyName = \"Obadal\"" << std::endl;
  std::cout << std::endl;
  
  stillMyName = "Obadal";
  
  std::cout << "myName = " << myName << std::endl;
  std::cout << "Address of myName_ptr: " << myName_ptr << std::endl;
  std::cout << "Address of alsoMyName: " << &alsoMyName << std::endl;
  
  std::cout << "myName = " << myName << std::endl;
  std::cout << "Address of myName_ptr: " << myName_ptr << std::endl;
  std::cout << "Address of alsoMyName: " << &alsoMyName << std::endl;
  
  //printSection("Default Values and variadic arguments")
  
  // If you look at the "square" function earlier you can see that it uses function overloading
  // You can set the default arguments in the prototype to avoid excessive function overloading
  
  
  
  // However, if you have noticed that the command line arguments have no limits, so how does that work?
  // For the curious you can look up variadic functions and templates
  
  
  // Add any examples or answers to problems from the homework and/or quiz

  
  return 0;  
}
