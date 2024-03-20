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
        ListNode* pointer1(ListNode* head,int num){
            if(head == NULL)return NULL;
            ListNode* temp = head;
            for(int i=0;i<num-1 and temp;i++){
                temp = temp->next;
            }
            return temp;
        }
        ListNode* pointer2(ListNode* head,int num){
            if(head == NULL)return NULL;
            ListNode* temp = head;
            for(int i=0;i<=num and temp;i++){
                temp = temp->next;
            }
            return temp;
        }
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* first = pointer1(list1,a);
        ListNode* second = pointer2(list1,b);
        ListNode* temp = list2;
        while(temp->next){
            temp = temp->next;
        }
        first->next = NULL;
        first->next = list2;
        temp->next = second;
        return list1;
    }
};