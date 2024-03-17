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
    private:
    void insertNode(Node* &head,Node* &tail,int value){
        Node* new_node = new Node(value);
        if(head == NULL){
            head = new_node;
            tail = new_node;
            return;
        }
        else{
            tail->next = new_node;
            tail = new_node;
        }
    }
public:
    Node* copyRandomList(Node* head) {

        Node* chead = NULL;
        Node* ctail = NULL;
        
        Node* temp = head;
        while(temp){
            insertNode(chead,ctail,temp->val);
            temp = temp->next;
        }

        unordered_map<Node*,Node*> old_new;

        Node* original_node = head;
        Node* clone_node = chead;
        while ((original_node) and  (clone_node)){
            old_new[original_node] = clone_node;
            original_node = original_node -> next;
            clone_node = clone_node -> next;
        }

        original_node = head;
        clone_node = chead;
        while((clone_node)){
            clone_node ->random = old_new[original_node->random];
            original_node = original_node -> next;
            clone_node = clone_node -> next;
        }
        return chead;    
    }
};