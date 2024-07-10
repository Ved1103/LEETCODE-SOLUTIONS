// using priority_queue approach
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        priority_queue<pair<int, int>> pq;
        int n = nums.size();
        vector<int> res;
        while (j != n) {
            pq.push({nums[j], j});
            if (j - i < k - 1) {
                j++;
            } else if (j - i == k - 1) {
                while (pq.top().second < i) {
                    pq.pop();
                }
                res.push_back(pq.top().first);
                i++;
                j++;
            }
        }
        return res;
    }
};