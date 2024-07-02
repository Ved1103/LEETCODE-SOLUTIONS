class Solution {
public:
    int commonFactors(int a, int b) {
        int temp = min(a, b);
        int ans = 0;
        for (int i = 1; i <= temp; i++) {
            if (a % i == 0 and b % i == 0) {
                ans++;
            }
        }
        return ans;
    }
};