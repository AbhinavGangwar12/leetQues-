class LRUCache {
    
public:
    unordered_map<int,int> c;
    vector<int> m;
    int capacity;
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(c.find(key) != c.end()){
            update(key);
            return c[key];
        }
        else return -1;
    }
    
    void put(int key, int value) {
        if(c.find(key) != c.end()){
            c[key] = value;
            update(key);
        }
        else {
            if(c.size() >= capacity){
                int val = m[0];
                c.erase(val);
                m.erase(m.begin());
            }
            c[key] = value;
            m.push_back(key);
        }
    }
    private:
    void update(int key){
        auto it = find(m.begin(),m.end(),key);
        m.erase(it);
        m.push_back(key);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */