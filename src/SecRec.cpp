#include "miracl.h" 
#include <ctime>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cmath>

struct Const 
    int cfracbit;
    int cintbit;
 const;


int random_sign() 
    return rand() % 2 == 0 ? -1 : 1;



int generateExpCoverSecret() 


float generateFixedShare() 


float limitFixedRangeByMod(float x) 



float float_to_fixed(float input, int fractional_bits) 
    return floor(input * (1 << fractional_bits));


std::pair<float, float> SecMul(float x1, float x2, float c1, float c2) 


std::pair<float, float> SecDiv(float x1, float x2, float y1, float y2) 

    int c_sgn = random_sign();
    float c_ = float(generateExpCoverSecret());
    float c = c_sgn * std::pow(2.0, c_);
    c = float_to_fixed(c, const.cfracbit);
    float c1 = generateFixedShare();
    float c2 = limitFixedRangeByMod(c - c1);

    auto [cx1, cx2] = SecMul(x1, x2, c1, c2);
    auto [cy1, cy2] = SecMul(y1, y2, c1, c2);

    float cy = limitFixedRangeByMod(cy1 + cy2);

    float cyInv = 1 / cy; 
    cyInv = float_to_fixed(cyInv, const.cfracbit);

    float xDivY1 = limitFixedRangeByMod(cyInv * cx1);
    float xDivY2 = limitFixedRangeByMod(cyInv * cx2);

    return xDivY1, xDivY2;


int main() 
    srand(time(NULL)); 
    
    int errorCount = 0;
    int num = static_cast<int>(std::pow(10, 6));
    float delta = static_cast<float>(std::pow(10, -3));
    std::vector<float> errorRes(num, 0.0f);


    return 0;