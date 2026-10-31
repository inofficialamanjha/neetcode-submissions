
class Node {
public:
    int key;
    int val;
    int freq;
    list<Node*>::iterator pos;

    Node(int key, int val) {
        this->key = key;
        this->val = val;
        this->freq = 1;
    }
};

class LFUCache {
public:
    int capacity;
    int minFreq = 0;

    unordered_map<int, list<Node*>> freqMap;
    unordered_map<int, Node*> keyMap;

    LFUCache(int capacity) {
        this->capacity = capacity;
    }

    void updateFrequency(Node* node) {
        int freq = node->freq;

        freqMap[freq].erase(node->pos);

        if (freqMap[freq].empty()) {
            freqMap.erase(freq);

            if (minFreq == freq) {
                minFreq++;
            }
        }

        node->freq++;

        freqMap[node->freq].push_front(node);
        node->pos = freqMap[node->freq].begin();
    }

    int get(int key) {
        if (!keyMap.count(key)) {
            return -1;
        }

        Node* node = keyMap[key];
        updateFrequency(node);

        return node->val;
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        if (keyMap.count(key)) {
            Node* node = keyMap[key];
            node->val = value;
            updateFrequency(node);
            return;
        }

        if (keyMap.size() == capacity) {
            Node* node = freqMap[minFreq].back();

            freqMap[minFreq].pop_back();
            keyMap.erase(node->key);

            delete node;
        }

        Node* node = new Node(key, value);

        freqMap[1].push_front(node);
        node->pos = freqMap[1].begin();

        keyMap[key] = node;
        minFreq = 1;
    }
};
