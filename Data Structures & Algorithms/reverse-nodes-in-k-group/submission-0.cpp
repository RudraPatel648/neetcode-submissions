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
        // Dummy node added so connecting first reversed group
        // becomes easy and avoids special edge cases for head
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // prevGroupTail tracks tail of previous reversed group
        ListNode* prevGroupTail = dummy;

        while (true) {
            // We first CHECK whether k nodes exist or not.
            // Your original code reversed even incomplete groups.
            ListNode* kthNode = prevGroupTail;

            for (int i = 0; i < k && kthNode; i++) {
                kthNode = kthNode->next;
            }

            // If less than k nodes remain,
            // leave remaining list unchanged.
            if (!kthNode) break;

            // groupNext stores node AFTER current k-group.
            // Needed later to reconnect list.
            ListNode* groupNext = kthNode->next;

            // Current group starts here
            ListNode* current = prevGroupTail->next;

            ListNode* prev = groupNext;

            // Standard linked list reversal logic
            // but ONLY for exactly k nodes.
            for (int i = 0; i < k; i++) {
                ListNode* nextNode = current->next;

                current->next = prev;

                prev = current;

                current = nextNode;
            }

            // oldGroupHead becomes tail after reversal
            ListNode* oldGroupHead = prevGroupTail->next;

            // Connect previous group to new reversed head
            prevGroupTail->next = kthNode;

            // Move prevGroupTail forward for next iteration
            prevGroupTail = oldGroupHead;
        }

        return dummy->next;
    }
};