class Solution {
public:
    unordered_map<Node*, Node*> mp;

    Node* copyRandomList(Node* head) {

        Node* curr = head;

        // Create copies
        while (curr != nullptr) {
            mp[curr] = new Node(curr->val);
            curr = curr->next;
        }

        // Connect pointers
        curr = head;

        while (curr != nullptr) {
            if (curr->next != nullptr)
                mp[curr]->next = mp[curr->next];

            if (curr->random != nullptr)
                mp[curr]->random = mp[curr->random];

            curr = curr->next;
        }

        return mp[head];
    }
};