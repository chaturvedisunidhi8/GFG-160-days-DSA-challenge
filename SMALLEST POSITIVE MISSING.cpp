//You are given an integer array arr[]. Your task is to find the smallest positive number missing from the array.

class Solution {
  public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(vector<int> &arr) {
        // Your code here
        int n = arr.size();
        for (int i=0; i<n; i++){
            if(arr[i]> 0&& arr[i] <= n){
                int index =arr[i]-1;
                if(arr[index] != arr[i]){
                    swap(arr[i], arr[index]);
                    i--;
                }
            }
        }
        for (int i=0;i<n;i++){
            if(arr[i] !=i+1)
            return i+1;
        }
        return n+1;
    }
};
