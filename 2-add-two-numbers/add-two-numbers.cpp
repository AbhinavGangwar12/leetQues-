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
    void insertNode(ListNode* &head,ListNode* &tail, int val){
        ListNode* new_node = new ListNode(val);
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
    ListNode* addTwoNumbers(ListNode* list_one, ListNode* list_two) {
        ListNode* ans_head = NULL;
        ListNode* ans_tail = NULL;
        int carry = 0;
        while(list_one != NULL or list_two != NULL or carry != 0){
            int val1 = 0;
            if(list_one != NULL)val1 = list_one->val;

            int val2 = 0;
            if(list_two != NULL)val2 = list_two->val;

            int sum = carry + val1 + val2;
            int digit = sum % 10;
            insertNode(ans_head,ans_tail,digit);
            carry = sum / 10;
            if(list_one != NULL)list_one = list_one->next;
            if(list_two != NULL)list_two = list_two->next;

        }
        return ans_head;
    }
};