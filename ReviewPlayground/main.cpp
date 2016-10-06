#include <iostream>
#include <string>

int x = 3;

int main(int argc, char **argv) {
    // create book struct
    using namespace std;
    
    struct book{
      string author;
      int numPages;
    };
    
    book mybook = { "author", 345 };

    // create and initialize array of books
    book listOfBooks[10] = { {"authorOne", 3} , { "authorTwo", 345}, { "bookThree", 34  } };
    

    // create pointer to "anonymous" array of books
    int myInt_list[10]{1,2,3};
    int * myInt_ptr = new int[10]{1,2,3};  // What about int[3]?
    
    int array2DInt[][10] = { {1,2,3}, {1,2,3,4,5}, {1,2,3,4,5,9,9} };
    
    
    for (int i = 0; i < 10; i++)
    {
      std::cout << i << ": " << myInt_ptr[i] << std::endl;
    }
    
    // can't modify array list
    std::cout << "Non reference " << std::endl;
    for(  int x: myInt_list )
    {
      x *= 2;
      std::cout << x  << std::endl;
    }
    
    std::cout << "Value of list " << std::endl;
    for ( int x: myInt_list )
    {
      std::cout << x << std::endl;
    }
    // use reference, now can modify array list
    for( int &x: myInt_list )
    {
      x *= 2;
    }
    
    std::cout << "value of list after reference version " << std::endl;
    for ( int x: myInt_list )
    {
      std::cout << x << std::endl;
    }
    
    // So then why use this?
    for( const int &x: myInt_list )
    {      
      //x = 5;
    }
    
    std::cout << *myInt_ptr << std::endl;
    return 0;
}
