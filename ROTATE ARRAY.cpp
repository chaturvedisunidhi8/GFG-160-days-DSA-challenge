//Given an array arr[]. Rotate the array to the left (counter-clockwise direction) by d steps, where d is a positive integer. Do the mentioned change in the array in place.

class Solution {
  public:

    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(vector<int>& arr, int d) {
        // code here
        d%=arr.size();
        reverse(arr,0,d-1);
        reverse(arr,d,arr.size()-1);
        reverse(arr,0,arr.size()-1);
    }
    private:
    void reverse(vector<int>& arr,int l,int r){
    while(l<r)
        swap(arr[l++],arr[r--]);
    }
};
