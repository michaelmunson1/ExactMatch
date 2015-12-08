//
//  main.cc
//  StringMatching
//
//  Created by Munson on 11/4/15.
//  Copyright © 2015 Munson. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include "exact_match.h"

using namespace std;



int main(int argc, const char * argv[])
{
    const string P = "aba";
    const string T = "bbabaxababay";
    
    vector<int> times = TimeMatchingAlgo(SimplestLinearMatch, P, T);
    PrintTimes(times, 4);
  
    return 0;
}

