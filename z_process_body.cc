//
//  z_process_body.cc
//  exact_match
//
//  Created by Michael Munson on 11/30/15.
//

#include <iostream>
#include <vector>
#include <string>
#include "exact_match.h"



vector<int> ZProcessBody(bool is_pattern, const string str, vector<int>& z_vals, int n, int m, int begin, int end)
{
    vector<int> matches;
    
    int l = z_vals[n];
    int r = z_vals[n+1];
    int j = 0;
    
    
    
    for (int k=begin; k < end; ++k)               // iterate over pattern or text
    {
        bool is_match = true;
        if(k > r)
        {
            // compare to prefix of str
            for (int i=k; is_match && i < end; ++i)
            {
                if (str[i] != str[i-k]) {        // mis_match occurs
                    j = i;
                    is_match = false;
                }
            }
            if (is_match)                        // no mis_match found, to end of str
            {
                l=k;
                r=end-1;
                if (is_pattern)
                {
                    z_vals[k] = n - k;
                }
                if (! is_pattern)
                {
                    int zVal = n+m+1-k;
                    if (zVal == n)  matches.push_back(k-n-1);   // match found between P and substring of T
                }
            }
            else
            {
                int zVal = j - k;
                
                if (is_pattern)  z_vals[k] = zVal;
                
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
            
            if (z_vals[k_prime] >= beta_length)
            {
                is_match = true;
                //int r_prime = k_prime + beta_length - 1;
                for (int i= r + 1; is_match && i < end; ++i){
                    if (str[i] != str[i - k]){
                        j = i;
                        is_match = false;
                    }
                }
                
                
                if (is_match)
                {
                    l = k;
                    r = end-1;
                    
                    if (is_pattern)
                    {
                        z_vals[k] = n - k;
                    }
                    if (! is_pattern)
                    {
                        int zVal = n+m+1-k;
                        if (zVal == n)  matches.push_back(k-n-1);
                    }
                    
                }
                else
                {
                    int zVal = j - k;
                    
                    if (is_pattern)  z_vals[k] = zVal;
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
                int zVal = z_vals[k_prime];
                
                if (is_pattern)  z_vals[k] = z_vals[k_prime];         // l and r unchanged
                else if(zVal == n) matches.push_back(k-n-1);
            }
            
        }
    }
    
    z_vals[n] = l;
    z_vals[n+1] = r;
    
    return matches;
}

