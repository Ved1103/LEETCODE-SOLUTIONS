class Solution {
public:
    int f(int i,vector<int>& nums,vector<int>&dp){
        if(i>=nums.size()-1)return 0;
        if(dp[i]!=-1)return dp[i];
        int ans=nums.size()-1;
        for(int k=1;k<=nums[i];k++){
            int res=1+f(i+k,nums,dp);
            ans=min(ans,res);
        }
        return dp[i]=ans;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return f(0,nums,dp);
    }
};