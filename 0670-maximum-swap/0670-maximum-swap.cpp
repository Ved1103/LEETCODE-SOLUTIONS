class Solution {
public:
    int maximumSwap(int num) {
        string numstr = to_string(num);
        vector<int> lastIndex(10, -1);
        for (int i = 0; i < numstr.size(); i++) {
            lastIndex[numstr[i] - '0'] = i;
        }
        for (int i = 0; i < numstr.size(); i++) {
            for (int j = 9; j > numstr[i] - '0'; j--) {
                if (lastIndex[j] > i) {
                    swap(numstr[i], numstr[lastIndex[j]]);
                    return stoi(numstr);
                }
            }
        }
        
        return num;  
    }
};
