#include <iostream>
#include "vector.h"

#include <iostream>
#include <string>

using std::string;


//quick overview of modifiers
//auto (eliminated as a specifier in C++11) 
//register <-- tell the compiler variable is heavily used( so store it in a register)
//             but is now deprecated
//static  <-- in a {} "block" tells the compiler to keep the value in memory
//            in "global" scope tells the compiler to only use internal linkage
//extern  <--- in "global" scope tells the compiler that this is defined in another file
//		This usage is NOT recommended unless absolutely necessary
//thread_local (added by C++11)  <-- used to keep the variable available as long as the thread is running
//
//mutable <-- Can change this variable even if the "parent" variable is constant
//const <-- compiler will try to make sure it is not modified
//volatile <-- compiler will not assume the value won't change by other programs/hardware.

struct Book{
  string author;
  string title;
  int numPages;
  mutable int numberOfTimesCheckedOut;
};

// function prototype
void strcount(const string &someString);

int main()
{
  
   std::cout << "Calling strcount() three times." << std::endl;
   string first = "Jeffrey";
   string middle = "Ray";
   string last = "Obadal";
   
   strcount(first);
   strcount(middle);
   strcount(last);
   
   //Create a const book with the variable name "myBook" and try to modify the different members.
   
   
   //Now create a pointer to myBook and modify the values
   
   //Create functiosn in the vector class to add and subtract vectors
   
   //What about comparing vectors? Would it make sense to even compare vectors?
   
   //Any other operations that would be good for vectors?
   
   
   return 0;
}

void strcount(const string &someString)
{
    using namespace std;

    static int total = 0; // static local variable

    int count = 0; // automatic local variable
    
    count = someString.size();
    
    total += count;
    cout << count << " characters\n";
    
    cout << total << " characters total\n";
}

