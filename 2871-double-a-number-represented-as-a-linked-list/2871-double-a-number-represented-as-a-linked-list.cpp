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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        while (current != nullptr) {
            ListNode* nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        return prev;
    }

    ListNode* doubleIt(ListNode* head) {
        if (!head) return nullptr;
        head = reverseList(head);

        ListNode* current = head;
        ListNode* prev = nullptr;
        int carry = 0;

        while (current != nullptr) {
            int doubledValue = current->val * 2 + carry;
            current->val = doubledValue % 10;
            carry = doubledValue / 10;

            prev = current;
            current = current->next;
        }
        if (carry > 0) {
            prev->next = new ListNode(carry);
        }
        return reverseList(head);
    }
};