class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> rmdfr(k, 0);
        
        for (int a : arr) {
            int rmd = a % k;
            if (rmd < 0) rmd += k;
            rmdfr[rmd]++;
        }

        for (int i = 1; i < k; i++) {
            if (rmdfr[i] != rmdfr[k - i]) {
                return false;
            }
        }

        return rmdfr[0] % 2 == 0;
    }
};