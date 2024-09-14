// class Solution {
// public:
//     int shortestSubarray(vector<int>& nums, int k) {
//         int n = nums.size();
//         int maxsum = 0;
//         int i = 0, j = 0;
//         int maxsize = INT_MAX;
        
//         while (j < n) {
//             maxsum += nums[j];
//             while (maxsum >= k) {
//                 maxsize = min(maxsize, j - i + 1);
//                 maxsum -= nums[i];
//                 i++;
//             }
            
//             j++;
//         }
//         return maxsize == INT_MAX ? -1 : maxsize;
//     }
// };
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefixSum(n + 1, 0);  
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        deque<int> dq;  
        int minLength = INT_MAX;

        for (int i = 0; i <= n; i++) {
            while (!dq.empty() && prefixSum[i] - prefixSum[dq.front()] >= k) {
                minLength = min(minLength, i - dq.front());
                dq.pop_front();
            }

            while (!dq.empty() && prefixSum[i] <= prefixSum[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        return minLength == INT_MAX ? -1 : minLength;
    }
};
