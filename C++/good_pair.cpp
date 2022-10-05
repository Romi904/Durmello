class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        //here we will used hashmap basically
        //and analyze the pattern of the count.
        unordered_map<int, int> mp;
        int res = 0;
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        //here we stored the count of each element;
        //now used pairs math formula
        for(auto ele: mp) {
            res+= ((ele.second) * (ele.second - 1))/2;
        }
        return res;
    }
};