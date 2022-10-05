class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& arr) {
        int count = 0, maxCount = 0;
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] == 1) {
                count++;
            }
            else if(arr[i] == 0) {
                if(count > maxCount) {
                    maxCount = count;
                }
                count = 0;
            }
        }
        return count > maxCount ? count : maxCount;
    }
};