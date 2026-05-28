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
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prevGroupTail = dummy;

        while(true){
            ListNode* kthNode = prevGroupTail;
            for(int i = 0 ; i < k && kthNode; i++){
                kthNode = kthNode->next;
            }

            if(!kthNode) break;

            ListNode* current = prevGroupTail->next;
            ListNode* prev = kthNode->next;

            for(int i = 0 ; i < k ; i++){
                ListNode* nextNode = current->next;

                current->next = prev;
                prev = current;
                current = nextNode;
            }

            ListNode* oldGroupHead = prevGroupTail->next;
            prevGroupTail->next = kthNode;
            prevGroupTail = oldGroupHead;
        }

        return dummy->next;
    }
};
