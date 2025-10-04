//Given an array arr[] where no two adjacent elements are same, find the index of a peak element. An element is considered to be a peak 
//if it is greater than its adjacent elements (if they exist). If there are multiple peak elements, return index of any one of them. 
//The output will be "true" if the index returned by your function is correct; otherwise, it will be "false".


class Solution {
  public:
    int peakElement(vector<int> &arr) {
        // Your code here
    int n=arr.size();
    int st=0,end=n-1;
    while(st<=end){
        int mid=st+(end-st)/2;
        
        bool left=(mid==0|| arr[mid] >arr[mid-1]);
        bool right=(mid==n-1 || arr[mid]>arr[mid+1]);
        
        
        if(left && right ){
            return  mid;
        }
        else if(mid>0 && arr[mid-1]>arr[mid]){
            end=mid-1;
        }
        else{
            st=mid+1;
        }
    }
  return -1;    
  }
  
        
};
