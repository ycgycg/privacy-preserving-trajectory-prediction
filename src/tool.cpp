#include <miracl.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cstdlib>

struct Const 
    int cfracbit;
    int efracbit;
    int cintbit;
    int cshareintbit;
    int dim;
;

Const const; 


int generateExpSecret() 

    return rand() % (2 * const.cintbit) - const.cintbit;




miracl* initializeMiracl() 
    time_t seed;
    time(&seed);
    miracl* mip = mirsys(5000, 0); 
    irand((int)seed); // 设置随机种子


    return mip;

class FixedPoint 
;

int main() 
    miracl *mip = initializeMiracl();

    FixedPoint xTrue, x1, x2, x1_, x2_;
    int x1_sgn, x2_sgn;

    mirexit();

    return 0;