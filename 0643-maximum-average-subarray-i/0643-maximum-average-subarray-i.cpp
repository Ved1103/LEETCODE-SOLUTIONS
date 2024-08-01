class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        double ans = INT_MIN;
        int n = nums.size();
        int sum = 0;
        while (j < n) {
            sum += nums[j];
            if (j - i + 1 < k) {
                j++; // increasing the window size upto k
            } else { // if window size is reached to k
                double temp = (double)sum / k;
                ans = max(ans, temp);
                j++;
                sum -= nums[i]; // removing the ith element
                i++;
            }
        }
        return ans;
    }
};