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
    ListNode* mergeLists(ListNode* l1 , ListNode* l2){
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        ListNode* p1 = l1;
        ListNode* p2 = l2;

        while(p1 && p2){
            if(p1->val < p2->val){
                temp->next = p1;
                p1 = p1->next;
                temp = temp->next;
            }
            else{
                temp->next = p2;
                p2 = p2->next;
                temp = temp->next;
            }
        }
        while(p1){
            temp->next = p1;
            p1 = p1->next;
            temp = temp->next;
        }
        while(p2){
            temp->next = p2;
            p2 = p2->next;
            temp = temp->next;
        }

        return dummy->next;

    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(!lists.size()) return NULL;

        while(lists.size() > 1){
            vector<ListNode*> mergedLists;

            for(int i = 0 ; i < lists.size() ; i+=2){
                ListNode* l1 = lists[i];
                ListNode* l2 = (i + 1 < lists.size()) ? lists[i + 1] : NULL;

                mergedLists.push_back(mergeLists(l1,l2));
            }

            lists = mergedLists;
        }

        return lists[0];
    }
};
