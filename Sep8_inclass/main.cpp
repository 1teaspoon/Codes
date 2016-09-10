#include <iostream>

// <return type> <function name> ( parameters );

double addTwo(int x, int y){
  return 0;
}

int main(int argc, char **argv) {
    std::cout << addTwo(6.88,2.0) << std::endl;
    std::cout << addTwo(1.0,2.0) << std::endl;
  
    std::cout << "Enter an integer: ";
    
    int inputInt{};
    
    std::cin >> inputInt;    
    
    std::cout << "Error flag: " << std::cin.fail() << std::endl;
    
    std::cout << "Input int: " << inputInt << std::endl;
    
  //Thursday September 8th
  //Pointers and Functions

 
   int a = 3.5;
   int v{100};
   int* ptr = &v;  // This stores the "address" of int v in an "int pointer"
   
   // sanity check 
   std::cout << "Value of v: " << v << std::endl;
   std::cout << "Address of v: " << &v << std::endl;
   std::cout << "Value of ptr: " << ptr << std::endl;
   std::cout << "*ptr: " << *ptr << std::endl;
   
   //use the dereferenced int pointer just like an int
   *ptr = 123;
   
   std::cout << "Value of v: " << v << std::endl;
   
   int e{200};
   
   //One can freely change the value of the pointer to the address of any int
   ptr = &e;
   *ptr = 919;
         
   // What happens if we try to point it to a double?
   
   double height{6.3};
   double* double_ptr = &height;
   
   
   int length = 5;
   // Arrays are implemented with pointers
   int errorList[5] = {1, 2, 3, 4, 5};
   
   // how to make a loop that prints out all of the values?
   
   for(int i = 0; i < length; i++)
   {
      std::cout << i << ":" << errorList[i] << std::endl;  
   }
   
   std::cout << "errorList: " << errorList << std::endl;
   std::cout << "&errorList: " << &errorList << std::endl;
   std::cout << "&errorList[0]: " << &errorList[0] << std::endl;
   
   std::cout << std::endl;
   std::cout << std::endl;
   
   // Do you think sizeof() will be the same? Why or why not?
   
   std::cout << "size of errorList: " << sizeof(errorList) << std::endl;
   std::cout << "size of errorList[0]" << sizeof(errorList[0]) << std::endl;
   std::cout << "size of &errorList: " << sizeof(&errorList) << std::endl;
   std::cout << "size of &errorList[0]: " << sizeof(&errorList[0]) << std::endl;
   
   std::cout << std::endl;
   std::cout << std::endl;
   
   // Pointer arithmetic
   // Pointers add the multiple of the size of the type
   
   // What will this be?
   int* ptr_errorList = &errorList[0];
   ptr_errorList++;
   std::cout << "First elment: ptr_errorList++ : " << ptr_errorList << std::endl;
   std::cout << "First element: *ptr_errorList : " << *ptr_errorList << std::endl;
   
   // And this? Is this ever a good idea?
   std::cout << "&Entire array + 1: " << &errorList + 1 << std::endl;  
     
   //Functions
   
   
   return 0;
}
