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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return {-1, -1};
        }  
        ListNode* prev = head;
        ListNode* curr = head->next;
        int currPos = 1;
        int firstCrit = -1;
        int prevCrit = -1;
        int minDist = INT_MAX;
        int maxDist = 0;
        while (curr->next != nullptr) {
            if ((curr->val > prev->val && curr->val > curr->next->val) || 
                (curr->val < prev->val && curr->val < curr->next->val)) {    
                if (firstCrit == -1) {
                    firstCrit = currPos;
                } else {
                    minDist = min(minDist, currPos - prevCrit);
                    maxDist = currPos - firstCrit;
                }
                prevCrit = currPos;
            }
            prev = curr;
            curr = curr->next;
            currPos++;
        }
        if (firstCrit == -1 || prevCrit == firstCrit) {
            return {-1, -1};
        }
        return {minDist, maxDist};
    }
};
