// //brute force
// class Solution {
// public:
//     vector<int> dailyTemperatures(vector<int>& temperatures) {
//         int n = temperatures.size();
//         vector<int> ans(n, 0); 
//         for (int i = 0; i < n; ++i) {
//             for (int j = i + 1; j < n; ++j) {
//                 if (temperatures[j] > temperatures[i]) {
//                     ans[i] = j - i; 
//                     break; 
//                 }
//             }
//         }
//         return ans;
//     }
// };

//optimised approach
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> s; 
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && temperatures[i] > temperatures[s.top()]) {
                int idx = s.top();
                s.pop();
                ans[idx] = i - idx; 
            }
            s.push(i);
        } 
        return ans;
    }
};

