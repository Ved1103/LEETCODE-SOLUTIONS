class Solution {
public:
    string addBinary(string a, string b) {
        string result;
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';

            carry = sum > 1 ? 1 : 0;
            result.push_back('0' + (sum % 2));  
        }

        if (carry) result.push_back('1');  // Avoid unnecessary to_string conversion
        reverse(result.begin(), result.end());

        return result;
    }
};
