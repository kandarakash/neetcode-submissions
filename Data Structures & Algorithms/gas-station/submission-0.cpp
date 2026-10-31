class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int maxi = -1;
        int maxdiff = 0;
        int total = 0;
        int curr = 0;
        for(int i = 0; i < n; i++) {
            int diff = gas[i] - cost[i];
            total += diff;
            curr += diff;
            if(curr < 0) {
                curr = 0;
                maxi = i + 1;
            }
        }
        if(total < 0) return -1;
        return maxi == -1 ? 0 : maxi;
    }
};