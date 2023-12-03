#include <miracl/miracl.h> 
#include <random>
#include <cmath>
#include <vector>
#include <iostream>


#include "constant.h" 
#include "tool.h"     
#include "SecMul.h"  


class FXfamily 
    int precision;
public:
    FXfamily(int p) : precision(p) 

 
;


class Random 
public:
    int choice(std::initializer_list<int> list) 
        std::vector<int> vec(list);
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, vec.size() - 1);
        return vec[dis(gen)];
    
;


std::tuple<big, big, int, int> SecAddRes(big x1, big x2) 
    std::array<int, 2> sign = 1, -1;
    Random random;

    // offline
    big c_ = generateExpCoverSecret(); 
    int c_sgn = random.choice(sign);
    
    big c1_ = generateExpShare(); 
    big c2_ = limitExpRangeByMod(c_ - c1_); 

    int c1_sgn = random.choice(sign);
    int c2_sgn = c1_sgn * c_sgn;

    big c = exp(c_sgn * (1 << c_.toInt())); 
    
  
    FXfamily famcfrac(const_cfracbit);

    std::tie(xc1, xc2) = SecMul(x1, x2, c1, c2); 
    big xc = limitFixedRangeByMod(xc1 + xc2); 

    double xc_ = log2(abs(xc.toDouble()));


    return std::make_tuple(x1_, x2_, x1_sgn, x2_sgn);
