//
//  z_algo.cc
//  exact_match
//
//  Created by Michael Munson on 11/30/15.
//


#include <iostream>
#include <string>
#include <vector>
#include "exact_match.h"

using namespace std;


vector<int> SimplestLinearMatch(const string P, const string T)
{
    vector<int> zVals = ZPre(P);
    
    string S = P + "$" + T ;    // check that $ is not contained in P or T; if it is, choose another separator
    
    return FindZMatchesInTextBody(S, zVals, (int) P.length(), (int) T.length());
}


vector<int> ZPre(const string P)
{
    int n = (int) P.length();
    vector<int> zVals(n+2);
    
    ZPreprocessPatternBody(P, zVals, n, 0);
    
    //for (int i=0; i<zVals.size(); ++i) cout<< zVals[i] << endl;
    
    return zVals;
}


void ZPreprocessPatternBody(const string P, vector<int>& zVals, int n, int m)
{
    ZProcessBody(true, P, zVals, n, m, 1, n);
}


vector<int> FindZMatchesInTextBody(const string S, vector<int>& zVals, int n, int m)
{
    return ZProcessBody(false, S, zVals, n, m, n+1, n+m+1);
}