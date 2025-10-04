//Given a sorted array of distinct positive integers arr[], we need to find the k-th positive number that is missing from arr[].



class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0, high = arr.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] - (mid + 1) < k)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low + k;
    }
};
