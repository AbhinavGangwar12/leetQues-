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
        // ListNode* merge(ListNode* &list1,ListNode* &list2){
        //     if(list1 == NULL)return list2;
        //     if(list2 == NULL)return list2;
        //     // if(list1->next == NULL){
        //     //     list1->next = list2;
        //     //     return list1;
        //     // }
            
        //     ListNode* low = list1;
        //     ListNode* high = list1->next;
            
        //     ListNode* curr = list2;
        //     ListNode* curr_next = list2->next;

        //     while(high and curr){
        //         int val = curr->val;
                
        //         if((val >= low->val) and (val <= high->val)){
        //             low->next = curr;
        //             curr_next = curr->next;
        //             curr->next = high;
        //             low = curr;
        //             curr = curr_next;
        //         }else{
        //             low = high;
        //             high = high->next;
        //             if(high == NULL){
        //                 low->next = curr;
        //                 // return list1;
        //             }
        //         }
        //     }
        //     return list1;
        // }
        ListNode* merge(ListNode* head1,ListNode* head2){
            if(head1 == NULL)return head2;
            if(head2 == NULL)return head1;

            if(head1->val < head2->val){
                head1->next = merge(head1->next,head2);
                return head1;
            }
            else{
                head2->next = merge(head1,head2->next);
                return head2;
            }

        }
        ListNode* solve(vector<ListNode*> &head,int low,int high){
            if(head.empty())return nullptr;
            if(low >= high)return head[low];
            int mid = low + (high - low)/2;
            ListNode* a = solve(head,low,mid);
            ListNode* b = solve(head,mid+1,high);
            // ListNode* result = a->val < b->val ? merge(a,b) : merge(b,a);
            return merge(a,b);
        }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())return nullptr;
        return solve(lists,0,lists.size()-1);
    }
};