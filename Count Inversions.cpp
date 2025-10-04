// Given an array of integers arr[]. Find the Inversion Count in the array.
// Two elements arr[i] and arr[j] form an inversion if arr[i] > arr[j] and i < j.

// Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If the array is already sorted then the inversion count is 0.
// If an array is sorted in the reverse order then the inversion count is the maximum. 


  class Solution {
  public:
    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr) {
        // Your Code Here
        vector<int> temp(arr.size());
        return mergeSort(arr,temp,0,arr.size()-1);
    }
    private:
    int mergeSort(vector<int>& arr,vector<int>&temp,int left , int right){
        int inv_count =0;
        if(left<right){
            int mid = left+(right-left)/2;
        inv_count +=mergeSort(arr,temp,left,mid);
        inv_count += mergeSort(arr,temp,mid+1,right);
        inv_count +=merge(arr,temp,left,mid+1,right);
        }
     return inv_count;
    }
     

int merge(vector<int> &arr , vector<int> &temp , int left, int mid,int right){
    int i= left;
    int j = mid;
    int k = left;
    int inv_count =0;
    while((i<=mid-1)&&(j<=right)){
        if(arr[i]<=arr[j]){
            temp[k++] = arr[i++];
        } else {
            temp[k++]= arr[j++];
            inv_count += (mid-i);
        }
        
    }
    while(i<=mid-1) temp[k++] = arr[i++];
    while(j<=right) temp[k++] = arr[j++];
    for(int i = left;i<=right;i++) 
    arr[i] =temp[i];
    return inv_count;
}
};
