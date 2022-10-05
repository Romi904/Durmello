class Solution {
public:
    int count = 1;
    vector<string> output;
   
    vector<string> letterCasePermutation(string s) {
        //First of all converting all the characters of the string to the lower case
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        //now storing it to the string 
        output.push_back(s);
        //Now we have covered cases where all characters are small.
        //Now we will cover all cases where combination of upper and lower alphabets will be there
        for(int i = 0; i < s.size(); i++) {
            //check if the character is alphabet or not ?
            if(isalpha(s[i])) {
                store(toupper(s[i]), i);
            }
        }
        return output;
    }
    
    void store(char temp, int pos) {
        int i = 0;
        while(i < count) {
            string res = output[i];
            res[pos] = temp;
            output.push_back(res);
            i++;
        }
        count+= count;
    }
};