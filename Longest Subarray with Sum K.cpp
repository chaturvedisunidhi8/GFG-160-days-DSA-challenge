class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        unordered_map<int, int> prefixSumIndex;
        int sum = 0, maxLen = 0;

        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];

            if (sum == k) {
                maxLen = i + 1;
            }

            if (prefixSumIndex.find(sum - k) != prefixSumIndex.end()) {
                maxLen = max(maxLen, i - prefixSumIndex[sum - k]);
            }

            if (prefixSumIndex.find(sum) == prefixSumIndex.end()) {
                prefixSumIndex[sum] = i;
            }
        }

        return maxLen;
    }
};
