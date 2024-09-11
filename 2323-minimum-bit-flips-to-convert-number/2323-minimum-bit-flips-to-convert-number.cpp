class Solution {
public:
    int minBitFlips(int start, int goal) {
        int diffnum = (start ^ goal);
        int bitCnt = 0;
        while (diffnum > 0) {
            bitCnt++;
            diffnum &= (diffnum - 1);
        }
        return bitCnt;
    }
};