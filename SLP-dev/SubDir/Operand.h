//
//  Operand.h
//  Bertini2
//
//  Created by James Collins on 11/19/13.
//  Copyright (c) 2013 James Collins. All rights reserved.
//

#ifndef __Bertini2__Operand__
#define __Bertini2__Operand__

#include <iostream>

class Operand
{
protected:
    bool isLeaf;
    
public:
    int IsLeaf() { return isLeaf;};
    virtual double evaluate() = 0;
    virtual double evaluate(double* vars) = 0;
};


#endif /* defined(__Bertini2__Operand__) */
