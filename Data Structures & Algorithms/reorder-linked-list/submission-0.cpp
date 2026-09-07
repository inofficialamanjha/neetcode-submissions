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
        if (head==nullptr || head->next==nullptr || head->next->next == nullptr) {
            return;
        }

        ListNode* front = head;
        ListNode* preRear = head;
        while(preRear->next->next!=nullptr) {
            preRear = preRear->next; // Move
        }

        ListNode* rear = preRear->next;
        preRear->next = nullptr;
        head = front->next;

        front->next = rear;
        rear->next = head;

        reorderList(head);
    }
};

/**
T(n)  = T(n-2) + n
T(n) = T(n-4) + n + n-2
T(n) = T(n-6) + n + n-2 + n-4
T(n) = T(2) + (n/2)*n - [n/2[(n-1)2]] = (n*n)/2 - (n*n)/4 + n/4 = o(n) square 
**/
