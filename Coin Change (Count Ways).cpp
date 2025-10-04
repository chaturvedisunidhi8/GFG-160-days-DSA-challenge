class Solution {
public:
    long long int count(vector<int>& coins, int sum) {
        int N = coins.size();
        vector<long long int> dp(sum + 1, 0);
        dp[0] = 1;

        for (int i = 0; i < N; i++) {
            for (int j = coins[i]; j <= sum; j++) {
                dp[j] += dp[j - coins[i]];
            }
        }

        return dp[sum];
    }
};
