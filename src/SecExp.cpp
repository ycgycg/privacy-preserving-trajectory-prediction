#include <iostream>
#include <miracl/miracl.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "FixedPoint.h" 
#include "SecMulRes.h" 
#include "Tool.h"
using namespace std;

pair<Big, Big> SecExp(const Big& x1, const Big& x2) 
    Big res1, res2;

    Big x1_limited = limitExpRangeByMod(x1); 
    Big x2_limited = limitExpRangeByMod(x2);

    tie(res1, res2) = SecMulRes(x1_limited, x2_limited, 1, 1);

    return make_pair(res1, res2);


int main() 
    const int NUM_TESTS = 1000000;
    const Big ERROR_THRESHOLD = Big(1 << (BASE - 3)); // 对应 delta = 10^-3
    int errorCount = 0;

    miracl* mip = mirsys(100, 0);
    mip->IOBASE = 10;

    vector<Big> errorRes(NUM_TESTS);
    Big totalError = 0;
    Big maxError = 0;

    for (int i = 0; i < NUM_TESTS; ++i) 
        Big xTrue, x1, x2;
        tie(xTrue, x1, x2) = normSecretForTest();

        Big res1, res2;
        tie(res1, res2) = SecExp(x1, x2);
        Big res = limitExpRangeByMod(res1 + res2); 

        errorRes[i] = abs(abs(xTrue) - res);
        if (errorRes[i] > ERROR_THRESHOLD) 
            errorCount++;

        totalError += errorRes[i];
        if (errorRes[i] > maxError) 
            maxError = errorRes[i];
        
   
    cout << "Error count: " << errorCount << endl;
    cout << "Mean error: "  << (totalError / NUM_TESTS).toString() << endl;
    cout << "Max error: " << maxError.toString() << endl;

    mirexit();

    return 0;