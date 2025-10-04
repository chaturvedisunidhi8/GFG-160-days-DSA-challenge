#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxLen(vector<int>& arr) {
        // Convert 0s to -1
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 0) {
                arr[i] = -1;
            }
        }
        
        unordered_map<int, int> sumIndices;
        sumIndices[0] = -1; // Initialize with sum 0 at index -1
        int prefixSum = 0;
        int maxLength = 0;
        
        for (int i = 0; i < arr.size(); i++) {
            prefixSum += arr[i];
            
            if (sumIndices.find(prefixSum) != sumIndices.end()) {
                int length = i - sumIndices[prefixSum];
                if (length > maxLength) {
                    maxLength = length;
                }
            } else {
                sumIndices[prefixSum] = i;
            }
        }
        
        return maxLength;
    }
};
