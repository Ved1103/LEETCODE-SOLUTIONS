class Solution {
private:
    int reverses(int integer) {
        int s = 0;
        while (integer > 0) {
            s = s * 10 + integer % 10;
            integer /= 10;
        }
        return s;
    }
public:
    bool sumOfNumberAndReverse(int num) {
        for (int i = 0; i <= num; i++) {
            int temp = reverses(i);
            if (i + temp == num) {
                return true;
            }
        }
        return false;
    }
};