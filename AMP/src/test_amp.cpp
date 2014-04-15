
#include "amp.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>



int main(){
  int testcount = 1;
  
    
    std::cout << "\n*******************\n\n";
    std::cout << "Test " << testcount++ << " --- default constructor : \n";
    std::cout << "AMP a1;\n";
    AMP a1;
    
    std::cout << a1.GetStats("a1");
    
    mpfr_t m1;
    mpfr_init2(m1, 200);
    std::string sm1 = ".4289752083091740193840376037104709136407130583909742058139425891364961384691827392735927503872508358392040183748013740812740827410871";
    mpfr_set_str(m1, sm1.c_str(), 10, MPFR_RNDN);
    std::cout << "\n*******************\n\n";
    std::cout << "Test " << testcount++ << " --- AMP(mpfr_t m1) Constructor : \n";
    std::cout << "AMP a2(m1);\n";
    AMP a2(m1);
    
    std::cout << a2.GetStats("a2");

    std::string sm2 = ".5829639709248056731870470984209830741072392174087420580329850983409137083472102754084092850236497126478518735401842097649285703124830186489724091709248102948618305714701836593872048267529637108243258794872015627398140932976481648923740381740";

    std::cout << "\n*******************\n\n";
    std::cout << "Test " << testcount++ << " --- AMP(std::string s, int base, int prec) Constructor : \n";
    std::cout << "AMP a3(sm2, 10, 320);\n";
    
    AMP a3(sm2, 10, 1024);
    
    std::cout << a3.GetStats("a3");
    
    
    AMP a4(.1750284075032985);
    std::cout << "\n*******************\n\n";
    std::cout << "Test " << testcount++ << " --- AMP(double d) Constructor : \n";
    std::cout << "AMP a4(.1750284075032985);\n";
    std::cout << a4.GetStats("a4");
    std::cout << "\n*******************\n\n";
    
    
    std::cout << "Constructors are all successful.\n";
    
    
    std::cout << "\n\nTesting Inspectors / Getters.\n\n";
    
    std::cout << "Testing a3.GetD() : "
              << *a3.GetD()
              << "\n\n"
              << "Testing a3.GetMP() : \n"
              << *a3.GetMP()
              << "\n\n"
              << "Testing a3.GetPrecisionB() : "
              << a3.GetPrecisionB()
              << "\n\n"
              << "Testing a3.GetPrecision() : "
              << a3.GetPrecision()
              << "\n\n";
    
    std::cout << "Testing Inspectors are all succesful.\n";
    
    std::cout << "\n\nTesting Modifiers / Setters.\n\n";
    
    AMP a100(a3);
    
    std::cout << "Testing a100.SetPrecision(int) : a100.SetPrecision(400);\n";
    std::cout << a100.GetStats("a100") << "\n\n";
    a100.SetPrecision(400);
    std::cout << a100.GetStats("a100") << "\n\n";
    std::cout << "Testing a100.SetPrecision(mp_prec_t) : a100.SetPrecision(mpfr_get_prec(a3));\n";
    a100.SetPrecision(mpfr_get_prec(*a3.GetMP()));
    std::cout << a100.GetStats("a100") << "\n\n";
    std::cout << "Testing a100.SetPrecision(int) -- move to hardware precision : a100.SetPrecision(HARDWARE_PRECISION);\n";
    a100.SetPrecision(HARDWARE_PRECISION);
    std::cout << a100.GetStats("a100") << "\n\n";
    std::cout << "***********************\n\n";
    
    
    std::cout << "Testing a1.Set(double) : a1.Set(.1894724908572);\n\n";
    a1.Set(.1894724908572);
    std::cout << a1.GetStats("a1");
    
    
    std::cout << "Testing a1.Set(mpfr_t) : a1.Set(m1);\n\n";
    a1.Set(m1);
    std::cout << a1.GetStats("a1") << "\n";
    
    
    std::cout << "Testing a1.Set(std::string str, int base, int prec) : a1.Set(sm3, 10, 1024); \n";
    
    std::string sm3 = ".689639782987492570298395720689350927503297598163249817649217407035927059732057320562308945732057209347309587092375095327509372438193469185703298515896139058029467903570329582305790";
    a1.Set(sm3, 10, 1024);
    
    std::cout << a1.GetStats("a1") << "\n";
    
    std::cout << "Testing = assignment operator : a5 = a1; \n";
    AMP a5;
    a5 = a1;
    std::cout << a5.GetStats("a5");
    
    
    std::cout << "Assignment = operator successful.\n\n";
    
    std::cout << "Testing << insertion operator. \n\n";
    std::cout << "a1 = " << a1 << "\n\n" << "a2 = " << a2 << "\n\n" << "a3 = " << a3 << "\n\n"
              << "a4 = " << a4 << "\n\n" << "a5 = " << a5 << "\n\n";
    
    
    std::cout << " << insertion operator successful.\n\n"
    << "********************\n\n";
    std::cout << "Testing arithmetic operations. \n\n";
    std::cout << "********************\n\n";
    std::cout << "Testing Addition.\n\n";
    std::cout << "********************\n\n";
    std::cout << "Testing AMP + AMP (double + double) : AMP a6 = a4 + a4; \n\n";
    AMP a6 = a4 + a4;
    std::cout << a4.GetStats("a4") << "\n\n";
    std::cout << a6.GetStats("a6") << "\n\n";
    std::cout << "Testing AMP + double (double + double) : AMP a7 = a4 + 3.2; \n\n";
    AMP a7 = a4 + 3.2;
    std::cout << a4.GetStats("a4") << "\n\n"
              << a7.GetStats("a7") << "\n\n";
    std::cout << "Testing double + AMP (double + double) : AMP a8 = 2.5 + a4; \n\n";
    AMP a8 = 2.5 + a4;
    std::cout << a4.GetStats("a4") << "\n\n"
              << a8.GetStats("a8") << "\n\n";
    
    std::cout << "Testing AMP + AMP (double + MP) : AMP a9 = a8 + a5;\n\n";
    AMP a9 = a8 + a5;
    std::cout << a8.GetStats("a8") << "\n\n" << a5.GetStats("a5") << "\n\n" << a9.GetStats("a9") << "\n\n";
    
    std::cout << "Testing AMP + AMP (MP + double) : AMP a10 = a3 + a7;\n\n";
    AMP a10 = a3 + a7;
    std::cout << a3.GetStats("a3") << "\n\n" << a7.GetStats("a7") << "\n\n" << a10.GetStats("a10") << "\n\n";
    std::cout << "Testing AMP + AMP (MP + MP) : AMP a11 = a2 + a3; \n\n";
    AMP a11 = a2 + a3;
    std::cout << a2.GetStats("a2") << "\n\n" << a3.GetStats("a3") << "\n\n" << a11.GetStats("a11") << "\n\n";
    std::cout << "Testing AMP + double (MP + double) : AMP a12 = a2 + 4.2\n\n";
    AMP a12 = a2 + 4.2;
    std::cout << a2.GetStats("a2") << "\n\n" << a12.GetStats("a12") << "\n\n";
    
    std::cout << "Testing double + AMP (double + MP) : AMP a13 = 1.4 + a2;\n\n";
    AMP a13 = 1.4 + a2;
    std::cout << a2.GetStats("a2") << "\n\n";
    std::cout << a13.GetStats("a13") << "\n\n";
    
    
    
    
    
    
    std::cout << "********************\n\n";
    std::cout << "Testing Subtraction.\n\n";
    std::cout << "********************\n\n";
    std::cout << "Testing AMP - AMP (double - double) : AMP a14 = a8 - a4; \n\n";
    AMP a14 = a8 - a4;
    std::cout << a8.GetStats("a8") << "\n\n";
    std::cout << a4.GetStats("a4") << "\n\n";
    std::cout << a14.GetStats("a14") << "\n\n";
    std::cout << "Testing AMP - double (double - double) : AMP a15 = a4 - 3.2; \n\n";
    AMP a15 = a4 - 3.2;
    std::cout << a4.GetStats("a4") << "\n\n"
              << a15.GetStats("a15") << "\n\n";
    std::cout << "Testing double - AMP (double - double) : AMP a16 = 2.5 - a4; \n\n";
    AMP a16 = 2.5 - a4;
    std::cout << a4.GetStats("a4") << "\n\n"
              << a16.GetStats("a16") << "\n\n";
    
    std::cout << "Testing AMP - AMP (double - MP) : AMP a17 = a8 - a5;\n\n";
    AMP a17 = a8 - a5;
    std::cout << a8.GetStats("a8") << "\n\n" << a5.GetStats("a5") << "\n\n" << a17.GetStats("a17") << "\n\n";
    
    std::cout << "Testing AMP - AMP (MP - double) : AMP a18 = a3 - a7;\n\n";
    AMP a18 = a3 - a7;
    std::cout << a3.GetStats("a3") << "\n\n" << a7.GetStats("a7") << "\n\n" << a18.GetStats("a18") << "\n\n";
    std::cout << "Testing AMP - AMP (MP - MP) : AMP a19 = a2 - a3; \n\n";
    AMP a19 = a2 - a3;
    std::cout << a2.GetStats("a2") << "\n\n" << a3.GetStats("a3") << "\n\n" << a19.GetStats("a19") << "\n\n";
    std::cout << "Testing AMP - double (MP - double) : AMP a20 = a2 - 4.2\n\n";
    AMP a20 = a2 - 4.2;
    std::cout << a2.GetStats("a2") << "\n\n" << a20.GetStats("a20") << "\n\n";
    
    std::cout << "Testing double - AMP (double - MP) : AMP a21 = 1.4 - a2;\n\n";
    AMP a21 = 1.4 - a2;
    std::cout << a2.GetStats("a2") << "\n\n";
    std::cout << a21.GetStats("a21") << "\n\n";
    

    std::cout << "********************\n\n";
    std::cout << "Testing Multiplication.\n\n";
    std::cout << "********************\n\n";
    std::cout << "Testing AMP * AMP (double * double) : AMP a22 = a8 * a4; \n\n";
    AMP a22 = a8 * a4;
    std::cout << a8.GetStats("a8") << "\n\n";
    std::cout << a4.GetStats("a4") << "\n\n";
    std::cout << a22.GetStats("a22") << "\n\n";
    std::cout << "Testing AMP * double (double * double) : AMP a23 = a4 * 3.2; \n\n";
    AMP a23 = a4 * 3.2;
    std::cout << a4.GetStats("a4") << "\n\n"
              << a23.GetStats("a23") << "\n\n";
    std::cout << "Testing double * AMP (double * double) : AMP a24 = 2.5 * a4; \n\n";
    AMP a24 = 2.5 * a4;
    std::cout << a4.GetStats("a4") << "\n\n"
              << a24.GetStats("a24") << "\n\n";
    
    std::cout << "Testing AMP * AMP (double * MP) : AMP a25 = a8 * a5;\n\n";
    AMP a25 = a8 * a5;
    std::cout << a8.GetStats("a8") << "\n\n" << a5.GetStats("a5") << "\n\n" << a25.GetStats("a25") << "\n\n";

    std::cout << "Testing AMP * AMP (MP * double) : AMP a26 = a3 * a7;\n\n";
    AMP a26 = a3 * a7;
    std::cout << a3.GetStats("a3") << "\n\n" << a7.GetStats("a7") << "\n\n" << a26.GetStats("a26") << "\n\n";
    std::cout << "Testing AMP * AMP (MP * MP) : AMP a27 = a2 * a3; \n\n";
    AMP a27 = a2 * a3;
    std::cout << a2.GetStats("a2") << "\n\n" << a3.GetStats("a3") << "\n\n" << a27.GetStats("a27") << "\n\n";
    std::cout << "Testing AMP * double (MP * double) : AMP a28 = a2 * 4.2\n\n";
    AMP a28 = a2 * 4.2;
    std::cout << a2.GetStats("a2") << "\n\n" << a28.GetStats("a28") << "\n\n";
    
    std::cout << "Testing double * AMP (double * MP) : AMP a29 = 1.4 * a2;\n\n";
    AMP a29 = 1.4 * a2;
    std::cout << a2.GetStats("a2") << "\n\n";
    std::cout << a29.GetStats("a29") << "\n\n";
    
    
    
 
    
    std::cout << "********************\n\n";
    std::cout << "Testing Division.\n\n";
    std::cout << "********************\n\n";
    std::cout << "Testing AMP / AMP (double / double) : AMP a30 = a8 / a4; \n\n";
    AMP a30 = a8 / a4;
    std::cout << a8.GetStats("a8") << "\n\n";
    std::cout << a4.GetStats("a4") << "\n\n";
    std::cout << a22.GetStats("a22") << "\n\n";
    std::cout << "Testing AMP / double (double / double) : AMP a31 = a4 / 3.2; \n\n";
    AMP a31 = a4 / 3.2;
    std::cout << a4.GetStats("a4") << "\n\n"
              << a31.GetStats("a31") << "\n\n";
    std::cout << "Testing double / AMP (double / double) : AMP a32 = 2.5 / a4; \n\n";
    AMP a32 = 2.5 / a4;
    std::cout << a4.GetStats("a4") << "\n\n"
              << a32.GetStats("a32") << "\n\n";
    
    std::cout << "Testing AMP / AMP (double / MP) : AMP a33 = a8 / a5;\n\n";
    AMP a33 = a8 / a5;
    std::cout << a8.GetStats("a8") << "\n\n" << a5.GetStats("a5") << "\n\n" << a33.GetStats("a33") << "\n\n";
    
    std::cout << "Testing AMP / AMP (MP / double) : AMP a34 = a3 / a7;\n\n";
    AMP a34 = a3 / a7;
    std::cout << a3.GetStats("a3") << "\n\n" << a7.GetStats("a7") << "\n\n" << a34.GetStats("a34") << "\n\n";
    std::cout << "Testing AMP / AMP (MP / MP) : AMP a35 = a2 / a3; \n\n";
    AMP a35 = a2 / a3;
    std::cout << a2.GetStats("a2") << "\n\n" << a3.GetStats("a3") << "\n\n" << a35.GetStats("a35") << "\n\n";
    std::cout << "Testing AMP / double (MP / double) : AMP a36 = a2 / 4.2\n\n";
    AMP a36 = a2 / 4.2;
    std::cout << a2.GetStats("a2") << "\n\n" << a36.GetStats("a36") << "\n\n";
    
    std::cout << "Testing double / AMP (double / MP) : AMP a37 = 1.4 / a2;\n\n";
    AMP a37 = 1.4 / a2;
    std::cout << a2.GetStats("a2") << "\n\n";
    std::cout << a37.GetStats("a37") << "\n\n";
    
    
    std::ofstream fout("results_amp");
    fout << a1 << "\n"
         << a2 << "\n"
         << a3 << "\n"
         << a4 << "\n"
         << a5 << "\n"
         << a6 << "\n"
         << a7 << "\n"
         << a8 << "\n"
         << a9 << "\n"
         << a10 << "\n"
         << a11 << "\n"
         << a12 << "\n"
         << a13 << "\n"
         << a14 << "\n"
         << a15 << "\n"
         << a16 << "\n"
        << a17 << "\n"
        << a18 << "\n"
        << a19 << "\n"
        << a20 << "\n"
        << a21 << "\n"
        << a22 << "\n"
        << a23 << "\n"
        << a24 << "\n"
        << a25 << "\n"
        << a26 << "\n"
    << a27 << "\n"
    << a28 << "\n"
    << a29 << "\n"
    << a30 << "\n"
    << a31 << "\n"
    << a32 << "\n"
    << a33 << "\n"
    << a34 << "\n"
    << a35 << "\n"
    << a36 << "\n"
    << a37 << "\n";
    
    
    /*
    
  
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
  std::cout << "Test " << testcount++ << " -- Set(double d) \n\n";

  a1.Set(.973100428183079789);
  std::cout << "successful a1.Set(double d):   'a1.Set(.973100428183079789)'\n";
  std::cout << "a1 = " << a1 << "\n"
	    << "a1.GetPrecision() = " << a1.GetPrecision() << "\n";

  std::cout << "\n*******************\n\n";
  std::cout << "Test " << testcount++ << " -- Set(mpfr_t m) \n\n";
  AMP a45;
  mpfr_t m;
  mpfr_init2(m, 180);
  mpfr_set_str(m, ".920476107502730816407810360957203649318725896391601836480123806013847981365897102476031847028658021740164087421047036850174230271047919024707310957093754276593164",
	       10,
	       MPFR_RNDN);

  a45.Set(m);
  std::cout << "successful a45.Set(mpfr_t m):   'a45.Set(m)'\n";
  std::cout << "a45 = " << a45 << "\n"
	    << "a45.GetPrecision() = " << a45.GetPrecision() << "\n";
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
  std::cout << "Here\n";

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
  std::cout << "successful * operator :  left operand is mp, right operand is hardware:  'AMP a14 = a1 * a5;'\n";
    std::cout << "HERE\n\n";
  std::cout << "a14 = " << a14 << "\n"
	    << "a14.GetPrecision() = " << a14.GetPrecision() << "\n";

  std::cout << "\n\nHERE\n\n";
  std::cout << (a1.GetPrecisionB() == 0 ? "left operand is hardware. " : "left operand is mp. ");
  std::cout << (a5.GetPrecisionB() == 0 ? "right operand is hardware. " : "right operand is mp. ");
  std::cout << ((a1.GetPrecisionB() || a5.GetPrecisionB()) == 0 ? "hardware multiplication performed.\n" : "mp multiplication performed.\n");


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
