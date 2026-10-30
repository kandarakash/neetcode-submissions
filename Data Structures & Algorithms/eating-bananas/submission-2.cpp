class Solution {
public:
    long long func(vector<int>& piles, int k) {
        long long ans = 0;

        for (int i = 0; i < piles.size(); i++) {
            ans += (piles[i] + k - 1) / k;
        }

        return ans;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        while (left <= right) {
            int mid = left + (right - left) / 2;
            long long curr = func(piles, mid);

            if (curr <= h)
                right = mid - 1;
            else
                left = mid + 1;
        }

        return left;
    }
};