// Given a sorted array, arr[] and a number target, you need to find the number of occurrences of target in arr[]. 


class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        // code here
        int count =0;
        for(int num : arr){
            if(num == target){
                count++;
            }
        }
        return count;
    }
};
