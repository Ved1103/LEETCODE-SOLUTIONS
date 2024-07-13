class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions,
                                      vector<int>& healths, string directions) {
        int count = positions.size();
        vector<int> indices(count);
        for (int i = 0; i < count; ++i) {
            indices[i] = i;
        }

        stack<int> robotStack;

        auto compare = [&](int a, int b) {
            return positions[a] < positions[b];
        };

        sort(begin(indices), end(indices), compare);

        vector<int> result;
        for (int index : indices) {
            if (directions[index] == 'R') {
                robotStack.push(index);
            } else {
                while (!robotStack.empty() && healths[index] > 0) {
                    int topIndex = robotStack.top();
                    robotStack.pop();

                    if (healths[topIndex] > healths[index]) {
                        healths[topIndex] -= 1;
                        healths[index] = 0;
                        robotStack.push(topIndex);
                    } else if (healths[topIndex] < healths[index]) {
                        healths[index] -= 1;
                        healths[topIndex] = 0;
                    } else {
                        healths[index] = 0;
                        healths[topIndex] = 0;
                    }
                }
            }
        }

        for (int i = 0; i < count; ++i) {
            if (healths[i] > 0) {
                result.push_back(healths[i]);
            }
        }
        return result;
    }
};
