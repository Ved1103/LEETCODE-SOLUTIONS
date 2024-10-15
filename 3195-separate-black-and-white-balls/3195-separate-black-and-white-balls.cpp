class Solution {
public:
    long long minimumSteps(string s) {
        // 110101001 0+2+3+4+4
        // 110100101
        // 110100011
        // 110010011
        // 110001011
        // 110000111
        // 101000111
        // 100100111
        // 100010111
        // 100001111
        // 010001111
        // 001001111
        // 000101111
        // 000011111
        long long ans = 0;
        long long zeroes = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '1') {
                ans += zeroes;

            } else {
                zeroes++;
            }
        }
        return ans;
    }
};