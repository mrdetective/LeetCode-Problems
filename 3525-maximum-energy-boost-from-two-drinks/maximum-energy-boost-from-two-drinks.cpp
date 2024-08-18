class Solution {
public:
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        int n = energyDrinkA.size();
        vector<pair<long long, long long>>p;
        for(int i = 0; i < n; i++){
            p.push_back({energyDrinkA[i], energyDrinkB[i]});
        }
        for(int i = 0; i < n - 1; i++){
            if(i != n - 2){
                p[i + 2].second = max(p[i + 2].second, p[i].first + energyDrinkB[i + 2]);
                p[i + 2].first = max(p[i + 2].first, p[i].second + energyDrinkA[i + 2]);
            }
            p[i + 1].first = max(p[i + 1].first, p[i].first + energyDrinkA[i + 1]);
            p[i + 1].second = max(p[i + 1].second, p[i].second + energyDrinkB[i + 1]);
        }
        long long ans = 0;
        for(int i = 0; i < n; i++){
            ans = max({ans, p[i].first, p[i].second});
        }
        return ans;
    }
};