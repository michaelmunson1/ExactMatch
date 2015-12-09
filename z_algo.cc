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
// the pattern relative to the text whenever aligned characters in the pattern (P)
// and text (T) mismatch.

vector<int> SimplestLinearMatch(const string P, const string T)      // P: pattern; T: text
{
    vector<int> z_vals = ZPreprocess(P);
    
    string S = P + "$" + T ;    // TODO: check that $ is not contained in P or T; if it is, choose another separator
    
    return FindZMatchesInTextBody(S, z_vals, (int) P.length(), (int) T.length());
}


// Implements 'fundamental preprocessing' of the pattern string 'P', according to
// the 'fundamental preprocessing' algorithm (or 'Z algorithm') described in
// section 1.4 of 'Algorithms on Strings, Trees, and Sequences:
// Computer Science and Computational Biology' by Gusfield.

vector<int> ZPreprocess(const string P)
{
    int n = (int) P.length();
    vector<int> z_vals(n+2);
    
    ZPreprocessPatternBody(P, z_vals, n);      // z_vals passed by reference,
                                               // populated during function call
    
    //for (int i=0; i<z_vals.size(); ++i) cout<< z_vals[i] << endl;
    
    return z_vals;
}


//  Applies the 'fundamental preprocessing' or 'Z' algorithm  (see Gusfield,
// 'Algorithms on Strings...'), section 1.4, to the pattern string 'P', of length
// 'n'.  The results of this preprocesing are stored in the vector 'z_vals'.

void ZPreprocessPatternBody(const string P, vector<int>& z_vals, int n)
{
    ZProcessBody(true, P, z_vals, n, 0, 1, n);
}


// Applies the 'fundamental preprocessing' or 'Z' algorithm  (see Gusfield,
// 'Algorithms on Strings...'), section 1.4, to the string 'S'.  Typically,
//  S will be of the form 'P' + '$' + 'T', where 'P' is the pattern string of
// length 'n' and 'T' is the text string of length 'm'.
//
// This function assumes that 'P' has already been preprocessed, e.g., via
// ZPreprocessPatternBody(P, z_vals, n), add the results of that preprocessing
// are stored in 'z_vals'.

vector<int> FindZMatchesInTextBody(const string S, vector<int>& z_vals, int n, int m)
{
    return ZProcessBody(false, S, z_vals, n, m, n+1, n+m+1);
}