// Given an array arr[] and a number target, find a pair of elements (a, b) in arr[], where a<=b whose sum is closest to target.
// Note: Return the pair in sorted order and if there are multiple such pairs return the pair with maximum absolute difference. If no such pair exists return an empty array.

class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        // code here
        vector<int> result;
        int n = arr.size();
        if (n < 2) return result;

        sort(arr.begin(), arr.end());
        int left = 0, right = n - 1;
        int closestDiff = INT_MAX;
        int maxAbsDiff = INT_MIN;

        while (left < right) {
            int sum = arr[left] + arr[right];
            int diff = abs(target - sum);

            if (diff < closestDiff || 
               (diff == closestDiff && abs(arr[right] - arr[left]) > maxAbsDiff)) {
                closestDiff = diff;
                maxAbsDiff = abs(arr[right] - arr[left]);
                result = {arr[left], arr[right]};
            }

            if (sum < target) {
                left++;
            } else {
                right--;
            }
        }

        return result;
    }
};
