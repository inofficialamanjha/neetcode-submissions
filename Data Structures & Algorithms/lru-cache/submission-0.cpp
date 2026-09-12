#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    Node* prev;
    Node* next;
    int key;

    Node(int key) {
        this->key = key;
        prev = nullptr;
        next = nullptr;
    }
};

class DoubleEndedLinkedList {
public:
    Node* front;   // LRU
    Node* rear;    // MRU

    DoubleEndedLinkedList() {
        front = nullptr;
        rear = nullptr;
    }

    // Add a NEW node at rear
    Node* push(int key) {
        Node* newNode = new Node(key);

        if (rear == nullptr) {
            // Empty list
            front = rear = newNode;
        } 
        else {
            newNode->prev = rear;
            rear->next = newNode;
            rear = newNode;
        }

        return newNode;
    }

    // Remove a specific node
    void remove(Node* node, bool toDelete = true) {
        if (node == nullptr)
            return;

        // Only node
        if (front == node && rear == node) {
            front = rear = nullptr;
        }

        // Removing front
        else if (front == node) {
            front = node->next;
            front->prev = nullptr;
        }

        // Removing rear
        else if (rear == node) {
            rear = node->prev;
            rear->next = nullptr;
        }

        // Removing middle
        else {
            Node* prev = node->prev;
            Node* next = node->next;

            prev->next = next;
            next->prev = prev;
        }

        // Completely detach node
        node->prev = nullptr;
        node->next = nullptr;

        if (toDelete) {
            delete node;
        }
    }

    // Remove LRU node
    Node* pop() {
        if (front == nullptr)
            return nullptr;

        Node* lru = front;

        remove(lru, false);

        return lru;
    }

    // Move an existing node to MRU position
    void moveToRear(Node* node) {
        if (node == nullptr || node == rear)
            return;

        // Remove node from current position
        remove(node, false);

        // Add SAME node at rear
        node->prev = rear;
        node->next = nullptr;

        if (rear != nullptr) {
            rear->next = node;
        } 
        else {
            // List was empty
            front = node;
        }

        rear = node;
    }
};


class LRUCache {
public:
    DoubleEndedLinkedList* doubly;

    // key -> {value, pointer to node}
    unordered_map<int, pair<int, Node*>> index;

    int capacity;

    LRUCache(int capacity) {
        this->capacity = capacity;
        doubly = new DoubleEndedLinkedList();
    }

    int get(int key) {
        // Key doesn't exist
        if (index.find(key) == index.end()) {
            return -1;
        }

        // Get node
        Node* node = index[key].second;

        // This key was recently accessed,
        // so move it to MRU
        doubly->moveToRear(node);

        // Return value
        return index[key].first;
    }

    void put(int key, int value) {
        // Key already exists
        if (index.find(key) != index.end()) {
            Node* node = index[key].second;

            // Update value
            index[key].first = value;

            // This key is now recently used
            doubly->moveToRear(node);

            return;
        }

        // Cache is full
        if (index.size() == capacity) {
            // Remove LRU
            Node* lru = doubly->pop();

            // Remove from hashmap
            index.erase(lru->key);

            // Free memory
            delete lru;
        }

        // Add new key at MRU
        Node* node = doubly->push(key);

        // Store value + node pointer
        index[key] = {value, node};
    }
};