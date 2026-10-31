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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy = ListNode();
        dummy.next = head;
        int delta = right - left + 1;

        if (delta==1) {
            return head;
        }
        
        // Reach the front
        ListNode* _front = &dummy;
        while(left!=1) {
            _front = _front->next;
            left--;
        }

        // The starting point of reversal
        ListNode* front = _front->next;

        // Reverse till the rear
        ListNode* prev = nullptr;
        ListNode* current = front;

        while(delta) {
            ListNode* currentNext = current->next;
            current->next = prev;
            prev = current;
            current = currentNext;
            delta--;
        }

        // Form the linked list : current is the _Rear, and Front is the prev
        _front->next = prev;
        front->next = current;

        return dummy.next;
    }
};