//
//  naive_match.cc
//  exact_match
//
//  Created by Munson on 11/30/15.
//  Copyright © 2015 Munson. All rights reserved.
//

#include <iostream>
#include <vector>
#include "exact_match.h"

vector<int> NaiveMatch(string P_mult, string T_mult){
    vector<int> matches;
    
    for (int i=0; i <= T_mult.length() - P_mult.length(); ++i)
    {
        for(int j=0; j < P_mult.length(); ++j)
        {
            if (P_mult[j] != T_mult[i+j]) break;
            else if (j == P_mult.length() - 1) matches.push_back(i);
        }
    }
    return matches;
}