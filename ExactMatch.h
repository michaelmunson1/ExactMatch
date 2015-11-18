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
vector<int> simplestLinearMatch(string, string);
vector<int> zPre(string P);
vector<int> findZMatches(string, int, int, vector<int>);
void printTimes(vector<int>, int);

#endif /* ExactMatch_h */
