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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL)return NULL;

        ListNode* large_curr = head;
        ListNode* large_prev = NULL;

        while(large_curr and ( large_curr->val < x )){
            large_prev = large_curr;
            large_curr = large_curr->next;
        }
        if(large_curr == NULL)return head;

        ListNode* small_curr = large_curr;
        ListNode* small_prev = large_curr;

        while(small_curr){
            if((large_prev == NULL) and ( small_curr->val < x )){
                small_prev->next = small_curr->next;
                // small_prev = small_prev->next;
                small_curr->next = large_curr;
                head = small_curr;
                large_prev = small_curr;
                small_curr = small_prev!=NULL ? small_prev->next : NULL;
                
            }
            else if(small_curr->val < x){
                small_prev->next = small_curr->next;
                // small_prev = small_prev->next;
                large_prev->next = small_curr;
                small_curr->next = large_curr;
                large_prev = small_curr;
                small_curr = small_prev ? small_prev->next : NULL;
            }
            else {
                small_prev = small_curr;
                small_curr = small_curr->next;
            }
        }
        return head;
    }
};