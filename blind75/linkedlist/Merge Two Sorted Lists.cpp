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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 && !list2) return NULL;

        if(!list1) return list2;

        if(!list2) return list1;


        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        ListNode* cur = NULL;
        ListNode* head = NULL;

        if(temp1->val <= temp2->val){
            cur = temp1;
            head = temp1;
            temp1 = temp1->next;
        }else{
            cur = temp2;
            head = temp2;
            temp2 = temp2->next;
        }


        while(temp1 != NULL && temp2 != NULL){
            if(temp1->val <= temp2->val){
                cur->next = temp1;
                temp1 = temp1->next;
                cur = cur->next;
            }else{
                cur->next = temp2;
                temp2 = temp2->next;
                cur = cur->next;
            }


        }


        if(temp1){
            cur->next = temp1;
        }

        if(temp2){
            cur->next = temp2;
        }

        return head;
    }
};