class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int specialCount = 0;

        for (int r = 0; r < mat.size(); r++) {
            int cIndex = findSpecialInRow(mat, r);
            if (cIndex >= 0 && isSpecialInColumn(mat, r, cIndex))
                specialCount++;
        }

        return specialCount;
    }

private:
    int findSpecialInRow(vector<vector<int>>& mat, int r) {
        int cIndex = -1;
        for (int c = 0; c < mat[0].size(); c++) {
            if (mat[r][c] == 1) {
                if (cIndex >= 0)
                    return -1;
                else
                    cIndex = c;
            }
        }
        return cIndex;
    }

    bool isSpecialInColumn(vector<vector<int>>& mat, int r, int cIndex) {
        for (int rIndex = 0; rIndex < mat.size(); rIndex++) {
            if (mat[rIndex][cIndex] == 1 && rIndex != r)
                return false;
        }
        return true;
    }
};
