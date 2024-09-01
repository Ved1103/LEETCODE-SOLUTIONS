class Solution {
public:
    int solve(string s, int start, int end, int k){
        if(end-start < k) return 0;
        vector<int>arr(26, 0);
        for(int i = start; i < end; i++){
            arr[s[i]-'a']++;
        }
        for(int i = start; i < end; i++){
            if(arr[s[i]-'a'] < k){
                int j = i+1;
                while(j < end && arr[s[j]-'a'] < k){
                    j++;
                }
                return max(solve(s,start,i,k),solve(s,j,end,k));
            }
        }
        return end-start;
    }
    
    int longestSubstring(string s, int k) {
        return solve(s,0,s.size(),k);
    }
};