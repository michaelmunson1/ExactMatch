//
//  time_matching_algo.cc
//  exact_match
//
//  Created by Michael Munson on 11/30/15.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;


// Returns the running time in microseconds of the input matching algorithm 'algo',
// for an input of the pattern and multiples of the text string; namely, the input text
// string repeated 1,10,100, and 1000 times.  For each input size, 'algo' is run
// num_times_to_run (5 suggested), and the fastest time is recorded.
//
// Currently prints the indices of occurrences of pattern in T, for the first run with
// num_text_repeats = 1.

vector<int> TimeMatchingAlgo(vector<int> (*algo)(const string, const string), const string pattern, const string text){
    
    vector<int> times {0,0,0,0};
    
    for(int i=0; i < 4; ++i){
        
        int num_text_repeats = (int) pow(10.0, (double) i);  // 1, 10, 100, 1000 for i in {0,...,3}
        
        string T_repeated = "";
        
        for (int k=0; k< num_text_repeats; ++k)
        {
            T_repeated += T;                     // create longer text string for timing
        }
        
        double min_time = 9999999.9;             // find fastest of several runs, to give best
                                                 //indication of algorithm performance
        
        int num_times_to_run = 5;
        
        for (int j=0; j < num_times_to_run; ++j){      //run algorithm multiple times
            //cout << "j is " << j << endl;
            
            clock_t start_time = clock();             // time is measured in clock ticks, later
                                                      //converted to microseconds
            
            vector<int> match_indices = (*algo)(pattern,T_repeated);   // find all occurrences of pattern in T_repeated
            
            // Print match_indices
            
            auto time_in_seconds = (double) (clock() - start_time ) /  CLOCKS_PER_SEC;
            auto this_time = (int) 1000000 * time_in_seconds;                  //in microseconds
            if (this_time < min_time)  min_time = this_time;
            
            if (i == 0 && j==0) {                         // for first run w/ num_text_repeats = 1,
                                                          // print the occurrences of pattern in T
                
                cout << "# of match_indices is " << match_indices.size() << endl;
                for (int i=0; i < match_indices.size(); ++i)  cout << match_indices[i] << endl;
                cout << "**********" << endl;
            }
            
        }
        times[i] = min_time;
    }
    return times;
}


void PrintTimes(vector<int> times, int num_times){
    cout << "Times:" << endl;
    for(int i = 0; i < num_times; ++i){
        cout << times[i] << endl;
    }
}