//
//  naive_match.cc
//
//  Created by Michael Munson on 11/30/15.
//

#include <iostream>
#include <vector>
#include "exact_match.h"

vector<int> NaiveMatch(const string P, const string T){
    vector<int> matches;
    
    for (int i=0; i <= T.length() - P.length(); ++i)
    {
        for(int j=0; j < P.length(); ++j)
        {
            if (P[j] != T[i+j]) break;
            else if (j == P.length() - 1) matches.push_back(i);
        }
    }
    return matches;
}