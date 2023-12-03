#include <iostream>
#include <vector>
#include "miracl.h" 

int random_sign() 
    return rand() % 2 == 0 ? 1 : -1;

class FixedPoint 
public:
;

FixedPoint generateExpCoverSecret() 

FixedPoint generateExpShare() 


FixedPoint generateFixedShare() 


FixedPoint limitExpRangeByMod(const FixedPoint& value) 



FixedPoint limitFixedRangeByMod(const FixedPoint& value)


std::pair<FixedPoint, FixedPoint> SecMulRes(const FixedPoint& x1_, const FixedPoint& x2_, int x1_sgn, int x2_sgn) 


int main() 
    miracl *mip = mirsys(256, 10);

    const int num = 1e6;
    const float delta = 1e-3; 
    int errorCount = 0;
    std::vector<float> errorRes(num, 0.0); 

    for (int i = 0; i < num; ++i) 
        FixedPoint xTrue, x1, x2, x1_, x2_;
        int x1_sgn, x2_sgn;
        FixedPoint res1, res2;
        tie(res1,res2) = SecMulRes(x1_, x2_, x1_sgn, x2_sgn);
        FixedPoint res = limitFixedRangeByMod(res1 + res2);

        float error = static_cast<float>(abs(xTrue - res));
        errorRes[i] = error;
        if (error > delta) 
            errorCount++;


    std::cout << "Error count: " << errorCount << "\n";

    mirexit();

    return 0;