class Solution {
public:
    bool wordPattern(string pattern, string s) {
        //here we will use two hashmaps and store count of words in it
        // and compare if frequency matches or not 
        // special stl properly stringstream out(in) is used here to break space separated words in it
        unordered_map<char, int> mp;
        unordered_map<string, int> mp1;
        stringstream out(s);
        int i = 0, n = pattern.size();
        for(string word; out >> word; i++) {
            if(i == n || mp[pattern[i]] != mp1[word])
                return false;
            mp[pattern[i]] = mp1[word] = i + 1;
        }
        return i == n;
    }
};