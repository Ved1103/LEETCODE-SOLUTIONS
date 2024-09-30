class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int> temp;
        for (int i = 1; i < n; i++) {
            fact *= i;
            temp.push_back(i);
        }
        temp.push_back(n);
        string ans = "";
        k--;
        while (true) {
            ans += to_string(temp[k / fact]);
            temp.erase(temp.begin() + k / fact);
            if (temp.empty()) break;
            k %= fact;
            fact /= temp.size();
        }
        return ans;
    }
};
