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

using namespace std;

int* naiveMatch(const char* P, const char* T){
    int* matches = new int[3];
    int k = 0;
    
    for (int i=0; i <= strlen(T) - strlen(P); ++i)
    {
        for(int j=0; j < strlen(P); ++j)
        {
            if (P[j] != T[i+j]) break;
            else if (j == strlen(P) - 1)
            {
                matches[k] = i;
                ++k;
            }
        }
    }
    return matches;
}

int main(int argc, const char * argv[])
{
    // insert code here...
    cout << "Hello, World!\n";
    
    const char* P = "aba";
    const char* T = "bbabaxababay";
    
    //int diff = strlen(T) - strlen(P) + 1;
    
    int *matches = naiveMatch(P,T);
    
    for (int i=0; i < 3; ++i){
        cout << matches[i] << endl;
    }
    
    delete[] matches;
    return 0;
}


