//Given two sorted arrays a[] and b[] and an element k, the task is to find the element that would be at the kth position of the combined sorted array.



class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b,int k) {
        // code here
      //  int n1,n2,k;
      int n1=a.size();
      int n2=b.size();
      
      if(k<=0 || k>n1+n2) return -1;
        if(n1>n2) return kthElement(b,a,k);
        int low =max(0,k-n2), high=min(k,n1);
       // int left=k;
        //int n=n1+n2;
        while(low<=high){
            int mid1=(low+high)>>1;
            int mid2=k-mid1;
            
            int l1=(mid1 >0) ? a[mid1-1] :INT_MIN;
            int l2=(mid2>0) ? b[mid2-1] :INT_MIN;
            int r1=(mid1<n1) ? a[mid1] :INT_MAX;
            int r2=(mid2<n2) ? b[mid2] :INT_MAX;
    
            if(l1<=r2 && l2<=r1) {
                return max(l1,l2);
                
            }
        
        else if(l1>r2){
            high=mid1-1;
        }
        else{
            
            low=mid1+1;
        }
        }
        
        return -1;
        
    }
};
