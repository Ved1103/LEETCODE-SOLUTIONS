class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if (n > m) return false;
        unordered_map<char, int> mp1, mp2;
        for (char ch : s1) {
            mp1[ch]++;
        }
        for (int i = 0; i < n; i++) {
            mp2[s2[i]]++;
        }
        if (mp1 == mp2) return true;
        for (int i = n; i < m; i++) {
            mp2[s2[i]]++;
            char leftChar = s2[i - n];
            if (mp2[leftChar] == 1) {
                mp2.erase(leftChar);
            } else {
                mp2[leftChar]--;
            }
            if (mp1 == mp2) return true;
        }

        return false;
    }
};
