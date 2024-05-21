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

    ListNode* merge(ListNode* head1, ListNode* head2){

        if(!head1 && !head2) return NULL;

        if(!head1) return head2;

        if(!head2) return head1;

       priority_queue<pair<int,ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int,ListNode*>>> pq;

        ListNode* head;
        ListNode* cur = NULL;

        pq.push({head1->val, head1});
        pq.push({head2->val, head2});

    
        while(pq.size() > 1){
            auto t = pq.top();
            pq.pop();
            if(cur == NULL){
                cur = t.second;
                head = t.second;
            }else{
                cur->next = t.second;
                cur = cur->next;
            }
            if(t.second->next){
                pq.push({t.second->next->val, t.second->next});
            }
        }
       
        cur->next = pq.top().second;

        return head;
    }


    ListNode* mergeSort(vector<ListNode*> &lists, int l, int h){
        if(l >= h) return lists[l];

        int m = (l+h) / 2;

        ListNode* head1 = mergeSort(lists, l, m);
        ListNode* head2 = mergeSort(lists, m+1, h);

        return merge(head1, head2);

    }



public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        return mergeSort(lists, 0, lists.size()-1);
    }
};