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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* cur = head;
        ListNode* prev = NULL;

        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            cur->next = prev;
            prev = cur;
            cur = slow;
        }

        cout << prev->val << endl;

        ListNode* last = NULL;

        if(fast){
            last = slow;
            slow = slow->next;
            last->next = NULL;

        }

        while(prev && slow){
            ListNode* l1 = prev->next;
            ListNode* l2 = slow->next;

            prev->next = slow;
            slow->next = last;

            last = prev;

            prev = l1;
            slow = l2;
        }

    }
};