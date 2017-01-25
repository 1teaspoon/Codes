//
//  WIN.hpp
//  FinalProject1
//
//  Created by Jiahui Wang on 12/17/16.
//  Copyright © 2016 Apple Inc. All rights reserved.
//

#ifndef WIN_hpp
#define WIN_hpp

#include <stdio.h>
class WIN
{
public:
    virtual int win(int,int,int[15][15]) = 0;
};

class WIN2 : public WIN
{
public:
    int win(int,int,int[15][15]);
};

class WIN3 : public WIN
{
public:
    int win(int,int,int[15][15]);
};

class WIN4 : public WIN
{
public:
    int win(int,int,int[15][15]);
};
class WIN5 : public WIN
{
public:
    int win(int,int,int[15][15]);
};

#endif /* WIN_hpp */
