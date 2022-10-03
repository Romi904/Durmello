// Leetcode 804: Unique Morse Code Words

class Solution {
    public int uniqueMorseRepresentations(String[] words) {
        String[] codes = {".-","-...","-.-.","-..",".","..-.","--.","....","..",
                          ".---","-.-",".-..","--","-.","---",".--.","--.-",".-.",
                          "...","-","..-","...-",".--","-..-","-.--","--.."};
        Set<String> transformations = new HashSet<String>();
        
        for(String word : words) {
            String morseCode = "";
            char[] charWord = word.toCharArray();
            for(char ch : charWord) {
                morseCode += codes[ch - 'a'];
            }
            transformations.add(morseCode);
        }
        return transformations.size();
    }
}
