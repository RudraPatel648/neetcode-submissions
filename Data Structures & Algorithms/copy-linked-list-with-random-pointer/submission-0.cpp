/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        Node* newHead = new Node(head->val);
        Node* oldtemp = head;
        Node* temp = newHead;
        unordered_map<Node* , Node*> mpp;
        mpp[oldtemp] = temp;

        while(oldtemp){
            if(oldtemp->next)temp->next = new Node(oldtemp->next->val);
            oldtemp = oldtemp->next;
            temp = temp->next;
            mpp[oldtemp] = temp;
        }

        temp = newHead;
        oldtemp = head;
        while(temp){
            if(oldtemp->random)temp->random = mpp[oldtemp->random];
            else temp->random = NULL;
            temp = temp->next;
            oldtemp = oldtemp->next;
        }

        return newHead;
    }
};