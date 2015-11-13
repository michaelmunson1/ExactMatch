//
//  ExactMatch.h
//  
//
//  Created by Michael Munson on 11/12/15.
//
//

#ifndef ExactMatch_h
#define ExactMatch_h


#include <string>

using namespace std;

vector<int> naiveMatch(string, string);
vector<int> timeMatchingAlgo(vector<int> (*algo)(string,string), string, string);
void printTimes(vector<int> times, int n);

#endif /* ExactMatch_h */
