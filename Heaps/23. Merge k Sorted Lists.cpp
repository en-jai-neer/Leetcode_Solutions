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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* a, ListNode* b)
        {
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        ListNode* head;
        ListNode* temp;
        int cnt = 0, n = lists.size();
        for(int i = 0; i < n; i++)
        {
            if(lists[i] != NULL)
                pq.push(lists[i]);
            else
                cnt++;
        }
        if(pq.empty())
            return NULL;
        head = pq.top();
        temp = head;
        pq.pop();
        if(temp->next != NULL)
            pq.push(temp->next);
        else
            cnt++;
        while(cnt != lists.size())
        {
            temp->next = pq.top();
            temp = temp->next;
            pq.pop();
            if(temp->next != NULL)
                pq.push(temp->next);
            else
                cnt++;
        }
        return head;
    }
};
