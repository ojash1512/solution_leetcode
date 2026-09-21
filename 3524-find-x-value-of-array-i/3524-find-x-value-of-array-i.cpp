class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);

        vector<long long> dp(k, 0);

        for (int num : nums) {
            int x = num % k;

            vector<long long> next(k, 0);

            next[x]++;

            for (int r = 0; r < k; r++) {
                int newRemainder = (r * x) % k;
                next[newRemainder] += dp[r];
            }
            for (int r = 0; r < k; r++) {
                ans[r] += next[r];
            }

            dp = next;
        }

        return ans;
    }
};