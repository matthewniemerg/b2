//
//  MultOp.cpp
//  Bertini2
//
//  Created by James Collins on 11/19/13.
//  Copyright (c) 2013 James Collins. All rights reserved.
//

#include "MultOp.h"
#include "LeafOperand.h"


MultOp::MultOp(int nOperands, std::vector<Operand*> inOperands)
{
    numOperands = nOperands;
    operands = inOperands;
}




double MultOp::evaluate(double* vars)
{
    double retval = 1;

    for(int ii = 0; ii < numOperands; ii++)
    {

        if(operands[ii]->IsLeaf())
        {
            retval *= operands[ii]->evaluate(vars);
        }
        else
        {
            retval *= operands[ii]->evaluate(vars);
        }
    }
    
    return retval;
}