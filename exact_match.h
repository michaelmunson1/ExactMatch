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


// Accepts a pattern string and text string, and returns the indices of all
// occurrences of the pattern in the text.  If the pattern has length 'n' and
// the text has length 'm', the worst-case time complexity of the algorithm
// is O('nm').

// Example:
//
// const string P = "aba";
// const string T = "bbabaxababay";
// vector<int> match_indices = NaiveMatch(P, T);

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


// Accepts an input vector of times, and a vector length, and prints it
//
// Example:
//
// vector<int> times = TimeMatchingAlgo(SimplestLinearMatch, pattern_string, text_string);
// PrintTimes(times, 4);

void PrintTimes(vector<int>, int);


// Accepts a pattern string and text string, and returns the indices of all
// occurrences of the pattern in the text in linear worst-case time.
//
// Example:
//
// const string P = "aba";
// const string T = "bbabaxababay";
//
// vector<int> match_indices = SimplestLinearMatch(P, T);


vector<int> SimplestLinearMatch(const string, const string);



vector<int> ZPreprocess(const string P);

void ZPreprocessPatternBody(const string, vector<int>&, int);

vector<int> ZProcessBody(bool, const string, vector<int>& , int, int, int, int);

vector<int> FindZMatchesInTextBody(const string, vector<int>&, int, int);

#endif /* exact_match_hpp */