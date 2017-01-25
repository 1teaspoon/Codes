#include <cstdlib>
#include <iostream>
#include <string>
#include "Game.h"
#include "exception.h"
using namespace std;


int main(void)
{
    char option;
    do
    {
        cout<<"--------------------------------\n";
        cout<<"      Welcome to Gomoku Game    \n";
        cout<<"--------------------------------\n";
        cout<<"         Main Menu:             \n";
        cout<<"         1. Start Game          \n";
        cout<<"         2. Help                \n";
        cout<<"         q. Exit                \n";
        cout<<"--------------------------------\n";
        Game a = Game();
        cin >> option;
        try{
            if (option <1 || option >2){
                throw myex;
        
            }
        }
        catch (exception& e){
            cout << e.what() << '\n';
            
        }
        switch(option)
        {
            case '1':
                cout << "Game start, your piece is X\n";
                a.play();
                break;
            case '2':
                cout<<"Get five pieces connected horizontally, vertically, or diagonally to win.\nEnter Coordinates to set a piece.\nEnter q to exit\n";
                break;
                
        }
    }
    while(option!='q');
    
    
    return 0;
}
