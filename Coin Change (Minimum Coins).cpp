class Solution {
public:
    int minCoins(vector<int>& coins, int V) {
        int M = coins.size();
        vector<int> dp(V + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= V; i++) {
            for (int j = 0; j < M; j++) {
                if (coins[j] <= i && dp[i - coins[j]] != INT_MAX) {
                    dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
                }
            }
        }

        return dp[V] == INT_MAX ? -1 : dp[V];
    }
};
