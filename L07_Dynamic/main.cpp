//  Dynamic Memory and arrays

#include <iostream>

// function declarations, this allows us to first use it in the code
// and later define it. Note the compiler only cares about the function "signature".
// That is the name of the function, and what parameters it takes.

// this function returns "nothing"
void dynamic_array(int);	

//This function returns a pointer to an int
int * get_dynamic_array(int);

//This function 
int * get_local_array(const int);

static int STATIC_VAR = 10000;

int main(int argc, const char * argv[])
{
    
    // Up until now you have used automatic storage. That is the compiler takes care of memory allocation.
    // The compiler will write the code to ask the OS for memory to store myNumbers[100], keep track of its address( &myNumbers ),
    // and finally delete it from memory when it's no longer in scope.
    int myNumbers[100] = {}; // The compiler will write the code to ask the OS for memory to store myNumbers[100]
    
    // Static variables or "static memory"
    // Static modifier means in general that the variable exist for the lifetime of the program,
    // or at least since the first instance of an object is created.
    // This will make more sense once we get to classes.
        
    // this is a static variable (see top of this source code file)
    std::cout << "Static Memory" << STATIC_VAR << std::endl;
    
    // Dynamic memory is when your program explicitly calls for the allocation or deletion of memory.
    // This is required when you don't know ahead of time how much storage you'll need.
    // For example if your program loads a list of numbers from a file.
    
    // Normally this is done at the library level or handled by the class itself.
    
    std::cout << "---------------------------------------------------------" << std::endl;
    std::cout << "Example 1: Dynamic double " << std::endl;
    std::cout << "---------------------------------------------------------" << std::endl;
    
    double * dynDouble= new double(100); // new double; also works for initalization
    std::cout << *dynDouble << std::endl;
    
    *dynDouble = double(200);
    std::cout << *dynDouble << std::endl;
    
    // When we allocate memory dynamically, C++ no longer takes care of memory management for us.
    // We have to manally allocate and deallocate memory, otherwise we get what is called a
    // memory leak. Deallocation is done using the delete operator.
    
    // delete dyn;
    
    // Q: What if we just allocated another new double to this pointer without
    // calling delete first?
    
    std::cout << "ADDRESS 1:" << dynDouble << std::endl;
    dynDouble = new double[50];
    std::cout << "ADDRESS 2:" << dynDouble << std::endl;
    
    // The address is different, because we allocated new memory for another double variable.
    // The previous double (unless we retained it's address in another pointer variable)
    // is no longer accessible and *cannot* be deallocated. This is a memory leak.
    
    
    // Which version of delete do you think we should use?
    //delete[] dynamicDoubleArray;
    //delete dynamicDoubleArray;
    
    std::cout  << std::endl;
    
    // ----------------------------------------------------------------
    // EXAMPLE 2: Dynamic Arrays
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "EXAMPLE 2: Dynamic Arrays" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    // ----------------------------------------------------------------
    
    // So far we've mostly encountered static arrays, which are limited
    // to a fixed (static) size determined at compile time. A more common
    // case is when we want to declare an array of some size determined at runtime.
    dynamic_array(10);
    
    std::cout <<  std::endl;
    
    // ----------------------------------------------------------------
    // EXAMPLE 3: Returning arrays
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "EXAMPLE 3: Returning Arrays" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    
    
    // In C++ using new and delete you must remember to delete memory allocated with new.
    // Otherwise you program will "leak" memory. That is it will keep using more and more memory 
    // if you have a loop that calls new, but never deletes the memory after it's finished.
    
    int len = 15;
    int * array = get_dynamic_array(len);
    
    for(int i=0;i<len;i++)
    {
        std::cout << "array[" << i << "] == " << array[i] << std::endl;
    }
    
    delete [] array;
    
    std::cout << std::endl;
    
  
    // 2. Could we write a function that returns a statically declared array?
  
    // This will compile
    int * array2 = get_local_array(len);
    
    for(int i=0;i<len;i++)
    {
        std::cout << "array2[" << i << "] == " << array2[i] << std::endl; // this will print a bunch of garbage!
    }
    
    // However if we attempt to delete the memory (which was locally scoped and
    // released when the function returned, we will get a runtime error.
    //delete [] array2;
    
    return 0;
}


// Allocate a dynamic array of ints and show some pointer arithmetic.
void dynamic_array(int len)
{       
    int * ptr = new int[len];
    
    for(int i=0; i<len; i++)       // initialize array
    {
        ptr[i] = i+1;
    }
    
    for(int i=0; i<len; i++)       // increment pointer
    {
        std::cout << *(ptr+i) << std::endl;
    }
    
    delete [] ptr;                 // delete entire array -- notice the sytax is difference when deleting an array
    
}

int * get_dynamic_array(int len)
{
    int * numbers = new int[len];
    
    for(int i=0; i<len; i++)       // initialize array
    {
        numbers[i] = i+1;
        std::cout << numbers[i] << std::endl;
    }
    
    return numbers;                 // remember numbers is just a pointer to the first element of the array
}

// Would this function works? Why or why not?
int * get_local_array(const int len)
{
    int numbers[len];
    
    for(int i=0; i<len; i++)       // initialize array
    {
        numbers[i] = i+1;
        std::cout << numbers[i] << std::endl;
    }
    
    return numbers;                 // remember numbers is just a pointer to the first element of the array
}
