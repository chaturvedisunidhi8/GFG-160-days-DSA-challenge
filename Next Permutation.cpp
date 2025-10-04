// Given an array of integers arr[] representing a permutation, implement the next permutation that rearranges the numbers into the lexicographically next greater permutation. If no such permutation exists, rearrange the numbers into the lowest possible order (i.e., sorted in ascending order). 
// Note - A permutation of an array of integers refers to a specific arrangement of its elements in a sequence or linear order.


class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        // code here
        int n = arr.size();
        int i =n-2;
        while(i>=0&& arr[i]>=arr[i+1]){
            i--;
        }
        if(i>=0){
            int j=n-1;
            while(j>i&&arr[j]<=arr[i]){
                j--;
            }
            swap(arr[i],arr[j]);
        }
        reverse(arr.begin()+i+1,arr.end());
    }
};
