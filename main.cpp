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

using namespace std;

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


int main(int argc, const char * argv[])
{
    
    
    const string P = "aba";
    const string T = "bbabaxababay";
    
    string P_mult = "";      // for time tests of input size
    string T_mult = "";
    
    clock_t startTime;
    
    vector<double> times(4);
    
    double minTime;
    double thisTime;
    
    vector<int> matches;
    
    
    for(int i=0; i < 4; ++i){
        
        //cout << "i is " << i << endl;
        int inSize = (int) pow(10.0, (double) i);
        
        for (int k=0; k< inSize; ++k){
            P_mult += P;
            T_mult += T;
        }
        
        minTime = 9999999.9;
        for (int j=0; j < 5; ++j){
            //cout << "j is " << j << endl;
            
            startTime = clock();
            //cout << startTime << endl;
            matches = naiveMatch(P_mult,T_mult);
            //cout << clock() << endl;
            thisTime = double( clock() - startTime );
            if (thisTime < minTime)  minTime = thisTime;
        }
        times[i] = minTime;
        
    }
    
    for(int i = 0; i < 4; ++i){
        cout << times[i] << endl;
    }
    
    return 0;
}
