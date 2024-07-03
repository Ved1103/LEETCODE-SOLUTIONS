class Solution {
public:
    int subtractProductAndSum(int n) {
        int product = 1, sum = 0;
        string temp = to_string(n);
        for (char ch : temp) {
            int digit = ch - '0'; 
            product *= digit;
            sum += digit;
        }
        return product - sum;
    }
};