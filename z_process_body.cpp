//
//  z_process_body.cpp
//  exact_match
//
//  Created by Munson on 11/30/15.
//  Copyright © 2015 Munson. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include "exact_match.hpp"


vector<int> z_process_body(bool isPattern, string str, vector<int>& zVals, int n, int m, int begin, int end)
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

