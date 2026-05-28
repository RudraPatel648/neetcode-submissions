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
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* second = slow->next;
        slow->next = NULL;

        ListNode* prev = NULL;
        while(second){
            ListNode* next = second->next;
            second->next = prev;
            prev = second;
            second = next;
        }
        second = prev;

        ListNode* temp = head;

        while(second){
            ListNode* temp1 = temp->next;
            ListNode* temp2 = second->next;

            temp->next = second;
            second->next = temp1;

            temp = temp1;
            second = temp2;
        }
    }
};
