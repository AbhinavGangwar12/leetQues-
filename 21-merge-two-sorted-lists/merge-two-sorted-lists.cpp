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
        ListNode* solve(ListNode* &head1, ListNode* &head2){
            if(head1->next == NULL){
                head1->next = head2;
                return head1;
            }

            ListNode* low = head1;
            ListNode* high = head1->next;
            ListNode* curr = head2;
            ListNode* cnext = head2->next;

            while(high != NULL and curr !=NULL ){
                int v = curr->val;
                if((v>=low->val) and (v <= high->val)){
                    low->next = curr;
                    cnext = curr->next;
                    curr->next = high;
                    low = curr;
                    curr = cnext;
                }
                else {
                    low = high;
                    high = high->next;
                    if(high == NULL){
                        low->next = curr;
                        return head1;
                    }
                }
            }
            // if(curr != NULL)high->next = curr;
            return head1;
        }
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL)return list2;
        if(list2 == NULL)return list1;
        if(list1->val < list2->val)return solve(list1,list2);
        else return solve(list2,list1);
    }
};