class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int longest = 1;
        unordered_set<int> st(nums.begin(), nums.end());
        for (int num : st) {
            if (st.find(num - 1) == st.end()) { 
                int currentNum = num;
                int currentStreak = 1;
                
                while (st.find(currentNum + 1) != st.end()) {
                    currentNum++;
                    currentStreak++;
                }
                
                longest = max(longest, currentStreak);
            }
        }
        return longest;
    }
};
