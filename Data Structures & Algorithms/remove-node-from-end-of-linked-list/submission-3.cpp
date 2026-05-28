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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return NULL;
        ListNode* first = head;
        int firstIndex = 1;
        while(first)
        {
            first = first->next;
            firstIndex++;
        }

        ListNode* second = head;
        int secondIndex = 1;
        ListNode* prev = NULL;
        while(firstIndex - secondIndex != n){
            prev = second;
            second = second->next;
            secondIndex++;
        }

        if(!prev) return head->next;
        prev->next = second->next;
        return head;
    }
};
