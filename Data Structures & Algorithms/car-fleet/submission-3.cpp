class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> cars(n);
        
        for (int i = 0; i < n; ++i) {
            cars[i] = {position[i], speed[i]};
        }
        
        // Sort cars by position in ascending order
        sort(cars.begin(), cars.end());
        
        int fleets = 0;
        double max_time = 0;
        
        // Iterate from the car closest to the target backwards
        for (int i = n - 1; i >= 0; --i) {
            double time = static_cast<double>(target - cars[i].first) / cars[i].second;
            
            // If this car takes strictly longer than the current fleet ahead,
            // it cannot catch up and forms a new fleet.
            if (time > max_time) {
                fleets++;
                max_time = time;
            }
        }
        
        return fleets;
    }
};