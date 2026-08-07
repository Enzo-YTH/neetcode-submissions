class TimeMap {
private:
    std::unordered_map<std::string, std::vector<std::pair<int, std::string>>> keyStore;
public:
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        keyStore[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (keyStore.find(key) != keyStore.end()) {
            int l = 0, r = keyStore[key].size() - 1;
            int val = -1, val_idx;
            while (l <= r) {
                int m = l + (r - l) / 2;
                if (keyStore[key][m].first == timestamp)
                    return keyStore[key][m].second;
                else if (keyStore[key][m].first > timestamp) {
                    r = m - 1;
                }
                else {
                    if (keyStore[key][m].first > val) {
                        val = keyStore[key][m].first;
                        val_idx = m;
                    }
                    l = m + 1;
                }
            }
            return (val == -1) ? "" : keyStore[key][val_idx].second;
        }
        else {
            return "";
        }
    }
};
