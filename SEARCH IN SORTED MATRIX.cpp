//Given a strictly sorted 2D matrix mat[][] of size n x m and a number x. Find whether the number x is present in the matrix or not.
//Note: In a strictly sorted matrix, each row is sorted in strictly increasing order, and the first element of the ith row (i!=0) is greater than the last element of the (i-1)th row.


class Solution {
  public:
    // Function to search a given number in row-column sorted matrix.
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        // code here
        
        int n=mat.size();
        if(n==0) return false;
        int m=mat[0].size();
        
        int row=0,col=m-1;
        
        while(row<n && col>=0){
            if(mat[row][col]==x){
                return true;
            }
            else if(mat[row][col]>x){
                col--;
                
            }
            else{
                row++;
            }
        }
         return false;
    }
};
