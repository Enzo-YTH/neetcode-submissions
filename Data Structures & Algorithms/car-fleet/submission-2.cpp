class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        std::vector<std::pair<int, int>> cars;
        for (int i = 0; i < position.size(); i++) {
            cars.push_back({position[i], speed[i]});
        }
        std::sort(cars.begin(), cars.end());
        vector<float> stack;
        for (int i = cars.size() - 1; i >= 0; i--) {
            float time = (float)(target - cars[i].first) / cars[i].second;
            if (stack.empty() || time > stack.back()) {
                stack.push_back(time);
                // printf("position[i] = %d \n", position[i]);
            }
        }

        return stack.size();
    }
};
