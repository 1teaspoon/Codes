//
//  main.cpp
//  HW04
//  Author: 

#include <iostream>
#include "list.h"
#include "loadfile.h"
#include "book.h"


int main( int argc, const char * argv[] ) {
    
    //char filename[] ="data/test_subset1.tsv";
    const char * filename = argv[1];
    List BookList;
    int i = load_book_data(filename, BookList);
    if (i){
        std::cout<<"loading file successful"<<std::endl;
        //BookList.remove(Book("0439110246","Losers","Inc. Claudia Mills",1999,0.0));
        BookList.sort();

    }
    else{
        
    
    }
   
    
    return 0;
}

