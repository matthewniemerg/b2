#include "amp.hpp"
#include "complex_amp.hpp"
#include <string>
#include <iostream>
#include <sstream>
//#include <gmp.h>
//#include <mpfr.h>



int main(){

  double a = 4.2;
  mpfr_t m1, m2, tmp;
  mpfr_inits2(200, m1, m2, tmp, mpfr_ptr(0));
  std::stringstream ss;
  ss << a;
  mpfr_set_str(m1, ss.str().c_str(), 10, MPFR_RNDN);
  mpfr_set_d(m2, a, MPFR_RNDN);
  mpfr_sub(tmp, m2, m1, MPFR_RNDN);

  std::cout << "m2 - m1 = tmp\n\n"
	    << m2 << "\n        -       \n" << m1 << "\n        =       \n" << tmp << "\n\n";


  mpfr_clears(m1, m2, tmp, mpfr_ptr(0));




  return 0;
}
