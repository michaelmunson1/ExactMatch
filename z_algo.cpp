//
//  z_algo.cpp
//  ExactMatch
//
//  Created by Munson on 11/30/15.
//  Copyright © 2015 Munson. All rights reserved.
//


#include <iostream>
#include <string>
#include <vector>
#include "ExactMatch.hpp"

using namespace std;




vector<int> simplestLinearMatch(string P, string T)
{
    vector<int> zVals = zPre(P);
    
    string S = P + "$" + T ;    // check that $ is not contained in P or T; if it is, choose another separator
    
    return findZMatchesInTextBody(S, zVals, (int) P.length(), (int) T.length());
}



vector<int> zPre(string P)
{
    int n = (int) P.length();
    vector<int> zVals(n+2);
    
    zPreProcessPatternBody(P, zVals, n, 0);
    
    //for (int i=0; i<zVals.size(); ++i) cout<< zVals[i] << endl;
    
    return zVals;
}


void zPreProcessPatternBody(string P, vector<int>& zVals, int n, int m)
{
    zProcessBody(true, P, zVals, n, m, 1, n);
}


vector<int> findZMatchesInTextBody(string S, vector<int>& zVals, int n, int m)
{
    return zProcessBody(false, S, zVals, n, m, n+1, n+m+1);
}