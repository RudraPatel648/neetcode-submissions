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
        stack<ListNode*> st;

        ListNode* temp = head;
        while(temp)
        {
            st.push(temp);
            temp = temp->next;
        }

        int count = 1;
        while(count < n){
            st.pop();
            count++;
        }
        temp = st.top();
        st.pop();
        if(st.empty()) return head->next;

        st.top()->next = temp->next;
        temp->next = NULL;

        return head;
    }
};
