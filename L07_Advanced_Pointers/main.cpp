//
//  pointers2.cpp
//  pointers
//
//  Created by Jason Fries on 9/19/13.
//  Copyright (c) 2013 Jason Fries. All rights reserved.
//

#include <iostream>
#include <math.h>

int square(int i);
int cube(int i);
double product(double x, double y);

void apply(int data[], int n, int (*pf)(int) );    // this takes an array function as an argument
void print_array(int data[], int n);

int main(int argc, const char * argv[])
{
    using namespace std;
    
    //
    // I. Pointers Continued
    //
    cout << "============================================" << endl;
    cout << "I. Pointers Continued " << endl;
    cout << "============================================" << endl;
    
    // ----------------------------------------------------------------
    // EXAMPLE 1: Strings & Pointers
    cout << "--------------------------------------------" << endl;
    cout << "EXAMPLE 1: Strings & Pointers" << endl;
    cout << "--------------------------------------------" << endl;
    // ----------------------------------------------------------------
    
    // Since strings are just really a sequence of characters,
    // you can use pointer arithmatic in a similar fashion to
    // iterate through a string
    
    string s = "the lone and level sands stretch far away.";
    char * s_ptr = &s[0];

    for(int i=0;i<s.length();i++)
    {
        cout << *(s_ptr+i) << " ";
        
    }
    cout << endl << endl;
    
    // ----------------------------------------------------------------
    // EXAMPLE 2: cout, string pointers and c-style strings
    cout << "--------------------------------------------" << endl;
    cout << "EXAMPLE 3: cout, string pointers and c-style strings" << endl;
    cout << "--------------------------------------------" << endl;
    // ----------------------------------------------------------------
    
    // NOTE: One subtle difference between a pointer to a dymamically
    // allocated string object and a locally allocated string object is
    // illustrated below
    
    string * dyn_str = new string("foobar"); // dynamically allocate sing

    cout << dyn_str << " " << &dyn_str[0] << endl; // this prints out as a memory address
    cout << *dyn_str << endl; // this prints out the actual string

    // Compare the above to what happens with the locally stored string variable s
    cout << s_ptr << " " << &s[0] << endl; // this prints out the entire string!
    
    const char str_literal[] = "this is a string literal (c-style string)";
    //const char * str_literal = "this is a string literal (c-style string)"; // also valid syntax
    cout << str_literal << endl;
    
    // cout interprets a pointer to a c-style string, which outputs the entire string to stdout
    // if you want to actually print the memory address, you need to type cast the varaible
    cout << long(s_ptr) << " " << long(&s[0]) << endl << endl;

    delete dyn_str;
    
    // ----------------------------------------------------------------
    // EXAMPLE 3: 2D Dynamic Arrays
    cout << "--------------------------------------------" << endl;
    cout << "EXAMPLE 3: 2D Dynamic Arrays" << endl;
    cout << "--------------------------------------------" << endl;
    // ----------------------------------------------------------------
    
    // You might be tempted to use a declaration like this ..
    
    // int * twodee = new int[4][4];
    
    // but that's not actually going to work! A 2D array is really just
    // an array of pointers, pointing to some data type. That means the
    // declaration type is a pointer to a pointer!
    int ** twodee = new int *[4];
    for(int i=0;i<4;i++)
    {
        twodee[i] = new int[4];
    }
    
    // Now we can use the 2D array as expected
    twodee[0][2] = 10;
    twodee[0][0] = 8;
    cout << "0:2 " << twodee[0][2] << endl;
    cout << "0:0 " << twodee[0][0] << endl;
    
    // But deleting the array is now rather cumbersome.
    for(int i=0;i<4;i++)
    {
        delete [] twodee[i];
    }
    delete [] twodee;
    
    cout << endl;
    
    // ----------------------------------------------------------------
    // EXAMPLE 4: 2D Dynamic Arrays -- a better way
    cout << "--------------------------------------------" << endl;
    cout << "EXAMPLE 4: 2D Dynamic Arrays" << endl;
    cout << "--------------------------------------------" << endl;
    // ----------------------------------------------------------------
    
    // A better way to allocate a 2D (or any multidimensional array)
    // is to allocate one big block of memory and just change how we
    // index into that 1D array.
    
    int m = 4, n = 2;
    int * flat2D = new int[m * n];                            // 4x4 array == 16 indexable slots
    
    for(int i=0; i<m; i++)
    {   for(int j=0; j<n; j++)
        {
            flat2D[i * n + j] = i * n + j;
        }
    }
    
    // how does this actually look if we iterated through the array 1 element at a time?
    for(int i=0; i < m * n; i++)
    {
        cout << flat2D[i] << " ";
    }
    cout << endl;
    
    // compared to the standard matrix form
    for(int i=0; i < m; i++) {
        cout << "| " ;
        for(int j=0; j < n; j++) {
            cout << flat2D[i*n+j] << " ";
        }
        cout << "|" << endl;
    }
    
    delete [] flat2D;                                                   // deleting is now pretty easy
    
    cout << endl;
    
    //
    // II. Function Pointers
    //
    cout << "============================================" << endl;
    cout << "II. Function Pointers " << endl;
    cout << "============================================" << endl;
    
    
    int * numbers = new int[4];
    for(int i=0; i<4; i++)
    {
        numbers[i]  = int(rand() % 10) + 1;                             // deterministically "random"
    }
    
    // ----------------------------------------------------------------
    // EXAMPLE 1: Creating pointers to functions
    cout << "--------------------------------------------" << endl;
    cout << "EXAMPLE 1: Pointers to functions" << endl;
    cout << "--------------------------------------------" << endl;
    // ----------------------------------------------------------------
    
    // Just like named variables, functions themselves reside in a memory location and
    // can be accessed using pointers. Why would you want to do this?
    
    int (*pf)(int);
    
    int * pf2(int);                                    // Q: Why do we use paranthesis in the above function pointers? Could we use this syntax?
    
    pf = square;
    
    //pf = product;                                    // INVALID! Neither the return type or arugment list match, so this doesn't work
    
    double (*pf3)(double,double);                      // correct!
    pf3 = product;
    
    cout << endl;
    
    // ----------------------------------------------------------------
    // EXAMPLE 2: Passing functions as function arguments
    cout << "--------------------------------------------" << endl;
    cout << "EXAMPLE 2: Passing functions as arguments" << endl;
    cout << "--------------------------------------------" << endl;
    // ----------------------------------------------------------------
    
    cout << "BEFORE" << endl;
    print_array(numbers, 4);
    
    apply(numbers,4,pf);
    
    cout << "AFTER" << endl;
    print_array(numbers, 4);
    
    
    apply(numbers,4,square);                         // you don't really need to create a separate pointer, you can just pass the name directly
    cout << "AFTER" << endl;
    print_array(numbers, 4);
    
    cout << "================================================" << endl;
    
    return 0;
}

double product(double x, double y)
{
    return x*y;
}

int cube(int i)
{
    return i*i*i;
}

int square(int i)
{
    return i*i;
}


void apply(int data[], int n, int (*pf)(int) )
{
    for(int i=0;i<n;i++){
        // the next two lines are logically equivilent
        data[i] = (*pf)(data[i]);
        //data[i] = pf(data[i]);
    }
}

void print_array(int data[], int n)
{
    std::cout << "[ ";
    for(int i=0;i<n;i++)
    {
        std::cout << data[i] << " ";
    }
    std::cout << "]" << std::endl;
}

