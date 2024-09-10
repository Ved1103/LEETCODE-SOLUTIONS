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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp = head;
        
        while(temp != nullptr && temp->next != nullptr) {
            int gcd_val = __gcd(temp->val, temp->next->val);
            
            ListNode* new_node = new ListNode(gcd_val);
            new_node->next = temp->next;
            temp->next = new_node;
            temp = new_node->next;
        }
        
        return head;
    }
};
