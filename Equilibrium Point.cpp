
class Solution {
  public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) {
        // code here
        int totalSum = 0;
        int n = arr.size();  
        for (int i = 0; i < n; i++) {
            totalSum += arr[i];
        }
        int leftSum = 0;
        for (int i = 0; i < n; i++) {
            totalSum -= arr[i]; 
            if (leftSum == totalSum) {
                return i;  
            }
            leftSum += arr[i];
        }
        return -1;
    }
};
