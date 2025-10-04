//Given a square matrix mat[][] of size n x n. The task is to rotate it by 90 degrees in an anti-clockwise direction without using any extra space. 


class Solution {
  public:
    // Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                swap(mat[i][j],mat[j][i]);
            }
        }
        
       
            for(int j=0;j<n;j++){
                int top=0,bottom=n-1;
                while(top<bottom){
                    swap(mat[top][j],mat[bottom][j]);
                    top++;
                    bottom--;
                }
        
            }
        
        
    }
};

