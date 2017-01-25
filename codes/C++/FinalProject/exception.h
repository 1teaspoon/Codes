//
//  exception.hpp
//  FinalProject1
//
//  Created by Jiahui Wang on 12/17/16.
//  Copyright © 2016 Apple Inc. All rights reserved.
//

#ifndef exception_hpp
#define exception_hpp

#include <stdio.h>
#include <iostream>
#include <exception>
using namespace std;

class myexception: public exception
{
    virtual const char* what() const throw()
    {
        return "Please Enter a valid number";
    }
} myex;
#endif /* exception_hpp */
