class Solution {
public:
    bool isVowel(char &ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    int maxVowels(string s, int k) {
        int n = s.length();
        int maxi_count = 0;
        int temp = 0;
        int low = 0, high = 0;
        while (high < n) {
            if (isVowel(s[high])) {
                temp++;
            }
            if (high - low + 1 == k) {
                maxi_count = max(maxi_count, temp);
                if (isVowel(s[low])) {
                    temp--;
                }
                low++;
            }
            high++;
        }
        return maxi_count;
    }
};