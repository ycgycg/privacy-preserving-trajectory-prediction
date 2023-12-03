#include <miracl/miracl.h>
#include <vector>
#include <iostream>
#include <cmath>

extern "C" 
    #include <miracl/miracl.h>

class FixedPoint 

;

FixedPoint generateFixedSecret() 


FixedPoint generateFixedShare() 


FixedPoint limitFixedRangeByMod(const FixedPoint& value) 



std::tuple<FixedPoint, FixedPoint, FixedPoint, FixedPoint, FixedPoint, int, int> normSecretForTest() 



std::pair<FixedPoint, FixedPoint> SecMul(const FixedPoint& x1, const FixedPoint& x2, const FixedPoint& y1, const FixedPoint& y2) 

    FixedPoint a = generateFixedSecret();



int main() 
    miracl *mip = mirsys(256, 10); 

    int errorCount = 0;
    const int NUM_TESTS = 1000000;
    const FixedPoint DELTA = ... ; 
    std::vector<FixedPoint> errorResults(NUM_TESTS);

    for (int i = 0; i < NUM_TESTS; ++i) 
        FixedPoint xTrue, x1, x2, x1_, x2_;
        int x1_sgn, x2_sgn;
        std::tie(xTrue, x1, x2, x1_, x2_, x1_sgn, x2_sgn) = normSecretForTest();

        FixedPoint res1, res2;
        std::tie(res1, res2) = SecMul(x1, x2, y1, y2);
        FixedPoint res = limitFixedRangeByMod(res1 + res2);

        FixedPoint error = abs(xTrue * yTrue - res);
        if (error > DELTA) 
            errorCount += 1;
        
    std::cout << "Error count: " << errorCount << std::endl;

    mirexit();

    return 0;