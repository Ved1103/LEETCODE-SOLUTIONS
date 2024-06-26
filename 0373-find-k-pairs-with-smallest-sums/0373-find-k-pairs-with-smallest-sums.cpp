class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int, pair<int, int>>> maxHeap;
        int n = nums1.size();
        int m = nums2.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int sum = nums1[i] + nums2[j];
                if (maxHeap.size() < k) {
                    maxHeap.push({sum, {nums1[i], nums2[j]}});
                } else if (sum < maxHeap.top().first) {
                    maxHeap.pop();
                    maxHeap.push({sum, {nums1[i], nums2[j]}});
                } else {
                    break; // No need to check further in this row since arrays are sorted
                }
            }
        }
        vector<vector<int>> result;
        while (!maxHeap.empty()) {
            result.push_back({maxHeap.top().second.first, maxHeap.top().second.second});
            maxHeap.pop();
        }
        return result;
    }
};
