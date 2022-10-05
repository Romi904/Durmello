class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major_ele = 0, count = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(count == 0) {
                major_ele = nums[i];
            }
            if(nums[i] == major_ele) {
                count = count + 1;
            }
            else {
                count = count - 1;
            }
        }
        return major_ele;
    }
};


