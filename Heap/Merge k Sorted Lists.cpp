//https://leetcode.com/problems/merge-k-sorted-lists/description/?envType=problem-list-v2&envId=heap-priority-queue

class cmp {
public:
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;

        for(auto x : lists) {
            if(x) pq.push(x);
        }

        ListNode* h = new ListNode(-1);
        ListNode* t = h;

        while(!pq.empty()) {
            auto x = pq.top();
            pq.pop();

            t->next = x;
            t = t->next;

            if(x->next) pq.push(x->next);
        }

        return h->next;
    }
};

//TC : O(N log k)
//SC :O(k)
