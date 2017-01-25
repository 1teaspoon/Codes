
#include <vector>
using namespace std;
class Array
{
private:
    
    vector< vector<int> > adData; //using STL structure
public:
    Array()
    {
        adData.resize(15, vector<int>(15,0));
    }
        
    int operator()(const int nCol, const int nRow);
    void operator()(const int nCol, const int nRow, int value);
    void operator()();
};
