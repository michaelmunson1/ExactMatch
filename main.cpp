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
#include "ExactMatch.h"

using namespace std;



int main(int argc, const char * argv[])
{
    const string P = "aba";
    const string T = "bbabaxababay";
    
    vector<int> times = timeMatchingAlgo(naiveMatch, P, T);
    printTimes(times, 4);
  
    return 0;
}


vector<int> findZMatches(string S, int n, int m, vector<int> zVals)
{
    vector<int> matches;
    
    
    
    return matches;
}

vector<int> zPre(string P)
{
    int n = P.length;
    vector<int> zVals(n);
    
    return zVals;
}


vector<int> simplestLinearMatch(string P, string T)
{
    vector<int> zVals = zPre(P);
    
    string S = P + "$" + T ;    // check that $ is not contained in P or T; if it is, choose another separator
    
    return findMatches(S, P.length, T.length, zVals);
}



vector<int> naiveMatch(string P_mult, string T_mult){
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



vector<int> timeMatchingAlgo(vector<int> (*algo)(string, string), string P, string T){
    
    vector<int> times {0,0,0,0};
    
    for(int i=0; i < 4; ++i){
        
        //cout << "i is " << i << endl;
        int inSize = (int) pow(10.0, (double) i);
        
        string P_mult = "";      // for time tests of input size
        string T_mult = "";
        
        for (int k=0; k< inSize; ++k){
            P_mult += P;
            T_mult += T;
        }
        
        double minTime = 9999999.9;
        for (int j=0; j < 5; ++j){
            //cout << "j is " << j << endl;
            
            clock_t startTime = clock();
            
            vector<int> matches = (*algo)(P_mult,T_mult);
           
            auto s = (double) (clock() - startTime ) /  CLOCKS_PER_SEC; // time in seconds
            auto thisTime = (int) 1000000 * s;   //time in us
            if (thisTime < minTime)  minTime = thisTime;
        }
        times[i] = minTime;
    }
    return times;
}


void printTimes(vector<int> times, int n){
    for(int i = 0; i < n; ++i){
        cout << times[i] << endl;
    }
}
