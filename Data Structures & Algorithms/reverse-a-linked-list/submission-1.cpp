class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;

        while (head != nullptr) {
            ListNode* curr = head;
            ListNode* nextCurr = head->next;

            curr->next = prev;
            prev = curr;
            head = nextCurr;
        }

        return prev;
    }
};