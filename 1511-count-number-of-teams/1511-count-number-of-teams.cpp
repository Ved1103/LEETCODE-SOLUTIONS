// // brute force O(N3)
// class Solution {
// public:
//     int numTeams(vector<int>& rating) {
//         int count = 0;
//         int n = rating.size();
//         for (int i = 0; i < n; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 for (int k = j + 1; k < n; k++) {
//                     if ((rating[i] < rating[j] && rating[j] < rating[k]) ||
//                         (rating[i] > rating[j] && rating[j] > rating[k])) {
//                         count++;
//                     }
//                 }
//             }
//         }
//         return count;
//     }
// };

// 0(n2) 
class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int count = 0;
        for (int j = 0; j < n; j++) {
            int left_less = 0, left_greater = 0;
            int right_less = 0, right_greater = 0;
            
            for (int i = 0; i < j; i++) {
                if (rating[i] < rating[j]) left_less++;
                if (rating[i] > rating[j]) left_greater++;
            }
            
            for (int k = j + 1; k < n; k++) {
                if (rating[k] < rating[j]) right_less++;
                if (rating[k] > rating[j]) right_greater++;
            }
            count += left_less * right_greater + left_greater * right_less;
        }
        
        return count;
    }
};
