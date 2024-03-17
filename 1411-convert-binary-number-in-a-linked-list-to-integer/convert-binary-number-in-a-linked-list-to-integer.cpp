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
        ListNode* rev(ListNode* head){
            ListNode* curr = head;
            ListNode* prev = NULL;
            ListNode* next = NULL;
            while(curr){
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            return prev;
        }
public:
    int getDecimalValue(ListNode* head) {
        head = rev(head);
        ListNode* temp = head;
        int p = 2;
        int ans = temp->val == 1? 1 : 0;
        if(temp->next){
            temp = temp->next;
            while(temp){
                if(temp->val == 1){
                    ans += p;
                }
                p *= 2;
                temp = temp->next;
            }
        }
        // head = rev(head);
        return ans;
    }
};