//
//  WIN.cpp
//  FinalProject1
//
//  Created by Jiahui Wang on 12/17/16.
//  Copyright © 2016 Apple Inc. All rights reserved.
//

#include "WIN.h"


int WIN::win(int x, int y, int board[15][15])
{
    int i, j;
    
    i = x;
    j = y-3;
    if(j < 0)
        j = 0;
    while((j <= y))
    {
        if((board[i][j] == board[x][y]) && (board[i][j+1] == board[x][y]) && (board[i][j+2] == board[x][y]) && (board[i][j+3] == board[x][y]))
            return 1;
        j++;
    }
    j = y;
    i = x-3;
    if(i < 0)
        i = 0;
    while(i<=x)
    {
        if((board[i][j] == board[x][y]) && (board[i+1][j] == board[x][y]) && (board[i+2][j] == board[x][y]) && (board[i+3][j] == board[x][y]))
            return 1;
        i++;
    }
    j = y-3;
    i = x-3;
    while(i<0 || j<0)
    {
        j++;
        i++;
    }
    while((i <= x) && (j <= y))
    {
        if((board[i][j] == board[x][y]) && (board[i+1][j+1] == board[x][y]) && (board[i+2][j+2] == board[x][y]) && (board[i+3][j+3] == board[x][y]))
            return 1;
        j++;
        i++;
    }
    j = y+3;
    i = x-3;
    if(i<0)
        i=0;
    while(j<0 || i<0)
    {
        j--;
        i++;
    }
    while((i <= x) && (j >= y) && (j >= 3))
    {
        if((board[i][j] == board[x][y]) && (board[i+1][j-1] == board[x][y]) && (board[i+2][j-2] == board[x][y]) && (board[i+3][j-3] == board[x][y]))
            return 1;
        j--;
        i++;
    }
    return 0;
}

int WIN2::win(int x, int y, int board[15][15]){
    int i, j;
    
    i = x;
    j = y-3;
    if(j < 0)
        j = 0;
    while((j <= y))
    {
        if((board[i][j] == board[x][y]) && (board[i][j+1] == board[x][y]) && (board[i][j+2] == board[x][y]) && (board[i][j+3] == board[x][y]))
            return 1;
        j++;
    }
    j = y;
    i = x-3;
    if(i < 0)
        i = 0;
    while((i <= x))
    {
        if((board[i][j] == board[x][y]) && (board[i+1][j] == board[x][y]) && (board[i+2][j] == board[x][y]) && (board[i+3][j] == board[x][y]))
            return 1;
        i++;
    }
    j = y-3;
    i = x-3;
    while(j<0 || i<0)
    {
        i++;
        j++;
    }
    while((i <= x) && (j <= y))
    {
        if((board[i][j] == board[x][y]) && (board[i+1][j+1] == board[x][y]) && (board[i+2][j+2] == board[x][y]) && (board[i+3][j+3] == board[x][y]))
            return 1;
        j++;
        i++;
    }
    j = y+3;
    i = x-3;
    while(i<0)
    {
        i++;
        j--;
    }
    while((i <= x) && (j >= y) && (j >= 3))
    {
        if((board[i][j] == board[x][y]) && (board[i+1][j-1] == board[x][y]) && (board[i+2][j-2] == board[x][y]) && (board[i+3][j-3] == board[x][y]))
            return 1;
        j--;
        i++;
    }
    return 0;
}


