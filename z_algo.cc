//
//  z_algo.cc
//  exact_match
//
//  Created by Michael Munson on 11/30/15.
//


#include <iostream>
#include <string>
#include <vector>
#include "exact_match.h"

using namespace std;


// Implements the linear time matching algorithm algorithm described in
// sections 1.3-1.5 of 'Algorithms on Strings, Trees, and Sequences:
// Computer Science and Computational Biology' by Gusfield.  After preprocessing
// the pattern text, the pattern string is concatenated with the text string,
// and the results of the preprocessing are used to intelligently 'shift'
// the pattern relative to the text whenever aligned characters in the pattern
// and text mismatch.
//
// Returns {-1} in error condition, if no suitable character is found to separate
// the pattern and text strings.

vector<int> SimplestLinearMatch(const string pattern, const string text)
{
    vector<int> z_vals = ZPreprocess(pattern);
    
    char separator = choose_separator(pattern,text);  // separator should not be in either pattern
                                             // or text
    
    if(separator == -1){
        cout << "Exiting: No separator found" << endl;
        return vector<int> {-1};
    }
    
    string S = pattern + separator + text ;    // TODO: check that $ is not contained in pattern or T; if it is, choose another separator
    
    return FindZMatchesInTextBody(S, z_vals, (int) pattern.length(), (int) text.length());
}


// Return a separator character which occurs in neither the pattern nor
// the text string
//
// Returns -1 if all candidate separators occurred

char choose_separator(const string pattern, const string text){
    vector<char> separator_list = {'$', '%', '&', '\'', '(', ')', '*',
        '+', ',', '-', '.', '/'};     // ASCII values {36,37,...,47}
    
    vector<bool> found_list = {false, false, false, false, false, false, false, false, false, false, false, false};   // whether chars with ASCII values 36,...,47
                                       // have been found
    
    int pattern_length = (int) pattern.length();
    int text_length = (int) text.length();
    
    // iterate through pattern and text, marking separators as found whenever
    // they occur
    for(int i = 0; i < pattern_length; ++i){
        int char_val = (int) pattern[i];
        if(char_val < 48 && char_val > 35 && ! found_list[char_val-36]){
            found_list[char_val-36] = true;
        }
    }
    for(int i = 0; i < text_length; ++i){
        int char_val = (int) text[i];
        if(char_val < 48 && char_val > 35 && ! found_list[char_val-36]){
            found_list[char_val-36] = true;
        }
    }
    
    //choose first separator (lowest ascii value) which occurs in
    //neither pattern nor text
    for(int i = 0; i < found_list.size(); ++i){
        if(! found_list[i]) return separator_list[i];
    }
    
    return -1;       // no valid separator found
}


// Implements 'fundamental preprocessing' of the pattern string 'P', according to
// the 'fundamental preprocessing' algorithm (or 'Z algorithm') described in
// section 1.4 of 'Algorithms on Strings, Trees, and Sequences:
// Computer Science and Computational Biology' by Gusfield.
//
// The results of this preprocessing are stored in the vector 'z_vals", with the \
// following interpretation

vector<int> ZPreprocess(const string pattern){
    int n = (int) pattern.length();
    
    vector<int> tmp = {0};  // TODO: split ZProcessBody into a separate pattern and
                            // text function
    
    vector<int> z_vals = ZProcessBody(true, pattern, tmp, n, 0, 1, n);
    
    //for (int i=0; i<z_vals.size(); ++i) cout<< z_vals[i] << endl;
    
    return z_vals;
}


// Applies the 'fundamental preprocessing' or 'Z' algorithm  (see Gusfield,
// 'Algorithms on Strings...'), section 1.4, to the string 'S'.  Typically,
//  S will be of the form 'P' + '$' + 'T', where 'P' is the pattern string of
// length 'n' and 'T' is the text string of length 'm'.
//
// This function assumes that 'P' has already been preprocessed, e.g., via
// ZPreprocessPatternBody(pattern, z_vals, n), add the results of that preprocessing
// are stored in 'z_vals'.

vector<int> FindZMatchesInTextBody(const string S, vector<int>& z_vals, int n, int m)
{
    return ZProcessBody(false, S, z_vals, n, m, n+1, n+m+1);
}