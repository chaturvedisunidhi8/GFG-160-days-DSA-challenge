//Given an array of integers arr[] in a circular fashion. Find the maximum subarray sum that we can get if we assume the array to be circular.

class Solution {
  public:
    // arr: input array
    // Function to find maximum circular subarray sum.
    int circularSubarraySum(vector<int> &arr) {
int n=arr.size(),mn=INT_MAX,mx=INT_MIN,sum1=0,sum2=0,total=0;

for(int i=0;i<n;i++){
    
    
    total+=arr[i];
    sum2=min(arr[i],sum2+arr[i]);
    mn=min(mn,sum2);
    sum1=max(arr[i],sum1+arr[i]);
    mx=max(mx,sum1);
}



if(mx<0) return mx;
  
  
return max(mx,total-mn);
    }
};
