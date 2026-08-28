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
    bool hasCycle(ListNode* head) {
        ListNode* front = head;
        ListNode* rear = head;

        do {
            if(front!=nullptr && front->next!=nullptr && front->next->next!=nullptr) {
                front = front->next->next;
            } else {
                front = nullptr;
            }

            if(rear!=nullptr && rear->next!=nullptr) {
                rear = rear->next;
            } else {
                rear = nullptr;
            }

            if(front==rear && front!=nullptr) {
                return true; // Cycle exists
            }

        } while (front!=nullptr || rear!=nullptr);

        return false;
    }
};
