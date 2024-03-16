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
    ListNode* middle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != NULL and fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode * rev(ListNode* head){
        ListNode* curr = head;
        ListNode* nxt = NULL;
        ListNode* prev = NULL;
        while(curr != NULL){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
            // nxt = nxt->next;
        }
        return prev;
    }

public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL)return false;
        if(head->next == NULL)return true;
        
        ListNode* mid = middle(head);
        ListNode* temp = mid->next;
        mid->next = rev(temp);

        ListNode* ptr1 = head;
        ListNode* ptr2 = mid->next;

        while(ptr2 != NULL){
            if(ptr1->val != ptr2->val)return false;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        temp = mid->next;
        mid->next = rev(mid->next);

        return true;
    }
};