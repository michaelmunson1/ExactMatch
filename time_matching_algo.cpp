//
//  time_matching_algo.cpp
//  ExactMatch
//
//  Created by Munson on 11/30/15.
//  Copyright © 2015 Munson. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;


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