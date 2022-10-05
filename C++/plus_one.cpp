class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int>ans;
        int carry = 0;
        int temp = 0;
        for(int i = digits.size()-1; i >= 0; i--) {
            if(i == digits.size()-1) {
                temp = digits[i] + carry + 1;
            }else {
                temp = digits[i] + carry;
            }
            
            if(temp > 9) {
                carry = 1;
                temp = 0;
            } else {
                carry = 0;
            }
            ans.push_back(temp);
        }
        if(carry)
            ans.push_back(1);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};