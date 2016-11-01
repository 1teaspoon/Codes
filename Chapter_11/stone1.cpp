// stone1.cpp -- user-defined conversion functions
// compile with stonewt1.cpp
#include <iostream>
#include "stonewt1.h"

void printwhateverDouble(double x){
  std::cout << x << std::endl;
}

void printwhateverStone(Stonewt &s){
  s.show_stn();
}

int main()
{
    using std::cout;
    Stonewt poppins(9,2.8);     // 9 stone, 2.8 pounds
    double p_wt = poppins;      // implicit conversion
    cout << "Convert to double => ";
    cout << "Poppins: " << p_wt << " pounds.\n";
    cout << "Convert to int => ";
    cout << "Poppins: " << int (poppins) << " pounds.\n";
	// std::cin.get();
    
    printwhateverDouble(poppins);
    printwhateverDouble(p_wt);
    printwhateverStone(poppins);
    printwhateverStone((Stonewt)p_wt);
    
    return 0; 
}
