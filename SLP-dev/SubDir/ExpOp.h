//
//  ExpOp.h
//  Bertini2
//
//  Created by James Collins on 11/20/13.
//  Copyright (c) 2013 James Collins. All rights reserved.
//

#ifndef __Bertini2__ExpOp__
#define __Bertini2__ExpOp__

#include <iostream>
#include <vector>
#include "OpOperand.h"
#include "Operand.h"


class ExpOp : public OpOperand
{
private:
    Operand* base;
    int exp;
public:
    ExpOp(Operand* inBase, int inExp);
    virtual double evaluate() {return 1;};
    virtual double evaluate(double* vars);
};

#endif /* defined(__Bertini2__ExpOp__) */
