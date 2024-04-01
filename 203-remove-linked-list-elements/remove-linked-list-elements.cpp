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
    private:
    // void del(ListNode* head,int )
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL)return NULL;
        if(head->val == val){
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
        
        ListNode* curr = head;
        ListNode* prev = NULL;

        while(curr){
            if(curr->val == val){
                if(prev == NULL){
                    // ListNode* temp = curr;
                    curr = curr->next;
                    head = curr;
                    // delete temp;
                }
                else {
                    prev->next = curr->next;
                    // delete curr;
                    curr = prev->next;
                }
            }
            else {
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};