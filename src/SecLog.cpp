#include <miracl/miracl.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <tuple>
#include "SecAddRes.h"          
#include "FixedPointOperations.h" 
#include "TestUtils.h"           

const double DELTA = 0.001;

int main() 
    const int NUM_TESTS = 1000000; 
    int errorCount = 0; 

    miracl* mip = mirsys(100, 0); 
    mip->IOBASE = 10;

    for (int i = 0; i < NUM_TESTS; ++i) 
      
        double xTrue;
        Big x1, x2, x1_, x2_;
        int x1_sgn, x2_sgn;
        std::tie(xTrue, x1, x2, x1_, x2_, x1_sgn, x2_sgn) = normSecretForTest();

     
        std::tie(x1_, x2_, x1_sgn, x2_sgn) = SecLog(x1, x2);

   
        x1_ = limitExpRangeByMod(x1_);
        x2_ = limitExpRangeByMod(x2_);


        double res = x1_sgn * x2_sgn * pow(2.0, big_to_double(x1_ + x2_));

 
        double error = fabs(xTrue - res);

        if (error > DELTA) 
            errorCount++;
        
    

    std::cout << "Error count: " << errorCount << " out of " << NUM_TESTS << " tests." << std::endl;


    mirexit();

    return 0;



inline double big_to_double(const Big& num) 

std::tuple<double, Big, Big, Big, Big, int, int> normSecretForTest() 



Big limitExpRangeByMod(const Big& x) 


std::tuple<Big, Big, int, int> SecLog(const Big& x1, const Big& x2) 