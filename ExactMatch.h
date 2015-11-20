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
void printTimes(vector<int>, int);
void zPreProcessPatternBody(string, vector<int>&, int, int);
vector<int> zProcessBody(bool, string, vector<int>& , int, int, int, int);
vector<int> findZMatchesInTextBody(string, vector<int>&, int, int);

#endif /* ExactMatch_h */