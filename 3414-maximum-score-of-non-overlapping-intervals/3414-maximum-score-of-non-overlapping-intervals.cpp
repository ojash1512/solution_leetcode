class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        for (int i = 0; i < n; i++) {
            intervals[i].push_back(i);
        }

        sort(intervals.begin(), intervals.end());

        vector<int> starts(n);
        for (int i = 0; i < n; i++)
            starts[i] = intervals[i][0];

        vector<vector<pair<long long, vector<int>>>> dp(
            n + 1, vector<pair<long long, vector<int>>>(5, {0, {}})
        );

        for (int i = n - 1; i >= 0; i--) {
            for (int cnt = 1; cnt <= 4; cnt++) {
                dp[i][cnt] = dp[i + 1][cnt];

                int j = lower_bound(starts.begin(), starts.end(), intervals[i][1] + 1) - starts.begin();

                long long score = intervals[i][2] + dp[j][cnt - 1].first;

                vector<int> ids = dp[j][cnt - 1].second;
                ids.push_back(intervals[i][3]);

                sort(ids.begin(), ids.end());

                if (score > dp[i][cnt].first ||
                    (score == dp[i][cnt].first && ids < dp[i][cnt].second)) {
                    dp[i][cnt] = {score, ids};
                }
            }
        }

        return dp[0][4].second;
    }
};