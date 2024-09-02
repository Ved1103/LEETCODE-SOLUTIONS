class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        long long int totalsum = 0;
        for (int num : chalk) {
            totalsum += num;
        }
        int rem = k % totalsum;
        for (int i = 0; i < n; i++) {
            if (rem < chalk[i]) {
                return i;
            }
            rem -= chalk[i];
        }
        return -1; 
    }
};