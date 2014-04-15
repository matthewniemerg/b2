#include <mpfr.h>
#include <gmp.h>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <sstream>
//#include <ifstream>
//#include <ofstream>

std::ostream& operator << (std::ostream &sout, mpfr_t m);

int main(){

  mpfr_t m1, m2, m3;
  std::cout << "Before mpfr_inits2 .\n";
  mpfr_inits2(1024, m1, m2, m3, mpfr_ptr(0));

  std::string s1 = ".90327301273408742390886429074301957629843482314891635012847092374568913764081724568931748309165398417420812740821740871209765238956782356872356872163498121358196423918467891963847689174098573209521037957105971094927104";
  std::string s2 = ".5839263918639642301384091783508623059813539047510934617824702439507340165890127240632891742018508236084921891639581360857070909999135791624785617946988983256892635987195369047203957890257023570283570135789020395717486215397";
  std::string s3 = ".1794207459028350983209673205978320957029357092384902389572130947610234711938561398478913274098123570175490135710395739017580189438602359723058209358700019325713894619826489769139833869848848884448958588802000048247891364879263947777772305972305702395709237509283509825";

  std::cout << "Before set strings.\n";
  
  mpfr_set_str(m1, s1.c_str(), 10, MPFR_RNDN);
  std::cout << "After set m1\n";
  mpfr_set_str(m2, s2.c_str(), 10, MPFR_RNDN);
  std::cout << "After set m2\n";
  mpfr_set_str(m3, s3.c_str(), 10, MPFR_RNDN);
  std::cout << "After set m3\n";
  
  std::cout << "s1 = " << s3 << "\n"
	    << "m1 = " << m1 << "\n"
	    << "s2 = " << s2 << "\n"
	    << "m2 = " << m2 << "\n"
    	    << "s3 = " << s3 << "\n"
	    << "m3 = " << m3 << "\n";
  mpfr_clears(m1,m2, m3, mpfr_ptr(0));
 
  mpfr_t * m5;
  
  int bits = 100024;
  m5 = new mpfr_t[ 1 ];
  
  mpfr_init2(*m5, bits);
  mpfr_set_str(*m5, s1.c_str(), 10, MPFR_RNDN);

  std::cout << "m5 = " << *m5 << "\n";

  mpfr_clear(*m5);
  delete[] m5;
  
  
 return 0;
}




/* An mpfr insertion operator. */

std::ostream& operator << (std::ostream &sout, mpfr_t m){

  if (&m != NULL){
    

    // int mp_prec = int(mpfr_get_prec(m));
    // assume a base of 10 to output

    // d = log10(2^b);

    //  std::cout << "int(mpfr_get_prec(m)) = " << int(mpfr_get_prec(m)) << "\n";
    
    int buf_size = floor( int(mpfr_get_prec(m))*  log10(2));
    
    //    std::cout << "buf_size = " << buf_size;
    
    char* the_buf = new char[buf_size];
    std::stringstream somess;
    somess << "%." << buf_size << "RNf";
    mpfr_sprintf(the_buf, somess.str().c_str() , m);
    
    sout << the_buf;
    delete[] the_buf;
  }

  return sout;


}
