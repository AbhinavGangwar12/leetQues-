/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        vector<ListNode*> lista;
        vector<ListNode*> listb;

        ListNode* temp = headA;
        while(temp){
            lista.push_back(temp);
            temp = temp->next;
        }
        temp = headB;
        while(temp){
            listb.push_back(temp);
            temp = temp->next;
        }
        for(int i=0;i<lista.size();i++){
            for(int j=0;j<listb.size();j++){
                if(lista[i] == listb[j])return lista[i];
            }
        }
        return NULL;
    }
};