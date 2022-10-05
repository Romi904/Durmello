class Solution {
public:
    uint32_t  reverseBits(uint32_t n) {
        uint32_t answer= 0;
        //first digit appended will be MSB at the end ensuring reverse
        for(int i=0; i<32; i++) {
            answer = (answer<<1) + (n>>i &1);
        }
        return answer;
    }
};