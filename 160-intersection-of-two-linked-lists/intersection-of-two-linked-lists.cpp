/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    private:
    int len_(ListNode* head){
        int len = 0;
        ListNode* temp =  head;
        while(temp){
            len++;
            temp = temp->next;
        }
        return len;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // vector<ListNode*> lista;
        // vector<ListNode*> listb;

        // ListNode* temp = headA;
        // while(temp){
        //     lista.push_back(temp);
        //     temp = temp->next;
        // }
        // temp = headB;
        // while(temp){
        //     listb.push_back(temp);
        //     temp = temp->next;
        // }
        // for(int i=0;i<lista.size();i++){
        //     for(int j=0;j<listb.size();j++){
        //         if(lista[i] == listb[j])return lista[i];
        //     }
        // }
        // return NULL;


        if(headA == NULL or headB == NULL)return NULL;
        ListNode* temp = headA;
        ListNode* temp_ = headB;
        int len = len_(headA),len1 = len_(headB);
        int diff = abs(len - len1);
        if(len > len1){
            for(int i=0;i<diff;i++){
                temp = temp->next;
            }
        }
        else{
            for(int i=0;i<diff;i++){
                temp_ = temp_->next;
            }
        }
        while (temp != temp_){
            temp = temp->next;
            temp_ = temp_->next;
        }
        return temp;
    }
};