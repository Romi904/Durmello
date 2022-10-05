#include <iostream>
#include <bits/stdc++.h>
using namespace std;

 bool isMonotonic(vector<int>& nums) {
        int count_inc = 0, count_dec = 0;
        for(int i = 0; i < nums.size()-1; i++) {
            if(nums[i] <= nums[i+1]) count_inc++;
            if(nums[i] >= nums[i+1]) {
                count_dec++;
            }
            
        }
        //now check.
        if(count_inc == nums.size()-1 || count_dec == nums.size()-1) return true;
        else return false;
    }

int main() {

    // Insert Your Code Here. Here are the steps to get started: 
    // Step-I: Define the input format using the examples from the problem description. 
    // Step-II: Parse input from standard in. 
    // Step-III: Write your algorithm to generate the required output. 
    // Note: In case of any issues use #feedback channel on Discord. 
    int n;
    bool ans;
    cin >> n;
    vector<int> arr;
    for(int i = 0; i < n; i++) {
        int val;
        cin >> val;
        arr.push_back(val);
    }
    ans = isMonotonic(arr);
    cout << ans << endl;
    return 0;
}
