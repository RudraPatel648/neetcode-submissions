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
    ListNode* mergeTwo(ListNode* a , ListNode* b){
        if (!a) return b;
        if (!b) return a;
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        ListNode* temp1 = a;
        ListNode* temp2 = b;

        while(temp1 && temp2){
            if(temp1->val < temp2->val){
                temp->next = temp1;
                temp1 = temp1->next;
            }
            else{
                temp->next = temp2;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        if(temp1) temp->next = temp1;
        if(temp2) temp->next = temp2;

        return dummy->next;
    }


    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        stack<ListNode*> st;
        for(auto it : lists){
            if (it) st.push(it);
        }
        if (st.empty()) return nullptr;
        while(st.size() > 1)
        {
            // if(st.size() == 1)
            // return st.top();

            vector<ListNode*> temp;
            while(!st.empty()){
                ListNode* first = st.top();
                st.pop();
                if (st.empty()) {
                    temp.push_back(first);
                } else {
                    ListNode* second = st.top();
                    st.pop();
                    temp.push_back(mergeTwo(first , second));
                }
            }
            for(auto it : temp){
                st.push(it);
            }
        }
        return st.top();
    }
};
