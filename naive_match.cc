//
//  naive_match.cc
//
//  Created by Michael Munson on 11/30/15.
//

#include <iostream>
#include <vector>
#include "exact_match.h"

vector<int> NaiveMatch(const string pattern, const string text){
    vector<int> matches;
    
    for (int i=0; i <= text.length() - pattern.length(); ++i)
    {
        for(int j=0; j < pattern.length(); ++j)
        {
            if (pattern[j] != text[i+j]) break;
            else if (j == pattern.length() - 1) matches.push_back(i);
        }
    }
    return matches;
}