

#ifndef __BVALUE_HPP__
#define __BVALUE_HPP__

class BValue { // an empty wrapper class -- to be used as the parent of all numerical value data types, AMP, ComplexAMP, RationalAMP, ComplexRationalAMP

  //   protected:
  public:
 virtual ~BValue() = 0; // they all have a destructor method
};


#endif
