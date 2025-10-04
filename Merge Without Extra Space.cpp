// Given two sorted arrays a[] and b[] of size n and m respectively, the task is to merge them in sorted order without using any extra space. Modify a[] so that it contains the first n elements and modify b[] so that it contains the last m elements.

class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        // code here
        int n = a.size(), m = b.size();
        
        int gap = nextGap(n+m);
        while(gap>0){
            int i =0, j = gap;
            while(j<n+m){
                int val1 , val2;
                if (i<n) val1 = a[i];
                else val1 = b[i-n];
                
                if(j<n) val2 = a[j];
                else val2 = b[j-n];
                
                if(val1>val2){
                    if(i<n && j<n){
                        swap(a[i],a[j]);
                    } else if (i<n && j >=n){
                        swap(a[i], b[j-n]);
                    } else{
                        swap(b[i-n], b[j-n]);
                    }
                }
                i++;
                j++;
            }
            gap = nextGap(gap);
        }
    }
private:
int nextGap(int gap){
    if (gap<= 1) return 0;
    return (gap/2) + (gap%2);
}
};
