#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <fstream>
#include "AdditionOp.h"
#include "MultOp.h"
#include "ExpOp.h"
#include "LeafOperand.h"



int main()
{
    std::cout << "f(x,y,z) = x^3 - 5y + 2z^2\n";
    double x=3.0, y=1.0, z=2.0;
    std::cout << "x = " << x << ", y = " << y << ", z = " << z << "\n";
    double var[] = {x,y,z};
    std::vector<Operand*> testOperands;
    
    std::vector<Operand*> bot[3];
    bot[0].push_back(new LeafOperand(0));
    testOperands.push_back(new ExpOp(bot[0][0],3));

    bot[1].push_back(new LeafOperand(-5.0));
    bot[1].push_back(new LeafOperand(1));
    testOperands.push_back(new MultOp(2,bot[1]));
    
    bot[2].push_back(new LeafOperand(2.0));
    bot[2].push_back(new ExpOp(new LeafOperand(2),2));
    testOperands.push_back(new MultOp(2,bot[2]));

    AdditionOp testOp(3, testOperands);
    std::cout << "result =  " << testOp.evaluate(var) << "\n";
    
    
    return 1;
}