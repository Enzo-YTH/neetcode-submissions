class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<std::pair<int, int>> vec;  // temp, index
        vector<int> ret(temperatures.size(), 0);
        for (int i = 0; i < temperatures.size(); i++) {
            if (!vec.empty() && vec.back().first < temperatures[i]) {
                while (!vec.empty() && vec.back().first < temperatures[i]) {
                    ret[vec.back().second] = i - vec.back().second;
                    vec.pop_back();
                }
            }
            vec.push_back({temperatures[i], i});
        }

        return ret;
    }
};
