class LRUCache {
private:
    int capacity;
    list<pair<int, int>> cache; // stores {key, value}
    unordered_map<int, list<pair<int, int>>::iterator> map;

    void moveToFront(int key, int value) {
        cache.erase(map[key]);
        cache.push_front({key, value});
        map[key] = cache.begin();
    }

public:
    LRUCache(int cap) {
        capacity = cap;
    }

    int get(int key) {
        if (map.find(key) == map.end()) {
            return -1;
        }
        int value = map[key]->second;
        moveToFront(key, value);
        return value;
    }

    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            moveToFront(key, value);
        } else {
            if (cache.size() == capacity) {
                int lruKey = cache.back().first;
                cache.pop_back();
                map.erase(lruKey);
            }
            cache.push_front({key, value});
            map[key] = cache.begin();
        }
    }
};
