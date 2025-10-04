// User function template for C++

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        // code here
        int n = arr.size();
    if (n == 0) return {};
    
    vector<int> res(n, 1);
    
    // Calculate left products
    for (int i = 1; i < n; ++i) {
        res[i] = res[i - 1] * arr[i - 1];
    }
    
    // Calculate right products and multiply with left products
    int right = 1;
    for (int i = n - 1; i >= 0; --i) {
        res[i] = res[i] * right;
        right *= arr[i];
    }
    
    return res;
    }
};
