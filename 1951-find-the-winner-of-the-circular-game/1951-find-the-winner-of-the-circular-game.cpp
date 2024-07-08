// class Solution {
// public:
//     int findTheWinner(int n, int k) {
//         vector<int> vec;

//         for (int i = 1; i <= n; i++) {
//             vec.push_back(i);
//         }
//         int size = vec.size();
//         int i = 0;
//         while (vec.size() > 1) {
//             int temp = (i + k - 1) % vec.size();
//             vec.erase(vec.begin() + temp);
//             i = temp; 
//         }
//         int ans = vec[0];
//         return ans;
//     }
// };

//
class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        
        for (int i = 1; i <= n; i++) {
            q.push(i);
        }
        
        while (q.size() > 1) {
            for (int i = 0; i < k - 1; i++) {
                q.push(q.front());
                q.pop();
            }
            q.pop();
        }
        
        return q.front();
    }
};
