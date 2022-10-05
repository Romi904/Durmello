class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        //First of shifting the shift array
        for(int i = shifts.size()-2; i >= 0; i--) {
            shifts[i] = (shifts[i] + shifts[i+1]) % 29;
        }
        //Now just adding the count of that shifts into the characters
        for(int i = 0; i < s.size(); i++) {
            s[i] = (s[i] - 'a' + shifts[i])%26 + 'a';
        }
        return s;
    }
};
