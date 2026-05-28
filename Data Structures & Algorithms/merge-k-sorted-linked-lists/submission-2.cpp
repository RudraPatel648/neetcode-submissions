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
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        if (!a) return b;
        if (!b) return a;
        ListNode* temp1 = a;
        ListNode* temp2 = b;

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while (temp1 && temp2) {
            if (temp2->val > temp1->val) {
                temp->next = temp1;
                temp1 = temp1->next;
            } else {
                temp->next = temp2;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }

        if (temp1)
            temp->next = temp1;
        else
            temp->next = temp2;

        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        stack<ListNode*> st;
        for(auto it : lists) st.push(it);
        
        while (st.size() > 1) {
            stack<ListNode*> temp;

            while (!st.empty()) {
                ListNode* first = st.top();
                st.pop();
                if(st.empty()){
                    temp.push(first);
                    break;
                }
                ListNode* second = st.top();
                st.pop();

                ListNode* third = mergeTwoLists(first, second);
                temp.push(third);
            }
            st = temp;
        }

        if(st.empty()) return NULL;
        return st.top();
    }
};
