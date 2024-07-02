class Solution {
public:
    int pivotInteger(int n) {
        int total_sum = n * (n + 1) / 2;
        int sum = 0, ans = -1;
        for (int i = 1; i <= n; i++) {
            sum += i;
            if (sum == (total_sum + i - sum)) {
                ans = i;
            }
        }
        return ans;
    }
};