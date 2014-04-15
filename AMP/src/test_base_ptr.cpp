

#include <iostream>
#include "bvalue.hpp"
#include "amp.hpp"
#include "complex_amp.hpp"


int main(){
  
  BValue* Test = new AMP;
  
  delete Test;

  BValue* Test2 = new ComplexAMP;

  delete Test2;


  return 0;
}
