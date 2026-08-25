#define RANGE 1000000

class MyHashSet {
public:
    vector<bool> counter;

    MyHashSet() {
        counter = vector<bool>(RANGE + 1,false);
    }
    
    void add(int key) {
        counter[key] = true;
    }
    
    void remove(int key) {
        counter[key] = false;
    }
    
    bool contains(int key) {
        return counter[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */