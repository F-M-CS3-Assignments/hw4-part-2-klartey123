// Author: Kelvin Lartey

#include <iostream>
#include "bdc.h"
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Writing a program to find the biggest conglomerate in a set of numbers. 
// So that means that the biggest number can be divided evenly by atleast one of the smaller numbers
// But then from the first set of numbers divisible by the largest numbers you make sure
// The second largest number will be divisible by those smaller numbers
// You do that till the first number. 

// This appraochh will be dynamic programming. The time complexity for this one will be 
// O(n^2) Due to the nested for loop that goes to construct the chains. 

// My last approach which the more I learn I realized resmbles more of a brute force approach 
//

// Convert to string
string vec_to_string(vector<int> v){
    string s;
    s = "[";
    for (int i =0; i < v.size(); i++){
        s+= to_string(v[i]);
        if (i < v.size()-1){
            s += ", ";
              
        }   
    }
    s += "]";
    return s;
}

// Actual code implementation to find the conglomerate.
vector<int> biggest_divisible_conglomerate(vector<int> input){

// Step 1; I will first sort the values in ascending order
    sort(input.begin(), input.end() );

// Now that we have sorted our table we can build a dp[] and prev_chain[] 
// dp[i] stores the length of the longest chain ending at input[i]
// prev_chain[i] stores the index of the previous number in that chain
vector<int> dp(input.size(), 1);
vector<int> prev_chain(input.size(), -1);
// building the table
for (int i=0; i < dp.size(); i++){
    for (int j = 0; j < i; j++){
        // If input[i] is divisible by input[j], check if adding it to
        // the chain ending at input[j] results in a longer chain
        if (input[i]% input[j]==0){
            if (dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                prev_chain[i] = j;
            }
        }
    }
}
// comment to see if it commit. 
// So now we want to find the longest chain from the growing list and then that will be our answer. Hopefully.
int max = 0;
// then we want to see where the best input is which would be the last on in the chain.
int best_input= -1;
// now all we have to do is to interate 
for (int i= 0; i < dp.size();i ++){
    if (dp[i] > max) {
        max = dp[i];
        best_input = i;
    }
}
//Reconstruct the chain using prev_chain[]
vector<int> results;
int current_best= best_input;
    while (current_best !=-1){
        results.push_back(input[current_best]);
        current_best = prev_chain[current_best];

    }
    reverse(results.begin(), results.end());

    return results;

}



