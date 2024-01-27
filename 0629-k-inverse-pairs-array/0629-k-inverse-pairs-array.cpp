// class Solution {
// public:
//     int kInversePairs(int n, int k) {
//         int dp[1001][1001] = {1};  
//         for (int i = 1; i <= n; i++) {
//             for (int j = 0; j <= k; j++) {
//                 for (int x = 0; x <= min(j, i - 1); x++) {
//                     if (j - x >= 0) {
//                         dp[i][j] = (dp[i][j] + dp[i - 1][j - x]) % 1000000007;
//                     }
//                 }
//             }
//         }

//         return dp[n][k];
//     }
// };

class Solution {
private:
    const int mod=int(1e9+7);
    int dp[1001][1001];
    int f(int n,int k) {
        if(k<=0) return k==0;
        if(dp[n][k]!=-1) return dp[n][k];


        int ans=0;
        for(int i=0;i<n;++i) {
            ans+=f(n-1,k-i);
            ans%=mod;
        }
        return dp[n][k]=ans;
    }
public:
    int kInversePairs(int n, int k) {
        memset(dp,-1,sizeof(dp));
        return f(n,k);
    }
};
