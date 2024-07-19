// // S.C O(N)
// class Solution {
// public:
//     vector<int> luckyNumbers (vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         int m = matrix[0].size();

//         vector<int> rowMin(n, INT_MAX); 
//         vector<int> colMax(m, INT_MIN);

//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 rowMin[i] = min(rowMin[i], matrix[i][j]);
//                 colMax[j] = max(colMax[j], matrix[i][j]);
//             }
//         }

//         vector<int> lucky;
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 if (matrix[i][j] == rowMin[i] && matrix[i][j] == colMax[j]) {
//                     lucky.push_back(matrix[i][j]);
//                 }
//             }
//         }

//         return lucky;
//     }
// };

//S.C O(1)


class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> lucky;
        for (int i = 0; i < n; i++) {
            int minVal = matrix[i][0];
            int minCol = 0;
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] < minVal) {
                    minVal = matrix[i][j];
                    minCol = j;
                }
            }

            bool isLucky = true;
            for (int k = 0; k < n; k++) {
                if (matrix[k][minCol] > minVal) {
                    isLucky = false;
                    break;
                }
            }

            if (isLucky) {
                lucky.push_back(minVal);
            }
        }

        return lucky;
    }
};

