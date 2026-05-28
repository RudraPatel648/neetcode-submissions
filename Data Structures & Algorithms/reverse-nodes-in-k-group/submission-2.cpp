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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prevTailNode = dummy;
        ListNode* kthNode = head;
        while (true) {
            for (int i = 1; i < k; i++) {
                if (!kthNode) break;
                kthNode = kthNode->next;
            }

            if (!kthNode) return dummy->next;

            ListNode* temp = prevTailNode->next;
            ListNode* oldHead = temp;
            ListNode* prev = kthNode->next;
            for (int i = 0; i < k; i++) {
                ListNode* currentNext = temp->next;
                temp->next = prev;
                prev = temp;
                temp = currentNext;
            }
            prevTailNode->next = kthNode;
            prevTailNode = oldHead;
            kthNode = oldHead->next;
        }
        return dummy->next;
    }
};
