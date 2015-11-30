//
//  main.cpp
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
#include "ExactMatch.hpp"

using namespace std;



int main(int argc, const char * argv[])
{
    const string P = "aba";
    const string T = "bbabaxababay";
    
    vector<int> times = timeMatchingAlgo(simplestLinearMatch, P, T);
    printTimes(times, 4);
  
    return 0;
}

