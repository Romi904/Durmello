class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        //This can be solved by comparing the two lists minima and maxima.
        vector<vector<int>> ans;
        int i = 0, j = 0;
        //Here we are comparing every pair first and second element with both lists
        //first we are finding max and then min element to get the common pair in between them
        //Accordingly increasing value of i and j to come over next pair by comparing minima and maxima
        //And inserting pari if and only if low <= high to avoid invalid pairs which are not common in between them.
        while(i < firstList.size() && j < secondList.size()) {
            int low = max(firstList[i][0], secondList[j][0]);
            int high = min(firstList[i][1], secondList[j][1]);
            if(low <= high) ans.push_back({low, high});
            if(firstList[i][1] < secondList[j][1]) i++;
            else j++;
        }
        return ans;
    }
};
