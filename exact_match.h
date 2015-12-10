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
// const string pattern = "aba";
// const string text = "bbabaxababay";
// vector<int> match_indices = NaiveMatch(pattern, text);


vector<int> NaiveMatch(const string, const string);


// Accepts a pointer to an exact string matching algorithm, a pattern string,
// and a text string. Returns the running time in microseconds of the matching
// algorithm for an input of the pattern and multiples of the text string:
// namely, the text string repeated 1,10,100, and 1000 times.
//
// Example:
//
// const string pattern = "aba";
// const string text = "bbabaxababay";
// vector<int> times = TimeMatchingAlgo(SimplestLinearMatch, pattern, text);
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
// const string pattern = "aba";
// const string text = "bbabaxababay";
//
// vector<int> match_indices = SimplestLinearMatch(pattern, text);


vector<int> SimplestLinearMatch(const string, const string);


// Accepts a pattern string and text string and returns a separator
// character not contained in either
// Example:
//
// const string pattern = "aba";
// const string text = "bbabaxababay";
// char separator = choose_separator(pattern,text);
// cout << separator << endl;   //  $


char choose_separator(const string, const string);


// Implements 'fundamental preprocessing' of the pattern string 'P', according to
// the 'fundamental preprocessing' algorithm (or 'Z algorithm') described in
// section 1.4 of 'Algorithms on Strings, Trees, and Sequences:
// Computer Science and Computational Biology' by Gusfield.  The bulk of the
// processing is done in the subroutine 'ZProcessBody'.
// (for more, see function definition in 'z_algo.cc')
//
// Example:
//
// const string pattern = "abxyabxz";
// vector<int> z_vals = ZPreprocess(const string pattern);  // z_vals = [0,0,0,0,3,0,0,0]


vector<int> ZPreprocess(const string pattern);


// Subroutine called by ZPreprocess and FindZMatchesInTextBody; the heart of both.


vector<int> ZProcessBody(bool, const string, vector<int>& , int, int, int, int);


// Implements Z algorithm on the text, seeking occurrences of the pattern
// and shifting according to the results of preprocessing on the pattern


vector<int> FindZMatchesInTextBody(const string, vector<int>&, int, int);

#endif /* exact_match_hpp */