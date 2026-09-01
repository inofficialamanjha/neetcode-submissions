class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t reverseN = 0;
        int power = 31;
        while(n!=0) {
            reverseN += (n&1) * (uint32_t)pow(2,power);
            power--;
            n = n >> 1;
        }
        return reverseN;
    }
};
