/* Given an array arr[] denoting heights of N towers and a positive integer K.
For each tower, you must perform exactly one of the following operations exactly once.
Increase the height of the tower by K
Decrease the height of the tower by K
Find out the minimum possible difference between the height of the shortest and tallest towers after you have modified each tower.*/
class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        // code here
        int minVal=0,maxVal=0,r=0;
        sort(arr.begin(), arr.end()); 
        int n = arr.size();
        r= arr[n-1] - arr[0];
        for(int i =1; i<n;i++){
            if (arr[i]>=k){
                maxVal = max(arr[i-1]+k,arr[n-1]-k);
                minVal = min(arr[i]-k , arr[0]+k);
                r =min(r,maxVal-minVal);
            }
            else{
                continue;
            }
        }
        return r;
    }
};


