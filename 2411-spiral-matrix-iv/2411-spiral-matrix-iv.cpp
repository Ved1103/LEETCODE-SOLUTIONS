/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));
        int top = 0, bottom = m - 1, left = 0, right = n - 1;
        ListNode* curr = head;
        while (curr != nullptr && top <= bottom && left <= right) {
            for (int i = left; i <= right && curr != nullptr; i++) {
                ans[top][i] = curr->val;
                curr = curr->next;
            }
            top++;
            for (int i = top; i <= bottom && curr != nullptr; i++) {
                ans[i][right] = curr->val;
                curr = curr->next;
            }
            right--;
            for (int i = right; i >= left && curr != nullptr; i--) {
                ans[bottom][i] = curr->val;
                curr = curr->next;
            }
            bottom--;
            for (int i = bottom; i >= top && curr != nullptr; i--) {
                ans[i][left] = curr->val;
                curr = curr->next;
            }
            left++;
        }
        return ans;
    }
};