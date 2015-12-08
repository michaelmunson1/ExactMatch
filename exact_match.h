//
//  exact_match.h
//  
//
//  Created by Michael Munson on 11/12/15.
//
//

#ifndef exact_match_hpp
#define exact_match_hpp


#include <string>
#include <vector>

using namespace std;

vector<int> NaiveMatch(string, string);
vector<int> TimeMatchingAlgo(vector<int> (*algo)(string,string), string, string);
vector<int> SimplestLinearMatch(string, string);
vector<int> ZPre(string P);
void PrintTimes(vector<int>, int);
void ZPreprocessPatternBody(string, vector<int>&, int, int);
vector<int> ZProcessBody(bool, string, vector<int>& , int, int, int, int);
vector<int> FindZMatchesInTextBody(string, vector<int>&, int, int);

#endif /* exact_match_hpp */