class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> set;
        for (int i = 0; i < nums.size(); i++) {
            set.insert(nums[i]);
            int reversed = reverseDigits(nums[i]);
            set.insert(reversed);
        }
        return set.size();
    }
    
private:
    int reverseDigits(int num) {
        int reversed = 0;
        while (num > 0) {
            reversed = reversed * 10 + num % 10;
            num /= 10;
        }
        return reversed;
    }
};