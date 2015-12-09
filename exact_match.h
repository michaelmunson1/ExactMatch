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




vector<int> NaiveMatch(const string, const string);

// Accepts a pointer to an exact string matching algorithm, a pattern string,
// and a text string. Returns the running time in microseconds of the matching
// algorithm for an input of the pattern and multiples of the text string:
// namely, the text string repeated 1,10,100, and 1000 times.
//
// Example:
//
// const string P = "aba";
// const string T = "bbabaxababay";
// vector<int> times = TimeMatchingAlgo(SimplestLinearMatch, P, T);
// PrintTimes(times, 4);


vector<int> TimeMatchingAlgo(vector<int> (*algo)(string,string), const string, const string);

// Accepts a pattern string and text string, and returns the indices of all
// occurrences of the pattern in the text in linear worst-case time.
//
// Example:
//
// const string P = "aba";
// const string T = "bbabaxababay";
//
// vector<int> match_indices = TimeMatchingAlgo(SimplestLinearMatch, P, T);


vector<int> SimplestLinearMatch(const string, const string);



vector<int> ZPreprocess(const string P);

void PrintTimes(vector<int>, int);

void ZPreprocessPatternBody(const string, vector<int>&, int);

vector<int> ZProcessBody(bool, const string, vector<int>& , int, int, int, int);

vector<int> FindZMatchesInTextBody(const string, vector<int>&, int, int);

#endif /* exact_match_hpp */