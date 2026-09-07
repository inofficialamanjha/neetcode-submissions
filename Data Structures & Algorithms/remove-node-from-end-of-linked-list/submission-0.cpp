class Solution {
public:

    ListNode* reverseLinkedList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* next = curr->next;

            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {

        // 1. Reverse the list
        head = reverseLinkedList(head);

        // 2. Remove nth node from the beginning
        //    (which is nth from the end in original list)

        if (n == 1) {
            head = head->next;
        } 
        else {
            ListNode* curr = head;

            // Move to node just before nth node
            for (int i = 1; i < n - 1; i++) {
                curr = curr->next;
            }

            curr->next = curr->next->next;
        }

        // 3. Reverse again
        head = reverseLinkedList(head);

        return head;
    }
};