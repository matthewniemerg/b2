
#include "amp.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "complex_amp.hpp"

int main(){

  AMP a1;     // default constructor
  AMP a2 = a1; // copy constructor
  a1 = a2;  // assignment operator
  
  int testcount = 1;
  std::cout << "\n\n";
  std::cout << "Test " << testcount++ << " : default constructor : ComplexAMP c1;\n\n\n";
  
  ComplexAMP c1;  // default constructor

  std::cout << c1.GetStats("c1");
  
  std::cout << "\n\n\n*****************\n\n\n";
  std::cout << "Test " << testcount++ << " : copy constructor :  ComplexAMP c2 = c1;\n\n\n";
  ComplexAMP c2 = c1; // copy constructor
  std::cout << c2.GetStats("c2");
  std::cout << "\n\n\n*****************\n\n\n";
  std::cout << "Test " << testcount++ << " : SetReal(double) : c2.SetReal(.593072401841);\n\n\n";
  c2.SetReal(.593072401841);
  std::cout << c2.GetStats("c2");
  std::cout << "\n\n\n*****************\n\n\n";
  std::cout << "Test " << testcount++ << " : SetImag(double) : c2.SetImag(.428960349017371302841);\n\n\n";
  c2.SetImag(.428960349017371302841);
  std::cout << c2.GetStats("c2");
  std::cout << "\n\n\n*****************\n\n\n";
  std::cout << "Test " << testcount++ << " : assignment operator : c1 = c2;\n\n\n";
  c1 = c2;  // assignment operator
  std::cout << c1.GetStats("c1");
  std::cout << "\n\n\n*****************\n\n\n";
  std::cout << "Test " << testcount++ << " : Copy Constructor : c1 = ComplexAMP(.5, .8053);\n\n\n";
  c1 = ComplexAMP(.5, .8053);
  std::cout << c1.GetStats("c1");
  
  std::cout << "\n\n\n*****************\n\n\n";
  std::cout << "Test " << testcount++ << " : Constructor ComplexAMP(double, double) : \n"
	    << "ComplexAMP c3(.583201013489742971, .9068024709817308098072);"
	    << "\n\n\n";
  ComplexAMP c3(.583201013489742971, .9068024709817308098072);
  std::cout << c3.GetStats("c3");
  
  
  
  std::cout << "\n\n\n*****************\n\n\n";
  std::cout << "Test " << testcount++ << " : Constructor ComplexAMP(mpfr_t, mpfr_t) : \n"
	    << "mpfr_t m1, m2;\nmfpr_init2(m1, 128)\nmpfr_init2(m2, 200)\n"
	    << "mpfr_set_str(m1, \".481297639170974021707401883065289608083607087169857297742\", 10, MPFR_RNDN);\n" 
	    << "mpfr_set_str(m2, \".582528390710367708537023494697095375046194720237124959874025896184704235698471042772184697124\", 10, MPFR_RNDN);\n"
	    << "ComplexAMP c4(m1, m2);"
	    << "\n\n\n";
  mpfr_t m1, m2; 
  mpfr_init2(m1, 128); 
  mpfr_init2(m2, 200);
  mpfr_set_str(m1, ".481297639170974021707401883065289608083607087169857297742", 10, MPFR_RNDN);
  mpfr_set_str(m2, ".582528390710367708537023494697095375046194720237124959874025896184704235698471042772184697124", 10, MPFR_RNDN);



  ComplexAMP c4(m1, m2);

  std::cout << c4.GetStats("c4");

  mpfr_clears(m1,m2, mpfr_ptr(0));


  std::cout << "\n\n\n*****************\n\n\n";
  std::cout << "Test " << testcount++ << " : Constructor ComplexAMP(AMP r, AMP i) : \n"
	    << "mpfr_t m3, m4;\nmpfr_init2(m3, 300);\nmpfr_init2(m4, 380);\nmpfr_set_str(m3, \".5930731036947013816939879017243968712638965930813048012746978093147986124984940579203562943678216439127249512497048205736927401736597048356042308402853\", 10, MPFR_RNDN);\nmpfr_set_str(m4, \".648074209478056347204783962493184238057103756912074080984057203480192430680234719261979018023807609648235378947619246982375027834925698720146923741985692107402650192840864238417098175980702157102948096720137192035792034780239570723150971259049\",10, MPFR_RNDN);\nAMP a42(m3);\nAMP a43(m4);\nComplexAMP c5(a42, a43);"
	    <<"\n\n\n";

  

  mpfr_t m3, m4;
  mpfr_init2(m3, 300);
  mpfr_init2(m4, 380);
  mpfr_set_str(m3, ".5930731036947013816939879017243968712638965930813048012746978093147986124984940579203562943678216439127249512497048205736927401736597048356042308402853", 10, MPFR_RNDN);
  mpfr_set_str(m4, ".648074209478056347204783962493184238057103756912074080984057203480192430680234719261979018023807609648235378947619246982375027834925698720146923741985692107402650192840864238417098175980702157102948096720137192035792034780239570723150971259049",
10, MPFR_RNDN);
  //  std::cout << "m4 = " << m4 << "\n";
  AMP a42(m3);
  AMP a43(m4);
  ComplexAMP c5(a42, a43);
  std::cout << c5.GetStats("c5");
  std::cout << "\n\n\n";

  mpfr_clears(m3,m4, mpfr_ptr(0));


  std::cout << "Constructor Tests complete.\n\n";
    
  std::cout << "\n\n\n*****************\n\n\n";

    std::cout << "Begin Testing Modifiers / Setters \n\n";
    
    std::cout << "Test " << testcount++ << " : c6.SetReal(amp), c6.SetImag(amp) : \n"
	    << "mpfr_t m5, m6;\n"
	    << "mpfr_init2(m5, 220);\nmpfr_init2(m6, 260);\n"
	    << "mpfr_set_str(m5, \".81239750380249294720948057320480985093713097520703478590238404829649170589205702469016498764297408170370370472048095830970287248753297589327503218409176428974301724092740927409274092740724097204709707420472071389674502804250972304731097209173029170912740971340917409127402917409217420853098640275238964021235o87923784592723597892357293578924325320723047\",10,  MPFR_RNDN);\n"
	    << "mpfr_set_str(m6, \".28947203840974309257203487389257032850973023840173503279509348609823585730296820345972642893346902710960942838529356792168421986983275021894301795029375019740219750972150987250196704237530937513095612057049257308765029385239670975403698223590275031701620935710783501706273509270597329057209357016892475298734897234904213538942679348179347190287401275092378509753209573902746219862094750239854702397509327409327508340239507320457029357302957029357932054720357029357023750927465027357\", 10, MPFR_RNDN);\n"
	    << "ComplexAMP c6;\n" 
	    <<"\n\n\n";

  mpfr_t m5, m6;

  mpfr_init2(m5, 220);
  mpfr_init2(m6, 260);
  mpfr_set_str(m5, ".81239750380249294720948057320480985093713097520703478590238404829649170589205702469016498764297408170370370472048095830970287248753297589327503218409176428974301724092740927409274092740724097204709707420472071389674502804250972304731097209173029170912740971340917409127402917409217420853098640275238964021235o87923784592723597892357293578924325320723047",10,  MPFR_RNDN);
  mpfr_set_str(m6, ".28947203840974309257203487389257032850973023840173503279509348609823585730296820345972642893346902710960942838529356792168421986983275021894301795029375019740219750972150987250196704237530937513095612057049257308765029385239670975403698223590275031701620935710783501706273509270597329057209357016892475298734897234904213538942679348179347190287401275092378509753209573902746219862094750239854702397509327409327508340239507320457029357302957029357932054720357029357023750927465027357", 10, MPFR_RNDN);

  ComplexAMP c6;
  AMP a44(m5);
  AMP a45(m6);
  c6.SetReal(a44);
  c6.SetImag(a45);
  std::cout << c6.GetStats("c6");
  std::cout << "\n\n\n";
  
    std::cout << "Testing SetReal(mpfr_t) and SetImag(mpfr_t) : c6.SetReal(m6); c6.SetImag(m5);\n\n";
    c6.SetReal(m6);
    c6.SetImag(m5);
    std::cout << c6.GetStats("c6");
    
    mpfr_clears(m5, m6, mpfr_ptr(0));

    std::cout << "\n\n************************\n\n";
    std::cout << "Testing SetRealPrecision(500) : SetImagPrecision(600) : c6.SetRealPrecision(500); c6.SetImagPrecision(600);\n\n";
    std::cout << c6.GetStats("c6") << "\n\n";
    c6.SetRealPrecision(500);
    c6.SetImagPrecision(600);
    std::cout << c6.GetStats("c6") << "\n\n";
    std::cout << "Testing SetPrecision(700) : c6.SetPrecision(700)\n\n";
    c6.SetPrecision(700);
    std::cout << c6.GetStats("c6") << "\n\n";
    std::cout << "Testing SetPrecision(HARDWARE_PRECISION) : c6.SetPrecision(HARDWARE_PRECISION)\n\n";
    c6.SetPrecision(HARDWARE_PRECISION);
    std::cout << c6.GetStats("c6") << "\n\n";
    std::cout << "Testing move from hardware precision to higher precision : SetPrecision(180) : c6.SetPrecision(180);\n\n";
    c6.SetPrecision(180);
    std::cout << c6.GetStats("c6") << "\n\n";
    
    std::cout << "Finished Testing Modifiers \n\n"
              << "**************************\n\n";


    
    std::cout << "Testing ComplexAMP arithmetic.\n\n";
    
    
    std::cout << "\n\n\n*****************\n\n\n";
    std::cout << "Test " << testcount++ << " : ComplexAMP*ComplexAMP (double*double) : \n"
	      << "ComplexAMP c7 = c1*c3;\n";
    
    ComplexAMP c7 = c1*c3;
    std::cout << c7.GetStats("c7");
    
    
    ComplexAMP c8 = c1+c3;
    
    std::cout << "\n\n\n*****************\n\n\n";
    std::cout << "Test " << testcount++ << " : ComplexAMP+ComplexAMP (double+double) : \n"
	      << "ComplexAMP c8 = c1+c3;\n";
    std::cout << c8.GetStats("c8");
    
    ComplexAMP c9 = c1 - c3;
    
    std::cout << "\n\n\n*****************\n\n\n";
    std::cout << "Test " << testcount++ << " : ComplexAMP-ComplexAMP (double-double) : \n"
	      << "ComplexAMP c9 = c1-c3;\n";
    std::cout << c9.GetStats("c9");
    
    ComplexAMP c10 = c1/c3;
    
    
    std::cout << "\n\n\n*****************\n\n\n";
    std::cout << "Test " << testcount++ << " : ComplexAMP / ComplexAMP (double / double) : \n"
	      << "ComplexAMP c10 = c1 / c3;\n";
    std::cout << c10.GetStats("c10");
    std::cout << "\n\n\n";
    std::cout << "\n\n\n*****************\n\n\n";
    
    // note c1, c2, c3, c7, c8, c9, c10 are all double
    // and c4, c5, c6 are all at various precisions for the mp values
    
    
    std::cout << "Test " << testcount++ << " : ComplexAMP * ComplexAMP (double * MP) : \n"
	      << "ComplexAMP c11 = c1*c4;\n";
    ComplexAMP c11 = c1*c4;
    std::cout << c1.GetStats("c1");
    std::cout << "\n\n";
    std::cout << c4.GetStats("c4");
    std::cout << "\n\n";
    std::cout << c11.GetStats("c11");
    std::cout << "\n\n";
    std::cout << "\n\n\n*****************\n\n\n";
    


    std::cout << "Test " << testcount++ << " : ComplexAMP * ComplexAMP ( MP * double) : \n"
	      << "ComplexAMP c12 = c11*c1;\n";
    ComplexAMP c12 = c11*c1;
    std::cout << c11.GetStats("c11");
    std::cout << "\n\n";
    std::cout << c1.GetStats("c1");
    std::cout << "\n\n";
    std::cout << c12.GetStats("c12");
    std::cout << "\n\n";
    std::cout << "\n\n\n*****************\n\n\n";
    
    
    
    std::cout << "Test " << testcount++ << " : ComplexAMP * ComplexAMP ( MP * MP) : \n"
	      << "ComplexAMP c13 = c11*c5;\n";
    ComplexAMP c13 = c11*c5;
    std::cout << c11.GetStats("c11");
    std::cout << "\n\n";
    std::cout << c5.GetStats("c5");
    std::cout << "\n\n";
    std::cout << c13.GetStats("c13");
    std::cout << "\n\n";
    std::cout << "\n\n\n*****************\n\n\n";
    
    
    std::cout << "Test " << testcount++ << " : ComplexAMP + ComplexAMP ( MP + MP) : \n"
	      << "ComplexAMP c14 = c11+c5;\n";
    ComplexAMP c14 = c11+c5;
    std::cout << c11.GetStats("c11");
    std::cout << "\n\n";
    std::cout << c5.GetStats("c5");
    std::cout << "\n\n";
    std::cout << c14.GetStats("c14");
    std::cout << "\n\n";
    std::cout << "\n\n\n*****************\n\n\n";
    
    

    std::cout << "Test " << testcount++ << " : ComplexAMP + ComplexAMP ( double + MP) : \n"
	      << "ComplexAMP c15 = c1+c5;\n";
    ComplexAMP c15 = c1+c5;
    std::cout << c1.GetStats("c1");
    std::cout << "\n\n";
    std::cout << c5.GetStats("c5");
    std::cout << "\n\n";
    std::cout << c15.GetStats("c15");
    std::cout << "\n\n";
    std::cout << "\n\n\n*****************\n\n\n";
    

    std::cout << "Test " << testcount++ << " : ComplexAMP + ComplexAMP ( MP + double ) : \n"
	      << "ComplexAMP c16 = c5+c4;\n";
    ComplexAMP c16 = c5+c3;
    std::cout << c5.GetStats("c5");
    std::cout << "\n\n";
    std::cout << c3.GetStats("c3");
    std::cout << "\n\n";
    std::cout << c16.GetStats("c16");
    std::cout << "\n\n";
    std::cout << "\n\n\n*****************\n\n\n";
    







  std::cout << "Test " << testcount++ << " : ComplexAMP - ComplexAMP ( MP - MP) : \n"
	    << "ComplexAMP c14 = c11-c5;\n";
  ComplexAMP c17 = c11-c5;
  std::cout << c11.GetStats("c11");
  std::cout << "\n\n";
  std::cout << c5.GetStats("c5");
  std::cout << "\n\n";
  std::cout << c17.GetStats("c17");
  std::cout << "\n\n";
  std::cout << "\n\n\n*****************\n\n\n";



  std::cout << "Test " << testcount++ << " : ComplexAMP - ComplexAMP ( double - MP) : \n"
	    << "ComplexAMP c18 = c1+c5;\n";
  ComplexAMP c18 = c1-c5;
  std::cout << c1.GetStats("c1");
  std::cout << "\n\n";
  std::cout << c5.GetStats("c5");
  std::cout << "\n\n";
  std::cout << c18.GetStats("c18");
  std::cout << "\n\n";
  std::cout << "\n\n\n*****************\n\n\n";


  std::cout << "Test " << testcount++ << " : ComplexAMP + ComplexAMP ( MP - double ) : \n"
	    << "ComplexAMP c19 = c5-c4;\n";
  ComplexAMP c19 = c5-c3;
  std::cout << c5.GetStats("c5");
  std::cout << "\n\n";
  std::cout << c3.GetStats("c3");
  std::cout << "\n\n";
  std::cout << c19.GetStats("c19");
  std::cout << "\n\n";
  std::cout << "\n\n\n*****************\n\n\n";







  std::cout << "Test " << testcount++ << " : ComplexAMP / ComplexAMP ( MP / MP) : \n"
	    << "ComplexAMP c20 = c11/c5;\n";
  ComplexAMP c20 = c11/c5;
  std::cout << c11.GetStats("c11");
  std::cout << "\n\n";
  std::cout << c5.GetStats("c5");
  std::cout << "\n\n";
  std::cout << c20.GetStats("c20");
  std::cout << "\n\n";
  std::cout << "\n\n\n*****************\n\n\n";



  std::cout << "Test " << testcount++ << " : ComplexAMP + ComplexAMP ( double / MP) : \n"
	    << "ComplexAMP c21 = c1/c5;\n";
  ComplexAMP c21 = c1/c5;
  std::cout << c1.GetStats("c1");
  std::cout << "\n\n";
  std::cout << c5.GetStats("c5");
  std::cout << "\n\n";
  std::cout << c21.GetStats("c21");
  std::cout << "\n\n";
  std::cout << "\n\n\n*****************\n\n\n";


  std::cout << "Test " << testcount++ << " : ComplexAMP + ComplexAMP ( MP / double ) : \n"
	    << "ComplexAMP c22 = c5/c3;\n";
  ComplexAMP c22 = c5/c3;
  std::cout << c5.GetStats("c5");
  std::cout << "\n\n";
  std::cout << c3.GetStats("c3");
  std::cout << "\n\n";
  std::cout << c22.GetStats("c22");
  std::cout << "\n\n";
  std::cout << "\n\n\n*****************\n\n\n";

  

  std::cout << "Testing other overloading of operators\n\n";

  


  std::cout << "Test " << testcount++ << " : double + ComplexAMP ( double + MP ) : \n"
	    << "ComplexAMP c23 = 1+c5;\n";
  ComplexAMP c23 = 1+c5;
  std::cout << c5.GetStats("c5");
  std::cout << "\n\n";
  std::cout << c23.GetStats("c23");
  std::cout << "\n\n";
  std::cout << "\n\n\n*****************\n\n\n";

  std::cout << "Test " << testcount++ << " : ComplexAMP + double ( MP + double ) : \n"
	    << "ComplexAMP c24 = c5 + 1;\n";
  ComplexAMP c24 = c5 + 1;
  std::cout << c5.GetStats("c5");
  std::cout << "\n\n";
  std::cout << c24.GetStats("c24");
  std::cout << "\n\n";
  std::cout << "\n\n\n*****************\n\n\n";



  std::cout << "Test " << testcount++ << " : double + ComplexAMP ( double + double) : \n"
	    << "ComplexAMP c25 = 1+c1;\n";
  ComplexAMP c25 = 1+c1;
  std::cout << c1.GetStats("c1");
  std::cout << "\n\n";
  std::cout << c25.GetStats("c25");
  std::cout << "\n\n";
  std::cout << "\n\n\n*****************\n\n\n";


  std::cout << "Test " << testcount++ << " : ComplexAMP + double ( double + double ) : \n"
	    << "ComplexAMP c26 = c1+1;\n";
  ComplexAMP c26 = c1+1;
  std::cout << c1.GetStats("c1");
  std::cout << "\n\n";
  std::cout << c26.GetStats("c26");
  std::cout << "\n\n";
  std::cout << "\n\n\n*****************\n\n\n";





  std::cout << "Test " << testcount++ << " : double - ComplexAMP ( double - MP ) : \n"
	    << "ComplexAMP c27 = 1-c5;\n";
  ComplexAMP c27 = 1-c5;
  std::cout << c5.GetStats("c5");
  std::cout << "\n\n";
  std::cout << c27.GetStats("c27");
  std::cout << "\n\n";
  std::cout << "\n\n\n*****************\n\n\n";

  std::cout << "Test " << testcount++ << " : ComplexAMP - double ( MP - double ) : \n"
	    << "ComplexAMP c28 = c5 - 1;\n";
  ComplexAMP c28 = c5 - 1;
  std::cout << c5.GetStats("c5");
  std::cout << "\n\n";
  std::cout << c28.GetStats("c24");
  std::cout << "\n\n";
  std::cout << "\n\n\n*****************\n\n\n";



  std::cout << "Test " << testcount++ << " : double - ComplexAMP ( double - double) : \n"
	    << "ComplexAMP c29 = 1-c1;\n";
  ComplexAMP c29 = 1-c1;
  std::cout << c1.GetStats("c1");
  std::cout << "\n\n";
  std::cout << c29.GetStats("c29");
  std::cout << "\n\n";
  std::cout << "\n\n\n*****************\n\n\n";


  std::cout << "Test " << testcount++ << " : ComplexAMP - double ( double - double ) : \n"
	    << "ComplexAMP c30 = c1-1;\n";
  ComplexAMP c30 = c1-1;
  std::cout << c1.GetStats("c1");
  std::cout << "\n\n";
  std::cout << c30.GetStats("c30");
  std::cout << "\n\n";
  std::cout << "\n\n\n*****************\n\n\n";









  std::cout << "Test " << testcount++ << " : double * ComplexAMP ( double * MP ) : \n"
	    << "ComplexAMP c31 = 2*c5;\n";
  ComplexAMP c31 = 2*c5;
  std::cout << c5.GetStats("c5");
  std::cout << "\n\n";
  std::cout << c31.GetStats("c31");
  std::cout << "\n\n";
  std::cout << "\n\n\n*****************\n\n\n";

  std::cout << "Test " << testcount++ << " : ComplexAMP * double ( MP * double ) : \n"
	    << "ComplexAMP c32 = c5 * 2;\n";
  ComplexAMP c32 = c5 * 2;
  std::cout << c5.GetStats("c5");
  std::cout << "\n\n";
  std::cout << c32.GetStats("c32");
  std::cout << "\n\n";
  std::cout << "\n\n\n*****************\n\n\n";



  std::cout << "Test " << testcount++ << " : double * ComplexAMP ( double * double) : \n"
	    << "ComplexAMP c29 = 2*c1;\n";
  ComplexAMP c33 = 2*c1;
  std::cout << c1.GetStats("c1");
  std::cout << "\n\n";
  std::cout << c33.GetStats("c33");
  std::cout << "\n\n";
  std::cout << "\n\n\n*****************\n\n\n";


  std::cout << "Test " << testcount++ << " : ComplexAMP * double ( double * double ) : \n"
	    << "ComplexAMP c34 = c1*2;\n";
  ComplexAMP c34 = c1*2;
  std::cout << c1.GetStats("c1");
  std::cout << "\n\n";
  std::cout << c34.GetStats("c34");
  std::cout << "\n\n";
  std::cout << "\n\n\n*****************\n\n\n";






  std::cout << "Test " << testcount++ << " : double / ComplexAMP ( double / MP ) : \n"
	    << "ComplexAMP c35 = 3 / c5;\n";
  ComplexAMP c35 = 3 / c5;
  std::cout << c5.GetStats("c5");
  std::cout << "\n\n";
  std::cout << c35.GetStats("c35");
  std::cout << "\n\n";
  std::cout << "\n\n\n*****************\n\n\n";

  std::cout << "Test " << testcount++ << " : ComplexAMP / double ( MP / double ) : \n"
	    << "ComplexAMP c36 = c5 / 3;\n";
  ComplexAMP c36 = c5 / 3;
  std::cout << c5.GetStats("c5");
  std::cout << "\n\n";
  std::cout << c36.GetStats("c36");
  std::cout << "\n\n";
  std::cout << "\n\n\n*****************\n\n\n";



  std::cout << "Test " << testcount++ << " : double / ComplexAMP ( double / double ) : \n"
	    << "ComplexAMP c37 = 3 / c1;\n";
  ComplexAMP c37 = 3 / c1;
  std::cout << c1.GetStats("c1");
  std::cout << "\n\n";
  std::cout << c37.GetStats("c37");
  std::cout << "\n\n";
  std::cout << "\n\n\n*****************\n\n\n";


  std::cout << "Test " << testcount++ << " : ComplexAMP / double ( double / double ) : \n"
	    << "ComplexAMP c38 = c1 / 3;\n";
  ComplexAMP c38 = c1 / 3;
  std::cout << c1.GetStats("c1");
  std::cout << "\n\n";
  std::cout << c38.GetStats("c38");
  std::cout << "\n\n";
  std::cout << "\n\n\n*****************\n\n\n";



  // a42, a43, a44, a45 are AMP objects at various precisions

    
  std::cout << "Test " << testcount++ << " : ComplexAMP + AMP ( double + MP ) : \n"
	    << "ComplexAMP c39 = c1 + a42;\n";
  ComplexAMP c39 = c1 + a42;
  std::cout << c1.GetStats("c1");
  std::cout << "\n\n";
  std::cout << a42.GetStats("a42");
  std::cout << "\n\n";
  std::cout << c39.GetStats("c39");
  std::cout << "\n\n";
  std::cout << "\n\n\n*****************\n\n\n";


  std::cout << "Test " << testcount++ << " : AMP + ComplexAMP ( MP + double ) : \n"
	    << "ComplexAMP c40 = a42 + c1;\n";
  ComplexAMP c40 = a42 + c1;
  std::cout << a42.GetStats("a42");
  std::cout << "\n\n";
  std::cout << c1.GetStats("c1");
  std::cout << "\n\n";
  std::cout << c40.GetStats("c40");
  std::cout << "\n\n";
  std::cout << "\n\n\n*****************\n\n\n";


  std::cout << "Test " << testcount++ << " : ComplexAMP + AMP ( MP + MP ) : \n"
	    << "ComplexAMP c41 = a42 + c4;\n";
  ComplexAMP c41 = c4 + a42;
  std::cout << c4.GetStats("c4");
  std::cout << "\n\n";
  std::cout << a42.GetStats("a42");
  std::cout << "\n\n";
  std::cout << c41.GetStats("c41");
  std::cout << "\n\n";
  std::cout << "\n\n\n*****************\n\n\n";


  std::cout << "Test " << testcount++ << " : AMP + ComplexAMP ( MP + MP ) : \n"
	    << "ComplexAMP c42 = a42 + c5;\n";
  ComplexAMP c42 = a42 + c5;
  std::cout << a42.GetStats("a42");
  std::cout << "\n\n";
  std::cout << c5.GetStats("c5");
  std::cout << "\n\n";
  std::cout << c42.GetStats("c42");
  std::cout << "\n\n";
  std::cout << "\n\n\n*****************\n\n\n";













  std::cout << "Test " << testcount++ << " : ComplexAMP - AMP ( double - MP ) : \n"
	    << "ComplexAMP c43 = c1 - a42;\n";
  ComplexAMP c43 = c1 - a42;
  std::cout << c1.GetStats("c1");
  std::cout << "\n\n";
  std::cout << a42.GetStats("a42");
  std::cout << "\n\n";
  std::cout << c43.GetStats("c43");
  std::cout << "\n\n";
  std::cout << "\n\n\n*****************\n\n\n";


  std::cout << "Test " << testcount++ << " : AMP - ComplexAMP ( MP - double ) : \n"
	    << "ComplexAMP c44 = a42 - c1;\n";
  ComplexAMP c44 = a42 - c1;
  std::cout << a42.GetStats("a42");
  std::cout << "\n\n";
  std::cout << c1.GetStats("c1");
  std::cout << "\n\n";
  std::cout << c44.GetStats("c44");
  std::cout << "\n\n";
  std::cout << "\n\n\n*****************\n\n\n";


  std::cout << "Test " << testcount++ << " : ComplexAMP - AMP ( MP - MP ) : \n"
	    << "ComplexAMP c45 = a42 - c4;\n";
  ComplexAMP c45 = c4 - a42;
  std::cout << c4.GetStats("c4");
  std::cout << "\n\n";
  std::cout << a42.GetStats("a42");
  std::cout << "\n\n";
  std::cout << c45.GetStats("c45");
  std::cout << "\n\n";
  std::cout << "\n\n\n*****************\n\n\n";


  std::cout << "Test " << testcount++ << " : AMP - ComplexAMP ( MP - MP ) : \n"
	    << "ComplexAMP c42 = a42 - c5;\n";
  ComplexAMP c46 = a42 - c5;
  std::cout << a42.GetStats("a42");
  std::cout << "\n\n";
  std::cout << c5.GetStats("c5");
  std::cout << "\n\n";
  std::cout << c46.GetStats("c46");
  std::cout << "\n\n";
  std::cout << "\n\n\n*****************\n\n\n";


  std::cout << "Test " << testcount++ << " : ComplexAMP * AMP ( double * MP ) : \n"
	    << "ComplexAMP c47 = c9 * a42;\n";
  ComplexAMP c47 = c9 * a42;
  std::cout << c9.GetStats("c9");
  std::cout << "\n\n";
  std::cout << a42.GetStats("a42");
  std::cout << "\n\n";
  std::cout << c47.GetStats("c47");
  std::cout << "\n\n";
  std::cout << "\n\n\n*****************\n\n\n";


  std::cout << "Test " << testcount++ << " : AMP * ComplexAMP ( MP * double ) : \n"
	    << "ComplexAMP c48 = a42 * c10;\n";
  ComplexAMP c48 = a42 * c10;
  std::cout << a42.GetStats("a42");
  std::cout << "\n\n";
  std::cout << c10.GetStats("c10");
  std::cout << "\n\n";
  std::cout << c48.GetStats("c48");
  std::cout << "\n\n";
  std::cout << "\n\n\n*****************\n\n\n";


  std::cout << "Test " << testcount++ << " : ComplexAMP * AMP ( MP + MP ) : \n"
	    << "ComplexAMP c49 = a42 + c40;\n";
  ComplexAMP c49 = c40 * a42;
  std::cout << c40.GetStats("c40");
  std::cout << "\n\n";
  std::cout << a42.GetStats("a42");
  std::cout << "\n\n";
  std::cout << c49.GetStats("c49");
  std::cout << "\n\n";
  std::cout << "\n\n\n*****************\n\n\n";


  std::cout << "Test " << testcount++ << " : AMP * ComplexAMP ( MP * MP ) : \n"
	    << "ComplexAMP c50 = a42 * c39;\n";
  ComplexAMP c50 = a42 * c39;
  std::cout << a42.GetStats("a42");
  std::cout << "\n\n";
  std::cout << c39.GetStats("c39");
  std::cout << "\n\n";
  std::cout << c50.GetStats("c50");
  std::cout << "\n\n";
  std::cout << "\n\n\n*****************\n\n\n";





  std::cout << "Test " << testcount++ << " : ComplexAMP / AMP ( double / MP ) : \n"
	    << "ComplexAMP c51 = c10 / a42;\n";
  ComplexAMP c51 = c10 / a42;
  std::cout << c10.GetStats("c10");
  std::cout << "\n\n";
  std::cout << a42.GetStats("a42");
  std::cout << "\n\n";
  std::cout << c51.GetStats("c51");
  std::cout << "\n\n";
  std::cout << "\n\n\n*****************\n\n\n";


  std::cout << "Test " << testcount++ << " : AMP / ComplexAMP ( MP / double ) : \n"
	    << "ComplexAMP c40 = a42 / c10;\n";
  ComplexAMP c52 = a42 / c10;
  std::cout << a42.GetStats("a42");
  std::cout << "\n\n";
  std::cout << c10.GetStats("c10");
  std::cout << "\n\n";
  std::cout << c52.GetStats("c52");
  std::cout << "\n\n";
  std::cout << "\n\n\n*****************\n\n\n";


  std::cout << "Test " << testcount++ << " : ComplexAMP / AMP ( MP / MP ) : \n"
	    << "ComplexAMP c53 = a42 / c4;\n";
  ComplexAMP c53 = c4 / a42;
  std::cout << c4.GetStats("c4");
  std::cout << "\n\n";
  std::cout << a42.GetStats("a42");
  std::cout << "\n\n";
  std::cout << c53.GetStats("c53");
  std::cout << "\n\n";
  std::cout << "\n\n\n*****************\n\n\n";


  std::cout << "Test " << testcount++ << " : AMP / ComplexAMP ( MP / MP ) : \n"
	    << "ComplexAMP c54 = a42 / c5;\n";
  ComplexAMP c54 = a42 / c5;
  std::cout << a42.GetStats("a42");
  std::cout << "\n\n";
  std::cout << c5.GetStats("c5");
  std::cout << "\n\n";
  std::cout << c54.GetStats("c54");
  std::cout << "\n\n";
  std::cout << "\n\n\n*****************\n\n\n";


    std::ofstream fout("results_complex_amp");
    fout << c1 << "\n"
    << c2 << "\n"
    << c3 << "\n"
    << c4 << "\n"
    << c5 << "\n"
    << c6 << "\n"
    << c7 << "\n"
    << c8 << "\n"
    << c9 << "\n"
    << c10 << "\n"  << "\n"
    << c11 << "\n"
    << c12 << "\n"
    << c13 << "\n"
    << c14 << "\n"
    << c15 << "\n"
    << c16 << "\n"
    << c17 << "\n"
    << c18 << "\n"
    << c19 << "\n"
    << c20 << "\n" << "\n"
    << c21 << "\n"
    << c22 << "\n"
    << c23 << "\n"
    << c24 << "\n"
    << c25 << "\n"
    << c26 << "\n"
    << c27 << "\n"
    << c28 << "\n"
    << c29 << "\n"
    << c30 << "\n" << "\n"
    << c31 << "\n"
    << c32 << "\n"
    << c33 << "\n"
    << c34 << "\n"
    << c35 << "\n"
    << c36 << "\n"
    << c37 << "\n"
    << c38 << "\n"
    << c39 << "\n"
    << c40 << "\n" << "\n"
    << c41 << "\n"
    << c42 << "\n"
    << c43 << "\n"
    << c44 << "\n"
    << c45 << "\n"
    << c46 << "\n"
    << c47 << "\n"
    << c48 << "\n"
    << c49 << "\n"
    << c50 << "\n" << "\n"
    << c51 << "\n"
    << c52 << "\n"
    << c53 << "\n"
    << c54 << "\n";














  /*  std::cout << "c1.GetRealPrecision() = " << c1.GetRealPrecision() << ", c1.GetImagPrecision() = " << c1.GetImagPrecision() << "\n"
	    << "c3.GetRealPrecision() = " << c3.GetRealPrecision() << ", c3.GetImagPrecision() = " << c3.GetImagPrecision() << "\n";
  
  
  
  std::cout << "c1 = " << c1 << "\n";
  std::cout << "c3 = " << c3 << "\n";

  */
  // ComplexAMP c4 = c1*c3;


  //  std::cout << "c4 = c1*c3 = " << c4 << " -- with a precision of c4.GetRealPrecision() = " << c4.GetRealPrecision() 
  //    << ", c4.GetImagPrecision() = " << c4.GetImagPrecision() << "\n";
  //  ComplexAMP c5 = c1/c3;
  //  ComplexAMP c6 = c1+c3;
  //  ComplexAMP c7 = c1-c3;
  



  //  std::cout << "c1 = " << c1 << "\n" << "c2 = " << c2 << "\n" << "c3 = " << c3 << "\n" << "c4 = " << c4 << "\n" << "c5 = " << c5 << "\n"
  //    << "c6 = " << c6 << "\n" << "c7 = " << c7 << "\n";



  /*  int testcount = 1;
  std::cout << "\n*******************\n\n";
  std::cout << "Test " << testcount++ << " -- default constructor \n\n";

  AMP a1;
  std::cout << "Successful default constructor for a1 'AMP A1;'.\n\n";
  std::cout << "a1 = " << a1 << "\n";
  std::cout << "a1.GetPrecision() = " << a1.GetPrecision() << "\n\n";


  std::cout << "\n*******************\n\n";
  std::cout << "Test " << testcount++ << " -- double constructor \n\n";
  AMP a2(2480.7931);

  std::cout << "Successful double constructor. 'AMP a2(2480.7931);'\n\n";
  std::cout << "a2 = " << a2 << "\n";
  std::cout << "a2.GetPrecision() = " << a2.GetPrecision() << "\n\n";


  std::cout << "\n*******************\n\n";
  std::cout << "Test " << testcount++ << " -- mp(string, int,int) constructor \n\n";

  AMP a3(".1390840284091369752084027084016871936786481647908452428080313686", 10, 200);
  std::cout << "Successful mp (string, int, int) constructor. 'AMP a3(\".1390840284091369752084027084016871936786481647908452428080313686\", 10, 200);' \n\n";
  std::cout << a3 << "\n\n";
  std::cout << "a3.GetPrecision() = " << a3.GetPrecision() << "\n\n";
  mpfr_t tmp;
  mpfr_init2(tmp, 100);
  mpfr_set_str(tmp, ".42975902804123819697520840729410370173905782749129317491707408952080428768462189421798301804261", 10, MPFR_RNDN);

  std::cout << "\n*******************\n\n";
  std::cout << "Test " << testcount++ << " -- AMP(mpfr_t m) constructor \n\n";

  AMP a4(tmp);
  std::cout << "Successful AMP (mpfr_t m) constructor. \n";
  std::cout << "' mpfr_t tmp;\nmpfr_init2(tmp, 100);\nmpfr_set_str(tmp, \".42975902804123819697520840729410370173905782749129317491707408952080428768462189421798301804261\", 10, MPFR_RNDN);"
	    << "\nAMP a4(tmp)\n\n";
  std::cout << "a4 = " << a4 << "\n";
  std::cout << "a4.GetPrecision() = " << a4.GetPrecision() << "\n";

  mpfr_clear(tmp);

  std::cout << "\n*******************\n\n";
  std::cout << "Test " << testcount++ << " -- SetD(double d) \n\n";

  a1.Set(.973100428183079789);
  std::cout << "successful a1.Set(double d):   'a1.SetD(.973100428183079789)'\n";
  std::cout << "a1 = " << a1 << "\n"
	    << "a1.GetPrecision() = " << a1.GetPrecision() << "\n";

  std::cout << "\n*******************\n\n";
  std::cout << "Test " << testcount++ << " -- move to higher precision from hardware -- \n\n";
  // test moving up in precision
  a1.SetPrecision(96);
  std::cout << "successful SetPrecision(int prec) from hardware precision to multiprecision: '  a1.SetPrecision(96);'\n'"
	    << "a1 = " << a1 << "\na1.GetPrecision() = " << a1.GetPrecision() << "\n";

  std::cout << "\n*******************\n\n";
  std::cout << "Test " << testcount++ << " -- assignment = operator \n\n";
  AMP a0 = a3;
  std::cout << "a0 = " << a0 << "\na0.GetPrecision() = " << a0.GetPrecision() << "\n" << "a0.GetPrecisionB() = " << a0.GetPrecisionB() << "\n"
	    << "a3 = " << a3 << "\na3.GetPrecision() = " << a3.GetPrecision() << "\n" << "a3.GetPrecisionB() = " << a3.GetPrecisionB() << "\n";

  std::cout << "\n*******************\n\n";
  std::cout << "Test " << testcount++ << " -- move to lower precision from multiprecision \n\n";

  a3.SetPrecision(64);
  std::cout << "successful SetPrecision(int prec) from multiprecision to hardware precision: ' a3.SetPrecision(64);'\n"
	    << "a3 = " << a3 << "\n" << "a3.GetPrecision() = " << a3.GetPrecision() << "\n"
	    << "\na0 should not have changed.\n\n"
	    << "a0 = " << a0 << "\na0.GetPrecision() = " << a0.GetPrecision() << "\n" << "a0.GetPrecisionB() = " << a0.GetPrecisionB() << "\n";

  
  std::cout << "\n*******************\n\n";
  std::cout << "Test " << testcount++ << " -- hardware precision to hardware precision \n\n";
  a2.SetPrecision(3);
  std::cout << "successful SetPrecision(int) : 'a2.SetPrecision(3)'\n";
  std::cout << "a2 = " << a2 << "\n" << "a2.GetPrecision() = " << a2.GetPrecision() << "\n";
  

  
  std::cout << "\n*******************\n\n";
  std::cout << "\n\naddition tests \n\n";


  std::cout << "\n*******************\n\n";
  std::cout << "Test " << testcount++ << " -- assignment = operator and + operator (hardware precision) \n\n";




  AMP a5 = a2 + a3;
  std::cout << "successful assignment = operator and + operator (hardware_precision): 'AMP a5 = a2 + a3;'\n";
  std::cout << "a5 = " << a5 << "\n" << "a5.GetPrecision() = " << a5.GetPrecision() << "\n";
  std::cout //<< "a2.GetPrecisionB() = " << a2.GetPrecisionB() 
	    //<< ", a3.GetPrecisionB() = " << a3.GetPrecisionB() 
    << ((a2.GetPrecisionB() || a3.GetPrecisionB()) == 0 ? " -- both are hardware\n" : " -- one or both is mp\n");

  std::cout << "\n*******************\n\n";
  std::cout << "Test " << testcount++ << " --  + operator (mp + hardware) \n\n";


  AMP a6 = a1 + a5;
  std::cout << "successful + operator :  left operand is mp, right operand is hardware:  'AMP a6 = a1 + a5;'\n"
	    << "a6 = " << a6 << "\n"
	    << "a6.GetPrecision() = " << a6.GetPrecision() << "\n"
	    << (a1.GetPrecisionB() == 0 ? "left operand is hardware. " : "left operand is mp. ") 
	    << (a5.GetPrecisionB() == 0 ? "right operand is hardware. " : "right operand is mp. ")
	    << ((a1.GetPrecisionB() || a5.GetPrecisionB()) == 0 ? "hardware addition performed.\n" : "mp addition performed.\n");


  std::cout << "\n*******************\n\n";
  std::cout << "Test " << testcount++ << " -- + operator (hardware + mp) \n\n";


  AMP a7 = a5 + a1;
  std::cout << "successful + operator :  left operand is hardware, right operand is mp:  'AMP a6 = a1 + a5;'\n"
	    << "a7 = " << a7 << "\n"
	    << "a7.GetPrecision() = " << a7.GetPrecision() << "\n"
	    << (a5.GetPrecisionB() == 0 ? "left operand is hardware. " : "left operand is mp. ") 
	    << (a1.GetPrecisionB() == 0 ? "right operand is hardware. " : "right operand is mp. ")
	    << ((a5.GetPrecisionB() || a1.GetPrecisionB()) == 0 ? "hardware addition performed.\n" : "mp addition performed.\n");


  std::cout << "\n*******************\n\n";
  std::cout << "Test " << testcount++ << " -- + operator (mp + mp) \n\n";
  
  AMP a8 = a1 + a0;
  std::cout << "successful + operator : left operand is mp, right operand is mp: 'AMP a8 = a1 + a0;'\n"
	    << "a8 = " << a8 << "\na8.GetPrecision() = " << a8.GetPrecision() << "\n"
	    << (a1.GetPrecisionB() == 0 ? "left operand is hardware. " : "left operand is mp. ") 
	    << (a0.GetPrecisionB() == 0 ? "right operand is hardware. " : "right operand is mp. ")
	    << ((a1.GetPrecisionB() || a0.GetPrecisionB()) == 0 ? "hardware addition performed.\n" : "mp addition performed.\n");

  



  std::cout << "\n\nsubtraction tests \n\n";




  std::cout << "\n*******************\n\n";
  std::cout << "Test " << testcount++ << " --  - operator (hardware precision) \n\n";




  AMP a9 = a2 - a3;
  std::cout << "successful - operator (hardware_precision): 'AMP a9 = a2 + a3;'\n";
  std::cout << "a9 = " << a9 << "\n" << "a9.GetPrecision() = " << a9.GetPrecision() << "\n";
  std::cout //<< "a2.GetPrecisionB() = " << a2.GetPrecisionB() 
	    //<< ", a3.GetPrecisionB() = " << a3.GetPrecisionB() 
    << ((a2.GetPrecisionB() || a3.GetPrecisionB()) == 0 ? " -- both are hardware\n" : " -- one or both is mp\n");

  std::cout << "\n*******************\n\n";
  std::cout << "Test " << testcount++ << " --  - operator (mp - hardware) \n\n";


  AMP a10 = a1 - a5;
  std::cout << "successful - operator :  left operand is mp, right operand is hardware:  'AMP a10 = a1 - a5;'\n"
	    << "a10 = " << a10 << "\n"
	    << "a10.GetPrecision() = " << a10.GetPrecision() << "\n"
	    << (a1.GetPrecisionB() == 0 ? "left operand is hardware. " : "left operand is mp. ") 
	    << (a5.GetPrecisionB() == 0 ? "right operand is hardware. " : "right operand is mp. ")
	    << ((a1.GetPrecisionB() || a5.GetPrecisionB()) == 0 ? "hardware subtraction performed.\n" : "mp subtraction performed.\n");


  std::cout << "\n*******************\n\n";
  std::cout << "Test " << testcount++ << " -- - operator (hardware + mp) \n\n";


  AMP a11 = a5 - a1;
  std::cout << "successful - operator :  left operand is hardware, right operand is mp:  'AMP a11 = a5 - a1;'\n"
	    << "a11 = " << a11 << "\n"
	    << "a11.GetPrecision() = " << a11.GetPrecision() << "\n"
	    << (a5.GetPrecisionB() == 0 ? "left operand is hardware. " : "left operand is mp. ") 
	    << (a1.GetPrecisionB() == 0 ? "right operand is hardware. " : "right operand is mp. ")
	    << ((a5.GetPrecisionB() || a1.GetPrecisionB()) == 0 ? "hardware subtraction performed.\n" : "mp subtraction performed.\n");


  std::cout << "\n*******************\n\n";
  std::cout << "Test " << testcount++ << " -- - operator (mp - mp) \n\n";
  
  AMP a12 = a1 - a0;
  std::cout << "successful - operator : left operand is mp, right operand is mp: 'AMP a12 = a1 - a0;'\n"
	    << "a12 = " << a12 << "\na12.GetPrecision() = " << a12.GetPrecision() << "\n"
	    << (a1.GetPrecisionB() == 0 ? "left operand is hardware. " : "left operand is mp. ") 
	    << (a0.GetPrecisionB() == 0 ? "right operand is hardware. " : "right operand is mp. ")
	    << ((a1.GetPrecisionB() || a0.GetPrecisionB()) == 0 ? "hardware subtraction performed.\n" : "mp subtraction performed.\n");

  

  std::cout << "\n\nmultiplication tests\n\n";

  std::cout << "\n*******************\n\n";
  std::cout << "Test " << testcount++ << " -- * operator (hardware precision) \n\n";




  AMP a13 = a2 * a3;
  std::cout << "successful * operator (hardware_precision): 'AMP a13 = a2 * a3;'\n";
  std::cout << "a13 = " << a13 << "\n" << "a13.GetPrecision() = " << a13.GetPrecision() << "\n";
  std::cout //<< "a2.GetPrecisionB() = " << a2.GetPrecisionB() 
	    //<< ", a3.GetPrecisionB() = " << a3.GetPrecisionB() 
    << ((a2.GetPrecisionB() || a3.GetPrecisionB()) == 0 ? " -- both are hardware\n" : " -- one or both is mp\n");

  std::cout << "\n*******************\n\n";
  std::cout << "Test " << testcount++ << " --  * operator (mp * hardware) \n\n";


  AMP a14 = a1 * a5;
  std::cout << "successful * operator :  left operand is mp, right operand is hardware:  'AMP a14 = a1 * a5;'\n"
	    << "a14 = " << a14 << "\n"
	    << "a14.GetPrecision() = " << a14.GetPrecision() << "\n"
	    << (a1.GetPrecisionB() == 0 ? "left operand is hardware. " : "left operand is mp. ") 
	    << (a5.GetPrecisionB() == 0 ? "right operand is hardware. " : "right operand is mp. ")
	    << ((a1.GetPrecisionB() || a5.GetPrecisionB()) == 0 ? "hardware multiplication performed.\n" : "mp multiplication performed.\n");


  std::cout << "\n*******************\n\n";
  std::cout << "Test " << testcount++ << " -- * operator (hardware * mp) \n\n";


  AMP a15 = a5 * a1;
  std::cout << "successful * operator :  left operand is hardware, right operand is mp:  'AMP a15 = a5 * a1;'\n"
	    << "a15 = " << a15 << "\n"
	    << "a15.GetPrecision() = " << a15.GetPrecision() << "\n"
	    << (a5.GetPrecisionB() == 0 ? "left operand is hardware. " : "left operand is mp. ") 
	    << (a1.GetPrecisionB() == 0 ? "right operand is hardware. " : "right operand is mp. ")
	    << ((a5.GetPrecisionB() || a1.GetPrecisionB()) == 0 ? "hardware multiplication performed.\n" : "mp multiplication performed.\n");


  std::cout << "\n*******************\n\n";
  std::cout << "Test " << testcount++ << " -- * operator (mp * mp) \n\n";
  
  AMP a16 = a1 * a0;
  std::cout << "successful * operator : left operand is mp, right operand is mp: 'AMP a16 = a1 * a0;'\n"
	    << "a16 = " << a16 << "\na16.GetPrecision() = " << a8.GetPrecision() << "\n"
	    << (a1.GetPrecisionB() == 0 ? "left operand is hardware. " : "left operand is mp. ") 
	    << (a0.GetPrecisionB() == 0 ? "right operand is hardware. " : "right operand is mp. ")
	    << ((a1.GetPrecisionB() || a0.GetPrecisionB()) == 0 ? "hardware multiplication performed.\n" : "mp multiplication performed.\n");

  

  std::cout << "\n\ndivision tests\n\n";

  std::cout << "\n*******************\n\n";
  std::cout << "Test " << testcount++ << " -- / operator (hardware precision) \n\n";




  AMP a17 = a2 / a3;
  std::cout << "successful / operator (hardware_precision): 'AMP a17 = a2 / a3;'\n";
  std::cout << "a17 = " << a17 << "\n" << "a17.GetPrecision() = " << a17.GetPrecision() << "\n";
  std::cout //<< "a2.GetPrecisionB() = " << a2.GetPrecisionB() 
	    //<< ", a3.GetPrecisionB() = " << a3.GetPrecisionB() 
    << ((a2.GetPrecisionB() || a3.GetPrecisionB()) == 0 ? " -- both are hardware\n" : " -- one or both is mp\n");

  std::cout << "\n*******************\n\n";
  std::cout << "Test " << testcount++ << " --  / operator (mp / hardware) \n\n";


  AMP a18 = a1 / a5;
  std::cout << "successful / operator :  left operand is mp, right operand is hardware:  'AMP a18 = a1 / a5;'\n"
	    << "a18 = " << a18 << "\n"
	    << "a18.GetPrecision() = " << a18.GetPrecision() << "\n"
	    << (a1.GetPrecisionB() == 0 ? "left operand is hardware. " : "left operand is mp. ") 
	    << (a5.GetPrecisionB() == 0 ? "right operand is hardware. " : "right operand is mp. ")
	    << ((a1.GetPrecisionB() || a5.GetPrecisionB()) == 0 ? "hardware division performed.\n" : "mp division performed.\n");


  std::cout << "\n*******************\n\n";
  std::cout << "Test " << testcount++ << " -- / operator (hardware / mp) \n\n";


  AMP a19 = a5 / a1;
  std::cout << "successful / operator :  left operand is hardware, right operand is mp:  'AMP a19 = a5 / a1;'\n"
	    << "a19 = " << a19 << "\n"
	    << "a19.GetPrecision() = " << a19.GetPrecision() << "\n"
	    << (a5.GetPrecisionB() == 0 ? "left operand is hardware. " : "left operand is mp. ") 
	    << (a1.GetPrecisionB() == 0 ? "right operand is hardware. " : "right operand is mp. ")
	    << ((a5.GetPrecisionB() || a1.GetPrecisionB()) == 0 ? "hardware division performed.\n" : "mp division performed.\n");


    
  std::cout << "\n*******************\n\n";
  std::cout << "Test " << testcount++ << " -- / operator (mp  mp) \n\n";
  
  AMP a20 = a1 / a0;
  std::cout << "successful / operator : left operand is mp, right operand is mp: 'AMP a20 = a1 / a0;'\n"
	    << "a20 = " << a20 << "\na20.GetPrecision() = " << a20.GetPrecision() << "\n"
	    << (a1.GetPrecisionB() == 0 ? "left operand is hardware. " : "left operand is mp. ") 
	    << (a0.GetPrecisionB() == 0 ? "right operand is hardware. " : "right operand is mp. ")
	    << ((a1.GetPrecisionB() || a0.GetPrecisionB()) == 0 ? "hardware division performed.\n" : "mp division performed.\n");

  







  */

  return 0;

}
