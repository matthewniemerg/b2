//
//  AdditionOp.cpp
//  Bertini2
//
//  Created by James Collins on 11/19/13.
//  Copyright (c) 2013 James Collins. All rights reserved.
//

#include "LeafOperand.h"
#include "AdditionOp.h"
#include <string>
#include <cstring>
#include <sstream>


AdditionOp::AdditionOp(int nOperands, std::vector<Operand*> inOperands)
{
    numOperands = nOperands;
    operands = inOperands;
    isExp = false;
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





std::string AdditionOp::print()
{
  std::stringstream ret;
  /*  if(operands.size() > 0)
      {
      std::stringstream term;
      term << operands[0]->print().str();
      
        ret << term.str();
	
        for(int ii = 1; ii < operands.size(); ii++)
        {
	//	  term.str("");
	
	  //	  term << ( operands[ii]->print().str() );
	  ret << " + " << term.str();
	  }
    }
  */
  for (int ii = 0; ii < operands.size(); ++ii){
    ret << operands[ii]->print() << (operands.size() > 1 && ii != operands.size() - 1 ? " + " : "" );
  }
  
  return ret.str();
}
