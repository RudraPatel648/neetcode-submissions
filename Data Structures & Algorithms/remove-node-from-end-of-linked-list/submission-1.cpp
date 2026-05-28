class Solution {
   public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        stack<ListNode*> st;

        ListNode* temp = head;

        while (temp) {
            st.push(temp);
            temp = temp->next;
        }

        int count = 1;
        while (count < n) {
            st.pop();
            count++;
        }

        ListNode* nodeToDelete = st.top();
        st.pop();

        // deleting head
        if (st.empty()) {
            return head->next;
        }

        ListNode* prev = st.top();

        prev->next = nodeToDelete->next;

        return head;
    }
};