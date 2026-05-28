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
        unordered_map<Node* , Node*> hash;
        Node* temp1 = head;
        Node* newHead = new Node(head->val);
        Node* temp2 = newHead;
        hash[temp1] = temp2;
        while(temp1 && temp1->next){
            temp2->next = new Node(temp1->next->val);
            temp2 = temp2->next;
            temp1 = temp1->next;
            hash[temp1] = temp2;
        }

        temp1 = head;
        temp2 = newHead;

        while(temp1){
            if(temp1->random == NULL) 
                temp2->random = NULL;
            else
                temp2->random = hash[temp1->random];
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return newHead;
    }
};