//
//  z_algo.cc
//  exact_match
//
//  Created by Munson on 11/30/15.
//  Copyright © 2015 Munson. All rights reserved.
//


#include <iostream>
#include <string>
#include <vector>
#include "exact_match.h"

using namespace std;


vector<int> SimplestLinearMatch(string P, string T)
{
    vector<int> zVals = ZPre(P);
    
    string S = P + "$" + T ;    // check that $ is not contained in P or T; if it is, choose another separator
    
    return FindZMatchesInTextBody(S, zVals, (int) P.length(), (int) T.length());
}


vector<int> ZPre(string P)
{
    int n = (int) P.length();
    vector<int> zVals(n+2);
    
    ZPreprocessPatternBody(P, zVals, n, 0);
    
    //for (int i=0; i<zVals.size(); ++i) cout<< zVals[i] << endl;
    
    return zVals;
}


void ZPreprocessPatternBody(string P, vector<int>& zVals, int n, int m)
{
    ZProcessBody(true, P, zVals, n, m, 1, n);
}


vector<int> FindZMatchesInTextBody(string S, vector<int>& zVals, int n, int m)
{
    return z_process_body(false, S, zVals, n, m, n+1, n+m+1);
}