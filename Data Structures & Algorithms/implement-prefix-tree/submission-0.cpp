class Node {
    public:
        char val;
        vector<Node*> next;
        bool isEnd;

        Node(char val) {
            this->val = val;
            next.resize(26,nullptr);
            isEnd = false;
        }
};

class PrefixTree {
public:
    Node* root;

    PrefixTree() {
        root = new Node('/0');
    }
    
    void insert(string word) {
        Node* current = root;

        for(int i=0; i<word.size(); i++) {
            int pos = word[i] - 'a';
            if (current->next[pos] == nullptr) {
                current->next[pos] = new Node(word[i]);
            } 
            current = current->next[pos];
        }

        current->isEnd = true;
    }
    
    bool search(string word) {
        Node* current = root;

        for(int i=0; i<word.size(); i++) {
            int pos = word[i] - 'a';
            if (current->next[pos] == nullptr) {
                return false;
            }
            current = current->next[pos];
        }

        if (current->isEnd) {
            return true;
        }

        return false;
    }
    
    bool startsWith(string prefix) {
        Node* current = root;

        for(int i=0; i<prefix.size(); i++) {
            int pos = prefix[i] - 'a';
            if (current->next[pos] == nullptr) {
                return false;
            }
            current = current->next[pos];
        }

        return true;
    }
};
