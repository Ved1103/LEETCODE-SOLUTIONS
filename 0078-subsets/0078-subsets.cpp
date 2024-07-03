// backtracking solution
class Solution {
private:
    void helper(vector<int>& temp, vector<vector<int>>& res, int start, vector<int>& nums) {
        res.push_back(temp); 
        for (int i = start; i < nums.size(); ++i) {
            temp.push_back(nums[i]); 
            helper(temp, res, i + 1, nums); 
            temp.pop_back(); 
        }
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        helper(temp, res, 0, nums);
        return res;
    }
};