class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<int> res;
        for (auto num : nums) {
            nums[abs(num) - 1] *= -1;
        }
        for (auto num : nums) {
            if (nums[abs(num) - 1] > 0) {
                res.push_back(abs(num));
            }
            nums[abs(num) - 1] *= -1;
        }
        return res;
    }
};