int WIN3::win(int x, int y, int board[15][15]){
    
    int i, j;
    
    i = x;
    j = y-2;
    if(j < 0)
        j = 0;
    while((j <= y))
    {
        if((board[i][j] == board[x][y]) && (board[i][j+1] == board[x][y]) && (board[i][j+2] == board[x][y]))
            return 1;
        j++;
    }
    j = y;
    i = x-2;
    if(i < 0)
        i = 0;
    while((i <= x))
    {
        if((board[i][j] == board[x][y]) && (board[i+1][j] == board[x][y]) && (board[i+2][j] == board[x][y]))
            return 1;
        i++;
    }
    j = y-2;
    i = x-2;
    while(i<0 || j<0)
    {
        i++;
        j++;
    }
    while((i <= x) && (j <= y))
    {
        if((board[i][j] == board[x][y]) && (board[i+1][j+1] == board[x][y]) && (board[i+2][j+2] == board[x][y]))
            return 1;
        j++;
        i++;
    }
    j = y+2;
    i = x-2;
    while(j<0 || i<0)
    {
        i++;
        j--;
    }
    while((i <= x) && (j >= y) && (j>=2))
    {
        if((board[i][j] == board[x][y]) && (board[i+1][j-1] == board[x][y]) && (board[i+2][j-2] == board[x][y]))
            return 1;
        j--;
        i++;
    }
    return 0;
}



int WIN4::win(int x, int y, int board[15][15]){
    
        int i, j;
        
        i = x;
        j = y-4;
        if(j < 0)
            j = 0;
        while((j <= y))
        {
            if((board[i][j] == board[x][y]) && (board[i][j+1] == board[x][y]) && (board[i][j+2] == board[x][y]) && (board[i][j+3] == board[x][y]) && (board[i][j+4] == board[x][y]))
                return 1;
            j++;
        }
        j = y;
        i = x-4;
        if(i < 0)
            i = 0;
        while((i <= x))
        {
            if((board[i][j] == board[x][y]) && (board[i+1][j] == board[x][y]) && (board[i+2][j] == board[x][y]) && (board[i+3][j] == board[x][y]) && (board[i+4][j] == board[x][y]))
                return 1;
            i++;
        }
        j = y-4;
        i = x-4;
        while(i<0 || j<0)
        {
            i++;
            j++;
        }
        
        while((i <= x) && (j <= y))
        {
            if((board[i][j] == board[x][y]) && (board[i+1][j+1] == board[x][y]) && (board[i+2][j+2] == board[x][y]) && (board[i+3][j+3] == board[x][y]) && (board[i+4][j+4] == board[x][y]))
                return 1;
            j++;
            i++;
        }
        j = y+4;
        i = x-4;
        while(i<0)
        {
            i++;
            j--;
        }
        
        while((i <= x) && (j >= y) && (j >= 4))
        {
            if((board[i][j] == board[x][y]) && (board[i+1][j-1] == board[x][y]) && (board[i+2][j-2] == board[x][y]) && (board[i+3][j-3] == board[x][y]) && (board[i+4][j-4] == board[x][y]))
                return 1;
            j--;
            i++;
        }
        return 0;
        
    

    
    
    
}

int WIN5::win(int x, int y, int board[15][15]){
    
        int i, j;
        
        i = x;
        j = y-1;
        if(j < 0)
            j = 0;
        while((j <= y))
        {
            if((board[i][j] == board[x][y]) && (board[i][j+1] == board[x][y]))
                return 1;
            j++;
        }
        j = y;
        i = x-1;
        if(i < 0)
            i = 0;
        while((i <= x))
        {
            if((board[i][j] == board[x][y]) && (board[i+1][j] == board[x][y]))
                return 1;
            i++;
        }
        j = y-1;
        i = x-1;
        while(i<0 || j<0)
        {
            i++;
            j++;
        }
        while((i <= x) && (i <= 9) && (j <= y) && (j <= 9))
        {
            if((board[i][j] == board[x][y]) && (board[i+1][j+1] == board[x][y]))
                return 1;
            j++;
            i++;
        }
        j = y+1;
        i = x-1;
        while(i<0)
        {
            j--;
            i++;
        }
        while((i <= x) && (i <= 9) && (j >= y) && (j >= 1))
        {
            if((board[i][j] == board[x][y]) && (board[i+1][j-1] == board[x][y]))
                return 1;
            j--;
            i++;
        }
        return 0;
        
        
    
    
    
    
}
