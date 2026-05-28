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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        int carry = 0;

        while(temp1 && temp2){
            int current = temp1->val + temp2->val + carry;
            carry = current / 10;
            temp->next = new ListNode(current % 10);
            
            temp = temp->next;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        while(temp1){
            int current = temp1->val + carry;
            carry = current / 10;
            temp->next = new ListNode(current % 10);

            temp = temp->next;
            temp1 = temp1->next;
        }
        while(temp2){
            int current = temp2->val + carry;
            carry = current / 10;
            temp->next = new ListNode(current % 10);

            temp = temp->next;
            temp2 = temp2->next;
        }

        if(carry) temp->next = new ListNode(carry);
        else temp->next = NULL;
        return dummy->next;
    }
};
