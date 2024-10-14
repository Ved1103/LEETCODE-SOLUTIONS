class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long int ans = 0;
        priority_queue<int> pq;
        for (auto i : nums) {
            pq.push(i);
        }
        while (k--) {
            int temp = pq.top();
            ans += temp;
            pq.pop();
            pq.push(ceil(temp / 3.0));
        }
        return ans;
    }
};