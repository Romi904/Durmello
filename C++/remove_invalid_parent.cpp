class Solution {
public:
    
    vector<string> res;
    unordered_map<string,int> mp;
    // This will give number of invalid parenthesis with the help of stack
    int getMinInvalid(string str) {
        stack<char> st;
        int i = 0;
        while(i < str.size()) {
            if(str[i] == '(') {
                st.push('(');
            } else if(str[i] == ')') {
                if(st.size() > 0 && st.top() == '(') {
                    st.pop();
                }else {
                    st.push(')');
                }
            }
            i++;
        }
        return st.size();
    }
    
    void solve(string s, int minInv) {
        //this is for avoiding duplicated strings
        if(mp[s] != 0) {
            return;
        } else {
            mp[s]++;
        }
        
        if(minInv < 0) return;
        if(minInv == 0) {
            if(!getMinInvalid(s)) {
                res.push_back(s);
            }
            return;
        }
         
        for(int i = 0; i < s.size(); i++) {
            string left = s.substr(0,i);
            string right = s.substr(i+1);
            solve(left+right, minInv-1);
        }
    }
    
    vector<string> removeInvalidParentheses(string s) {
        solve(s, getMinInvalid(s));
        return res;
    }
};