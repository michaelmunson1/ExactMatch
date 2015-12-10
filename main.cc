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
    const string pattern = "aba";
    const string text = "bbabaxababay";
    
    vector<int> times = TimeMatchingAlgo(SimplestLinearMatch, pattern, text);
    PrintTimes(times, 4);
  
    return 0;
}

