// class Solution {
// public:
//     int n;
//     int dp[50000];
    
//     int getnext(vector<vector<int>>& arr, int l, int currentjobend) {
//         int r = n - 1;
//         int ans = n + 1;

//         while (l <= r) {
//             int mid = l + (r - l) / 2;
//             if (arr[mid][0] >= currentjobend) {
//                 ans = mid;
//                 r = mid - 1;
//             } else {
//                 l = mid + 1;
//             }
//         }
//         return ans;
//     }

//     int solve(vector<vector<int>>& arr, int i) {
//         if (i >= n) return 0;
//         if (dp[i] != -1) return dp[i];

//         int nextjob = getnext(arr, i + 1, arr[i][1]);
//         int take = arr[i][2] + solve(arr, nextjob);
//         int nottake = solve(arr, i + 1);
//         return dp[i] = max(take, nottake);
//     }

//     int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
//         n = startTime.size();
//         memset(dp, -1, sizeof(dp));
//         vector<vector<int>> arr(n, vector<int>(3, 0));

//         for (int i = 0; i < n; i++) {
//             arr[i][0] = startTime[i];
//             arr[i][1] = endTime[i];
//             arr[i][2] = profit[i];
//         }

//         auto comp = [&](auto& vec1, auto& vec2) { // to sort array based on the starting element
//             return vec1[0] <= vec2[0];
//         };

//         sort(arr.begin(), arr.end(), comp);
//         return solve(arr, 0);
//     }
// };
class Solution {
public:
    int nextIndex(int idx,vector<vector<int>>&a)
    {
        int end = a.size(),st=idx+1;
        while(st<end) {
            int md = st+(end-st)/2;
            if(a[md][0]>=a[idx][1])
            end = md;
            else
            st=md+1;
        }
        return st;
    }
    int f(int idx,vector<vector<int>>&a,vector<int>&dp) {
        if(idx==a.size())
            return 0;
        if(dp[idx]!=-1)
            return dp[idx];
        int take = a[idx][2] + f(nextIndex(idx,a),a,dp),notTake = f(idx+1,a,dp);
        return dp[idx] = max(take,notTake);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>>a;
        int n = startTime.size();
        vector<int>dp(n+1,-1);
        for(int i=0;i<n;i++)
        a.push_back({startTime[i],endTime[i],profit[i]});
        sort(a.begin(),a.end());
        return f(0,a,dp);
    }
};