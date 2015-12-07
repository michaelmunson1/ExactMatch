//
//  z_algo.cpp
//  exact_match
//
//  Created by Munson on 11/30/15.
//  Copyright © 2015 Munson. All rights reserved.
//


#include <iostream>
#include <string>
#include <vector>
#include "exact_match.hpp"

using namespace std;


vector<int> simplest_linear_match(string P, string T)
{
    vector<int> zVals = z_pre(P);
    
    string S = P + "$" + T ;    // check that $ is not contained in P or T; if it is, choose another separator
    
    return find_z_matches_in_text_body(S, zVals, (int) P.length(), (int) T.length());
}


vector<int> z_pre(string P)
{
    int n = (int) P.length();
    vector<int> zVals(n+2);
    
    z_preprocess_pattern_body(P, zVals, n, 0);
    
    //for (int i=0; i<zVals.size(); ++i) cout<< zVals[i] << endl;
    
    return zVals;
}


void z_preprocess_pattern_body(string P, vector<int>& zVals, int n, int m)
{
    z_process_body(true, P, zVals, n, m, 1, n);
}


vector<int> find_z_matches_in_text_body(string S, vector<int>& zVals, int n, int m)
{
    return z_process_body(false, S, zVals, n, m, n+1, n+m+1);
}