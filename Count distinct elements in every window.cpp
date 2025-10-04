

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here.
        vector<int> result;
        unordered_map<int, int> freq;

        for (int i = 0; i < arr.size(); i++) {
            freq[arr[i]]++;

            if (i >= k - 1) {
                result.push_back(freq.size());

                int elementOut = arr[i - k + 1];
                freq[elementOut]--;

                if (freq[elementOut] == 0) {
                    freq.erase(elementOut);
                }
            }
        }
        return result;
    }
};
