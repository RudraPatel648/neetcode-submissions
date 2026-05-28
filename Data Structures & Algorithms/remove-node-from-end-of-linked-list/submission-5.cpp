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
    int traverse(ListNode* current , int n){
        if(!current) return 0;

        int nextCount = traverse(current->next , n ) + 1;
        
        if(nextCount == n + 1 && current->next)
        {
            current->next = current->next->next;
        }

        return nextCount;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int count = traverse(head , n);
        
        if(count == n) return head->next;
        return head;
    }
};
