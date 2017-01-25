#include <string>
#include <vector>
#include "Array.h"
#include "WIN.h"
class Game
{
private:
    int x1;
    int y1;
    int board[15][15];
public:
    Game();
    void play();
    void showboard();
    void top();
    void topnul();
    void computer();
    int win(int x,int y);
    int win2(int x,int y);
    int win3(int x,int y);
    int win4(int x,int y);
    int win5(int x,int y);
    int rank();
    
};
