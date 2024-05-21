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

    ListNode* reverse(ListNode*prev, ListNode* cur, ListNode*fast){
        if(fast == NULL){
            return prev;
        }

        fast = fast->next;
        cur->next = prev;
        prev = cur;
        cur = fast;
        
        return reverse(prev, cur, fast);

    }


public:
    ListNode* reverseList(ListNode* head) {
        
        return reverse(NULL, head, head);
    }
};