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
#include "exact_match.hpp"

using namespace std;



int main(int argc, const char * argv[])
{
    const string P = "aba";
    const string T = "bbabaxababay";
    
    vector<int> times = time_matching_algo(simplest_linear_match, P, T);
    print_times(times, 4);
  
    return 0;
}

