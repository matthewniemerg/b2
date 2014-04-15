
#include "amp.hpp"
#include <iostream>
#include <fstream>
#include <sstream>




int main(){

    AMP a1;
    AMP a5;
    
    std::string sm3 = ".689639782987492570298395720689350927503297598163249817649217407035927059732057320562308945732057209347309587092375095327509372438193469185703298515896139058029467903570329582305790";
    a1.Set(sm3, 10, 1024);

    a5 = a1;
    
    AMP a4(.1750284075032985);
    
    
    AMP a8 = 2.5 + a4;
    AMP a9 = a8 + a5;

    std::cout << a4 << "\n" << a5 << "\n" << a8 << "\n" << a9 << "\n";
    
    
    
    std::cout << "************ Quick Test ************* \n\n";
    double d = 35.2894029749201774721;
    std::cout << std::setprecision(16) << d << "\n";
    std::stringstream ss;
    ss << std::setprecision(42) << d;
    std::cout << ss.str() << "\n";

    double d2 = 4.2;
    
    std::cout << std::setprecision(16) << d2 << "\n\n";
    
    return 0;
}