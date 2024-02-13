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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)return NULL;
        ListNode* temp = head;
        while(temp && temp->next){
            if(temp->val != temp->next->val){
                temp = temp->next;
            }
            else{
                if(temp->next->next){
                    ListNode* next_node = temp->next->next;
                    ListNode* del = temp->next;
                    temp->next = next_node;
                    delete del;
                }
                else{
                    ListNode* del = temp->next;
                    temp->next = NULL;
                    delete del;
                }
            }
        }
        return head;
    }
};