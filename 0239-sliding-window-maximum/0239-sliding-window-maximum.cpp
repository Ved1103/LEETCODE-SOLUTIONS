// // using priority_queue approach
// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         int i = 0;
//         int j = 0;
//         priority_queue<pair<int, int>> pq;
//         int n = nums.size();
//         vector<int> res;
//         while (j != n) {
//             pq.push({nums[j], j});
//             if (j - i < k - 1) {
//                 j++;
//             } else if (j - i == k - 1) {
//                 while (pq.top().second < i) {
//                     pq.pop();
//                 }
//                 res.push_back(pq.top().first);
//                 i++;
//                 j++;
//             }
//         }
//         return res;
//     }
// };

//using deque approach (monotonic queue)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; // will store indices of the elements
        vector<int> res;
        int n = nums.size();

        for (int j = 0; j < n; ++j) {
            // Remove elements from the front that are out of the current window
            if (!dq.empty() && dq.front() == j - k) {
                dq.pop_front();
            }

            // Remove elements from the back that are smaller than the current element
            // because they are not useful anymore
            while (!dq.empty() && nums[dq.back()] < nums[j]) {
                dq.pop_back();
            }

            // Add the current element's index to the deque
            dq.push_back(j);

            // Once we have the first window (i.e., j >= k - 1), add the max to the result
            if (j >= k - 1) {
                res.push_back(nums[dq.front()]);
            }
        }

        return res;
    }
};
