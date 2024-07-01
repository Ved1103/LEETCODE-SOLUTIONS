class Solution {
public:
    int maxDepth(string s) {
        int nest_depth = 0;
        int temp = 0;
        int size = s.size();
        for (int i = 0; i < size; i++) {
            if (s[i] == '(') {
                temp++;
                nest_depth = max(temp, nest_depth);
            } else if (s[i] == ')') {
                temp--;
            }
        }
        return nest_depth;
    }
};