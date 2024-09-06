class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int start = 0, end = n-1;
        int ans = 1e9;
        while(start<=end){
            int mid = start + (end-start)/2;
            ans = min(ans, nums[mid]);
            if(nums[mid] < nums[end]) {
                end = mid - 1;
            } 
            else if(nums[mid] > nums[end]){
                start = mid + 1;
            }
            else{
                end--;
            }

        }
        return ans;
    }
};