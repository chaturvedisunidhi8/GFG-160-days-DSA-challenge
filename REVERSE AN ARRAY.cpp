// It is given an array of integers arr[]. Your task is to reverse the given array.

class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        // code here
        int l=0;
        int r=arr.size()-1;
        while(l<r)
        {
            swap(arr[l++],arr[r--]);
        }
    }
};
