//
//  AdditionOp.cpp
//  Bertini2
//
//  Created by James Collins on 11/19/13.
//  Copyright (c) 2013 James Collins. All rights reserved.
//

#include "LeafOperand.h"
#include "AdditionOp.h"


AdditionOp::AdditionOp(int nOperands, std::vector<Operand*> inOperands)
{
    numOperands = nOperands;
    operands = inOperands;
}




double AdditionOp::evaluate(double* vars)
{
    double retval = 0;
    for(int ii = 0; ii < numOperands; ii++)
    {
        if(operands[ii]->IsLeaf())
        {
            retval += operands[ii]->evaluate(vars);
        }
        else
        {
            retval += operands[ii]->evaluate(vars);
        }
    }
    
    return retval;
}