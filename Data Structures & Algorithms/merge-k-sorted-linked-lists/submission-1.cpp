class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int s = 0;
        int e = lists.size() - 1;

        return merge(lists, s, e);
    }

    ListNode* merge(const vector<ListNode*>& lists, int s, int e) {

        if (s > e) {
            return nullptr;
        }

        if (s == e) {
            return lists[s];
        }

        int mid = s + (e - s) / 2;

        ListNode* head1 = merge(lists, s, mid);
        ListNode* head2 = merge(lists, mid + 1, e);

        return merge2Lists(head1, head2);
    }

    ListNode* merge2Lists(ListNode* head1, ListNode* head2) {

        ListNode dummy(0);
        ListNode* current = &dummy;

        while (head1 != nullptr && head2 != nullptr) {

            if (head1->val < head2->val) {
                current->next = head1;
                head1 = head1->next;
            } else {
                current->next = head2;
                head2 = head2->next;
            }

            current = current->next;
        }

        if (head1 != nullptr) {
            current->next = head1;
        }

        if (head2 != nullptr) {
            current->next = head2;
        }

        return dummy.next;
    }
};