//Given an array arr[] that contains positive and negative integers (may contain 0 as well). Find the maximum product that we can get in a subarray of arr[].
//Note: It is guaranteed that the output fits in a 32-bit integer.

class Solution {
  public:
    // Function to find maximum product subarray
    int maxProduct(vector<int> &arr) {
        // Your Code Here
        if(arr.empty()) return 0;
        int maxP=arr[0],minP=arr[0],res=arr[0];
        
        for(int i=1;i<arr.size();i++){
            if(arr[i]<0) swap(maxP,minP);
            
            maxP=max(arr[i],maxP*arr[i]);
            
            minP=min(arr[i],minP*arr[i]);
            
            res=max(res,maxP);
            
        }
        return res;
    }
};





