// brute force:

// class Solution {
// public:
//     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//         int n = gas.size();
//         for (int i = 0; i < n; i++) {
//             if (gas[i] < cost[i]) {
//                 continue;
//             }
            
//             int j = (i + 1) % n;
//             int currentGas = gas[i] - cost[i] + gas[j];
//             while (j != i) {
//                 if (currentGas < cost[j]) {
//                     break;
//                 }
//                 currentGas = currentGas - cost[j] + gas[(j + 1) % n];
//                 j = (j + 1) % n;
//             }

//             if (i == j) {
//                 return i;
//             }
//         }
//         return -1;
//     }
// };
// optimised 
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        // Calculate total gas and total cost
        int sumGas = accumulate(begin(gas), end(gas), 0);
        int sumCost = accumulate(begin(cost), end(cost), 0);
        
        // If total gas is less than total cost, return -1
        if (sumGas < sumCost)
            return -1;
        
        int total = 0;
        int result = 0;
        
        // Iterate through each station
        for (int i = 0; i < n; i++) {
            total += gas[i] - cost[i];
            
            // If total gas is negative, reset total and update result
            if (total < 0) {
                total = 0;
                result = i + 1;
            }
        }
        return result;
    }
};
