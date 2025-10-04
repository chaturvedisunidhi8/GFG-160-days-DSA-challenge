
class Solution {
public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        multiset<int> window;
        int left = 0, start = 0, maxLen = 0;

        for (int right = 0; right < arr.size(); ++right) {
            window.insert(arr[right]);

            // shrink the window if the difference exceeds x
            while (*window.rbegin() - *window.begin() > x) {
                window.erase(window.find(arr[left]));
                left++;
            }

            if (right - left + 1 > maxLen) {
                maxLen = right - left + 1;
                start = left;
            }
        }

        vector<int> result;
        for (int i = start; i < start + maxLen; ++i) {
            result.push_back(arr[i]);
        }

        return result;
    }
};
