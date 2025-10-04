// Given an array arr[] of non-negative integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.


class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        // Your code here
        unordered_set<int> s(arr.begin(), arr.end());
        int longest = 0;
    for (int num : arr) {
        if (s.find(num - 1) == s.end()) { 
            int currentNum = num;
            int count = 1;
            while (s.find(currentNum + 1) != s.end()) {
                currentNum++;
                count++;
            }
            longest = max(longest, count);
        }
    }
    return longest;
    }
};
