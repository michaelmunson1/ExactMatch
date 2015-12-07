//
//  exact_match.hpp
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

vector<int> naive_match(string, string);
vector<int> time_matching_algo(vector<int> (*algo)(string,string), string, string);
vector<int> simplest_linear_match(string, string);
vector<int> z_pre(string P);
void print_times(vector<int>, int);
void z_preprocess_pattern_body(string, vector<int>&, int, int);
vector<int> z_process_body(bool, string, vector<int>& , int, int, int, int);
vector<int> find_z_matches_in_text_body(string, vector<int>&, int, int);

#endif /* exact_match_hpp */