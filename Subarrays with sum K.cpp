// Given an unsorted array of integers, find the number of subarrays having sum exactly equal to a given number k.


class Solution {
  public:
    int countSubarrays(vector<int> &arr, int k) {
        // code here
        unordered_map<int, int> prefixSumCount;
        int count = 0;
        int currentSum = 0;
        prefixSumCount[0] = 1;
        for (int num : arr) {
            currentSum += num;
            if (prefixSumCount.find(currentSum - k) != prefixSumCount.end()) {
                count += prefixSumCount[currentSum - k];
            }
            prefixSumCount[currentSum]++;
        }
        return count;
    }
};
