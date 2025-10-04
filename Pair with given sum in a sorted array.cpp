// You are given an integer target and an array arr[]. You have to find number of pairs in arr[] which sums up to target. It is given that the elements of the arr[] are in sorted order.
// Note: pairs should have elements of distinct indexes. 

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Complete the function
        unordered_map<int, int> freq;
        int count = 0;
        for (int num : arr) {
            int complement = target - num;
            if (freq.find(complement) != freq.end()) {
                count += freq[complement];
            }
            freq[num]++;
        }
        return count;
    }
};
