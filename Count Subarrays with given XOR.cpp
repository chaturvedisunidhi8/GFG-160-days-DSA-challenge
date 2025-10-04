// Given an array of integers arr[] and a number k, count the number of subarrays having XOR of their elements as k.


class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        unordered_map<int, int> freq;
        int xorSum = 0;
        long count = 0;
        for (int i = 0; i < arr.size(); i++) {
            xorSum ^= arr[i];
            if (xorSum == k)
                count++;
            int required = xorSum ^ k;
            if (freq.find(required) != freq.end())
                count += freq[required];
            freq[xorSum]++;
        }
        return count;
    }
};
