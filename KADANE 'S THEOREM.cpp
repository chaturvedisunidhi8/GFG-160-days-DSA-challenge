//Given an integer array arr[]. You need to find the maximum sum of a subarray.

class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        // Your code here
        int currSum=0,maxSum=INT_MIN;
        for(int val:arr){
            currSum+=val;
            maxSum=max(currSum,maxSum);
            if(currSum<0){
                currSum=0;
            }
            
        }
        
        return maxSum;
        
        
    }
};



