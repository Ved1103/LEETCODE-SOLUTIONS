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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* temp = head;
        long long size = 0; 
        while (temp != nullptr) {
            size++;
            temp = temp->next;
        }
        
        long long partsize = size / k;  
        long long rem = size % k;  
        vector<ListNode*> ans;
        temp = head;
        
        for (int i = 0; i < k; i++) {
            ans.push_back(temp);
            long long currentsize = partsize + (i < rem ? 1 : 0);  
            for (int j = 1; j < currentsize && temp != nullptr; j++) {
                temp = temp->next;
            }
            
            if (temp != nullptr) {
                ListNode* next = temp->next;
                temp->next = nullptr;
                temp = next;
            }
        }
        
        return ans;
    }
};
