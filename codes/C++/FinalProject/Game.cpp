#include "Game.h"
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;
Array prior;
Game::Game()
{
    x1 = 0;
    y1 = 0;
    
    int i = 0;
    int j = 0;
    for ( i = 0; i < 9; i++)
    {
        for ( j = 0; j < 9; j++)
        {
            board[i][j] = 0;
        }
    }
}
void Game::play()
{
    char xcoordinate[3], ycoordinate[3];
    int exit=1, turn=0;
    do
    {
        
        Game::showboard();
        cout<<"Enter X coordinate\n";
        cin >> xcoordinate;
        cout<<"Enter Y coordinate\n";
        cin >> ycoordinate;
        
        x1=atoi(xcoordinate);
        y1=atoi(ycoordinate);
        x1=x1-1;
        y1=y1-1;
        cout << "X: " << x1+1 << " Y: " << y1+1 << "\n";
        if(!strcmp(xcoordinate,"q") || !strcmp(ycoordinate,"q"))
                   {
                       exit=0;
                   }
                   if(x1<9 && x1>=0 && y1<9 && y1>=0)
                   {
                       if(board[y1][x1]==1 || board[y1][x1]==2)
                       {
                           cout<<"This place is taken\n";
                       }
                       else
                       {
                           board[y1][x1]=1;
                           
                           if(Game::win4(y1,x1)!=1)
                           {
                               Game::topnul();
                               Game::computer();
                               turn++;
                               if(Game::rank()==1)
                               {
                                   Game::showboard();
                                   cout<<"Computer wins!\n";
                                   exit=0;
                               }
                           }
                           else
                           {
                               exit=0;
                               Game::showboard();
                               cout<<"You win!\n";
                               return;
                           }
                       }
                   }
                   if(turn>=40)
                   {
                       exit=0;
                       Game::showboard();
                       cout<<"The board is full!\n";
                   }
                   }
                   while(exit!=0);
                   }
                   
void Game::showboard()
{
    int o;
    cout<<"0 1 2 3 4 5 6 7 8 9\n";
    for(int m=0; m<9; m++)
    {
        o=m+1;
        for(int n=0; n<9; n++)
            {
                if(board[m][n]==0){
                        if(n==0)
                        {
                            cout << o << "   ";
                        }
                        else
                        {
                            cout << "  ";
                        }
                }
                if(board[m][n]==1){
                        if(n==0)
                        {
                            cout << o << " X ";
                        }
                        else
                        {
                            cout << "X ";
                        }
                }
                if(board[m][n]==2){
                        if(n==0)
                        {
                            cout << o << " O ";
                        }
                        else
                        {
                            cout << "O ";
                        }
                }
        }
                cout << "\n";
        }
}
                   
void Game::top()
{
            for(int m=0; m<9; m++)
            {
                for(int n=0; n<9; n++)
                {
                    cout << prior(m,n) << " ";
                }
                cout << " ";
            }
}
                   
void Game::topnul()
{
    prior();
}
                   
int Game::rank()
{
            int maxy=0, maxx=0, maxo=-1;
            for(int m=0; m<9; m++)
            {
                for(int n=0; n<9; n++)
                {
                    if(board[m][n]!=1 && board[m][n]!=2)
                    {
                        if(maxo<prior(m,n))
                        {
                            maxo=prior(m,n);
                            maxy=m;
                            maxx=n;
                        }
                    }
                }
            }
            board[maxy][maxx]=2;
            if(Game::win4(maxy,maxx)==1)
                return 1;
            return 0;
}
void Game::computer()
{
            int m, n;
            for(m=0;m<9;m++)
                for(n=0;n<9;n++)
                {
                    if(board[m][n]!=1 && board[m][n]!=2)
                    {
                        board[m][n]=2;
                        if(Game::win2(m, n)==1)
                        {
                            prior(m,n,prior(m,n)+20);
                        }
                        board[m][n]=0;
                    }
                    else
                        prior(m,n,-1);
                    if(board[m][n]!=1 && board[m][n]!=2)
                    {
                        board[m][n]=1;
                        if(Game::win2(m, n)==1)
                        {
                            prior(m,n,prior(m,n)+9);
                        }
                        board[m][n]=0;
                    }
                    if(board[m][n]!=1 && board[m][n]!=2)
                    {
                        board[m][n]=2;
                        if(Game::win(m, n)==1)
                        {
                            prior(m,n,prior(m,n)+3);
                        }
                        board[m][n]=0;
                    }
                    else
                        prior(m,n,-1);
                    if(board[m][n]!=1 && board[m][n]!=2)
                    {
                        board[m][n]=1;
                        if(Game::win(m, n)==1)
                        {
                            prior(m,n,prior(m,n)+4);
                        }
                        board[m][n]=0;
                    }
                    if(board[m][n]!=1 && board[m][n]!=2)
                    {
                        board[m][n]=2;
                        if(Game::win3(m, n)==1)
                        {
                            prior(m,n,prior(m,n)+1);
                        }
                        board[m][n]=0;
                    }
                    else
                        prior(m,n,-1);
                    if(board[m][n]!=1 && board[m][n]!=2)
                    {
                        board[m][n]=1;
                        if(Game::win3(m, n)==1)
                        {
                            prior(m,n,prior(m,n)+2);
                        }
                        board[m][n]=0;
                    }
                    if(board[m][n]!=1 && board[m][n]!=2)
                    {
                        board[m][n]=2;
                        if(Game::win4(m, n)==1)
                        {
                            prior(m,n,prior(m,n)+21);
                        }
                        board[m][n]=0;
                    }
                    else
                        prior(m,n,-1);
                    if(board[m][n]!=1 && board[m][n]!=2)
                    {
                        board[m][n]=1;
                        if(Game::win4(m, n)==1)
                        {
                            prior(m,n,prior(m,n)+20);
                        }
                        board[m][n]=0;
                    }
                    if(board[m][n]!=1 && board[m][n]!=2)
                    {
                        board[m][n]=2;
                        if(Game::win5(m, n)==1)
                        {
                            prior(m,n,prior(m,n)+1);
                        }
                        board[m][n]=0;
                    }
                    else
                        prior(m,n,-1);
                    if(board[m][n]!=1 && board[m][n]!=2)
                    {
                        board[m][n]=1;
                        if(Game::win5(m, n)==1)
                        {
                            prior(m,n,prior(m,n)+1);
                        }
                        board[m][n]=0;
                    }
                }
}
                   
int Game::win(int x, int y)
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
                   
int Game::win2(int x, int y)
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
int Game::win4(int x, int y)
{
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
                   
int Game::win3(int x, int y)
{
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
int Game::win5(int x, int y)
{
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

