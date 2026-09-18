class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* groupPrev = &dummy;
        ListNode* slow = head;
        ListNode* fast = head;

        while (true) {
            // Check if we have k nodes
            for (int i = 0; i < k; i++) {
                if (fast == nullptr)
                    return dummy.next;

                fast = fast->next;
            }

            // Reverse [slow, fast)
            ListNode* prev = nullptr;
            ListNode* curr = slow;

            while (curr != fast) {
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            // Connect reversed group
            groupPrev->next = prev;
            slow->next = fast;

            // Move to next group
            groupPrev = slow;
            slow = fast;
        }
    }
};