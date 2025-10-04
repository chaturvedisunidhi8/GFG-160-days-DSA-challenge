// Given an array arr[] containing only 0s, 1s, and 2s. Sort the array in ascending order.

// You need to solve this problem without utilizing the built-in sort function.

class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int low =0 , mid =0 , high = arr.size()-1;
        while(mid<=high){
            if(arr[mid]==0){
                swap(arr[low],arr[mid]);
                low++;
                mid++;
            }
            else if (arr[mid]==1){
                mid++;
            }
            else{
                swap(arr[high],arr[mid]);
                high--;
            }
        }
    }
};
