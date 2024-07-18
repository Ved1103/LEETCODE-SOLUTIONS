class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int temp = n / 4;
        int ans = -1;

        for (int i = 0; i < n - temp; i++) {
            if (arr[i] == arr[i + temp]) {
                ans = arr[i];
                break;
            }
        }

        return ans;
    }
};
