class Solution {
public:
    int balancedStringSplit(string s) {
        int maxBalancedStrings = 0;
        int balanceCount = 0;

        for (char c : s) {
            if (c == 'L') {
                balanceCount++;
            } else {
                balanceCount--;
            }

            if (balanceCount == 0) {
                maxBalancedStrings++;
            }
        }

        return maxBalancedStrings;
    }
};
