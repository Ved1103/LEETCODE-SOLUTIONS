// 105 / 108 testcases passed
// class Solution {
// public:
//     bool canBeEqual(vector<int>& target, vector<int>& arr) {
//         unordered_set<int> st;
//         int n = target.size();
//         for (int i : target) {
//             st.insert(i);
//         }

//         for (int it : arr) {
//             if (st.count(it)) {
//                 st.erase(it);
//             }
//         }
//         if (st.size() == 0 && arr.size() == n) {
//             return true;
//         }
//         return false;
//     }
// };

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        if (target.size() != arr.size()) {
            return false; 
        }
        unordered_multiset<int> targetSet(target.begin(), target.end());
        unordered_multiset<int> arrSet(arr.begin(), arr.end());

        return targetSet == arrSet;
    }
};
