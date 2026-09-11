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
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val; // Looking from the bottn, a->val should be greater than b->val
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        
        ListNode dummy = ListNode(0);
        ListNode* current = &dummy;

        for(int i=0; i<lists.size(); i++) {
            if (lists[i]!=nullptr) {
                pq.push(lists[i]);
            }
        }

        while(!pq.empty()) {
            ListNode* head = pq.top();
            pq.pop();

            if (head->next!=nullptr) {
                pq.push(head->next);
            }

            current->next = head;
            head->next = nullptr;
            current = current->next;
        }

        return dummy.next;
    }
};
