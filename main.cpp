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
    
    vector<int> times = timeMatchingAlgo(simplestLinearMatch, P, T);
    printTimes(times, 4);
  
    return 0;
}


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


vector<int> zProcessBody(bool isPattern, string str, vector<int>& zVals, int n, int m, int begin, int end)
{
    vector<int> matches;
    
    int l = zVals[n];
    int r = zVals[n+1];
    int j = 0;
    
    
    // iterate over pattern or text
    for (int k=begin; k < end; ++k)
    {
        bool isMatch = true;
        if(k > r)
        {
            // compare to prefix of str
            for (int i=k; isMatch && i < end; ++i)
            {
                if (str[i] != str[i-k]) {     // mismatch occurs
                    j = i;
                    isMatch = false;
                }
            }
            if (isMatch)             // no mismatch found, to end of str
            {
                l=k;
                r=end-1;
                if (isPattern)
                {
                    zVals[k] = n - k;
                }
                if (! isPattern)
                {
                    int zVal = n+m+1-k;
                    if (zVal == n)  matches.push_back(k-n-1);   // match found between P and substring of T
                }
            }
            else
            {
                int zVal = j - k;
                
                if (isPattern)  zVals[k] = zVal;
                
                if (zVal > 0)
                {
                    l = k;
                    r = k + zVal - 1;
                    if (zVal == n)  matches.push_back(k-n-1);
                }
            }
        }
        else                          // k is inside a Z-box
        {
            int k_prime = k - l;
            int beta_length = r - k + 1;
            int j = 0;
            
            if (zVals[k_prime] >= beta_length)
            {
                isMatch = true;
                //int r_prime = k_prime + beta_length - 1;
                for (int i= r + 1; isMatch && i < end; ++i){
                    if (str[i] != str[i - k]){
                        j = i;
                        isMatch = false;
                    }
                }
                
                
                if (isMatch)
                {
                    l = k;
                    r = end-1;
                    
                    if (isPattern)
                    {
                        zVals[k] = n - k;
                    }
                    if (! isPattern)
                    {
                        int zVal = n+m+1-k;
                        if (zVal == n)  matches.push_back(k-n-1);
                    }
                    
                }
                else
                {
                    int zVal = j - k;
                    
                    if (isPattern)  zVals[k] = zVal;
                    if (zVal == n) matches.push_back(k-n-1);
                    
                    if(j > r+1)
                    {
                        l = k;
                        r = j - 1;
                    }
                }
            }
            else
            {
                int zVal = zVals[k_prime];
                
                if (isPattern)  zVals[k] = zVals[k_prime];   // l and r unchanged
                else if(zVal == n) matches.push_back(k-n-1);
            }
            
        }
    }
    
    zVals[n] = l;
    zVals[n+1] = r;
    
    return matches;
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
        
        string P_mult = "";     // for time tests of input size
        string T_mult = "";
        
        for (int k=0; k< inSize; ++k)
        {
            //P_mult += P;
            T_mult += T;
        }
        
        double minTime = 9999999.9;
        for (int j=0; j < 5; ++j){
            //cout << "j is " << j << endl;
            
            clock_t startTime = clock();
            
            vector<int> matches = (*algo)(P,T_mult);
         
            // Print matches
            
            if (i == 0 && j==0) {
                
                cout << "# of matches is " << matches.size() << endl;
                for (int i=0; i < matches.size(); ++i)  cout << matches[i] << endl;
                cout << "**********" << endl;
            }
            
            auto s = (double) (clock() - startTime ) /  CLOCKS_PER_SEC; // time in seconds
            auto thisTime = (int) 1000000 * s;   //time in us
            if (thisTime < minTime)  minTime = thisTime;
        }
        times[i] = minTime;
    }
    return times;
}


void printTimes(vector<int> times, int n){
    cout << "Times:" << endl;
    for(int i = 0; i < n; ++i){
        cout << times[i] << endl;
    }
}
