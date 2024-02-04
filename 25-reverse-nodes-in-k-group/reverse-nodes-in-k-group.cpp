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
    // ListNode* rev(ListNode* head,int k){
    //     if(head == NULL)return NULL;
    //     ListNode* next = NULL;
    //     ListNode* curr = head;
    //     ListNode* prev = NULL;
    //     int count = 0;
    //     while(count < k && curr){
    //         next = curr->next;
    //         curr->next = prev;
    //         prev = curr;
    //         curr = next;
    //         count++;
    //     }
    //     if(next)head->next = rev(next,k);
    //     return prev;
    // }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL)return NULL;
        ListNode* next = NULL;
        ListNode* curr = head;
        ListNode* prev = NULL;
        int count = 0;
        ListNode* temp = head;
        for (int i = 0; i < k; ++i) {
            if (temp == NULL) return head; // Not enough nodes, return as is
            temp = temp->next;
        }
        while(count < k && curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        if(next!=NULL)head->next = reverseKGroup(next,k);
        return prev;   
    }
};