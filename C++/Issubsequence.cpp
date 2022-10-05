class Solution {
public:
    bool isSubsequence(string s, string t) {
        //we have to find whether string s can be made from string t
        // in which we don't have to change the relative positions of the characters 
        // we can delete characters one or more characters.
        
        //case 1 : delete all the characters
        if(s.size() == 0) return true;
        
        //case 2: Two pointer approach to look all the characters present in the string s
        int s_point = 0;
        int t_point = 0;
        
        while(t_point < t.size()) {
            if(t[t_point] == s[s_point]) {
                s_point++;
                
                if(s_point == s.size()) return true;
            }
            
            t_point++;
        }
        
        return false;
        
    }
};