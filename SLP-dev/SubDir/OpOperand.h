//
//  SymbOp.h
//  Bertini2
//
//  Created by James Collins on 11/19/13.
//  Copyright (c) 2013 James Collins. All rights reserved.
//

#ifndef __Bertini2__SymbOp__
#define __Bertini2__SymbOp__

#include <iostream>
#include <vector>
#include "Operand.h"


class OpOperand : public Operand
{
protected:
    std::vector<Operand*> operands;
    int numOperands;
    
public:
    virtual double evaluate() = 0;
    virtual double evaluate(double* vars) = 0;
    
};




#endif /* defined(__Bertini2__SymbOp__) */
